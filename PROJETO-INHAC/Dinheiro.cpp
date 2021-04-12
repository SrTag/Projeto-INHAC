#include "Dinheiro.h"

Dinheiro::Dinheiro()
{
	carregarStatusDinheiro();
}

void Dinheiro::carregarStatusDinheiro()
{
	gRecursos.carregarSpriteSheet("statusDinheiro", "assets/SpritesSheet/dinheiro.png", 1, 11);
}
