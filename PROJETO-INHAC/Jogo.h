#pragma once
#include "libUnicornio.h"
#include "MontaCartas.h"
#include "Usuario.h"
#include<iostream>

enum Botoes{bNao,bSim , bJogar , bCreditos, bvoltar, bLoad, bNewGame, bSair, bRecord, bSaveUser, bSaveUser2, bSaveUser3 };
enum Fundo{fMenu, fJogo, fcel,fLoad};
enum som{somMenu, somJogo, somBotao};
using namespace std;

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
	//metodos novos Versao 2.0
	void newGame();
	void load();
	void records();
	void user1();
	void user2();
	void user3();
private:
	string nomeUserNovo,senhaNova;
	int idUser;
	Usuario* user;
	bool novoJogador;
	Texto creditosText, txtUser[2], txt[1], txtRecord[2];
	Som som[3];
	int personagem;
	MontaCartas* cartas;
	BotaoSprite botao[15];
	Sprite fundo[8];
	Sprite vitoria;
};

