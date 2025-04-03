#include <iostream>
#include "NoLSE.h"
#include "NoAVL.h"

using namespace std;

NoLSE::NoLSE(NoAVL* no)
{
	this->no = no;
	this->prox = NULL;
}

NoLSE::~NoLSE()
{
	if (this->prox != NULL)
		delete this->prox;
}

void NoLSE::insere(NoAVL* no)
{
	if (no != NULL)
	{
		NoLSE* p = this;
		while (p->prox != NULL)
			p = p->prox;
		p->prox = new NoLSE(no);
	}
}

NoAVL* NoLSE::getNo()
{
	return this->no;
}

NoLSE* NoLSE::getProx()
{
	return this->prox;
}
