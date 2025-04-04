#include <iostream>
#include "NoABB.h"

using namespace std;

NoABB::NoABB(int valor)
{
	this->valor = valor;
	this->esq = NULL;
	this->dir = NULL;
}

NoABB::~NoABB()
{
	delete this->esq;
	delete this->dir;
}

int NoABB::getValor()
{
	return this->valor;
}

NoABB* NoABB::getEsq()
{
	return this->esq;
}

NoABB* NoABB::getDir()
{
	return this->dir;
}

void NoABB::setValor(int valor)
{
	this->valor = valor;
}

void NoABB::setEsq(NoABB* no)
{
	this->esq = no;
}

void NoABB::setDir(NoABB* no)
{
	this->dir = no;
}

void NoABB::insere(int valor)
{
	// ...
}

NoABB* NoABB::busca(int valor)
{
	// ...
}

NoABB* NoABB::remove(NoABB* no, int valor)
{
	// ...
}

void NoABB::imprimeOrdemCrescente()
{
	// ...
}

void NoABB::imprimeVisualizacao(int n)
{
	for (int i = 0; i < n; i++)
		cout << "--";
	cout << "(" << this->valor << ")" << endl;
	if (this->esq != NULL)
		this->esq->imprimeVisualizacao(n + 1);
	if (this->dir != NULL)
		this->dir->imprimeVisualizacao(n + 1);
}
