#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define TAM 40
char tabela[9][TAM];
char player1[2][TAM],player2[2][TAM];
int posicao,comeca,term=0;

int add(char simbolo[1]);
int verif(char simVen[TAM]);
void erro();
void tratarErro(int num, char simbolo[1]);

int main(void) {
  srand(time(NULL));
  int num = rand() % 2;
  int venceu = 0;
 

  for(int i=0;i<9;i++){
    strcpy(tabela[i]," ");
  }


  printf("\n----Jogo da Velha----\n\n");

  printf("Qual o nome do primeiro jogador\n>> ");
  scanf(" %39[^\n]s",player1[0]);
  fflush(stdin);

  printf("Qual o nome do segundo jogador\n>> ");
  scanf(" %39[^\n]s",player2[0]);
  fflush(stdin);

  printf("%s %s\n",player1[0],player2[0]);

  strcpy(player1[1],"o");
  strcpy(player2[1],"o");
  system("clear");
  if(num == 0){
    printf("%s joga primeiro\n",player1[0]);
    strcpy(player1[1],"x");
    comeca = 0;
    
  }else {
    printf("%s joga primeiro\n",player2);
    strcpy(player2[1],"x");
    comeca = 1;
  }
  system("sleep 2");

  do{
    system("clear");
      if(strcmp(tabela[0],"x") == 0 && strcmp(tabela[4],"x")==0 && strcmp(tabela[8],"x")==0 || strcmp(tabela[0],"o")==0&&strcmp(tabela[4],"o")==0&&strcmp(tabela[8],"o")==0  ){
          if(strcmp(tabela[0],"x") ==0){
            verif("x");
          }else {
            verif("o");
          }
      break; 
    }else if(strcmp(tabela[2],"x")==0&&strcmp(tabela[4],"x")==0&&strcmp(tabela[6],"x")==0 || strcmp(tabela[2],"o")==0&&strcmp(tabela[4],"o")==0&&strcmp(tabela[6],"o")==0){
          if(strcmp(tabela[2],"x") ==0){
            verif("x");
          }else {
            verif("o");
          }
          break;
    }else if(strcmp(tabela[0],"x")==0&&strcmp(tabela[1],"x")==0&&strcmp(tabela[2],"x")==0 || strcmp(tabela[0],"o")==0&&strcmp(tabela[1],"o")==0&&strcmp(tabela[2],"o")==0){
          if(strcmp(tabela[0],"x") ==0){
            verif("x");
          }else {
            verif("o");
          }
          break;
    }else if(strcmp(tabela[3],"x")==0&&strcmp(tabela[4],"x")==0&&strcmp(tabela[5],"x")==0 || strcmp(tabela[3],"o")==0&&strcmp(tabela[4],"o")==0&&strcmp(tabela[5],"o")==0) {
          if(strcmp(tabela[3],"x")==0){
            verif("x");
          }else {
            verif("o");
          }
          break;
    }else if(strcmp(tabela[6],"x")==0&&strcmp(tabela[7],"x")==0&&strcmp(tabela[8],"x")==0 || strcmp(tabela[6],"o")==0&&strcmp(tabela[7],"o")==0&&strcmp(tabela[8],"o")==0){
          if(strcmp(tabela[6],"x")==0){
            verif("x");
          }else {
            verif("o");
          }
          break;
    }else if(strcmp(tabela[0],"x")==0&&strcmp(tabela[3],"x")==0&&strcmp(tabela[6],"x")==0 || strcmp(tabela[0],"o")==0&&strcmp(tabela[3],"o")==0&&strcmp(tabela[6],"o")==0){
          if(strcmp(tabela[0],"x")==0){
            verif("x");
          }else {
            verif("o");
          }
          break;
    }else if(strcmp(tabela[1],"x")==0&&strcmp(tabela[4],"x")==0&&strcmp(tabela[7],"x")==0 || strcmp(tabela[1],"o")==0&&strcmp(tabela[4],"o")==0&&strcmp(tabela[7],"o")==0){
          if(strcmp(tabela[1],"x")==0){
            verif("x");
          }else {
            verif("o");
          }
          break;
    }else if(strcmp(tabela[2],"x")==0&&strcmp(tabela[5],"x")==0&&strcmp(tabela[8],"x")==0 || strcmp(tabela[2],"o")==0&&strcmp(tabela[5],"o")==0&&strcmp(tabela[8],"o")==0){
          if(strcmp(tabela[2],"x")==0){
            verif("x");
          }else {
            verif("o");
          }
          break;
    }else {
      term++;
      if(term > 9) {
        printf("Deu velha!!!\n");
        printf("   1    2   3 \n1  %s | %s | %s  \n  ---|---|---\n2  %s | %s | %s \n  ---|---|---\n3  %s | %s | %s \n",tabela[0],tabela[1],tabela[2],tabela[3],tabela[4],tabela[5],tabela[6],tabela[7],tabela[8]);
        break;
      }
    }
    
    if(comeca == 0){
      printf("   1    2   3 \n1  %s | %s | %s  \n  ---|---|---\n2  %s | %s | %s \n  ---|---|---\n3  %s | %s | %s \n",tabela[0],tabela[1],tabela[2],tabela[3],tabela[4],tabela[5],tabela[6],tabela[7],tabela[8]);
      printf("x: Vez do jogador %s: ",player1[0]);
      scanf("%d",&posicao);
      fflush(stdin);
      comeca = 1;
      add("x");
    }else { 
      printf("   1    2   3 \n1  %s | %s | %s  \n  ---|---|---\n2  %s | %s | %s \n  ---|---|---\n3  %s | %s | %s \n",tabela[0],tabela[1],tabela[2],tabela[3],tabela[4],tabela[5],tabela[6],tabela[7],tabela[8]);
      printf("o: Vez do jogador %s: ",player2[0]);
      scanf("%d",&posicao);
      fflush(stdin);
      comeca = 0;
      add("o");
    }

  }while(true);


} 

int add(char simbolo[1]) {
  switch(posicao) {
    case 11:
      tratarErro(0,simbolo);
    break;
    case 12:
      tratarErro(1,simbolo);
    break;
    case 13:
      tratarErro(2,simbolo);
    break;
    case 21:
      tratarErro(3,simbolo);
    break;
    case 22:
      tratarErro(4,simbolo);
    break;
    case 23:
      tratarErro(5,simbolo);
    break;
    case 31:
      tratarErro(6,simbolo);
    break;
    case 32:
      tratarErro(7,simbolo);
    break;
    case 33:
      tratarErro(8,simbolo);
    break;
    default:
      printf("Valor invalido\n");
      system("sleep 2");
      erro();
    break;
  }
  return 0;
}

void erro() {
  if(comeca == 1){
    comeca = 0;
    term--;
  }else {
    comeca = 1;
    term--;
  }
}

void tratarErro(int num, char simbolo[1]) {
    if(strcmp(tabela[num]," ") == 0)
        strcpy(tabela[num],simbolo);
      else{
        printf("Ai ja foi marcado.\n");
        system("sleep 1"); 
        erro();
      }
}


int verif(char simbVen[TAM]){
        if(strcmp(player1[1],simbVen)==0) {
          printf("%s venceu\n",player1[0]);
        }else {
          printf("%s venceu\n",player2[0]);
        }

        printf("   1    2   3 \n1  %s | %s | %s  \n  ---|---|---\n2  %s | %s | %s \n  ---|---|---\n3  %s | %s | %s \n",tabela[0],tabela[1],tabela[2],tabela[3],tabela[4],tabela[5],tabela[6],tabela[7],tabela[8]);
}

