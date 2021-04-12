#pragma once
#include "libUnicornio.h"

class Dinheiro
{
private:
	Sprite sprite_Dinheiro;
	int indiceDinheiro;
	int pos_X, pos_Y;

public:
	Dinheiro();
	~Dinheiro();

	void carregarStatusDinheiro();
	void setStatusDinheiro();
	void desenharSpriteDinheiro();
	void definePosX_and_PosY(int x, int y);
	void atualizaStatusDinheiro(int att);
	void gameOverDinheiro();
};

