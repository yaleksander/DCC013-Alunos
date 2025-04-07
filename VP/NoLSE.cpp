#include <iostream>
#include "NoLSE.h"
#include "NoVP.h"

using namespace std;

NoLSE::NoLSE(NoVP* no)
{
	this->no = no;
	this->prox = NULL;
}

NoLSE::~NoLSE()
{
	if (this->prox != NULL)
		delete this->prox;
}

void NoLSE::insere(NoVP* no)
{
	if (no != NULL)
	{
		NoLSE* p = this;
		while (p->prox != NULL)
			p = p->prox;
		p->prox = new NoLSE(no);
	}
}

NoVP* NoLSE::getNo()
{
	return this->no;
}

NoLSE* NoLSE::getProx()
{
	return this->prox;
}
