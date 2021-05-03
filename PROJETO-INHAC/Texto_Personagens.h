#pragma once
#include "libUnicornio.h"
#include <fstream>

class Texto_Personagens
{
private:

	// atributo do arq
	ifstream arqFalas;

	//atributos base, que um Texto precisa ter Sprite e Texto
	Sprite base_Texto;
	Texto fala[20];
	
	//como sao varios personagens com varias falas, precisa de um indice para controlar, qual deles vc quer q apareça
	int indiceFala;

public:

	//construtor e destrutor
	Texto_Personagens();
	~Texto_Personagens();

	//desenha o texto
	void desenharBaseTexto();
	///////////////////////

	//Setar a imagem de onde o texto sera colocado
	void setSpriteTexto();
	////////////////////
	
	//metodo para manipular o arquivo
	void carregarFalas();
	//////////////////////////
	
	//metodo para manipular o Indice de qual texto usar
	void setTexto(int i);
	////////////////////////
	

};

