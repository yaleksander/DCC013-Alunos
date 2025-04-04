#include <iostream>
#include "ABB.h"
#include "NoABB.h"
#include "NoLSE.h"

using namespace std;

ABB::ABB()
{
	this->raiz = NULL;
}

ABB::~ABB()
{
	delete this->raiz;
}

bool ABB::vazia()
{
	return this->raiz == NULL;
}

void ABB::insere(int valor)
{
	if (this->vazia())
		this->raiz = new NoABB(valor);
	else
		this->raiz->insere(valor);
}

NoABB* ABB::busca(int valor)
{
	if (this->vazia())
		return NULL;
	return this->raiz->busca(valor);
}

void ABB::remove(int valor)
{
	if (!this->vazia())
		this->raiz = this->raiz->remove(this->raiz, valor);
}

void ABB::imprimeEmLargura()
{
	if (!this->vazia())
	{
		NoLSE* lista = new NoLSE(this->raiz);
		for (NoLSE* p = lista; p != NULL; p = p->getProx())
		{
			cout << p->getNo()->getValor() << ", ";
			p->insere(p->getNo()->getEsq());
			p->insere(p->getNo()->getDir());
		}
		delete lista;
	}
	cout << "\b\b  " << endl;
}

void ABB::imprimeOrdemCrescente()
{
	if (!this->vazia())
		this->raiz->imprimeOrdemCrescente();
	cout << "\b\b  " << endl;
}

void ABB::imprimeVisualizacao()
{
	if (!this->vazia())
		this->raiz->imprimeVisualizacao(0);
}

void ABB::destroiArvore()
{
	delete this->raiz;
	this->raiz = NULL;
}
