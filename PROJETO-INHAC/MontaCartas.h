#pragma once
#include "libUnicornio.h"
#include "Cartas.h"
#include "Secreto.h"
#include "Saude.h"
#include "Dinheiro.h"
#include "Amor.h"

enum personagem_Carta { Stive, Vovo, Marcos, Wanda, Kyle, Pop, CoronaV, Nancy, Tom, Phill, Sasha, Ngm, Chefe, Empregado, Secretaria, Kevin, Informante, Keven, AgtA, AgtB };
class MontaCartas
{
private:

	//indice para controlar qual imagem estiver sendo utilizada
	int indice_imagemCarta;

	//sprites oficiais, que irao manipular as imagens
	Sprite personagem_carta;
	Sprite sprite_Amor;
	Sprite imagem_BaseTxt;
	Sprite sprite_Saude;
	Sprite sprite_Secreto;
	Sprite sprite_Dinheiro;

	//imagens dos personagens
	Cartas* cartas;

	// sao os ponteiros dos status, que irei manipular as sprites,       xxx talvez n use xxxxx
	//para que no jogo possa tanto subir a barra de energia quanto descer

	Amor *statusAmor;
	Saude* statusSaude;
	Dinheiro* statusDinheiro;
	Secreto* statusSecreto;
	
public:

	MontaCartas();
	~MontaCartas();

	void carregarSprites();
	void setCartas();


	
};

