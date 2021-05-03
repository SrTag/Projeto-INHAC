#include "MontaCartas.h"

MontaCartas::MontaCartas()
{
	//setando atributo
	indice_carta = 0;

	//alocando dinamicamente a memoria
	recursos = new CarregaRecursos();
	texto = new Texto_Personagens();
	carta = new Cartas[20];
	statusAmor = new Amor();
	statusSaude = new Saude();
	statusDinheiro = new Dinheiro();
	statusSecreto = new Secreto();
	
}

void MontaCartas::proxCarta(int num)
{
	//prox Personagem
	this->indice_carta = num;

	//prox Fala
	texto->setTexto(num);
}

void MontaCartas::carregarSprites()
{
	// carrega as imagens, para depois setar
	recursos->carregarTodasSprites();
	
}

void MontaCartas::setSpriteShetStatus()
{

	//seta todos os personagens em 20 cartas
	int j=1;

	for (int i = 0; i < 20; i++) {
		carta[i].definirPersonagem("personagem" + to_string(j));
		j++;
	}

	//texto
	texto->setSpriteTexto();
	texto->carregarFalas();

	//define os status Amor,Saude,Dinheiro,Secreto.
	statusAmor->setStatus();
	statusSaude->setStatus();
	statusDinheiro->setStatus();
	statusSecreto->setStatus();
	
}

void MontaCartas::carregarStatusCartas_Arq()
{
	///////////////////////ARQUIVO SIM///////////////////////////////////////////////////////////////////////////////////////////
	//aqui ira passar os valores para kd carta, no q irao atualizart os arquivos SIM
	arq_StatusSIM_Cartas.open("arqSIM.txt", ios::in);
	int indice_dos_status[4];
	
	if (!arq_StatusSIM_Cartas.is_open()) {

		arq_StatusSIM_Cartas.open("arqSIM.txt", ios::in);
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
	arq_StatusNAO_Cartas.open("arqNAO.txt", ios::in);

	if (!arq_StatusNAO_Cartas.is_open()) {
		gDebug.getCorFundo();
		arq_StatusNAO_Cartas.open("arqNAO.txt", ios::in);
	}
	else {

		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 4; j++) {

				arq_StatusNAO_Cartas >> indice_dos_status[j];
			}

			carta[i].carregarArqStatusNao(indice_dos_status[0], indice_dos_status[1], indice_dos_status[2], indice_dos_status[3]);
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
	texto->desenharBaseTexto();
	statusAmor->desenharSprite();
	statusSaude->desenharSprite();
	statusSecreto->desenharSprite();
	statusDinheiro->desenharSprite();
}

int MontaCartas::returnGameOver()
{
	if (statusAmor->gameOver() == true) {

		return true;
	}
	else if (statusSaude->gameOver() == true) 
	{
		return true;

	}
	else if (statusDinheiro->gameOver() == true)
	{
		return true;

	}
	else if (statusSecreto->gameOver() == true)
	{
		return true;

	}
	else 
	{
		return false;
	}
}


void MontaCartas::attStatus(int qualCarta, bool sim_ou_nao)
{
	
	if (sim_ou_nao == true) {
		
		statusAmor->atualizaStatus(carta[qualCarta].getAtt_SIM_Amor());
		statusDinheiro->atualizaStatus(carta[qualCarta].getAtt_SIM_Dinheiro());
		statusSaude->atualizaStatus(carta[qualCarta].getAtt_SIM_Saude());
		statusSecreto->atualizaStatus(carta[qualCarta].getAtt_SIM_Secreto());
		
		
		
	}
	if(sim_ou_nao == false)
	{
		statusAmor->atualizaStatus(carta[qualCarta].getAtt_NAO_Amor());
		statusDinheiro->atualizaStatus(carta[qualCarta].getAtt_NAO_Dinheiro());
		statusSaude->atualizaStatus(carta[qualCarta].getAtt_NAO_Saude());
		statusSecreto->atualizaStatus(carta[qualCarta].getAtt_NAO_Secreto());
		

	}
}

void MontaCartas::qualGameOver()
{
	if (statusAmor->gameOver() == true) {

		if (statusAmor->getIndiceStatus() <= 0)
		{
			gameOver.setSpriteSheet("amormenos");
		}
		if (statusAmor->getIndiceStatus() >= 10)
		{
			gameOver.setSpriteSheet("amormais");
		}
		
		
	}
	else if (statusSaude->gameOver() == true)
	{
		if (statusSaude->getIndiceStatus() <= 0)
		{
			gameOver.setSpriteSheet("saudemenos");
		}
		if (statusSaude->getIndiceStatus() >= 10)
		{
			gameOver.setSpriteSheet("saudemais");
		}

	}
	else if (statusDinheiro->gameOver() == true)
	{
		if (statusDinheiro->getIndiceStatus() <= 0)
		{
			gameOver.setSpriteSheet("dinheiromenos");
		}
		if (statusDinheiro->getIndiceStatus() >= 10)
		{
			gameOver.setSpriteSheet("dinheiromais");
		}

	}
	else if (statusSecreto->gameOver() == true)
	{
		if (statusSecreto->getIndiceStatus() <= 0)
		{
			gameOver.setSpriteSheet("secretomenos");
		}
		if (statusSecreto->getIndiceStatus() >= 10)
		{
			gameOver.setSpriteSheet("secretomais");
		}

	}
	gameOver.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
}



