#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <vector>

using namespace std;

class MaxHeap
{
	private:

		vector<int> v;
		void sobe(int i);
		void desce(int i);
		void imprimeArvoreAux(int i, int n, int altura);

	public:

		MaxHeap() {};
		~MaxHeap();
		bool vazia();
		int getRaiz();
		void insere(int valor);
		void remove();
		void imprimeLista();
		void imprimeArvore();
		vector<int> heapsort();
};

#endif
