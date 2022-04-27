#ifndef FUNCAO_H_INCLUDED
#define FUNCAO_H_INCLUDED

float selecionaMoeda(int mes, int moeda, float *Dolar, float *Euro, float *CAD,
                     char *nomeMoeda);

int selecionaAno(int ano, int mes);

float comparaMoedas(float moedaInicial, float moedaDeComparacao,
                    char *nomeMoedaInicial, char *nomeMoedaDeComparacao);

float maiorValor(float *dados);

float menorValor(float *MenorDado);

float mediaDosValores(float *MediaDados);

float * criaVet(float tamanho);

#endif