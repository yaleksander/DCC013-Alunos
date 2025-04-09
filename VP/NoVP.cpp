#include <iostream>
#include "NoVP.h"

using namespace std;

NoVP::NoVP(NoVP* pai, int valor)
{
	this->valor = valor;
	this->cor = VERMELHO;
	this->pai = pai;
	this->esq = NULL;
	this->dir = NULL;
}

NoVP::~NoVP()
{
	delete this->esq;
	delete this->dir;
}

int NoVP::getValor()
{
	return this->valor;
}

NoVP* NoVP::getEsq()
{
	return this->esq;
}

NoVP* NoVP::getDir()
{
	return this->dir;
}

COR NoVP::getCor()
{
	return this->cor;
}

void NoVP::setValor(int valor)
{
	this->valor = valor;
}

void NoVP::setEsq(NoVP* no)
{
	this->esq = no;
}

void NoVP::setDir(NoVP* no)
{
	this->dir = no;
}

void NoVP::setCor(COR cor)
{
	this->cor = cor;
}

void NoVP::trocaCor(NoVP* no)
{
	COR aux = this->cor;
	this->cor = no->cor;
	no->cor = aux;
}

NoVP* NoVP::corrigeInsercao()
{
	if (this->pai != NULL && this->pai->pai != NULL && this->pai->cor == VERMELHO)
	{
		NoVP* tio;
		NoVP* pai = this->pai;
		NoVP* avo = this->pai->pai;
		bool dirTio;
		bool dirFilho = (this->pai->dir == this);
		if (avo->esq == pai)
		{
			tio = avo->dir;
			dirTio = true;
		}
		else
		{
			tio = avo->esq;
			dirTio = false;
		}
		if (tio != NULL && tio->cor == VERMELHO)
		{
			pai->cor = PRETO;
			tio->cor = PRETO;
			if (avo->pai != NULL)
			{
				avo->cor = VERMELHO;
				return avo->corrigeInsercao();
			}
		}
		else
		{
			if (!dirTio && dirFilho)
			{
				avo->rotEsq();
				avo->trocaCor(pai);
			}
			else if (!dirTio && !dirFilho)
			{
				pai->rotDir();
				avo->rotEsq();
				avo->trocaCor(this);
			}
			else if (dirTio && !dirFilho)
			{
				avo->rotDir();
				avo->trocaCor(pai);
			}
			else
			{
				pai->rotEsq();
				avo->rotDir();
				avo->trocaCor(this);
			}
		}
	}
	NoVP* p = this;
	while (p->pai != NULL)
		p = p->pai;
	p->cor = PRETO;
	return p;
}

NoVP* NoVP::corrigeRemocao(NoVP* velho, NoVP* novo)
{
	// tabela com os 6 casos p/ corrigir a árvore após uma remoção:
	// https://medium.com/analytics-vidhya/deletion-in-red-black-rb-tree-92301e1474ea
	NoVP* p = velho;
	if (novo != NULL)
	{
		novo->pai = velho->pai;
		novo->cor = PRETO;
	}
	else
	{
		// descarta caso 1: folha vermelha
		while (p->cor == PRETO && p->pai != NULL)
		{
			bool dirIrmao;
			NoVP* irmao;
			if (p->pai->esq == p)
			{
				dirIrmao = true;
				irmao = p->pai->dir;
			}
			else
			{
				dirIrmao = false;
				irmao = p->pai->esq;
			}

			// caso 4: irmão vermelho
			if (irmao->cor == VERMELHO)
			{
				p->pai->trocaCor(irmao);
				if (dirIrmao)
					p->pai->rotDir();
				else
					p->pai->rotEsq();
			}

			// caso 3: irmão preto, sobrinhos pretos
			else if ((irmao->esq == NULL || irmao->esq->cor == PRETO) && (irmao->dir == NULL || irmao->dir->cor == PRETO))
			{
				irmao->cor = VERMELHO;
				if (p->pai->cor == VERMELHO)
				{
					p->pai->cor = PRETO;
					break;
				}
				else
					p = p->pai;
			}
			else
			{
				NoVP* proximo;
				NoVP* distante;
				if (dirIrmao)
				{
					proximo = irmao->esq;
					distante = irmao->dir;
				}
				else
				{
					proximo = irmao->dir;
					distante = irmao->esq;
				}

				// caso 5: sobrinho distante preto, sobrinho próximo vermelho
				if ((distante == NULL || distante->cor == PRETO) && proximo != NULL && proximo->cor == VERMELHO)
				{
					proximo->trocaCor(irmao);
					if (dirIrmao)
						irmao->rotEsq();
					else
						irmao->rotDir();
				}

				// caso 6: sobrinho distante vermelho
				if (distante != NULL && distante->cor == VERMELHO)
				{
					p->pai->trocaCor(irmao);
					if (dirIrmao)
						p->pai->rotDir();
					else
						irmao->rotEsq();
					distante->cor = PRETO;
					break;
				}
			}
		}
	}
	p = velho->pai;
	if (p != NULL)
	{
		if (p->esq == velho)
			p->esq = novo;
		else
			p->dir = novo;
	}
	while (p->pai != NULL)
		p = p->pai;
	velho->esq = NULL;
	velho->dir = NULL;
	delete velho;

	// precaução pro caso 2: raiz pode ser vermelha
	p->cor = PRETO;
	return p;
}

