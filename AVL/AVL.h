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
		void imprimeEmLargura();
		void imprimeOrdemCrescente();
		void imprimeVisualizacao();
		void destroiArvore();
};

#endif
