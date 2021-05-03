#pragma once
#include "libUnicornio.h"
#include "StatusBase.h"

class Dinheiro:public StatusBase
{
private:
	

public:
	Dinheiro();
	~Dinheiro();

	void setNovaImagem(int i)override;
	virtual void setStatus()override;
};

