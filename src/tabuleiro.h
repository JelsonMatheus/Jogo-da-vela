#ifndef TABULEIRO_H
#define TABULEIRO_H

#define DIMENSAO 3
#define VERSAO "1.0"

void limparTabuleiro(int tabuleiro[][DIMENSAO]);
void desenharTabuleiro(int tabuleiro[][DIMENSAO]);
bool verificarVencedor(int tabuleiro[][DIMENSAO]);
bool marcarTabuleiro(int tabuleiro[][DIMENSAO], int i, int j, int c);

#endif
