#include "Usuario.h"

Usuario::Usuario()
{
	this->senha = new Senha();
	name = "";
}

Usuario::~Usuario()
{
}

void Usuario::setIdIMG(int num)
{
	if (num == NULL) 
	{
		idImg == 0;
	}
	else 
	{
		this->idImg = num;
	}
	
}

void Usuario::setLVL(int lvlmxm)
{
	if (lvlmxm == NULL) 
	{
		nv = 0;
	}
	nv = lvlmxm;
}

int Usuario::getIdIMG()
{
	return idImg;
}

void Usuario::UP()
{
	nv++;
}

int Usuario::nvAtual()
{
	return nv;
}

void Usuario::setName(string nome)
{
	this->name = nome;
}

void Usuario::setID(int num)
{
	if (num == NULL) 
	{
		id = 0;
	}
	else 
	{
		this->id = num;
	}
	
}

void Usuario::setSenha(string nomeSenha)
{
	senha->setSenha(nomeSenha);
}

string Usuario::getNome()
{
	return this->name;
}

Senha *Usuario::getSenha()
{
	return this->senha;
}

int Usuario::getID()
{
	return this->id;
}
