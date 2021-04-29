#include "Dinheiro.h"

Dinheiro::Dinheiro()
{
	//instancia ja o indice em 5, para quando o jogo começar a sprite começar na metade
	this->indiceDinheiro = 5;

	
}

void Dinheiro::setStatusDinheiro()
{
	sprite_Dinheiro.setSpriteSheet("statusDinheiro" + to_string(5));
}

void Dinheiro::desenharSpriteDinheiro()
{
	
	sprite_Dinheiro.desenhar(500, 50);
}

void Dinheiro::definePosX_and_PosY(int x, int y)
{
	this->pos_X = x;
	this->pos_Y = y;
}

void Dinheiro::atualizaStatusDinheiro(int att)
{
	if ((indiceDinheiro - att) <= 0 || (indiceDinheiro + att) >= 10) {
		
	}
	else {
		if (att >= 0 && att < 10)
		{
			indiceDinheiro += att;
			setNovaImagem(indiceDinheiro);
		}
		else if (att < 0) {

			indiceDinheiro += att;
			setNovaImagem(indiceDinheiro);
		}
	}
}
void Dinheiro::setNovaImagem(int i)
{
	sprite_Dinheiro.setSpriteSheet("statusDinheiro" + to_string(i));
}

int Dinheiro::getDinheiro()
{
	return indiceDinheiro;
}

int Dinheiro::gameOverDinheiro()
{
	if (indiceDinheiro <= 0 || indiceDinheiro >= 10)
	{

		game = true;
		return game;
	}
	else {
		game = false;
		return game;
	}
}
