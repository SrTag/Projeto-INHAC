#pragma once
#include "libUnicornio.h"

class StatusBase
{
protected:
	
	Sprite sprite_base;
	
	Vetor2D pos;
	int indice;
	bool game;
public:
	StatusBase();
	~StatusBase();

	int getIndiceStatus();
	virtual void setStatus()=0;
	void desenharSprite();
	void definePosX_and_PosY(int x, int y);
	void atualizaStatus(int att);
	int gameOver();
	virtual void setNovaImagem(int i)= 0;
};

