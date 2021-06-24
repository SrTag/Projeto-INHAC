#include <iostream>
#include "Senha.h"
#include "libUnicornio.h"

using namespace std;

class Usuario
{
private:
	string name;
	Senha* senha;
	int id,nv,idImg;
	
public:
	Usuario();
	~Usuario();
	void setIdIMG(int num);
	void setLVL(int lvlmxm);
	int getIdIMG();
	void UP();
	int nvAtual();
	void setName(string nome);
	void setID(int num);
	void setSenha(string nomeSenha);
	string getNome();
	Senha* getSenha();
	int getID();

};

