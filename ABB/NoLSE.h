#ifndef NOLSE_H
#define NOLSE_H

#include "NoABB.h"

class NoLSE
{
	private:

		NoABB* no;
		NoLSE* prox;

	public:

		NoLSE(NoABB* no);
		~NoLSE();
		void insere(NoABB* no);
		NoABB* getNo();
		NoLSE* getProx();
};

#endif
