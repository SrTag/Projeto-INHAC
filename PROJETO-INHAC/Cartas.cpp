#include "Cartas.h"

Cartas::Cartas()
{
	carregarImagens();
	
}

void Cartas::carregarImagens()
{
	gRecursos.carregarSpriteSheet("spriteCartas", "assets/SpritesSheet/cartasPersonagens.png", 1, 20);
	gRecursos.carregarSpriteSheet("spriteBaseTexto", "assets/SpritesSheet/BaseChat.png", 1, 1);
}


