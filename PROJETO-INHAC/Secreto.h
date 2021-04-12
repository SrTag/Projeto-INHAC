#pragma once
#include "libUnicornio.h"

class Secreto
{
private:

	Sprite sprite_Secreto;
	int indiceSecreto;
	int pos_X, pos_Y;

public:
	Secreto();
	~Secreto();
	void carregarSpriteStatus();
	void setStatusSecreto();
	void desenharSpriteSecreto();
	void definePosX_and_PosY(int x, int y);
	void atualizaStatusSecreto(int att);
	void gameOverSecreto();
};

