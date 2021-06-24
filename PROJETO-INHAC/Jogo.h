#pragma once
#include "libUnicornio.h"
#include "MontaCartas.h"
#include "Usuario.h"
#include<iostream>
#include <fstream>
#include "Fila.h"

enum Botoes{bNao,bSim , bJogar , bCreditos, bvoltar, bLoad, bNewGame, bSair, bRecord, bSaveUser, bSaveUser2, bSaveUser3,bConfirm,RED,BLUE,ROXO };
enum Fundo{fMenu, fJogo, fcel,fLoad};
enum som{somMenu, somJogo, somBotao};
enum botaoJogador{p1,p2,p3};

using namespace std;

class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();
	void executar();
	void Jogar(int qualUser);
	void gameOver();
	void Vitoria();
	void creditos();
	//metodos novos Versao 2.0
	void attStatus(int qualCarta, bool sim_ou_nao);
	void senhaNegada();
	void confirmarUSER(int qualUser);
	void salvar();
	void baixarSave();
	void ConfirmarChamp(int qualChamp);
	void escolhaChamp();
	void escolherSenha(int qualPlayer);
	void confirmarSenha(string senha, int id);
	void verificarUser(int IDs);
	void newGame();
	void load();
	void records();
private:
	//v2.0
	Fila<Sprite>* fila;
	BotaoSprite botaoJogador[3];
	ofstream saveUS;
	ifstream USsave;
	Sprite image,imgFila[3];
	Sprite fotoPlayer[4];
	Amor* statusAmor;
	Saude* statusSaude;
	Dinheiro* statusDinheiro;
	Secreto* statusSecreto;
	/// //////////////
	
	string nomeUserNovo,senhaNova;
	int idUser;
	Usuario* user;
	bool novoJogador;
	Texto creditosText, txtUser[2], txt[15], txtRecord[2];
	Som som[3];
	int personagem;
	MontaCartas* cartas;
	BotaoSprite botao[20];
	Sprite fundo[8];
	Sprite vitoria;
};

