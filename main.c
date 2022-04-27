#include "lib.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int moedaInicial;
  int moedaDeComparacao;
  int mes;
  int ano;
  int mesAno;
  int verifica, compara;
  float valorInicial, valorParaComparacao;
  char nomeMoedaInicial[20];
  char nomeMoedaDeComparacao[20];

  float *ptrDolar,
      valorDolar[36] = {3.9099, 3.7049, 3.7155, 3.8344, 3.8730, 4.0031,
                        3.8813, 3.7463, 4.0188, 4.0616, 4.1488, 4.1831,
                        4.0949, 4.1622, 4.3163, 4.7362, 5.2579, 5.8229,
                        5.1883, 5.3491, 5.3852, 5.2728, 5.6172, 5.4854,
                        5.0968, 5.2714, 5.3815, 5.6296, 5.6234, 5.2701,
                        5.0874, 5.1000, 5.2474, 5.2576, 5.4510, 5.4199};

  ptrDolar = valorDolar;

  /* float *ptrEuro,
       valorEuro[36] = {4.1708, 4.2650, 4.4013, 4.3964, 4.3850, 4.3760,
                        4.2236, 4.5526, 4.5282, 4.4797, 4.6664, 4.5053,
                        4.7500, 4.9318, 5.7402, 6.0097, 5.9220, 6.1390,
                        6.1523, 6.5545, 6.5752, 6.6907, 6.3599, 6.3428,
                        6.6293, 6.7597, 6.6046, 6.5337, 6.3780, 5.8903,
                        6.1870, 6.0797, 6.3033, 6.5172, 6.3753, 6.3323};*/

  float *valorEuro, *ptrEuro;

  valorEuro = criaVet(36);

  valorEuro[0] = 4.1708;
  valorEuro[1] = 4.2650;
  valorEuro[2] = 4.4013;
  valorEuro[3] = 4.3964;
  valorEuro[4] = 4.3850;
  valorEuro[5] = 4.3760;
  valorEuro[6] = 4.2236;
  valorEuro[7] = 4.5526;
  valorEuro[8] = 4.5282;
  valorEuro[9] = 4.4797;
  valorEuro[10] = 4.6664;
  valorEuro[11] = 4.5053;
  valorEuro[12] = 4.7500;
  valorEuro[13] = 4.9318;
  valorEuro[14] = 5.7402;
  valorEuro[15] = 6.0097;
  valorEuro[16] = 5.9220;
  valorEuro[17] = 6.1390;
  valorEuro[18] = 6.1523;
  valorEuro[19] = 6.5545;
  valorEuro[20] = 6.5752;
  valorEuro[21] = 6.6907;
  valorEuro[22] = 6.3599;
  valorEuro[23] = 6.3428;
  valorEuro[24] = 6.6293;
  valorEuro[25] = 6.7597;
  valorEuro[26] = 6.6046;
  valorEuro[27] = 6.5337;
  valorEuro[28] = 6.3780;
  valorEuro[29] = 5.8903;
  valorEuro[30] = 6.1870;
  valorEuro[31] = 6.0797;
  valorEuro[32] = 6.3033;
  valorEuro[33] = 6.5172;
  valorEuro[34] = 6.3753;
  valorEuro[35] = 6.3323;

  ptrEuro = valorEuro;

  float *ptrCAD,
      valorCAD[36] = {2.7767, 2.8482, 2.9396, 2.9286, 2.9018, 2.9398,
                      2.8909, 3.1117, 3.1376, 3.0520, 3.1903, 3.0946,
                      3.2349, 3.3380, 3.7007, 3.9330, 3.8743, 4.0254,
                      3.8936, 4.2086, 4.2126, 4.3124, 4.1002, 4.0775,
                      4.2739, 4.3935, 4.4830, 4.4225, 4.3239, 4.0076,
                      4.1785, 4.0808, 4.2918, 4.5494, 4.4005, 4.4076};

  ptrCAD = valorCAD;

  do {
    printf("Informe a moeda desejada:\n 1- Dolar\n 2- Euro\n 3- CAD\n\n");
    scanf("%d", &moedaInicial);
  } while (moedaInicial < 1 || moedaInicial > 3);

  do {
    printf("Informe o ano desejado:\n 2019\n 2020\n 2021 \n\n");
    scanf("%d", &ano);
  } while (ano < 2019 || ano > 2021);

  do {
    printf("Informe o numero do mes desejado...\n\n");
    scanf("%d", &mes);

  } while (mes < 1 || mes > 12);

  mesAno = selecionaAno(ano, mes);
  valorInicial = selecionaMoeda(mesAno, moedaInicial, valorDolar, valorEuro,
                                valorCAD, nomeMoedaInicial);

  printf("O valor do ");

  puts(nomeMoedaInicial);

  printf("eh R$%.3f\n\n", valorInicial);

  do {
    printf("Deseja comparar com alguma moeda?\n0 - Sim\n1 - Não\n");
    scanf("%d", &verifica);
  } while (verifica != 0 && verifica != 1);

  if (verifica == 0) {
    do {
      printf(
          "Com qual moeda voce quer comparar?\n 1- Dolar\n 2- Euro\n 3- CAD\n");
      scanf("%d", &moedaDeComparacao);
    } while (moedaDeComparacao < 1 || moedaDeComparacao > 3);

    do {
      printf("Informe o ano desejado:\n 2019\n 2020\n 2021 \n\n");
      scanf("%d", &ano);
    } while (ano < 2019 || ano > 2021);

    do {
      printf("Informe o mes desejado...\n\n");
      scanf("%d", &mes);
    } while (mes < 1 || mes > 12);

    mesAno = selecionaAno(ano, mes);
    valorParaComparacao =
        selecionaMoeda(mesAno, moedaDeComparacao, valorDolar, valorEuro,
                       valorCAD, nomeMoedaDeComparacao);
    comparaMoedas(valorInicial, valorParaComparacao, nomeMoedaInicial,
                  nomeMoedaDeComparacao);
  }

  float maiorDolar = maiorValor(ptrDolar);

  float maiorEuro = maiorValor(ptrEuro);

  float maiorCAD = maiorValor(ptrCAD);

  float menorDolar = menorValor(ptrDolar);

  float menorEuro = menorValor(ptrEuro);

  float menorCAD = menorValor(ptrCAD);

  float mediaDolar = mediaDosValores(ptrDolar);

  float mediaEuro = mediaDosValores(ptrEuro);

  float mediaCAD = mediaDosValores(ptrCAD);

  printf("O pico do Dolar em 36 meses foi R$%.3f\n\n", maiorDolar);

  printf("O pico do Euro em 36 meses foi R$%.3f\n\n", maiorEuro);

  printf("O pico do CAD em 36 meses foi R$%.3f\n\n", maiorCAD);

  printf("O valor mais baixo do Dolar em 36 meses foi R$%.3f\n\n", menorDolar);

  printf("O valor mais baixo do Euro em 36 meses foi R$%.3f\n\n", menorEuro);

  printf("O valor mais baixo do CAD em 36 meses foi R$%.3f\n\n", menorCAD);

  printf("A media do Dolar em 36 meses foi R$%.3f\n\n", mediaDolar);

  printf("A media do Euro em 36 meses foi R$%.3f\n\n", mediaEuro);

  printf("A media do CAD em 36 meses foi R$%.3f\n\n", mediaCAD);

  free(valorEuro);
}
