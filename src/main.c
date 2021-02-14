#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "tabuleiro.h"

// *************** Protótipos de Funções****************
int mostrarMenu();
void jogar(int tabuleiro[][DIMENSAO]);
void terminarJogo(int vencedor);
void realizarJogada(int jogador, int tabuleiro[][DIMENSAO]);


int main(void) {
	int tabuleiro[DIMENSAO][DIMENSAO];
	int opcao;

	do {
		opcao = mostrarMenu();
		if (opcao == 1)
			jogar(tabuleiro);

	} while (opcao != 2);

	return 0;
}


int mostrarMenu() {
	int opcao;

	system("cls||clear");

	printf("\n======= JOGO DA VELHA - VERSAO %s =======\n", VERSAO);
	printf("@autor: Jelson Matheus\n\n");

	printf("MENU:\n");
	printf("> 1 - Jogar\n");
	printf("> 2 - Sair\n");
	printf("# Escolha: ");

	scanf("%d", &opcao);

	if (opcao < 1 || opcao > 2)
		mostrarMenu();

	return opcao;
}


void jogar(int tabuleiro[][DIMENSAO]) {
	int jogador = 0;
	int totalJogadas = 0;
	bool vencedor = false;

	limparTabuleiro(tabuleiro);
	desenharTabuleiro(tabuleiro);

	do {
		jogador = (jogador == 1) ? 2 : 1;
		realizarJogada(jogador, tabuleiro);
		desenharTabuleiro(tabuleiro);
		vencedor = verificarVencedor(tabuleiro);

		totalJogadas++;

	} while (!vencedor && totalJogadas < 9);

	if (vencedor)
		terminarJogo(jogador);
	else
		terminarJogo(0);
}


void terminarJogo(int vencedor) {
	switch (vencedor) {
	    case 1:
	    case 2:
		    printf("\nJOGO ENCERRADO! - JOGADOR %d VENCEU.\n", vencedor);
		    break;
	    default:
		    printf("\nJOGO ENCERRADO! - EMPATE.\n");
		    break;
	}

	printf("@ Pressione qualquer tecla para continuar.");
	getchar();
}


void realizarJogada(int jogador, int tabuleiro[][DIMENSAO]) {
	int linha, coluna, valor;
	bool check;
	valor = (jogador == 1) ? 1 : -1;

	do {
		printf(">Jogador %d: \n", jogador);

		printf("\t#Linha: ");
		scanf("%d", &linha);

		printf("\t#Coluna: ");
		scanf("%d%*c", &coluna);

		check = marcarTabuleiro(tabuleiro, linha, coluna, valor);

		if (check == false)
			printf("\t@ERRO! Posição invalida ou ja preenchida.\n");

	} while (!check);
}
