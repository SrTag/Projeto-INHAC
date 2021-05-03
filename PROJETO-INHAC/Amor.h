#pragma once

#include "libUnicornio.h"
#include "StatusBase.h"

class Amor:public StatusBase
{
private:
	
public:
	Amor();
	~Amor();

	void setNovaImagem(int i)override;
	virtual void setStatus()override;
};

