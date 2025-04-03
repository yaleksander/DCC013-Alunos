#ifndef NOLSE_H
#define NOLSE_H

#include "NoAVL.h"

class NoLSE
{
	private:

		NoAVL* no;
		NoLSE* prox;

	public:

		NoLSE(NoAVL* no);
		~NoLSE();
		void insere(NoAVL* no);
		NoAVL* getNo();
		NoLSE* getProx();
};

#endif
