#include "Amor.h"

Amor::Amor()
{
	//instancia ja o indice em 5, para quando o jogo começar a sprite começar na metade
	this->indiceAmor = 5;
	
	

}

int Amor::getIndiceAmor()
{
	return indiceAmor;
}

void Amor::setStatusAmor()
{
	sprite_Amor.setSpriteSheet("statusAmor" + to_string(this->indiceAmor));
	
	
}

void Amor::desenharSpriteAmor()
{
	sprite_Amor.desenhar(200,50);
}

void Amor::definePosX_and_PosY(int x, int y)
{
	this->pos_X = x;
	this->pos_Y = y;
}

void Amor::atualizaStatusAmor(int att)
{
	

	if ((indiceAmor - att) <= 0 || (indiceAmor + att) >= 10) {
		
	}
	else {
		if (att >= 0 && att < 10)
		{
			indiceAmor += att;
			setNovaImagem(indiceAmor);
			
		}
		else if (att < 0) {

			indiceAmor += att;
			setNovaImagem(indiceAmor);
		}
	}
}

int Amor::gameOverAmor()
{
	if (indiceAmor <= 0 || indiceAmor >= 10) 
	{

		game = true;
		return game;
	}
	else {
		game = false;
		return game;
	}
	
}

void Amor::setNovaImagem(int i)
{
	sprite_Amor.setSpriteSheet("statusAmor" + to_string(i));
}



