#pragma once
#include "libUnicornio.h"
#include "Cartas.h"
#include "Secreto.h"
#include "Saude.h"
#include "Dinheiro.h"
#include "Amor.h"

enum personagem_carta { Stive, Vovo, Marcos, Wanda, Kyle, Pop, CoronaV, Nancy, Tom, Phill, Sasha, Ngm, Chefe, Empregado, Secretaria, Kevin, Informante, Keven, AgtA, AgtB };
class MontaCartas
{
private:

	//indice para controlar qual imagem estiver sendo utilizada
	
	ifstream arq_StatusSIM_Cartas;
	ifstream arq_StatusNAO_Cartas;
	ifstream baixarDados_Att_Status;
	//imagens dos personagens
	//nao esta aceitando ceta
	Cartas* carta;
	
	// esse comando que vai ser utilizado no jogo pro SIM
	/*carta->setSim(int indicecarta) {
		carta[indicecarta].setEscolhaSim
	}
	*/

	int indice_carta = 0;

	// sao os ponteiros dos status, que irei manipular as sprites,  
	//para que no jogo possa tanto subir a barra de energia quanto descer

	Amor *statusAmor;
	Saude* statusSaude;
	Dinheiro* statusDinheiro;
	Secreto* statusSecreto;
	
public:

	MontaCartas();
	~MontaCartas();

	void carregarSprites();
	void setSpriteShetStatus();
	void carregarStatusCartas_Arq();
	void setPosX_PosY();
	void MontandoCartas();
	void attStatus();


	
};

