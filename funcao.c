#include "funcao.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int selecionaAno(int ano, int mes) {
  switch (ano) {
  case 2019:
    mes -= 1;
    return mes;
    break;

  case 2020:
    mes += 11;
    return mes;
    break;

  case 2021:
    mes += 23;
    return mes;
    break;
  }
}

float selecionaMoeda(int mes, int moeda, float *Dolar, float *Euro, float *CAD,
                     char *nomeMoedaInicial) {

  switch (moeda) {

  case 1:
    strcpy(nomeMoedaInicial, "Dolar");
    return Dolar[mes];
    break;

  case 2:
    strcpy(nomeMoedaInicial, "Euro");
    return Euro[mes];
    break;

  case 3:
    strcpy(nomeMoedaInicial, "CAD");
    return CAD[mes];
    break;
  }
}

float comparaMoedas(float moedaInicial, float moedaDeComparacao,
                    char *nomeMoedaInicial, char *nomeMoedaDeComparacao) {
  float diferenca = moedaInicial - moedaDeComparacao;

  if (moedaInicial > moedaDeComparacao) {
    printf("O maior valor eh R$%.3f sendo da moeda ", moedaInicial);
    puts(nomeMoedaInicial);
    printf("e a diferença eh de %.3f\n\n", diferenca);
  } else if (moedaInicial < moedaDeComparacao) {
    printf("O maior valor eh R$%.3f sendo da moeda ", moedaDeComparacao);
    puts(nomeMoedaDeComparacao);
    printf("e diferença eh de %.3f\n\n", diferenca);
  }
}

float maiorValor(float *MaiorDado) {
  float maiorDado = MaiorDado[0];
  for (int i = 0; i <= 35; i++) {
    if (maiorDado < *(MaiorDado + i)) {
      maiorDado = *(MaiorDado + i);
    };
  };
  return maiorDado;
};

float menorValor(float *MenorDado) {
  float menorDado = MenorDado[0];
  for (int i = 0; i <= 35; i++) {
    if (menorDado > *(MenorDado + i)) {
      menorDado = *(MenorDado + i);
    };
  };
  return menorDado;
}

float mediaDosValores(float *MediaDados) {
  float soma = 0;
  float media = 0;
  for (int i = 0; i <= 35; i++) {
    soma = soma + *(MediaDados + i);
    media = soma / 35;
  };
  return media;
};

float * criaVet(float tamanho){
  float *vetor;

  vetor = (float *) malloc(tamanho*sizeof(float));

  if(vetor == NULL){
    printf("Erro no vetor 2");
  }
  return vetor;
}