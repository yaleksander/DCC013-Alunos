#ifndef ABB_H
#define ABB_H

#include "NoABB.h"

class ABB
{
	private:

		NoABB* raiz;

	public:

		ABB();
		~ABB();
		bool vazia();
		void insere(int valor);
		NoABB* busca(int valor);
		void remove(int valor);
		void imprime();
		void imprimeOrdenado();
		void imprimePorNivel();
		void destroiArvore();
};

#endif
