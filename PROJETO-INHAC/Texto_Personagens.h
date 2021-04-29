#pragma once
#include "libUnicornio.h"
#include <fstream>

class Texto_Personagens
{
private:
	Sprite base_Texto;
	Texto fala[20];
	ifstream arqFalas;
	int indiceFala;

public:

	Texto_Personagens();
	~Texto_Personagens();

	void desenharBaseTexto();
	void setSpriteTexto();
	void carregarFalas();
	void setTexto(int i);
	
	

};

