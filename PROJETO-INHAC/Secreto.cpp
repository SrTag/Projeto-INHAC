#include "Secreto.h"

Secreto::Secreto()
{
	carregarSpriteStatus();
}

void Secreto::carregarSpriteStatus()
{
	gRecursos.carregarSpriteSheet("statusSecret", "assets/SpritesSheet/segredo.png", 1, 11);
}
