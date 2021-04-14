#include "MontaCartas.h"

MontaCartas::MontaCartas()
{
	carregarSprites();
}

void MontaCartas::carregarSprites()
{
	
	//carrega os recursos de todas as imagens imbutidos em cada classe individual
	this->carta = new Cartas[20];
	this->statusAmor = new Amor();
	this->statusSaude = new Saude();
	this->statusDinheiro = new Dinheiro();
	this->statusSecreto = new Secreto();
	
	//chamar o metodo para setar todas as imagens
	setSpriteShetStatus();
}

void MontaCartas::setSpriteShetStatus()
{
	//esse aqui define os personagens

	//seta todos os personagens em 20 cartas
	for (int i = 0; i < 20; i++) {
		carta[i]->definirPersonagem(i);
	}
	//define os status Amor,Saude,Dinheiro,Secreto.
	statusAmor->setStatusAmor();
	statusSaude->setStatusSaude();
	statusDinheiro->setStatusDinheiro();
	statusSecreto->setStatusSecreto();
	
}

void MontaCartas::carregarStatusCartas_Arq()
{
	//aqui ira passar os valores para kd carta, no q irao atualizart os arquivos SIM
	arq_StatusSIM_Cartas.open("Arq_Status_CartasSIM", ios::in);
	
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

	carta[indice_carta]->desenharCarta();
	statusAmor->desenharSpriteAmor();
	statusSaude->desenharSpriteSaude();
	statusSecreto->desenharSpriteSecreto();
	statusDinheiro->desenharSpriteDinheiro();
}

void MontaCartas::attStatus()
{
	int statusAtt[4];
	baixarDados_Att_Status.open("arq_Status.txt", ios::in);

	for (int i = 0; i < 4; i++) {
		baixarDados_Att_Status >> statusAtt[i];
	}
	
	statusAmor->atualizaStatusAmor(statusAtt[0]);
	statusDinheiro->atualizaStatusDinheiro(statusAtt[1]);
	statusSaude->atualizaStatusSaude(statusAtt[2]);
	statusSecreto->atualizaStatusSecreto(statusAtt[3]);

}

