#pragma once
#include "libUnicornio.h"
#include "MontaCartas.h"

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

