#pragma once
#include "libUnicornio.h"
#include "MontaCartas.h"

enum Botoes{bNao,bSim , bJogar , bCreditos};
enum Fundo{fMenu, fJogo, fcel};
enum som{somMenu, somJogo, somBotao};

class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();
	void executar();
	void Jogar();
	void gameOver();

private:

	Som som[3];
	int personagem;
	MontaCartas* cartas;
	BotaoSprite botao[4];
	Sprite fundo[3];
};

