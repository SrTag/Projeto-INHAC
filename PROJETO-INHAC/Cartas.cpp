#include "Cartas.h"

Cartas::Cartas()
{
	
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


void Cartas::definirPersonagem(string cartaPersonagem)
{
	cartaAtual.setSpriteSheet(cartaPersonagem);
}

void Cartas::desenharCarta()
{
	cartaAtual.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	
}

int Cartas::getAtt_SIM_Amor()
{ 
	return attStatus_SIM[amor];
}

int Cartas::getAtt_SIM_Dinheiro()
{
	 return attStatus_SIM[dinheiro];
}

int Cartas::getAtt_SIM_Saude()
{
	return attStatus_SIM[saude];
}

int Cartas::getAtt_SIM_Secreto()
{
	return attStatus_SIM[secreto];
}

int Cartas::getAtt_NAO_Amor()
{
	return attStatus_NAO[amor];
}

int Cartas::getAtt_NAO_Dinheiro()
{
	return attStatus_NAO[dinheiro];
}

int Cartas::getAtt_NAO_Saude()
{
	return attStatus_NAO[saude];
}

int Cartas::getAtt_NAO_Secreto()
{
	return attStatus_NAO[secreto];
}


