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

	gRecursos.carregarSpriteSheet("BotaoSIM", "assets/SpritesSheet/botaoSim.png", 3, 1);
	gRecursos.carregarSpriteSheet("BotaoNAO", "assets/SpritesSheet/botaoNao.png", 3, 1);

	botao[bSim].setSpriteSheet("BotaoSIM");
	botao[bNao].setSpriteSheet("BotaoNao");


	botao[bSim].setPos(50, gJanela.getAltura()/ 2);
	botao[bNao].setPos(750, gJanela.getAltura()/ 2);
	
	cartas = new MontaCartas();

	cartas->carregarStatusCartas_Arq();
	cartas->carregarSprites();
	cartas->setSpriteShetStatus();
	cartas->setPosX_PosY();
	
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
		
		cartas->MontandoCartas();
		
		botao[bSim].atualizar();
		botao[bSim].desenhar();

		botao[bNao].atualizar();
		botao[bNao].desenhar();
		
		
		if (botao[bNao].estaClicado()) {
			
			cartas->attStatus(personagem, false);
		}
		if (botao[bSim].estaClicado()) {
			cartas->attStatus(personagem, true);
		}

		// passa para o proximo personagem ou carta
		personagem++;

		uniTerminarFrame();
	}
}