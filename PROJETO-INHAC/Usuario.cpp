#include "Usuario.h"

Usuario::Usuario()
{
	this->senha = new Senha();
	name = "";
}

Usuario::~Usuario()
{
}

void Usuario::setName(string nome)
{
	this->name = nome;
}

void Usuario::setID(int num)
{
	this->id = num;
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
