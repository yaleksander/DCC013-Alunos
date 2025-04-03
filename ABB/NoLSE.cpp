#include <iostream>
#include "NoLSE.h"
#include "NoABB.h"

using namespace std;

NoLSE::NoLSE(NoABB* no)
{
	this->no = no;
	this->prox = NULL;
}

NoLSE::~NoLSE()
{
	if (this->prox != NULL)
		delete this->prox;
}

void NoLSE::insere(NoABB* no)
{
	if (no != NULL)
	{
		NoLSE* p = this;
		while (p->prox != NULL)
			p = p->prox;
		p->prox = new NoLSE(no);
	}
}

NoABB* NoLSE::getNo()
{
	return this->no;
}

NoLSE* NoLSE::getProx()
{
	return this->prox;
}
