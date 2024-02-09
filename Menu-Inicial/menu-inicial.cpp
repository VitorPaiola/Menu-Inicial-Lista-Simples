#include <iostream>
#include <string>
#include <new>
#include <locale.h>
#include <stdlib.h>

using namespace std;

struct pessoa {
	string nome;
	int rg;
};

static void limpaTela() {
	system("CLS");
}

static void imprimeSequencial(pessoa *ponteiroSequencial, int tamanhoDaLista) {
	int cont;
	for (cont = 0; cont < tamanhoDaLista; cont++) {
		cout << cont << "-" << ponteiroSequencial[cont].nome << "," << ponteiroSequencial[cont].rg << "\n";
	}
}

static void adcComecoSequencial(pessoa *&ponteiroSequencial, int *tamanhoDaLista, string nome, int rg) {

	// Se a lista for vazia cria uma lista nova
	if (*tamanhoDaLista == 0) {

		// Insere o primeiro novo elemento
		pessoa *novaListaSequencial = new pessoa[1];
		novaListaSequencial[0].nome = nome;
		novaListaSequencial[0].rg = rg;

		// Atualiza o ponteiro para a lista nova
		ponteiroSequencial = novaListaSequencial;
	} else {

		// Caso a lista já tenha membros
		pessoa *novaListaSequencial = new pessoa[*tamanhoDaLista + 1];

		// Insere o primeiro novo elemento
		novaListaSequencial[0].nome = nome;
		novaListaSequencial[0].rg = rg;

		// Passa os elementos do vetor antigo para o novo
		int cont;
		for (cont = 0; cont < *tamanhoDaLista; cont++) {
			novaListaSequencial[cont + 1].nome = ponteiroSequencial[cont].nome;
			novaListaSequencial[cont + 1].rg = ponteiroSequencial[cont].rg;
		}

		// Atualiza o ponteiro para a lista nova
		ponteiroSequencial = novaListaSequencial;

	}

	// Aumenta o tamanho da lista
	*tamanhoDaLista += 1;

}

static void adcFimSequencial(pessoa *&ponteiroSequencial, int *tamanhoDaLista, string nome, int rg) {

	// Cria uma lista com um tamanho maior
	pessoa* novaListaSequencial = new pessoa[*tamanhoDaLista + 1];

	// Passa os elementos do vetor antigo para o novo
	for (int cont = 0; cont < *tamanhoDaLista; cont++) {
		novaListaSequencial[cont].nome = ponteiroSequencial[cont].nome;
		novaListaSequencial[cont].rg = ponteiroSequencial[cont].rg;
	}

	// Posiciona o último elemento
	novaListaSequencial[*tamanhoDaLista].nome = nome;
	novaListaSequencial[*tamanhoDaLista].rg = rg;

	// Atualiza o ponteiro para a lista nova
	ponteiroSequencial = novaListaSequencial;

	// Atualiza o tamanho da lista
	*tamanhoDaLista += 1;

}

static void adcPosicaoSequencial(pessoa *&ponteiroSequencial, int *tamanhoDaLista, string nome, int rg, int posicao) {
	
	// Cria uma lista com um tamanho maior
	pessoa* novaListaSequencial = new pessoa[*tamanhoDaLista + 1];

	// Passa os elementos do vetor antigo para o novo
	int cont;
	for (cont = 0; cont < posicao; cont++) {
		novaListaSequencial[cont].nome = ponteiroSequencial[cont].nome;
		novaListaSequencial[cont].rg = ponteiroSequencial[cont].rg;
	}

	// Adiciona o novo registro na posição correta
	novaListaSequencial[posicao].nome = nome;
	novaListaSequencial[posicao].rg = rg;

	// Coloca o resto dos valores antigos
	for (cont = posicao + 1; cont < *tamanhoDaLista + 1; cont++) {
		novaListaSequencial[cont].nome = ponteiroSequencial[cont - 1].nome;
		novaListaSequencial[cont].rg = ponteiroSequencial[cont - 1].rg;
	}

	// Atualiza o ponteiro para a lista nova
	ponteiroSequencial = novaListaSequencial;

	// Aumenta o tamanho da lista
	*tamanhoDaLista += 1;

}

