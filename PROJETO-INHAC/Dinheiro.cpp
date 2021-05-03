#include "Dinheiro.h"

Dinheiro::Dinheiro()
{
	//instancia ja o indice em 5, para quando o jogo começar a sprite começar na metade
	indice = 5;

	
}

void Dinheiro::setNovaImagem(int i)
{
	sprite_base.setSpriteSheet("statusDinheiro" + to_string(i));
}

void Dinheiro::setStatus()
{
	sprite_base.setSpriteSheet("statusDinheiro" + to_string(indice));
}
