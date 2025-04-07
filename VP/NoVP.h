#ifndef NOVP_H
#define NOVP_H

enum COR {VERMELHO, PRETO};

class NoVP
{
	private:

		int valor;
		COR cor;
		NoVP* esq;
		NoVP* dir;
		NoVP* pai;

		void rotEsq();
		void rotDir();
		void corrigePai(NoVP* p);
		NoVP* corrigeInsercao();
		NoVP* corrigeRemocao(NoVP* velho, NoVP* novo);

	public:

		NoVP(NoVP* pai, int valor);
		~NoVP();
		int getValor();
		NoVP* getEsq();
		NoVP* getDir();
		COR getCor();
		void setValor(int valor);
		void setEsq(NoVP* no);
		void setDir(NoVP* no);
		void setCor(COR cor);
		void trocaCor(NoVP* no);
		NoVP* insere(int valor);
		NoVP* busca(int valor);
		NoVP* remove(int valor);
		void imprimeOrdemCrescente();
		void imprimeVisualizacao(int n);
};

#endif
