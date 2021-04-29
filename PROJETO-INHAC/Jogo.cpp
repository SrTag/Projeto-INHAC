#include "Jogo.h"

Jogo::Jogo()
{
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
	botao[bJogar].setSpriteSheet("botaoJogar");
	botao[bSim].setSpriteSheet("BotaoSIM");
	botao[bNao].setSpriteSheet("BotaoNAO");
	botao[bCreditos].setSpriteSheet("botaoCreditos");
	som[somBotao].setAudio("somBotao");
	som[somJogo].setAudio("somGame");

	///game over
	fundo[fcel].setSpriteSheet("fundoOver");
	fundo[fcel].setEscala(2, 2);

	fundo[fMenu].setSpriteSheet("fundoMenu");
	fundo[fMenu].setEscala(1, 1);

	botao[bJogar].setPos(100, (gJanela.getAltura() / 2) - 100);
	botao[bCreditos].setPos(100, gJanela.getAltura() / 2);
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
		
		botao[bJogar].atualizar();
		botao[bJogar].desenhar();

		botao[bCreditos].atualizar();
		botao[bCreditos].desenhar();

		if (botao[bCreditos].estaClicado()){}

		if (botao[bJogar].estaClicado())
		{
			som[somBotao].tocar();
			Jogar();
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

