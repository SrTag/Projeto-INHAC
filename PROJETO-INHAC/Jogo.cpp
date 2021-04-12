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
	gRecursos.carregarSpriteSheet("Botao", "assets/SpritesSheet/VoltarMini.png", 3, 1);
	gRecursos.carregarSpriteSheet("status0", "assets/SpritesSheet/core.png", 1, 11);
	gRecursos.carregarSpriteSheet("status1", "assets/SpritesSheet/TrabalhoEnergy.png", 1, 11);
	gRecursos.carregarSpriteSheet("status2", "assets/SpritesSheet/saude.png", 1, 11);
	gRecursos.carregarSpriteSheet("status3", "assets/SpritesSheet/Estudo.png", 1, 11);

	
	
	


	
	for(int i=0; i<4;i++)
	{
		sprite[i].setSpriteSheet("status" + to_string(i));
	}
	botao[0].setSpriteSheet("Botao");
	botao[1].setSpriteSheet("Botao");

	
	botao[0].setPos(50, gJanela.getAltura()/ 2);
	botao[1].setPos(750, gJanela.getAltura()/ 2);

	cartas = new Cartas[2];
	cartas[1].setSpriteMae();


	aux = 0;
	
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
		
		cartas[aux].desenhar();

		sprite[0].desenhar(200, 50);
		sprite[1].desenhar(300, 50);
		sprite[2].desenhar(400, 50);
		sprite[3].desenhar(500, 50);

		botao[0].atualizar();
		botao[0].desenhar();

		botao[1].atualizar();
		botao[1].desenhar();

		if (botao[bNao].estaClicado()) {
			aux--;
		}
		if (botao[bSim].estaClicado()) {
			status[cartas[aux].getEscolhaSimStatus()].alterarValor(cartas[aux].getEscolhaSimValor());
			//status[x].alterarValor(y);
		
			//Dado Carta -> Metoda carta -> Jogo -> Metodo Status -> Dado status
		
			aux++;
		}

		uniTerminarFrame();
	}
}