#include "Amor.h"

Amor::Amor()
{
	//instancia ja o indice em 5, para quando o jogo come�ar a sprite come�ar na metade
	indice = 5;
	
}

void Amor::setNovaImagem(int i)
{
	sprite_base.setSpriteSheet("statusAmor" + to_string(i));
}

void Amor::setStatus()
{
	sprite_base.setSpriteSheet("statusAmor" + to_string(indice));
}





