#include <iostream>
#include "NoAVL.h"

using namespace std;

NoAVL::NoAVL(int valor)
{
	this->valor = valor;
	this->altura = 0;
	this->esq = NULL;
	this->dir = NULL;
}

NoAVL::~NoAVL()
{
	delete this->esq;
	delete this->dir;
}

int NoAVL::getValor()
{
	return this->valor;
}

NoAVL* NoAVL::getEsq()
{
	return this->esq;
}

NoAVL* NoAVL::getDir()
{
	return this->dir;
}

void NoAVL::setValor(int valor)
{
	this->valor = valor;
}

void NoAVL::setEsq(NoAVL* no)
{
	this->esq = no;
}

void NoAVL::setDir(NoAVL* no)
{
	this->dir = no;
}

NoAVL* NoAVL::corrige(NoAVL* no)
{
	// função auxiliar para executar as rotações
}

NoAVL* NoAVL::insere(NoAVL* no, int valor)
{
	// ...

	return no->corrige(no);
}

NoAVL* NoAVL::busca(int valor)
{
	// igual à ABB
}

NoAVL* NoAVL::remove(NoAVL* no, int valor)
{
	// ...

	return no->corrige(no);
}

void NoAVL::imprimeOrdemCrescente()
{
	// igual à ABB
}

void NoAVL::imprimeVisualizacao(int n)
{
	for (int i = 0; i < n; i++)
		cout << "--";
	cout << "(" << this->valor << ")" << endl;
	if (this->esq != NULL)
		this->esq->imprimeVisualizacao(n + 1);
	if (this->dir != NULL)
		this->dir->imprimeVisualizacao(n + 1);
}

void NoAVL::atualizaAltura()
{
	// ...
}

int NoAVL::getFB()
{
	return ((this->dir == NULL) ? -1 : this->dir->altura) - ((this->esq == NULL) ? -1 : this->esq->altura);
}

NoAVL* NoAVL::rotEsq(NoAVL* p)
{
	// ...
}

NoAVL* NoAVL::rotDir(NoAVL* p)
{
	// simétrico a rotEsq
}
