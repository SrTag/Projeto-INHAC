#include "Amor.h"

Amor::Amor()
{
	carregarStatusAmor();
}

void Amor::setStatusAmor()
{
	sprite_Amor.setSpriteSheet("statusAmor");
}

void Amor::carregarStatusAmor()
{
	gRecursos.carregarSpriteSheet("statusAmor", "assets/SpritesSheet/coracao.png", 1, 11);
}

void Amor::desenharSpriteAmor()
{
	sprite_Amor.setAnimacao(indiceAmor);
	sprite_Amor.desenhar(pos_X,pos_Y);
}

void Amor::definePosX_and_PosY(int x, int y)
{
	this->pos_X = x;
	this->pos_Y = y;
}

void Amor::atualizaStatusAmor(int att)
{
	if ((indiceAmor - att) <= 0 || (indiceAmor + att) >= 10) {
		gameOverAmor();
	}
	else {
		if (att > 0 && att < 10)
		{
			indiceAmor++;
		}
		else if (att < 0) {

			if (indiceAmor > 0)
			{
				indiceAmor--;
			}
		}
	}
}
