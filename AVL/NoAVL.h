#ifndef NOAVL_H
#define NOAVL_H

class NoAVL
{
	private:

		int valor;
		int altura;
		NoAVL* esq;
		NoAVL* dir;

	public:

		// funções presentes na ABB
		NoAVL(int valor);
		~NoAVL();
		int getValor();
		NoAVL* getEsq();
		NoAVL* getDir();
		void setValor(int valor);
		void setEsq(NoAVL* no);
		void setDir(NoAVL* no);
		NoAVL* busca(int valor);
		void imprimeOrdemCrescente();
		void imprimeVisualizacao(int n);

		// funções novas/atualizadas
		void atualizaAltura();
		int getFB();
		NoAVL* rotEsq(NoAVL* no);
		NoAVL* rotDir(NoAVL* no);
		NoAVL* corrige(NoAVL* no);
		NoAVL* insere(NoAVL* no, int valor);
		NoAVL* remove(NoAVL* no, int valor);
};

#endif
