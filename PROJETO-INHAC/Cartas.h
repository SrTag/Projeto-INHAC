#pragma once
#include "libUnicornio.h"

enum attStatus{amor,saude,secreto,dinheiro};
class Cartas
{
private:

	//atributo do arquivo
	ofstream instanciador_Status;

	//atributos base para montar a carta como imagem, texto, etc
	Sprite cartaAtual,base_Texto;
	Texto texto;

	//status que cada carta tem, que ira retornar dependendo da escolha
	int attStatus_SIM[4];
	int attStatus_NAO[4];

	

public:

	//construtor e destrutor
	Cartas();
	~Cartas() {};

	// na classe montar cartas, usarei esse metodo, para carregar os status q as 20 cartas mechem
	///////////////////////////////////////////////////////////
	void carregarArqStatusSim(int Amor, int Saude, int Secreto, int Dinheiro);
	void carregarArqStatusNao(int Amor, int Saude, int Secreto, int Dinheiro);
	///////////////////////////////////////////////////////////

	//Definir personagem, sera um metodo usado na classe Montacartas e No Jogo, para manipular qual carta estarei utilizando
	/////////////////////////////////////////////
	void definirPersonagem(string cartaPersonagem);
	/////////////////////////////////////////////

	//metodo de desenhar, e para desenhar na tela a animação da carta
	//////////////////////////////
	void desenharCarta();
	/// ///////////////////////
	
	// Os getAtt_Sim ou Get_att_NAO, servem para a carta, retornar seus atributos, para manipular os status, como amor,dinheiro,saude e secreto;
	////////////////////////////
	int getAtt_SIM_Amor();
	int getAtt_SIM_Dinheiro();
	int getAtt_SIM_Saude();
	int getAtt_SIM_Secreto();

	int getAtt_NAO_Amor();
	int getAtt_NAO_Dinheiro();
	int getAtt_NAO_Saude();
	int getAtt_NAO_Secreto();
	////////////////////////////


};