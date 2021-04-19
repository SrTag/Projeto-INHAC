#pragma once
#include "libUnicornio.h"
#include "Cartas.h"
#include "Secreto.h"
#include "Saude.h"
#include "Dinheiro.h"
#include "Amor.h"
#include <fstream>

enum personagem_carta { Stive, Vovo, Marcos, Wanda, Kyle, Pop, CoronaV, Nancy, Tom, Phill, Sasha, Ngm, Chefe, Empregado, Secretaria, Kevin, Informante, Keven, AgtA, AgtB };
class MontaCartas
{
private:

	//atributos de arquivos
	
	ifstream arq_StatusSIM_Cartas;
	ifstream arq_StatusNAO_Cartas;
	
	
	// esse comando que vai ser utilizado no jogo pro SIM
	/*carta->setSim(int indicecarta) {
		carta[indicecarta].setEscolhaSim
	}
	*/

	int indice_carta;

	// sao os ponteiros dos status, que irei manipular as sprites,  
	//para que no jogo possa tanto subir a barra de energia quanto descer
	Cartas* carta;
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
	void attStatus(int qualCarta, bool sim_ou_nao);


	
};

