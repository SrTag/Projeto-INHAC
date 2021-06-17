#include "Senha.h"

Senha::Senha()
{
}

Senha::~Senha()
{
}

void Senha::setSenha(string nome)
{
	this->senha = nome;
}

string Senha::getSenha()
{
	return this->senha;
}
