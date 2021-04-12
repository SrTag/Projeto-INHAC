#pragma once
#include "libUnicornio.h"
#include "Cartas.h"

enum Botoes{bNao,bSim};

class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();

	void executar();
private:
	
	BotaoSprite botao[2];
	
};

