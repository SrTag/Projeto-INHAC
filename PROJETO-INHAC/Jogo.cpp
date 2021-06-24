#include "Jogo.h"

Jogo::Jogo()
{
	idUser = 0;
	novoJogador = false;
	user = new Usuario[4];
	nomeUserNovo = "";
	senhaNova = "";
	fila = new Fila<Sprite>();
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
	botao[bConfirm].setSpriteSheet("confirmar");

	botao[RED].setSpriteSheet("RED");
	botao[BLUE].setSpriteSheet("BLUE");
	botao[ROXO].setSpriteSheet("ROXO");

	imgFila[RED].setSpriteSheet("RED");
	imgFila[ROXO].setSpriteSheet("ROXO");
	imgFila[BLUE].setSpriteSheet("BLUE");
	//Pos dos botoes Versao 2.0
	botao[bLoad].setPos(100, (gJanela.getAltura() / 2) -100);
	botao[bNewGame].setPos(100, (gJanela.getAltura() / 2) -200);
	botao[bSair].setPos(700, (gJanela.getAltura() / 2) +250);
	botao[bRecord].setPos(100, (gJanela.getAltura() / 2) + 100);
	botao[bConfirm].setPos(700, (gJanela.getAltura() / 2) + 250);

	//POS botoes de load Versao 2.0
	botao[bSaveUser].setPos(gJanela.getLargura() / 2, (gJanela.getAltura() / 2) - 100);
	botao[bSaveUser2].setPos(gJanela.getLargura()/2, (gJanela.getAltura() / 2) - 200);
	botao[bSaveUser3].setPos(gJanela.getLargura()/2, (gJanela.getAltura() / 2) + 100);
	//V2.0 - botao de personagem
	botaoJogador[p1].setSpriteSheet("P11");
	botaoJogador[p1].setPos(100, (gJanela.getAltura() / 2) - 100);
	botaoJogador[p2].setSpriteSheet("P12");
	botaoJogador[p2].setPos(250, (gJanela.getAltura() / 2) - 100);
	botaoJogador[p3].setSpriteSheet("P13");
	botaoJogador[p3].setPos(400, (gJanela.getAltura() / 2) - 100);

	
	//sprite do fundo Versao 2.0
	fundo[fLoad].setSpriteSheet("fundoLoad");
	fundo[fLoad].setEscala(1, 1);

	// txt dos user Versao 2.0
	/*txt[0].setFonte("creditostxt");
	txt[0].setString("Ola Chefe, somos a OCCV !! qual seu nome para registro no sistema ?");
	txt[1].setFonte("creditostxt");
	txt[1].setString("Informe sua Senha");*/
	for (int i = 2; i < 10; i++) 
	{
		txt[i].setFonte("creditostxt");
	}
	// avisos


	/*for (int i = 0; i < 3; i++) 
	{
		txtUser[i].setFonte("creditostxt");
		txtUser[i].setCor(2, 2, 2);
		txtUser[i].setEspacamentoLinhas(1.5);
		txtUser[i].setEscala(0.5, 0.5);
		txtUser[i].setString(to_string(user[i].getID()) + " ->" + user[i].getNome());
	}*/
	
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
	botao[RED].setPos(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	botao[BLUE].setPos((gJanela.getLargura() / 2) - 200, gJanela.getAltura() / 2);
	botao[ROXO].setPos((gJanela.getLargura() / 2) + 200, gJanela.getAltura() / 2);

	baixarSave();
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
			novoJogador = true;
			som[somBotao].tocar();
			newGame();
		}
		if (botao[bLoad].estaClicado()) 
		{
			novoJogador = false;
			load();
		}

		uniTerminarFrame();
		
	}
}

