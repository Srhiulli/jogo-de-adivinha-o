#include <stdio.h>

#define PONTOS_INICIAIS 1000
#define NUMERO_SECRETO 20
#define MAX_GAME_LOOPS 15

int getUserTry(void) {
  int userInput;
  printf("Qual o número inteiro de 0 até 25 você chuta?\n");
  scanf("%d", &userInput);

  return userInput;
}

void printGameBanner(void) {
  printf("********************************\n");
  printf("Bem vindo ao jogo de adivinhação\n");
  printf("********************************\n");
  printf("Chute um número para acertar\n");
  printf("********************************\n");
  printf("Você tem até 15 tentativas, boa sorte\n");
  printf("********************************\n");
  printf("Contagem de pontos = 1000\n");
}

int isValidUserTry(int userTry) {
  if (userTry < 0) {
    printf("Você não pode chutar menores que zero, tente novamente\n");
    return 0;
  } else if (userTry > 25) {
    printf("Você pode chutar de 0 até 25, tente novamente\n");
    return 0;
  }
  
  return 1;
}

void startGame(void) {
  int pontos = PONTOS_INICIAIS;
  int gameLoops = 1;

  while (gameLoops <= MAX_GAME_LOOPS) {

    int userTry = getUserTry();

    int isValidInput = isValidUserTry(userTry);
    if (isValidInput == 0) {
      continue;
    }

    
    //compararEntradaDoUsuarioComOValorSecreto(int userTry);
    if (acertou) {
      acertou();
      break;
    }

    // giveAHint(int userTry);
    int maior = chute > NUMERO_SECRETO;
    int menor = chute < NUMERO_SECRETO;
    if (maior) {
      pontos = pontos - chute;
      printf("********************************\n");
      printf("Você ERROU,o número é MENOR!\n");
      printf("Número de gameLoops %d\n", gameLoops);
      printf("*** CONTAGEM DE PONTOS = %d ***\n", pontos);
    } else if (menor) {
      pontos = pontos - chute;
      printf("********************************\n");
      printf("Você ERROU,o numéro é MAAAIOR\n");
      printf("Número de gameLoops %d\n", gameLoops);
      printf("*** CONTAGEM DE PONTOS = %d ***\n", pontos);
    }
    
    gameLoops++;
  }
}

int main(void) {
  printGameBanner();
  startGame();
}