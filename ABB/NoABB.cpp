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
	// lembrando que não são permitidos nós com chaves/valores iguais em ABBs
}

NoABB* NoABB::busca(int valor)
{
	// ...
}

NoABB* NoABB::remove(NoABB* no, int valor)
{
	// ...
}

void NoABB::imprimeOrdenado()
{
	// ...
}

void NoABB::imprimePorNivel(int n)
{
	// ...
}
