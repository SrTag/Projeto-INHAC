#include "Secreto.h"

Secreto::Secreto()
{
	//instancia ja o indice em 5, para quando o jogo começar a sprite começar na metade
	this->indiceSecreto = 5;

}


void Secreto::setStatusSecreto()
{
	sprite_Secreto.setSpriteSheet("statusSecret" + to_string(5));
}

void Secreto::desenharSpriteSecreto()
{
	
	sprite_Secreto.desenhar(400, 50);
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
		
	}
	else 
	{

		if (att >= 0 && att < 10)
		{
			indiceSecreto += att;
			setNovaImagem(indiceSecreto);
		}
		else if (att < 0) {

			indiceSecreto += att;
			setNovaImagem(indiceSecreto);
		}
	}
}

int Secreto::gameOverSecreto()
{
	if (indiceSecreto <= 0 || indiceSecreto >= 10)
	{

		game = true;
		return game;
	}
	else {
		game = false;
		return game;
	}
}

void Secreto::setNovaImagem(int i)
{
	sprite_Secreto.setSpriteSheet("statusSecret" + to_string(this->indiceSecreto));
}

int Secreto::getSecreto()
{
	return indiceSecreto;
}