static void removeInicioSequencial(pessoa *&ponteiroSequencial, int *tamanhoDaLista) {

	// Cria um vetor com uma posição a menos
	pessoa* novaListaSequencial = new pessoa[*tamanhoDaLista - 1];

	// Passando elementos do vetor antigo para o novo
	int cont;
	for (cont = 1; cont < *tamanhoDaLista; cont++) {
		novaListaSequencial[cont - 1].nome = ponteiroSequencial[cont].nome;
		novaListaSequencial[cont - 1].rg = ponteiroSequencial[cont].rg;
	}

	// Atualiza o ponteiro para a lista nova
	ponteiroSequencial = novaListaSequencial;

	// Reduz o tamanho da lista
	*tamanhoDaLista -= 1;

}

static void removeFimSequencial(pessoa *&ponteiroSequencial, int *tamanhoDaLista) {

	// Cria um vetor com uma posição a menos
	pessoa* novaListaSequencial = new pessoa[*tamanhoDaLista - 1];

	// Passa os elementos do vetor antigo para o novo, menos o último
	int cont;
	for (cont = 0; cont < *tamanhoDaLista - 1; cont++) {
		novaListaSequencial[cont].nome = ponteiroSequencial[cont].nome;
		novaListaSequencial[cont].rg = ponteiroSequencial[cont].rg;
	}

	// Atualiza o ponteiro para a lista nova
	ponteiroSequencial = novaListaSequencial;

	// Reduz o tamanho da lista
	*tamanhoDaLista -= 1;

}

static void removePosicaoSequencial(pessoa *&ponteiroSequencial, int *tamanhoDaLista, int posicao) {

	// Cria um vetor com uma posição a menos
	pessoa* novaListaSequencial = new pessoa[*tamanhoDaLista - 1];

	// Passa os valores de acordo com o contador
	int cont;
	for (cont = 0; cont < *tamanhoDaLista - 1; cont++) {

		if (cont < posicao) {
			// Se estiver antes da posição, passa normalmente
			novaListaSequencial[cont].nome = ponteiroSequencial[cont].nome;
			novaListaSequencial[cont].rg = ponteiroSequencial[cont].rg;
		} else {
			// Se estiver antes da posição, passa normalmente
			novaListaSequencial[cont].nome = ponteiroSequencial[cont + 1].nome;
			novaListaSequencial[cont].rg = ponteiroSequencial[cont + 1].rg;
		}
	}

	// Atualiza o ponteiro para a lista nova
	ponteiroSequencial = novaListaSequencial;

	// Reduz o tamanho da lista
	*tamanhoDaLista - +1;

}

static string retornaNomeSequencial(pessoa *&ponteiroSequencial, int *tamanhoDaLista, int rg) {

	string nome = "Não encontrado";

	// Busca pelo nome com o rg digitado
	int cont;
	for (cont = 0; cont < *tamanhoDaLista; cont++) {
		if (ponteiroSequencial[cont].rg == rg) {
			nome = ponteiroSequencial[cont].nome;
		}
	}

	return nome;

}

