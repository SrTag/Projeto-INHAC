#include "Jogo.h"

Jogo::Jogo()
{
	idUser = 0;
	novoJogador = false;
	user = new Usuario[3];
	nomeUserNovo = "";
	senhaNova = "";
}

Jogo::~Jogo()
{
	
}

void Jogo::inicializar()
{
	uniInicializar(800, 600, false);

	personagem = 0;

	cartas = new MontaCartas();

	cartas->carregarStatusCartas_Arq();
	cartas->carregarSprites();
	cartas->setSpriteShetStatus();
	cartas->setPosX_PosY();
	
	//set do jogo
	//Botoes
	botao[bvoltar].setSpriteSheet("BotaoVoltar");
	botao[bJogar].setSpriteSheet("botaoJogar");
	botao[bSim].setSpriteSheet("BotaoSIM");
	botao[bNao].setSpriteSheet("BotaoNAO");
	botao[bCreditos].setSpriteSheet("botaoCreditos");

	//botoes Versao 2.0
	//Set botoes versao 2.0
	botao[bLoad].setSpriteSheet("BotaoLoad");
	botao[bNewGame].setSpriteSheet("BotaoNewGame");
	botao[bSair].setSpriteSheet("BotaoSair");
	botao[bRecord].setSpriteSheet("BotaoRecords");
	botao[bSaveUser].setSpriteSheet("saveUser");
	botao[bSaveUser2].setSpriteSheet("saveUser");
	botao[bSaveUser3].setSpriteSheet("saveUser");
	//Pos dos botoes Versao 2.0
	botao[bLoad].setPos(100, (gJanela.getAltura() / 2) -100);
	botao[bNewGame].setPos(100, (gJanela.getAltura() / 2) -200);
	botao[bSair].setPos(700, (gJanela.getAltura() / 2) +250);
	botao[bRecord].setPos(100, (gJanela.getAltura() / 2) + 100);

	//POS botoes de load Versao 2.0
	botao[bSaveUser].setPos(gJanela.getLargura() / 2, (gJanela.getAltura() / 2) - 100);
	botao[bSaveUser2].setPos(gJanela.getLargura()/2, (gJanela.getAltura() / 2) - 200);
	botao[bSaveUser3].setPos(gJanela.getLargura()/2, (gJanela.getAltura() / 2) + 100);

	//sprite do fundo Versao 2.0
	fundo[fLoad].setSpriteSheet("fundoLoad");
	fundo[fLoad].setEscala(1, 1);

	// txt dos user Versao 2.0
	txt[0].setFonte("creditostxt");
	txt[0].setString("Ola Chefe, somos a OCCV !! qual seu nome para registro no sistema ?");
	txt[1].setFonte("creditostxt");
	txt[1].setString("Informe sua Senha");
	// avisos


	for (int i = 0; i < 3; i++) 
	{
		txtUser[i].setFonte("creditostxt");
		txtUser[i].setCor(2, 2, 2);
		txtUser[i].setEspacamentoLinhas(1.5);
		txtUser[i].setEscala(0.5, 0.5);
		txtUser[i].setString(to_string(user[i].getID()) + " ->" + user[i].getNome());
	}
	
	////////////////////////////////////////////////
	

	//Musica
	som[somBotao].setAudio("somBotao");
	som[somJogo].setAudio("somGame");

	//fonte
	creditosText.setFonte("creditostxt");
	creditosText.setString("\n desenvolvedor: Jonathan Farias\n CURSO: JOGOS DIGITAIS - Algoritmos e Estruturas de Dados em C++ \n\n  Agradecimentos:  Matheus Wilhelms de Souza \ Raphael Leite Campos \n\n esse jogo foi desenvolvido, para ajudar contra a luta ao COVID, podenda as pessoas se intreter durante o isolamento social");

	
	///game over
	fundo[fcel].setSpriteSheet("fundoOver");
	fundo[fcel].setEscala(2, 2);

	//sprite do menu
	fundo[fMenu].setSpriteSheet("fundoMenu");
	fundo[fMenu].setEscala(1, 1);

	//definição da posição dos botoes
	botao[bvoltar].setPos(750, gJanela.getAltura() / 2);
	botao[bJogar].setPos(100, (gJanela.getAltura() / 2) - 100);
	botao[bCreditos].setPos(100, (gJanela.getAltura() / 2)+250);
	botao[bSim].setPos(50, gJanela.getAltura() / 2);
	botao[bNao].setPos(750, gJanela.getAltura() / 2);
}

void Jogo::finalizar()
{
	uniFinalizar();
}

