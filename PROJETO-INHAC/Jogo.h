#pragma once
#include "libUnicornio.h"
#include "MontaCartas.h"

enum Botoes{bNao,bSim , bJogar , bCreditos, bvoltar};
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
	void Vitoria();
	void creditos();
private:

	Texto creditosText;
	Som som[3];
	int personagem;
	MontaCartas* cartas;
	BotaoSprite botao[5];
	Sprite fundo[3];
	Sprite vitoria;
};

