#include "Saude.h"

Saude::Saude()
{
	//instancia ja o indice em 5, para quando o jogo come�ar a sprite come�ar na metade
	indice = 5;

	
}

void Saude::setNovaImagem(int i)
{
	sprite_base.setSpriteSheet("statusSaude" + to_string(i));
}

void Saude::setStatus()
{
	sprite_base.setSpriteSheet("statusSaude" + to_string(indice));
}
