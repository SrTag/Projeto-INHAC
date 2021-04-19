#pragma once

#include "libUnicornio.h"

class Amor
{
private:
	Sprite sprite_Amor;
	int pos_X, pos_Y;
	Vetor2D pos;
	int indiceAmor;
public:
	Amor();
	~Amor();

	void setStatusAmor();
	void carregarStatusAmor();
	void desenharSpriteAmor();
	void definePosX_and_PosY(int x, int y);
	void atualizaStatusAmor(int att);
	void gameOverAmor();

};

