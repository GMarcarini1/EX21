// Integrantes do grupo
// Giovanni Marcarini Silveira | 202410131 | giovanni.202410131@unilasalle.edu.br
// Arthur Contri Gasperin | 202410137 | arthur.202410137@unilasalle.edu.br
// Rafael Decarli Vargas | 202411103 | rafael.202411103@unilasalle.edu.br


#include <stdio.h>
#include <stdlib.h>
#define TAM 100

struct ALUNO {
  int matricula;
  double g1, g2, media;

};

int pilha[TAM], topo;

void inicia() {
  topo = -1
}

int empty(){
  if (topo == -1){
    return 1;
  }
  else{
    return 0;
  }
}

int full(){
  if (topo == (TAM -1))
  {
    return 1;
  }
  return 0;
}

void pop(){
  int vazio;
  vazio = empty();
  if(vazio == 1){
    printf("============================");
    printf("\nEscola sem alunos.\n");
  } 
  topo --;
}

void push(int matricula) {
  int retorno;
  retorno = full();
   if (retorno == 1){
     printf("\nA escola está cheia, não pode mais aceitar alunos.\n");
   }
   else{
     topo++;
      pilha[topo] = matricula;
   } 
  }

  void imp()
  {
    int i;
    printf("\n============ PILHA ============ \n");
    for (i = 0 ; i <= topo; i++){
      printf("%d\n", pilha[i]);
    }
  }

int preenchendo_alunos(struct ALUNO *alunos, int qnt){
  
  int i;
  
  for (i=0; i< qnt; i++) {
    printf("======== ALUNO %d ========\n", i+1);

    printf("Matrícula: ");
    scanf("%d", &alunos[i].matricula);

    printf("Nota G1: ");
    scanf("%lf", &alunos[i].g1);

    printf("Nota G2: ");
    scanf("%lf", &alunos[i].g2);

    alunos[i].media = (alunos[i].g1 + alunos[i].g2) / 2.0;
    
    push(alunos[i].matricula);
  }
  
  return 0;
  
};

int main(){
  int qnt;
  struct ALUNO *alunos;
  int escolha;
  inicia();

  do{
    printf("=======tela de comandos========\n");
    printf("caso queira adicionar alunos a pilha Digite (1).\n");
    printf("caso queira remover alunos da pilha Digite (2).\n");
    printf("caso queira sair Digite (3).\n");
    printf("===============================\n");
  
    printf("O que você deseja fazer? ");
    scanf("%i", &escolha);

    if(escolha == 1 ){  
    printf("Quantos\n");
    scanf("%i", &qnt);

    alunos = malloc(qnt*sizeof(struct ALUNO));
    if (alunos == NULL) {
      //erro nao alocou
      return 10;
    }
    preenchendo_alunos(alunos, qnt);
    imp();
    free(alunos);
    }
    else if(escolha == 2){
      pop();
      imp();
    }
    else if(escolha == 3){
      printf("Removendo todos os alunos.\n");
      do{
        pop();
      } while(topo != -1);
      imp();
      
      printf("Programa encerrando com sucesso.\n");
      printf("===============================\n");
    }
    else{
      printf("Comando inválido, digite novamente.\n");
    }
  } while(escolha != 3);
}
