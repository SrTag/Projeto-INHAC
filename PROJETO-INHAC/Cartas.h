#pragma once
#include "libUnicornio.h"

enum attStatus{amor,saude,secreto,dinheiro};
class Cartas
{
private:
	Sprite cartaAtual,base_Texto;
	Texto texto;
	int attStatus_SIM[4];
	int attStatus_NAO[4];
	ofstream instanciador_Status;

public:
	Cartas();
	~Cartas() {};
	// na classe montar cartas, usarei esse metodo, para carregar os status q as 20 cartas mechem
	void carregarArqStatusSim(int Amor, int Saude, int Secreto, int Dinheiro);
	void carregarArqStatusNao(int Amor, int Saude, int Secreto, int Dinheiro);
	// na classe do jogo, se escolher sim, ira chamar esse metodo, que ira carregar o arquivo Status, para no monta cartas baixar e manipular
	void setEscolhaSim();
	void setEscolhaNao();
	void definirPersonagem(string cartaPersonagem);
	void desenharCarta();

	int getAtt_SIM_Amor();
	int getAtt_SIM_Dinheiro();
	int getAtt_SIM_Saude();
	int getAtt_SIM_Secreto();

	int getAtt_NAO_Amor();
	int getAtt_NAO_Dinheiro();
	int getAtt_NAO_Saude();
	int getAtt_NAO_Secreto();



};