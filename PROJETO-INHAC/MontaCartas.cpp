#include "MontaCartas.h"

MontaCartas::MontaCartas()
{
	carregarSprites();
}

void MontaCartas::carregarSprites()
{
	this->statusAmor = new Amor();
	this->statusSaude = new Saude();
	this->statusDinheiro = new Dinheiro();
	this->statusSecreto = new Secreto();

}

void MontaCartas::setCartas()
{
	personagem_carta.setSpriteSheet("spriteCartas");
	
	sprite_Saude.setSpriteSheet("statusSaude");
	sprite_Secreto.setSpriteSheet("statusSecret");
	sprite_Dinheiro.setSpriteSheet("statusDinheiro");

}
