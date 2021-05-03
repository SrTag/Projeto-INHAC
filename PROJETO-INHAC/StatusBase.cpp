#include "StatusBase.h"

StatusBase::StatusBase()
{
	
}

StatusBase::~StatusBase()
{
}

int StatusBase::getIndiceStatus()
{
	return indice;
}

void StatusBase::desenharSprite()
{
	sprite_base.desenhar(pos.x, pos.y);
}

void StatusBase::definePosX_and_PosY(int x, int y)
{
	pos.x = x;
	pos.y = y;
}

void StatusBase::atualizaStatus(int att)
{
	if ((indice - att) <= 0 || (indice + att) >= 10) {

	}
	else {
		if (att >= 0 && att < 10)
		{
			indice += att;
			setNovaImagem(indice);

		}
		else if (att < 0) {

			indice += att;
			setNovaImagem(indice);
		}
	}
}

int StatusBase::gameOver()
{
	if (indice <= 0 || indice >= 10)
	{

		game = true;
		return game;
	}
	else {
		game = false;
		return game;
	}

}

void StatusBase::setNovaImagem(int i)
{
	sprite_base.setSpriteSheet("statusAmor" + to_string(i));
}