NoVP* NoVP::insere(int valor)
{
	if (valor < this->valor)
	{
		if (this->esq == NULL)
		{
			this->esq = new NoVP(this, valor);
			return this->esq->corrigeInsercao();
		}
		else
			return this->esq->insere(valor);
	}
	else
	{
		if (this->dir == NULL)
		{
			this->dir = new NoVP(this, valor);
			return this->dir->corrigeInsercao();
		}
		else
			return this->dir->insere(valor);
	}
}

NoVP* NoVP::busca(int valor)
{
	if (valor == this->valor)
		return this;
	else if (valor < this->valor && this->esq != NULL)
		return this->esq->busca(valor);
	else if (this->dir != NULL)
		return this->dir->busca(valor);
	return NULL;
}

NoVP* NoVP::remove(int valor)
{
	if (valor < this->valor)
		return this->esq->remove(valor);
	else if (valor > this->valor)
		return this->dir->remove(valor);
	else if (this->esq != NULL && this->dir != NULL)
	{
		NoVP* p = this->dir;
		while (p->esq != NULL)
			p = p->esq;
		this->valor = p->valor;
		return this->dir->remove(p->valor);
	}
	else
	{
		if (this->dir == NULL)
			return this->corrigeRemocao(this, this->esq);
		else
			return this->corrigeRemocao(this, this->dir);
	}
}

void NoVP::corrigePai(NoVP* p)
{
	if (this->pai != NULL)
	{
		if (this->pai->esq == this)
			this->pai->esq = p;
		else
			this->pai->dir = p;
	}
	p->pai = this->pai;
	this->pai = p;
}

void NoVP::rotEsq()
{
	NoVP* p = this->dir;
	this->dir = p->esq;
	p->esq = this;
	this->corrigePai(p);
}

void NoVP::rotDir()
{
	NoVP* p = this->esq;
	this->esq = p->dir;
	p->dir = this;
	this->corrigePai(p);
}

void NoVP::imprimeOrdemCrescente()
{
	if (this->esq != NULL)
		this->esq->imprimeOrdemCrescente();
	cout << this->valor << ", ";
	if (this->dir != NULL)
		this->dir->imprimeOrdemCrescente();
}

void NoVP::imprimeVisualizacao(int n)
{
	for (int i = 0; i < n; i++)
		cout << "--";
	if (this->cor == VERMELHO)
		cout << "\033[31;40m";
	cout << "(" << this->valor << ")\033[37;40m" << endl;
	if (this->esq != NULL)
		this->esq->imprimeVisualizacao(n + 1);
	if (this->dir != NULL)
		this->dir->imprimeVisualizacao(n + 1);
}