void Jogo::executar()
{
	
	while (!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{

		uniIniciarFrame();

		

		fundo[fMenu].desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
		
		/*botao[bJogar].atualizar();
		botao[bJogar].desenhar();
		*/
		botao[bCreditos].atualizar();
		botao[bCreditos].desenhar();

		//Versao 2.0 Desenhar Botoes
		botao[bNewGame].atualizar();
		botao[bNewGame].desenhar();
		botao[bLoad].atualizar();
		botao[bLoad].desenhar();
		botao[bSair].atualizar();
		botao[bSair].desenhar();
		botao[bRecord].atualizar();
		botao[bRecord].desenhar();
		

		/////////////////////////
		
		if (botao[bCreditos].estaClicado())
		{
			som[somBotao].tocar();
			creditos();
		}

		if (botao[bNewGame].estaClicado())
		{
			novoJogador == true;
			som[somBotao].tocar();
			newGame();
		}

		uniTerminarFrame();
		
	}
}

void Jogo::Jogar()
{
	while (!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{
		uniIniciarFrame();

		if (cartas->returnGameOver() == true) 
		{
			gameOver();
		}
		else 
		{
			som[somJogo].tocar();
			if (som[somJogo].terminouDeTocar()) {

				som[somJogo].tocar();
			}
			fundo[fMenu].desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
			cartas->MontandoCartas();

			botao[bSim].atualizar();
			botao[bSim].desenhar();

			botao[bNao].atualizar();
			botao[bNao].desenhar();


			if (botao[bNao].estaClicado()) {

				som[somBotao].tocar();
				cartas->attStatus(personagem, false);
				cartas->proxCarta(personagem + 1);
				personagem++;
			}
			if (botao[bSim].estaClicado()) {
				som[somBotao].tocar();
				cartas->attStatus(personagem, true);
				cartas->proxCarta(personagem + 1);
				personagem++;
			}

		}


		uniTerminarFrame();

	}
	
}

void Jogo::gameOver()
{
	while (!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{
		uniIniciarFrame();
		

		cartas->qualGameOver();

		uniTerminarFrame();

	}
	
}

void Jogo::Vitoria()
{
	vitoria.setSpriteSheet("vitoria");
	vitoria.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
}

void Jogo::creditos()
{

	while (!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{

		uniIniciarFrame();



		fundo[fMenu].desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
		creditosText.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

		botao[bvoltar].atualizar();
		botao[bvoltar].desenhar();

		if (botao[bvoltar].estaClicado())
		{
			som[somBotao].tocar();
			executar();
		}

		uniTerminarFrame();

	}

}

void Jogo::newGame()
{
	
	/////////////////////////////
	/*while (!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{

		uniIniciarFrame();
		fundo[fMenu].desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
		
		txt[0].desenhar(gJanela.getLargura() / 2, (gJanela.getAltura() / 2-200));
		txt[1].desenhar(gJanela.getLargura() / 2, (gJanela.getAltura() / 2));


		uniTerminarFrame();

	}*/
	novoJogador == true;
	load();
}

void Jogo::load()
{
	while (!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{

		uniIniciarFrame();



		fundo[fLoad].desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

		botao[bvoltar].atualizar();
		botao[bvoltar].desenhar();
		//USER 1
		botao[bSaveUser].atualizar();
		botao[bSaveUser].desenhar();
		txtUser[0].desenhar(gJanela.getLargura() / 2, (gJanela.getAltura() / 2) - 100);
		if (botao[bSaveUser].estaClicado() && novoJogador == true)
		{
			user[0].setName(nomeUserNovo);
			user[0].setSenha(senhaNova);
			novoJogador = false;
			Jogar();
		}
		else if (botao[bSaveUser].estaClicado() && novoJogador == false) 
		{
			string senhas;
			cout << "DIGITE A SENHA " << endl;
			cin >> senhas;
			if (user[0].getSenha()->getSenha() == senhas) 
			{
				Jogar();
			}
			else 
			{
				cout << "   SENHA INVALIDA  " << endl;
			}
		}
		//USER 2
		botao[bSaveUser2].atualizar();
		botao[bSaveUser2].desenhar();
		txtUser[1].desenhar(gJanela.getLargura() / 2, (gJanela.getAltura() / 2) - 200);
		if (botao[bSaveUser2].estaClicado() && novoJogador == true)
		{
			user[1].setName(nomeUserNovo);
			user[1].setSenha(senhaNova);
			novoJogador = false;
			Jogar();
		}
		else if (botao[bSaveUser2].estaClicado() && novoJogador == false)
		{
			string senhas;
			cout << "DIGITE A SENHA " << endl;
			cin >> senhas;
			if (user[1].getSenha()->getSenha() == senhas)
			{
				Jogar();
			}
			else
			{
				cout << "   SENHA INVALIDA  " << endl;
			}
		}
		//USER 3
		botao[bSaveUser3].atualizar();
		botao[bSaveUser3].desenhar();
		txtUser[2].desenhar(gJanela.getLargura() / 2, (gJanela.getAltura() / 2) + 100);
		if (botao[bSaveUser3].estaClicado() && novoJogador == true)
		{
			user[2].setName(nomeUserNovo);
			user[2].setSenha(senhaNova);
			novoJogador = false;
			Jogar();
		}
		else if (botao[bSaveUser3].estaClicado() && novoJogador == false)
		{
			string senhas;
			cout << "DIGITE A SENHA " << endl;
			cin >> senhas;
			if (user[2].getSenha()->getSenha() == senhas)
			{
				Jogar();
			}
			else
			{
				cout << "   SENHA INVALIDA  " << endl;
			}
		}

		
		/// //////////////////////////////////////////
		

		if (botao[bvoltar].estaClicado())
		{
			som[somBotao].tocar();
			executar();
		}

		uniTerminarFrame();

	}
}

void Jogo::records()
{
}

