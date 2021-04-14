#include "Secreto.h"

Secreto::Secreto()
{
	//instancia ja o indice em 5, para quando o jogo começar a sprite começar na metade
	this->indiceSecreto = 5;

	carregarSpriteStatus();
}

void Secreto::carregarSpriteStatus()
{
	gRecursos.carregarSpriteSheet("statusSecret", "assets/SpritesSheet/segredo.png", 1, 11);
}

void Secreto::setStatusSecreto()
{
	sprite_Secreto.setSpriteSheet("statusSecret");
}

void Secreto::desenharSpriteSecreto()
{
	sprite_Secreto.setAnimacao(indiceSecreto);
	sprite_Secreto.desenhar(pos_X, pos_Y);
}

void Secreto::definePosX_and_PosY(int x, int y)
{
	this->pos_X = x;
	this->pos_Y = y;
}

void Secreto::atualizaStatusSecreto(int att)
{
	if ((indiceSecreto - att) <= 0 || (indiceSecreto + att) >= 10) 
	{
		gameOverSecreto();
	}
	else 
	{

		if (att >= 0 && att < 10)
		{
			indiceSecreto += att;
		}
		else if (att < 0) {

			indiceSecreto -= att;
		}
	}
}

void Secreto::gameOverSecreto()
{
}
