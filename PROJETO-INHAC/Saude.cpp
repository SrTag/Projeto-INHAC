#include "Saude.h"

Saude::Saude()
{
	//instancia ja o indice em 5, para quando o jogo começar a sprite começar na metade
	this->indiceSaude = 5;

	carregarStatusSaude();
}

void Saude::carregarStatusSaude()
{
	gRecursos.carregarSpriteSheet("statusSaude", "assets/SpritesSheet/saude.png", 1, 11);
}

void Saude::setStatusSaude()
{
	sprite_Saude.setSpriteSheet("statusSaude");
}

void Saude::desenharSpriteSaude()
{
	sprite_Saude.setAnimacao(indiceSaude);
	sprite_Saude.desenhar(pos_X, pos_Y);
}

void Saude::definePosX_and_PosY(int x, int y)
{
	this->pos_X = x;
	this->pos_Y = y;
}

void Saude::atualizaStatusSaude(int att)
{
	if ((indiceSaude - att) <= 0 || (indiceSaude + att) >= 10) {
		gameOverSaude();
	}
	else {
		if (att >= 0 && att < 10)
		{
			indiceSaude += att;
		}
		else if (att < 0) {

			indiceSaude -= att;
		}
	}
}

void Saude::gameOverSaude()
{
}
