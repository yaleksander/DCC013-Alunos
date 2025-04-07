#ifndef NOLSE_H
#define NOLSE_H

#include "NoVP.h"

class NoLSE
{
	private:

		NoVP* no;
		NoLSE* prox;

	public:

		NoLSE(NoVP* no);
		~NoLSE();
		void insere(NoVP* no);
		NoVP* getNo();
		NoLSE* getProx();
};

#endif
