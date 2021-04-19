#include "Dinheiro.h"

Dinheiro::Dinheiro()
{
	//instancia ja o indice em 5, para quando o jogo começar a sprite começar na metade
	this->indiceDinheiro = 5;

	
}

void Dinheiro::carregarStatusDinheiro()
{
	gRecursos.carregarSpriteSheet("statusDinheiro", "assets/SpritesSheet/dinheiro.png", 1, 11);
}

void Dinheiro::setStatusDinheiro()
{
	sprite_Dinheiro.setSpriteSheet("statusDinheiro");
}

void Dinheiro::desenharSpriteDinheiro()
{
	sprite_Dinheiro.setAnimacao(indiceDinheiro);
	sprite_Dinheiro.desenhar(pos_X, pos_Y);
}

void Dinheiro::definePosX_and_PosY(int x, int y)
{
	this->pos_X = x;
	this->pos_Y = y;
}

void Dinheiro::atualizaStatusDinheiro(int att)
{
	if ((indiceDinheiro - att) <= 0 || (indiceDinheiro + att) >= 10) {
		gameOverDinheiro();
	}
	else {
		if (att >= 0 && att < 10)
		{
			indiceDinheiro += att;
		}
		else if (att < 0) {

			indiceDinheiro -= att;
		}
	}
}

void Dinheiro::gameOverDinheiro()
{
}
