#include "Cartas.h"

Cartas::Cartas()
{
	carregarImagens();
}

void Cartas::carregarArqStatusSim(int Amor, int Saude, int Secreto, int Dinheiro)
{
	// setar os valores no atributo da classe
	this->attStatus_SIM[amor] = Amor;
	this->attStatus_SIM[saude] = Saude;
	this->attStatus_SIM[secreto] = Secreto;
	this->attStatus_SIM[dinheiro] = Dinheiro;
}

void Cartas::carregarArqStatusNao(int Amor, int Saude, int Secreto, int Dinheiro)
{
	this->attStatus_NAO[amor] = Amor;
	this->attStatus_NAO[saude] = Saude;
	this->attStatus_NAO[secreto] = Secreto;
	this->attStatus_NAO[dinheiro] = Dinheiro;
}

void Cartas::setEscolhaSim()
{
	//abre o arquivo Status, para passar os valores
	
	instanciador_Status.open("arq_Status.txt", ios::trunc);
	instanciador_Status << this->attStatus_SIM[amor] << "\t" << this->attStatus_SIM[saude] << "\t" << this->attStatus_SIM[secreto] << "\t" << this->attStatus_SIM[dinheiro] << endl;
	
	//ARQ << 0 <<  << 1 <<  << 0 <<  << 1 << endl;
	//abrir esse mesmo arquivo e baixar essas informações no montaCarta
	
	
}

void Cartas::setEscolhaNao()
{
	//abre o arquivo Status, para passar os valores

	instanciador_Status.open("arq_Status.txt", ios::trunc);//xxxxxxxPerguntar para o sor entre essa maneira e ios::out ||ios::trunc,

	instanciador_Status << this->attStatus_NAO[amor] << "\t" << this->attStatus_NAO[saude] << "\t" << this->attStatus_NAO[secreto] << "\t" << this->attStatus_NAO[dinheiro] << endl;

	//ARQ << 0 <<  << 1 <<  << 0 <<  << 1 << endl;
	//abrir esse mesmo arquivo e baixar essas informações no montaCarta
}

void Cartas::definirPersonagem(int indiceCarta)
{
	cartaAtual.setAnimacao(indiceCarta);
}

void Cartas::carregarImagens()
{
	gRecursos.carregarSpriteSheet("spriteCartas", "assets/SpritesSheet/cartasPersonagens.png", 1, 20);
	gRecursos.carregarSpriteSheet("spriteBaseTexto", "assets/SpritesSheet/BaseChat.png", 1, 1);

	cartaAtual.setSpriteSheet("spriteCartas");
	base_Texto.setSpriteSheet("spriteBaseTexto");
}

void Cartas::desenharCarta()
{
	cartaAtual.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	base_Texto.desenhar(gJanela.getLargura() / 2, 100);
}


