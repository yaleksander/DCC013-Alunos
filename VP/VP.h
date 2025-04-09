#ifndef VP_H
#define VP_H

#include "NoVP.h"

class VP
{
	private:

		NoVP* raiz;

	public:

		VP();
		~VP();
		bool vazia();
		void insere(int valor);
		NoVP* busca(int valor);
		void remove(int valor);
		void imprimeEmLargura();
		void imprimeOrdemCrescente();
		void imprimeVisualizacao();
		void destroiArvore();
		int getAlturaNegra();
};

#endif
