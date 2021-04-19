#include "MontaCartas.h"

MontaCartas::MontaCartas()
{
	//seta o indice carta em 0, ja q quero começar com a primeira carta
	this->indice_carta = 0;
	//carrega os recursos de todas as imagens imbutidos em cada classe individual

	this->carta = new Cartas[20];
	this->statusAmor = new Amor();
	this->statusSaude = new Saude();
	this->statusDinheiro = new Dinheiro();
	this->statusSecreto = new Secreto();
	
}

void MontaCartas::carregarSprites()
{
	
	
	// carrega as imagens, para depois setar

	statusAmor->carregarStatusAmor();
	statusDinheiro->carregarStatusDinheiro();
	statusSaude->carregarStatusSaude();
	statusSecreto->carregarSpriteStatus();

	
	
}

void MontaCartas::setSpriteShetStatus()
{
	//esse aqui define os personagens

	//seta todos os personagens em 20 cartas
	for (int i = 0; i < 20; i++) {
		carta[i].definirPersonagem(i);
	}
	//define os status Amor,Saude,Dinheiro,Secreto.
	statusAmor->setStatusAmor();
	statusSaude->setStatusSaude();
	statusDinheiro->setStatusDinheiro();
	statusSecreto->setStatusSecreto();
	
}

void MontaCartas::carregarStatusCartas_Arq()
{
	///////////////////////ARQUIVO SIM///////////////////////////////////////////////////////////////////////////////////////////
	//aqui ira passar os valores para kd carta, no q irao atualizart os arquivos SIM
	arq_StatusSIM_Cartas.open("Arq_Status_CartasSIM.txt", ios::in);
	int indice_dos_status[4];
	
	if (!arq_StatusSIM_Cartas.is_open()) {
		gDebug.getCorFundo();
		arq_StatusSIM_Cartas.open("Arq_Status_CartasSIM.txt", ios::in);
	}
	else
	{

		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 4; j++) {

				arq_StatusSIM_Cartas >> indice_dos_status[j];
			}

			carta[i].carregarArqStatusSim(indice_dos_status[0], indice_dos_status[1], indice_dos_status[2], indice_dos_status[3]);
		}
	}
	arq_StatusSIM_Cartas.close();

	//depois que o primeiro arq, fecha, eu abro o segundo, para instanciar, quando o jogador falar nao, qual resposta deve ser
	/////////////////////ARQUIVO NAO //////////////////////////////////////////////////////////////////////////////////////////////////////
	arq_StatusNAO_Cartas.open("Arq_StatusNAO_CartasNAO.txt", ios::in);

	if (!arq_StatusNAO_Cartas.is_open()) {
		gDebug.getCorFundo();
		arq_StatusNAO_Cartas.open("Arq_Status_CartasNAO.txt", ios::in);
	}
	else {

		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 4; j++) {

				arq_StatusNAO_Cartas >> indice_dos_status[j];
			}

			carta[i].carregarArqStatusSim(indice_dos_status[0], indice_dos_status[1], indice_dos_status[2], indice_dos_status[3]);
		}

	}

	arq_StatusNAO_Cartas.close();

}

void MontaCartas::setPosX_PosY()
{
	statusAmor->definePosX_and_PosY(200, 50);
	statusSaude->definePosX_and_PosY(300,50);
	statusSecreto->definePosX_and_PosY(400,50);
	statusDinheiro->definePosX_and_PosY(500,50);
}

void MontaCartas::MontandoCartas()
{
	//monta a imagem da carta

	carta[indice_carta].desenharCarta();
	statusAmor->desenharSpriteAmor();
	statusSaude->desenharSpriteSaude();
	statusSecreto->desenharSpriteSecreto();
	statusDinheiro->desenharSpriteDinheiro();
}

void MontaCartas::attStatus(int qualCarta, bool sim_ou_nao)
{
	

	if (sim_ou_nao == true) {
		
		statusAmor->atualizaStatusAmor(carta[qualCarta].getAtt_SIM_Amor());
		statusDinheiro->atualizaStatusDinheiro(carta[qualCarta].getAtt_SIM_Dinheiro());
		statusSaude->atualizaStatusSaude(carta[qualCarta].getAtt_SIM_Saude());
		statusSecreto->atualizaStatusSecreto(carta[qualCarta].getAtt_SIM_Secreto());
		
		
	}
	else 
	{
		statusAmor->atualizaStatusAmor(carta[qualCarta].getAtt_NAO_Amor());
		statusDinheiro->atualizaStatusDinheiro(carta[qualCarta].getAtt_NAO_Dinheiro());
		statusSaude->atualizaStatusSaude(carta[qualCarta].getAtt_NAO_Saude());
		statusSecreto->atualizaStatusSecreto(carta[qualCarta].getAtt_NAO_Secreto());

	}

	
	

}

