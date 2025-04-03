#ifndef AVL_H
#define AVL_H

#include "NoAVL.h"

class AVL
{
	private:

		NoAVL* raiz;

	public:

		AVL();
		~AVL();
		bool vazia();
		void insere(int valor);
		NoAVL* busca(int valor);
		void remove(int valor);
		void imprime();
		void imprimeOrdenado();
		void imprimePorNivel();
		void destroiArvore();
};

#endif
