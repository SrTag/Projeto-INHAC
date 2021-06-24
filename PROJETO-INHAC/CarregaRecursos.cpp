#include "CarregaRecursos.h"

CarregaRecursos::CarregaRecursos()
{
	
}

void CarregaRecursos::carregarTodasSprites()
{
	
	carregarFontes();
	carregarAudio();
	carregarSprites();
	
}

void CarregaRecursos::carregarFontes()
{
	gRecursos.carregarFonte("TextoFont", "assets/SpritesSheet/leadcoat.ttf", 15);
	gRecursos.carregarFonte("creditostxt", "assets/SpritesSheet/leadcoat.ttf", 15);
}

void CarregaRecursos::carregarAudio()
{
	gRecursos.carregarAudio("somBotao", "assets/SpritesSheet/botao.wav");
	gRecursos.carregarAudio("somGame", "assets/SpritesSheet/gameMusic.wav");
}

void CarregaRecursos::carregarSprites()
{
	//att 2.0
	//personagens
	gRecursos.carregarSpriteSheet("P1", "assets/SpritesSheet/p1.png", 1, 1);
	gRecursos.carregarSpriteSheet("P2", "assets/SpritesSheet/p1.png", 1, 1);
	gRecursos.carregarSpriteSheet("P3", "assets/SpritesSheet/p1.png", 1, 1);
	gRecursos.carregarSpriteSheet("P4", "assets/SpritesSheet/p1.png", 1, 1);
	gRecursos.carregarSpriteSheet("P5", "assets/SpritesSheet/p1.png", 1, 1);
	//personagens BOTAO
	gRecursos.carregarSpriteSheet("P11", "assets/SpritesSheet/p11.png", 3, 1);
	gRecursos.carregarSpriteSheet("P12", "assets/SpritesSheet/p12.png", 3, 1);
	gRecursos.carregarSpriteSheet("P13", "assets/SpritesSheet/p13.png", 3, 1);
	gRecursos.carregarSpriteSheet("confirmar", "assets/SpritesSheet/botaoCONFIRM.png", 3, 1);

	gRecursos.carregarSpriteSheet("RED", "assets/SpritesSheet/corV.png", 3, 1);
	gRecursos.carregarSpriteSheet("BLUE", "assets/SpritesSheet/corB.png", 3, 1);
	gRecursos.carregarSpriteSheet("ROXO", "assets/SpritesSheet/corR.png", 3, 1);
	//recursos de novos botoes
	gRecursos.carregarSpriteSheet("BotaoLoad", "assets/SpritesSheet/botaoLoad.png", 3, 1);
	gRecursos.carregarSpriteSheet("BotaoNewGame", "assets/SpritesSheet/botaoNewGame.png", 3, 1);
	gRecursos.carregarSpriteSheet("BotaoSair", "assets/SpritesSheet/botaoSair.png", 3, 1);
	gRecursos.carregarSpriteSheet("BotaoRecords", "assets/SpritesSheet/botaoRecords.png", 3, 1);
	gRecursos.carregarSpriteSheet("saveUser", "assets/SpritesSheet/save.png", 3, 1);
	//Funods V2.0
	gRecursos.carregarSpriteSheet("fundoLoad", "assets/SpritesSheet/fundoLoad.png", 1, 1);

	/////////////////////////////////////////////////////////////////////////
	//versao 1
	gRecursos.carregarSpriteSheet("BotaoSIM", "assets/SpritesSheet/botaoSim.png", 3, 1);
	gRecursos.carregarSpriteSheet("BotaoNAO", "assets/SpritesSheet/botaoNao.png", 3, 1);
	gRecursos.carregarSpriteSheet("fundoMenu", "assets/SpritesSheet/fundo2.png", 1, 1);
	gRecursos.carregarSpriteSheet("botaoJogar", "assets/SpritesSheet/botaoJogar.png", 3, 1);
	gRecursos.carregarSpriteSheet("botaoCreditos", "assets/SpritesSheet/bCredit.png", 3, 1);
	gRecursos.carregarSpriteSheet("fundoOver", "assets/SpritesSheet/gameOver.png", 1, 1);
	gRecursos.carregarSpriteSheet("BotaoVoltar", "assets/SpritesSheet/botaoVoltar.png", 3, 1);
	gRecursos.carregarSpriteSheet("texto", "assets/SpritesSheet/BaseChat.png", 1, 1);
	gRecursos.carregarSpriteSheet("vitoria", "assets/SpritesSheet/Victory.png", 1, 1);
	gRecursos.carregarSpriteSheet("amormais", "assets/SpritesSheet/amordemais.png", 1, 1);
	gRecursos.carregarSpriteSheet("amormenos", "assets/SpritesSheet/amordemenos.png", 1, 1);
	gRecursos.carregarSpriteSheet("dinheiromais", "assets/SpritesSheet/dinheirodemais.png", 1, 1);
	gRecursos.carregarSpriteSheet("dinheiromenos", "assets/SpritesSheet/dinheirodemenos.png", 1, 1);
	gRecursos.carregarSpriteSheet("saudemais", "assets/SpritesSheet/saudedemais.png", 1, 1);
	gRecursos.carregarSpriteSheet("saudemenos", "assets/SpritesSheet/saudedemenos.png", 1, 1);
	gRecursos.carregarSpriteSheet("secretomais", "assets/SpritesSheet/secretodemais.png", 1, 1);
	gRecursos.carregarSpriteSheet("secretomenos", "assets/SpritesSheet/secretodemenos.png", 1, 1);

	for (int i = 1; i < 12; i++)
	{
		gRecursos.carregarSpriteSheet("statusAmor" + to_string(i), "assets/SpritesSheet/core" + to_string(i) + ".png", 1, 1);
		gRecursos.carregarSpriteSheet("statusDinheiro" + to_string(i), "assets/SpritesSheet/dinheiro" + to_string(i) + ".png", 1, 1);
		gRecursos.carregarSpriteSheet("statusSaude" + to_string(i), "assets/SpritesSheet/saude" + to_string(i) + ".png", 1, 1);
		gRecursos.carregarSpriteSheet("statusSecret" + to_string(i), "assets/SpritesSheet/secreto" + to_string(i) + ".png", 1, 1);

	}
	for (int i = 1; i < 21; i++)
	{
		gRecursos.carregarSpriteSheet("personagem" + to_string(i), "assets/SpritesSheet/personagem" + to_string(i) + ".png", 1, 1);
	}
}
