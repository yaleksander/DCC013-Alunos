#include <iostream>
#include "AVL.h"
#include "NoAVL.h"
#include "NoLSE.h"

using namespace std;

AVL::AVL()
{
	this->raiz = NULL;
}

AVL::~AVL()
{
	delete this->raiz;
}

bool AVL::vazia()
{
	return this->raiz == NULL;
}

void AVL::insere(int valor)
{
	if (this->vazia())
		this->raiz = new NoAVL(valor);
	else
		this->raiz = this->raiz->insere(this->raiz, valor);
}

NoAVL* AVL::busca(int valor)
{
	if (this->vazia())
		return NULL;
	return this->raiz->busca(valor);
}

void AVL::remove(int valor)
{
	if (!this->vazia())
		this->raiz = this->raiz->remove(this->raiz, valor);
}

void AVL::imprimeEmLargura()
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

void AVL::imprimeOrdemCrescente()
{
	if (!this->vazia())
		this->raiz->imprimeOrdemCrescente();
	cout << "\b\b  " << endl;
}

void AVL::imprimeVisualizacao()
{
	if (!this->vazia())
		this->raiz->imprimeVisualizacao(0);
}

void AVL::destroiArvore()
{
	NoAVL* r = this->raiz;
	delete r;
	this->raiz = NULL;
}
