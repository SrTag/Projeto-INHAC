#pragma once
#include "libUnicornio.h"

class Saude
{
private:

	Sprite sprite_Saude;
	int indiceSaude;
	int pos_X, pos_Y;

public:
	Saude();
	~Saude();

	void carregarStatusSaude();
	void setStatusSaude();
	void desenharSpriteSaude();
	void definePosX_and_PosY(int x, int y);
	void atualizaStatusSaude(int att);
	void gameOverSaude();

};

