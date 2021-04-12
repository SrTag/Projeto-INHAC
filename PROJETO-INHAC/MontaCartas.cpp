#include "MontaCartas.h"

MontaCartas::MontaCartas()
{
	carregarSprites();
}

void MontaCartas::carregarSprites()
{
	//carrega os recursos de todas as imagens imbutidos em cada classe individual
	this->statusAmor = new Amor();
	this->statusSaude = new Saude();
	this->statusDinheiro = new Dinheiro();
	this->statusSecreto = new Secreto();
	this->cartas = new Cartas();

	//chamar o metodo para setar todas as imagens
	setCartas();
}

void MontaCartas::setCartas()
{
	//esse aqui define os personagens
	personagem_carta.setSpriteSheet("spriteCartas");

	//define os status Amor,Saude,Dinheiro,Secreto
	statusAmor->setStatusAmor();
	statusSaude->setStatusSaude();
	statusDinheiro->setStatusDinheiro();
	statusSecreto->setStatusSecreto();
	
}

void MontaCartas::setPosX_PosY()
{
	statusAmor->definePosX_and_PosY(200,50);
	statusSaude->definePosX_and_PosY(300,50);
	statusSecreto->definePosX_and_PosY(400,50);
	statusDinheiro->definePosX_and_PosY(500,50);
}

void MontaCartas::MontandoCartas()
{
	//monta a imagem da carta
	personagem_carta.setAnimacao(indice_imagemCarta);
	personagem_carta.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

	statusAmor->desenharSpriteAmor();
	statusSaude->desenharSpriteSaude();
	statusSecreto->desenharSpriteSecreto();
	statusDinheiro->desenharSpriteDinheiro();
}

void MontaCartas::attStatus(int _amor, int _saude, int _secreto, int _dinheiro)
{
	personagem_carta.setAnimacao(indice_imagemCarta);
	statusAmor->atualizaStatusAmor(_amor);
	statusDinheiro->atualizaStatusDinheiro(_dinheiro);
	statusSaude->atualizaStatusSaude(_saude);
	statusSecreto->atualizaStatusSecreto(_secreto);
}
