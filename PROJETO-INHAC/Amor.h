#pragma once

#include "libUnicornio.h"

class Amor
{
private:
	Sprite sprite_Amor;
	int pos_X, pos_Y;
	Vetor2D pos;
	int indiceAmor;
	bool game;
public:
	Amor();
	~Amor();

	int getIndiceAmor();
	void setStatusAmor();
	void carregarStatusAmor();
	void desenharSpriteAmor();
	void definePosX_and_PosY(int x, int y);
	void atualizaStatusAmor(int att);
	int gameOverAmor();
	void setNovaImagem(int i);

};