int main() {
	setlocale(LC_ALL, "");

	// Variáveis
	int funcaoDesejada = 1;

	// Ponteiro para lista sequencial
	pessoa *ponteiroSequencial;

	// Tamanho da lista
	int tamanhoDaLista = 0;

	// EXEMPLO
	pessoa* exemploListaSequencial = new pessoa[1];

	// Dois registros de exemplos
	/* 
	exemploListaSequencial[0].nome = "John";
	exemploListaSequencial[0].rg = 123;
	exemploListaSequencial[1].nome = "Maicon";
	exemploListaSequencial[1].rg = 321; */

	// Faz o ponteiro principal apontar para o novo vetor
	ponteiroSequencial = exemploListaSequencial; 

	// Menu
	while (funcaoDesejada < 9 && funcaoDesejada > 0) {
		
		// Mostrando o menu
		cout << "Operações \n";
		cout << "1 - Inserção de um node no início da lista \n";
		cout << "2 - Inserção de um node no fim da lista \n";
		cout << "3 - Inserção de um node na posição N \n";
		cout << "4 - Retirar um node do início da lista \n";
		cout << "5 - Retirar um node no fim da lista \n";
		cout << "6 - Retirar um node na posição N \n";
		cout << "7 - Procurar um node com o campo RG \n";
		cout << "8 - Imprimir a Lista. \n";
		cout << "9 - Sair do sistema. \n";
		cout << "\nEscolha um número e pressione ENTER: ";

		// Lendo opção do usuário
		cin >> funcaoDesejada;

		limpaTela();

		// Variáveis usadas nas operações
		string nome;
		int rg, posicao;

		// Chama a função desejada
		switch (funcaoDesejada) {
		case 1:
			cout << "1 - Inserção de um node no início da lista \n";

			cout << "Digite um nome: ";
			cin >> nome;
			cout << "Digite um RG: ";
			cin >> rg;

			adcComecoSequencial(ponteiroSequencial, &tamanhoDaLista, nome, rg);

			break;
		case 2:
			cout << "Função escolhida: 2 - Inserção de um node no fim da lista \n";

			cout << "Digite um nome: ";
			cin >> nome;
			cout << "Digite um RG: ";
			cin >> rg;

			// Se a lista for vazia, usamos a função de criar no início
			if (tamanhoDaLista == 0) {
				adcComecoSequencial(ponteiroSequencial, &tamanhoDaLista, nome, rg);
			} else {
				adcFimSequencial(ponteiroSequencial, &tamanhoDaLista, nome, rg);
			}

			break;
		case 3:
			cout << "Função escolhida: 3 - Inserção de um node na posição N \n";

			cout << "Digite uma posição: ";
			cin >> posicao;
			cout << "Digite um nome: ";
			cin >> nome;
			cout << "Digite um RG: ";
			cin >> rg;

			if (posicao == 0) {
				// Se estiver adicionando no começo
				adcComecoSequencial(ponteiroSequencial, &tamanhoDaLista, nome, rg);
			} else if (posicao == tamanhoDaLista) {
				// Quando quer adicionar no fim
				adcFimSequencial(ponteiroSequencial, &tamanhoDaLista, nome, rg);
			} else {
				// Adiciona numa posição especifica
				adcPosicaoSequencial(ponteiroSequencial, &tamanhoDaLista, nome, rg, posicao);
			}

			break;
		case 4:
			cout << "Função escolhida: 4 - Retirar um node do início da lista \n";
			
			// Se a lista for vazia
			if (tamanhoDaLista == 0) {
				cout << "Lista vazia \n";
			} else {
				removeInicioSequencial(ponteiroSequencial, &tamanhoDaLista);
			}

			break;
		case 5:
			cout << "Função escolhida: 4 - Retirar um node no fim da lista \n";

			// Se a lista for vazia
			if (tamanhoDaLista == 0) {
				cout << "Lista vazia \n";
			} else {
				removeFimSequencial(ponteiroSequencial, &tamanhoDaLista);
			}

			break;
		case 6:
			cout << "Função escolhida: 6 - Retirar um node na posição N \n";

			// Se a lista for vazia
			if (tamanhoDaLista == 0) {
				cout << "Lista vazia \n";
			} else {
				cout << "Digite uma posição: ";
				cin >> posicao;

				if (posicao == 0) {
					removeInicioSequencial(ponteiroSequencial, &tamanhoDaLista);
				}else if (posicao == tamanhoDaLista - 1) {
					removeFimSequencial(ponteiroSequencial, &tamanhoDaLista);
				} else {
					removePosicaoSequencial(ponteiroSequencial, &tamanhoDaLista, posicao);
				}

			}

			break;
		case 7:
			cout << "Função escolhida: 7 - Procurar um node com o campo RG \n";

			// Se a lista for vazia
			if (tamanhoDaLista == 0) {
				cout << "Lista vazia \n";
			} else {
				cout << "Digite um rg: ";
				cin >> rg;

				cout << "Nome: " << retornaNomeSequencial(ponteiroSequencial, &tamanhoDaLista, rg) << "\n";

			}

			break;
		case 8:
			cout << "Função escolhida: 8 - Imprimir a Lista. \n";

			// Imprime a lista completa
			imprimeSequencial(ponteiroSequencial, tamanhoDaLista);

			break;

		}

	}

	return 0;
}