void Jogo::Jogar(int qualUser)
{
	
	while (!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{
		uniIniciarFrame();
		//cartas->proxCarta(user[qualUser].nvAtual());
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
				user[qualUser].UP();
				salvar();
			}
			if (botao[bSim].estaClicado()) {
				som[somBotao].tocar();
				cartas->attStatus(personagem, true);
				cartas->proxCarta(personagem + 1);
				personagem++;
				user[qualUser].UP();
				salvar();
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

void Jogo::senhaNegada()
{
	while (!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{

		uniIniciarFrame();

		fundo[fMenu].desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

		botao[bvoltar].atualizar();
		botao[bvoltar].desenhar();

		if (botao[bvoltar].estaClicado())
		{
			som[somBotao].tocar();
			gEventos.sair;///////////////////////////////////////duvida
		}

		uniTerminarFrame();

	}
}

void Jogo::confirmarUSER(int qualUser)
{
	string acomulaSenha;
	botao[RED].setPos(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	botao[BLUE].setPos((gJanela.getLargura() / 2) - 200, gJanela.getAltura() / 2);
	botao[ROXO].setPos((gJanela.getLargura() / 2) + 200, gJanela.getAltura() / 2);
	while (!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{
		uniIniciarFrame();

		fundo[fMenu].desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

		botao[RED].atualizar();
		botao[RED].desenhar();
		if (botao[RED].estaClicado())
		{
			som[somBotao].tocar();
			acomulaSenha += 'V';

		}
		botao[BLUE].atualizar();
		botao[BLUE].desenhar();
		if (botao[BLUE].estaClicado())
		{
			som[somBotao].tocar();
			acomulaSenha += 'A';

		}
		botao[ROXO].atualizar();
		botao[ROXO].desenhar();
		if (botao[ROXO].estaClicado())
		{
			som[somBotao].tocar();
			acomulaSenha += 'R';

		}

		botao[bConfirm].atualizar();
		botao[bConfirm].desenhar();

		if (botao[bConfirm].estaClicado())
		{
			som[somBotao].tocar();
			if (user[qualUser].getSenha()->getSenha() == acomulaSenha) 
			{
				Jogar(qualUser);
			}
			else 
			{
				senhaNegada();
			}
		}
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

void Jogo::salvar()
{
	//salvando o usuario na memoria
	saveUS.open("arqUser.txt");
	if (!saveUS.is_open()) 
	{
		saveUS.open("arqUser.txt");
	}
	else 
	{
		for (int i = 0; i < 3; i++)
		{
			saveUS << user[i].getIdIMG()
				<< "\t"
				<< user[i].getID()
				<< "\t"
				<< user[i].getNome()
				<< "\t"
				<< user[i].getSenha()->getSenha()
				<< user[i].nvAtual()
				<< endl;
		}
	}
	
	
	saveUS.close();

}

void Jogo::baixarSave()
{
	int auxID,auxIMG, nv;
	string auxSenha, auxUser;
	USsave.open("arqUser.txt", ios::in);
	
	if (!USsave.is_open())
	{
		USsave.open("arqUser.txt");
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			USsave >> auxIMG;
			USsave >> auxID;
			USsave >> auxUser;
			USsave >> auxSenha;
			USsave >> nv;

			user[i].setIdIMG(auxIMG);
			user[i].setName(auxUser);
			user[i].setSenha(auxSenha);
			user[i].setID(auxID);
			user[i].setLVL(nv);
				
		}
	}


	USsave.close();

}

void Jogo::ConfirmarChamp(int qualChamp)
{
	botaoJogador[qualChamp].setPos(gJanela.getLargura() / 2, (gJanela.getAltura() / 2));
	txt[4].setString("ESSE E VOCE CHEFE ?\n\n");
	txt[4].setCor(0, 5, 5);
	txt[4].setEscala(500,100);
	while (!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{
		uniIniciarFrame();
		txt[4].desenhar(gJanela.getLargura() / 2, (gJanela.getAltura() / 2)+100);
		fundo[fMenu].desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

		botaoJogador[qualChamp].atualizar();
		botaoJogador[qualChamp].desenhar();
		botao[bConfirm].atualizar();
		botao[bConfirm].desenhar();

		if (botao[bConfirm].estaClicado()) 
		{
			escolherSenha(qualChamp);
		}

		uniTerminarFrame();
	}
}

void Jogo::escolhaChamp()
{
	while (!gTeclado.soltou[TECLA_ESC] && !gEventos.sair) 
	{
		uniIniciarFrame();

		fundo[fMenu].desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

		botaoJogador[p1].atualizar();
		botaoJogador[p1].desenhar();
		if (botaoJogador[p1].estaClicado())
		{
			user[3].setIdIMG(0);
			user[3].setName("MARCOS");
			ConfirmarChamp(p1);
		}
		botaoJogador[p2].atualizar();
		botaoJogador[p2].desenhar();
		if (botaoJogador[p2].estaClicado())
		{
			user[3].setIdIMG(1);
			user[3].setName("POP");
			ConfirmarChamp(p2);
		}
		botaoJogador[p3].atualizar();
		botaoJogador[p3].desenhar();
		if (botaoJogador[p3].estaClicado())
		{
			user[3].setIdIMG(2);
			user[3].setName("SASHA");
			ConfirmarChamp(p3);
		}

		uniTerminarFrame();
	}
	
}

void Jogo::escolherSenha(int qualPlayer)
{
	string acomulaSenha;
	botao[RED].setPos(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	botao[BLUE].setPos((gJanela.getLargura() / 2)-200, gJanela.getAltura() / 2);
	botao[ROXO].setPos((gJanela.getLargura() / 2)+200, gJanela.getAltura() / 2);
	while (!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{
		uniIniciarFrame();
		if (acomulaSenha.size() >= 10) 
		{
			confirmarSenha(acomulaSenha, qualPlayer);
		}
		fundo[fMenu].desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

		botao[RED].atualizar();
		botao[RED].desenhar();
		if (botao[RED].estaClicado()) 
		{
		
			acomulaSenha += 'V';
		
		}
		botao[BLUE].atualizar();
		botao[BLUE].desenhar();
		if (botao[BLUE].estaClicado())
		{
			acomulaSenha += 'A';
			
		}
		botao[ROXO].atualizar();
		botao[ROXO].desenhar();
		if (botao[ROXO].estaClicado())
		{
			acomulaSenha += 'R';
			
		}

		botao[bConfirm].atualizar();
		botao[bConfirm].desenhar();

		if (botao[bConfirm].estaClicado())
		{
			user[3].setSenha(acomulaSenha);
			confirmarSenha(acomulaSenha, qualPlayer);
		}

		uniTerminarFrame();
	}
}

void Jogo::confirmarSenha(string senha, int id)
{
	txt[7].setString(senha);
	while (!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{
		uniIniciarFrame();
		
		fundo[fMenu].desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
		txt[7].desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
		botao[bConfirm].atualizar();
		botao[bConfirm].desenhar();
		botao[bvoltar].atualizar();
		botao[bvoltar].desenhar();

		if (botao[bvoltar].estaClicado())
		{
			som[somBotao].tocar();
			senha.clear();
			escolherSenha(id);
		}
		if (botao[bConfirm].estaClicado())
		{
			user[3].setSenha(senha);

			load();

		}

		uniTerminarFrame();
	}
}

void Jogo::verificarUser(int IDs)
{
	
	string acomulaSenha;
	while (!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{
		uniIniciarFrame();

		fundo[fMenu].desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
		botao[RED].atualizar();
		botao[RED].desenhar();
		if (botao[RED].estaClicado())
		{

			acomulaSenha += 'V';

		}
		botao[BLUE].atualizar();
		botao[BLUE].desenhar();
		if (botao[BLUE].estaClicado())
		{
			acomulaSenha += 'A';

		}
		botao[ROXO].atualizar();
		botao[ROXO].desenhar();
		if (botao[ROXO].estaClicado())
		{
			acomulaSenha += 'R';

		}
		
		botao[bConfirm].atualizar();
		botao[bConfirm].desenhar();
		botao[bvoltar].atualizar();
		botao[bvoltar].desenhar();

		if (botao[bvoltar].estaClicado())
		{
			executar();
		}
		if (botao[bConfirm].estaClicado())
		{
			
			if (acomulaSenha == user[IDs].getSenha()->getSenha()) 
			{
				Jogar(IDs);
			}
			else
			{
				executar();
			}

		}

		uniTerminarFrame();
	}
}


void Jogo::newGame()
{

	escolhaChamp();

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
			user[0] = user[3];
			novoJogador = false;
			salvar();
			Jogar(p1);
		}
		if (botao[bSaveUser].estaClicado() && novoJogador == false) 
		{
			verificarUser(p1);
		}
		//USER 2
		botao[bSaveUser2].atualizar();
		botao[bSaveUser2].desenhar();
		txtUser[1].desenhar(gJanela.getLargura() / 2, (gJanela.getAltura() / 2) - 200);
		if (botao[bSaveUser2].estaClicado() && novoJogador == true)
		{
			user[1] = user[3];
			novoJogador = false;
			salvar();
			Jogar(p2);
		}
		else if (botao[bSaveUser2].estaClicado() && novoJogador == false)
		{
			verificarUser(p2);
		}
		//USER 3
		botao[bSaveUser3].atualizar();
		botao[bSaveUser3].desenhar();
		txtUser[2].desenhar(gJanela.getLargura() / 2, (gJanela.getAltura() / 2) + 100);
		if (botao[bSaveUser3].estaClicado() && novoJogador == true)
		{
			user[2] = user[3];
			novoJogador = false;
			salvar();
			Jogar(p3);
		}
		else if (botao[bSaveUser3].estaClicado() && novoJogador == false)
		{
			verificarUser(p3);
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

