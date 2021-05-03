#pragma once
#include "libUnicornio.h"
#include "StatusBase.h"

class Secreto:public StatusBase
{
private:

	Sprite sprite_Secreto;
	int indiceSecreto;
	int pos_X, pos_Y;
	bool game;
public:
	Secreto();
	~Secreto();

	void setNovaImagem(int i)override;
	virtual void setStatus()override;
};

