#pragma once
#include "libUnicornio.h"
#include "StatusBase.h"

class Saude:public StatusBase
{
private:

public:
	Saude();
	~Saude();

	void setNovaImagem(int i)override;
	virtual void setStatus()override;

};

