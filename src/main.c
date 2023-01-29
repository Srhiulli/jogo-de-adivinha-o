#include <stdio.h>

#define PONTOSINICIAIS 0
#define NUMEROSECRETO20 20

/*
lorem ipsum
*/
int pontos = PONTOSINICIAIS;
int acertou;

int pegar_chute_do_usuario(void)
{
  int chute;

  printf("********************************\n");
  printf("Qual o número inteiro de 0 até 25 você chuta?\n");
  scanf("%d", &chute);
  printf("Seu chute foi %d!\n", chute);
  printf(":D\n");

  return chute;
}

void iniciodojogo(void)
{
  printf("********************************\n");
  printf("Bem vindo ao jogo de adivinhação\n");
  printf("********************************\n");
  printf("Chute um número para acertar\n");
  printf("********************************\n");
  printf("Você tem até 15 tentativas, boa sorte\n");
  printf("********************************\n");
  printf("Contagem de pontos = 1000\n");
}

void somar_a_pontos(int valor)
{
  pontos = pontos + valor;
}

void jogo1(void)
{
  int tentativas = 1;
  while (tentativas <= 15)
  {
    // pegar_chute_do_usuario();
    int chute = pegar_chute_do_usuario();
    if (chute < 0)
    {
      printf("Você não pode chutar menores que zero, tente novamente\n");
      continue;
    }
    else if (chute > 25)
    {
      printf("Você pode chutar de 0 até 25, tente novamente\n");
      continue;
    }

    if (chute == NUMEROSECRETO20)
    {
      somar_a_pontos(chute);

      printf("Parabéns!! Você acertou\n");
      printf("***********************\n");
      printf("*** CONTAGEM DE PONTOS = %d ***\n", pontos);
      printf("Você acertou em %d tentativas\n", tentativas);
      break;
    }

    int maior = chute > NUMEROSECRETO20;
    int menor = chute < NUMEROSECRETO20;
    if (maior)
    {
      pontos = pontos - chute;
      printf("********************************\n");
      printf("Você ERROU,o número é MENOR!\n");
      printf("Número de tentativas %d\n", tentativas);
      printf("*** CONTAGEM DE PONTOS = %d ***\n", pontos);
    }
    else if (menor)
    {
      pontos = pontos - chute;
      printf("********************************\n");
      printf("Você ERROU,o numéro é MAAAIOR\n");
      printf("Número de tentativas %d\n", tentativas);
      printf("*** CONTAGEM DE PONTOS = %d ***\n", pontos);
    }

    tentativas++;
  }
}

int main(void)
{
  iniciodojogo();
  jogo1();
}