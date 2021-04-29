#include "Saude.h"

Saude::Saude()
{
	//instancia ja o indice em 5, para quando o jogo começar a sprite começar na metade
	this->indiceSaude = 5;

	
}

void Saude::setStatusSaude()
{
	sprite_Saude.setSpriteSheet("statusSaude" + to_string(this->indiceSaude));
}

void Saude::desenharSpriteSaude()
{
	
	sprite_Saude.desenhar(300, 50);
}

void Saude::definePosX_and_PosY(int x, int y)
{
	this->pos_X = x;
	this->pos_Y = y;
}

void Saude::atualizaStatusSaude(int att)
{
	if ((indiceSaude - att) <= 0 || (indiceSaude + att) >= 10) {
		
	}
	else {
		if (att >= 0 && att < 10)
		{
			indiceSaude += att;
			setNovaImagem(indiceSaude);
		}
		else if (att < 0) {

			indiceSaude += att;
			setNovaImagem(indiceSaude);
		}
	}
}

int Saude::gameOverSaude()
{
	if (indiceSaude <= 0 || indiceSaude >= 10)
	{

		game = true;
		return game;
	}
	else {
		game = false;
		return game;
	}
}

void Saude::setNovaImagem(int i)
{
	sprite_Saude.setSpriteSheet("statusSaude" + to_string(i));
}

int Saude::getSaude()
{
	return indiceSaude;
}
