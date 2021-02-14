#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "tabuleiro.h"

void limparTabuleiro(int tabuleiro[][DIMENSAO]) {
	for (int i = 0; i < DIMENSAO; i++) {
		for (int j = 0; j < DIMENSAO; j++)
			tabuleiro[i][j] = 0;
	}
}

void desenharTabuleiro(int tabuleiro[][3]) {
	system("cls||clear");

	printf("\n======= JOGO DA VELHA - VERSAO %s =======\n\n", VERSAO);

	int valor;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			valor = tabuleiro[i][j];

			if (valor == 0)
				printf("   ");
			else if (valor == 1)
				printf(" X ");
			else
				printf(" O ");

			if (j < 2)
				printf("|");
		}

		if (i < 2)
			printf("\n___|___|___\n");
	}
	printf("\n\n");
}


bool marcarTabuleiro(int tabuleiro[][DIMENSAO], int i, int j, int c) {
	if (i < 1 || i > DIMENSAO || j < 1 || j > DIMENSAO)
		return false;

	if (tabuleiro[i - 1][j - 1] == 0) {
		tabuleiro[i - 1][j - 1] = c;
		return true;
	}

	return false;
}


bool verificarVencedor(int tabuleiro[][DIMENSAO]) {
	int soma;

	/*Verificar linhas*/
	for (int i = 0; i < DIMENSAO; i++) {
		soma = tabuleiro[i][0] + tabuleiro[i][1] + tabuleiro[i][2];
		if (soma == 3 || soma == -3)
			return true;
	}

	/*Verificar colunas*/
	for (int j = 0; j < DIMENSAO; j++) {
		soma = tabuleiro[0][j] + tabuleiro[1][j] + tabuleiro[2][j];
		if (soma == 3 || soma == -3)
			return true;
	}

	/*Verificar diagonal principal*/
	soma = tabuleiro[0][0] + tabuleiro[1][1] + tabuleiro[2][2];
	if (soma == 3 || soma == -3)
		return true;

	/*Verificar diagonal secundaria*/
	soma = tabuleiro[0][2] + tabuleiro[1][1] + tabuleiro[2][0];
	if (soma == 3 || soma == -3)
		return true;

	return false;
}
