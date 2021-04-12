#include "Saude.h"

Saude::Saude()
{
	carregarStatusSaude();
}

void Saude::carregarStatusSaude()
{
	gRecursos.carregarSpriteSheet("statusSaude", "assets/SpritesSheet/saude.png", 1, 11);
}
