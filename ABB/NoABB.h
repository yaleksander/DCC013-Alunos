#ifndef NOABB_H
#define NOABB_H

class NoABB
{
	private:

		int valor;
		NoABB* esq;
		NoABB* dir;

	public:

		NoABB(int valor);
		~NoABB();
		int getValor();
		NoABB* getEsq();
		NoABB* getDir();
		void setValor(int valor);
		void setEsq(NoABB* no);
		void setDir(NoABB* no);
		void insere(int valor);
		NoABB* busca(int valor);
		void imprimeOrdemCrescente();
		void imprimeVisualizacao(int n);
		NoABB* remove(NoABB* no, int valor);
};

#endif
