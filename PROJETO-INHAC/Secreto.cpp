#include "Secreto.h"

Secreto::Secreto()
{
	//instancia ja o indice em 5, para quando o jogo come�ar a sprite come�ar na metade
	indice = 5;

}


void Secreto::setNovaImagem(int i)
{
	sprite_base.setSpriteSheet("statusSecret" + to_string(i));
}

void Secreto::setStatus()
{
	sprite_base.setSpriteSheet("statusSecret" + to_string(indice));
}
