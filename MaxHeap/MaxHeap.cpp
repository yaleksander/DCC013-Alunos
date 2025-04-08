#include <iostream>
#include "MaxHeap.h"

MaxHeap::~MaxHeap()
{
	v.resize(0);
}

bool MaxHeap::vazia()
{
	return v.empty();
}

void MaxHeap::insere(int valor)
{
	this->v.push_back(valor);
	this->sobe(this->v.size() - 1);
}

int MaxHeap::getRaiz()
{
	// causa erro se a heap estiver vazia
	return this->v[0];
}

void MaxHeap::remove()
{
	int n = this->v.size();
	if (n > 0)
	{
		this->v[0] = this->v[n - 1];
		this->desce(0);
		this->v.pop_back();
	}
}

void MaxHeap::imprimeLista()
{
	int n = this->v.size();
	for (int i = 0; i < n; i++)
		cout << this->v[i] << ", ";
	cout << "\b\b  " << endl;
}

void MaxHeap::imprimeArvore()
{
	int n = this->v.size();
	if (n > 0)
		imprimeArvoreAux(0, n, 0);
}

vector<int> MaxHeap::heapsort()
{
	vector<int> v2(this->v);
	for (int i = v2.size() - 1; i > 0; i--)
	{
		swap(v2[0], v2[i]);
		int j = 0;
		int k = 1;
		while (j < i && k < i)
		{
			if (k + 1 < i && v2[k] < v2[k + 1])
				k++;
			swap(v2[j], v2[k]);
			j = k;
			k = 2 * j + 1;
		}
	}
	return v2;
}

void MaxHeap::imprimeArvoreAux(int i, int n, int altura)
{
	for (int i = 0; i < altura; i++)
		cout << "--";
	int filho = 2 * i + 1;
	cout << "(" << this->v[i] << ")" << endl;
	if (filho < n)
		imprimeArvoreAux(filho, n, altura + 1);
	if (++filho < n)
		imprimeArvoreAux(filho, n, altura + 1);
}

void MaxHeap::sobe(int i)
{
	int pai = (i - 1) / 2;
	if (this->v[i] > this->v[pai])
	{
		swap(this->v[i], this->v[pai]);
		if (pai >= 0)
			sobe(pai);
	}
}

void MaxHeap::desce(int i)
{
	int filho = 2 * i + 1;
	int n = this->v.size();
	if (filho < n)
	{
		if (filho + 1 < n && this->v[filho] < this->v[filho + 1])
			filho++;
		if (this->v[i] < this->v[filho])
		{
			swap(this->v[i], this->v[filho]);
			desce(filho);
		}
	}
}
