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
	//gRecursos.carregarSpriteSheet("Botao", "assets/SpritesSheet/VoltarMini.png", 3, 1);

	/*botao[0].setSpriteSheet("Botao");
	botao[1].setSpriteSheet("Botao");

	
	botao[0].setPos(50, gJanela.getAltura()/ 2);
	botao[1].setPos(750, gJanela.getAltura()/ 2);
	*/
	

	
}

void Jogo::finalizar()
{
	
		


	uniFinalizar();
}

void Jogo::executar()
{
	while(!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{
		uniIniciarFrame();
		

		botao[0].atualizar();
		botao[0].desenhar();

		botao[1].atualizar();
		botao[1].desenhar();

		
		if (botao[bNao].estaClicado()) {
			
			/*
			Cartas *carta[20]
			carta = new Carta[20]
			*/
		}
		if (botao[bSim].estaClicado()) {
		
		}

		uniTerminarFrame();
	}
}