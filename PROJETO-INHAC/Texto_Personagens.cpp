#include "Texto_Personagens.h"

Texto_Personagens::Texto_Personagens()
{
	indiceFala = 0;
}

Texto_Personagens::~Texto_Personagens()
{
}

void Texto_Personagens::desenharBaseTexto()
{
	//alt e seta
	base_Texto.desenhar(gJanela.getLargura() / 2, 600);
	fala[indiceFala].desenhar(gJanela.getLargura() / 2, 500);
}

void Texto_Personagens::setSpriteTexto()
{
	base_Texto.setSpriteSheet("texto");
	
	for (int i = 0; i < 20; i++)
	{
		fala[i].setFonte("TextoFont");
		fala[i].setAlinhamento(TEXTO_ALINHADO_A_ESQUERDA);
		fala[i].setLarguraMaxima(400);
		//fala[i].setEscala(0.5, 0.5);
		fala[i].setCor(0, 0, 0);
		fala[i].setEspacamentoLinhas(1.5);
	}
		
}

void Texto_Personagens::carregarFalas()
{
	arqFalas.open("falas.txt", ios::in);
	string linha;
	int i = 0;

	if (!arqFalas.is_open()) {

		arqFalas.open("falas.txt", ios::in);
	}
	else
	{
		while (getline(arqFalas, linha)) 
		{
			fala[i].setString(linha);
			i++;
		}
	}
	arqFalas.close();
}

void Texto_Personagens::setTexto(int i)
{
	this->indiceFala = i;
}

