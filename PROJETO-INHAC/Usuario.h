#include <iostream>
#include "Senha.h"

using namespace std;

class Usuario
{
private:
	string name;
	Senha* senha;
	int id;

public:
	Usuario();
	~Usuario();
	void nvAtual(int nv);
	int nvAtual();
	void setName(string nome);
	void setID(int num);
	void setSenha(string nomeSenha);
	string getNome();
	Senha* getSenha();
	int getID();

};

