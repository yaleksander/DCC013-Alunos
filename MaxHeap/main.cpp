#include <iostream>
#include <string>
#include "MaxHeap.h"

using namespace std;

int lerNumero()
{
	string s;
	getline(cin, s);
	int x = 0;
	int n = s.length();
	if (n == 0 || n > 6) // tamanho máximo arbitrário
		return -100000; // a flag precisa estar fora do escopo de números aceitáveis
	for (int i = ((s[0] == '-') ? 1 : 0); i < n; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
			x = x * 10 + s[i] - '0';
		else
			return -100000;
	}
	if (s[0] == '-')
		x *= -1;
	return x;
}

int filtrarEntrada()
{
	int n = lerNumero();
	while (n == -100000)
	{
		cout << "Numero invalido. Tente novamente: ";
		n = lerNumero();
	}
	return n;
}

int main()
{
	int a[] = {20, 13, 30, 11, 15, 25, 33, 10, 12, 14, 18};
	MaxHeap* heap = new MaxHeap();
	for (int i = 0; i < 11; i++)
		heap->insere(a[i]);
	int op = 0;
	char str[10];
	vector<int> v;
	while (true)
	{
		cout << "\033[2J\033[1;1H";
		cout << "Selecione uma operacao:" << endl;
		cout << " 1: Inserir valor" << endl;
		cout << " 2: Olhar raiz" << endl;
		cout << " 3: Remover raiz" << endl;
		cout << " 4: Imprimir em forma de lista" << endl;
		cout << " 5: Imprimir em forma de arvore" << endl;
		cout << " 6: Aplicar heapsort" << endl;
		cout << " 7: Encerrar o programa" << endl;
		cout << endl << "Digite o numero correspondente: ";
		op = lerNumero();
		while (op < 1 || op > 7)
		{
			cout << "Operacao invalida. Tente novamente: ";
			op = lerNumero();
		}
		switch (op)
		{
			case 1:
				cout << "Digite o valor a ser inserido (numero inteiro): ";
				heap->insere(filtrarEntrada());
				cout << "Insercao realizada com sucesso. Pressione ENTER para continuar.";
				lerNumero();
				break;

			case 2:
				cout << endl;
				cout << "A raiz tem valor " << heap->getRaiz() << ". Pressione ENTER para continuar.";
				lerNumero();
				break;

			case 3:
				heap->remove();
				cout << "No removido com sucesso. Pressione ENTER para continuar.";
				lerNumero();
				break;

			case 4:
				cout << endl;
				heap->imprimeLista();
				cout << endl << "Pressione ENTER para continuar.";
				lerNumero();
				break;

			case 5:
				cout << endl;
				heap->imprimeArvore();
				cout << endl << "Pressione ENTER para continuar.";
				lerNumero();
				break;

			case 6:
				cout << endl;
				v = heap->heapsort();
				for (int i = 0; i < v.size(); i++)
					cout << v[i] << ", ";
				cout << "\b\b  " << endl << endl << "Pressione ENTER para continuar.";
				lerNumero();
				break;

			default:
				break;
		}
		if (op == 7)
			break;
	}
	return 0;
}
