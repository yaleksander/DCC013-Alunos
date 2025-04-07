#include <iostream>
#include "VP.h"
#include "NoVP.h"
#include "NoLSE.h"

using namespace std;

VP::VP()
{
	this->raiz = NULL;
}

VP::~VP()
{
	delete this->raiz;
}

bool VP::vazia()
{
	return this->raiz == NULL;
}

void VP::insere(int valor)
{
	if (this->vazia())
		this->raiz = new NoVP(NULL, valor);
	else
		this->raiz = this->raiz->insere(valor);
}

NoVP* VP::busca(int valor)
{
	if (this->vazia())
		return NULL;
	return this->raiz->busca(valor);
}

void VP::remove(int valor)
{
	if (!this->vazia())
		this->raiz = this->raiz->remove(valor);
}

void VP::imprimeEmLargura()
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

void VP::imprimeOrdemCrescente()
{
	if (!this->vazia())
		this->raiz->imprimeOrdemCrescente();
	cout << "\b\b  " << endl;
}

void VP::imprimeVisualizacao()
{
	if (!this->vazia())
		this->raiz->imprimeVisualizacao(0);
}

void VP::destroiArvore()
{
	delete this->raiz;
	this->raiz = NULL;
}
