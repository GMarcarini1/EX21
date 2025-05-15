// Integrantes do grupo

// Arthur Contri | 202410137 | arthur.202410137@unilasalle.edu.br
// Responsável pela lapidação do código bruto, implementação da função de pesquisa e correção de bugs

// Giovanni Marcarini | 202410131 | giovanni.202410131@unilasalle.edu.br 
// Responsavel pela contrução das Funções POP, PUSH, EMPTY

// Rafael Decarli | 202411103 | rafael.202411103@unilasalle.edu.br
// Responsavel pelo inicio do código e contrução da lógica de programação

#include <stdio.h>
#include <stdlib.h>

typedef struct{
  //Estrutura do armazenamento de dados dos alunos

  int matricula;
  double g1, g2, media;

} ALUNO;

typedef struct{
  // Estrutura da Pilha

  ALUNO *q;
  int topo;
  int qntmax;
} PILHA;

int inicia(PILHA *p, int qnt) {
  // Função para inicializar a pilha, armazena a quantidade máxima da pilha, e reseta o topo

  p->topo = -1;
  p->qntmax = qnt;
  return 0;
}

int verifica_vazia(PILHA *p){
  //Verifica se a pilha esta vazia comparando o topo com o valor inicial -1
  return (p->topo == -1);
}

int verifica_cheia(PILHA *p){
  // Verifica se a pilha esta cheia comparando o topo com o valor de qntmax
  return (p->topo == p->qntmax-1);
}

int push(PILHA *p, ALUNO novo){
  //Verifica se a pilha está cheia e depois adiciona o aluno no topo da pilha
  if (verifica_cheia(p)){
    //erro pilha cheia
    return 1;
  }

  p->topo++;
  p->q[p->topo] = novo;

  return 0;
}

int pop(PILHA *p){
  //Verifica se a pilha está vazia e depois remove o aluno no topo da pilha
  if(verifica_vazia(p)){
    return 1;
  }

  p->topo--;
  return 0;
}

int main(){
  int qnt, i, pesquisa;
  PILHA *p;
  char letra;

  printf("Olá!\n");
  printf("Quantos alunos deseja adicionar?");
  scanf("%d", &qnt);

  p = malloc(sizeof(PILHA));
  if (p == NULL) {
    //erro não alocou
    return 1;
  }

  p->q= malloc(qnt*sizeof(ALUNO));
  if (p->q == NULL) {
    //erro não alocou
    return 1;
  }

  //Iniciza a pilha
  inicia(p, qnt);

  //Cadastro de Alunos
  printf("CADASTRANDO ALUNOS\n");

  for (i=0; i<qnt; i++){
    ALUNO novo;

    printf("ALUNO %d de %d\n", i+1, qnt);

    printf("Matrícula:");
    scanf("%d", &novo.matricula);

    printf("Nota G1:");
    scanf("%lf", &novo.g1);

    printf("Nota G2:");
    scanf("%lf", &novo.g2);

    novo.media = (novo.g1 + novo.g2)/2;

    push(p, novo);
    printf("Aluno %d Adicionado com sucesso!\n", novo.matricula);

    printf("Você deseja remover o último aluno adicionado? (s/n)");
    scanf(" %c", &letra);

    if (letra == 's'){
      pop(p);
      i--;

    }

  }

  printf("Os alunos abaixo foram adicionados com sucesso\n");
  for(i=0; i<qnt; i++){
    printf("%d\n", p->q[i].matricula);
  }

  printf("Digite o numero de matricula a pesquisar:");
  scanf("%d", &pesquisa);

  while (pesquisa != 0){
    for(i=p->topo; i >= 0; i--){
      if(pesquisa == p->q[i].matricula) {
        printf("Matrícula: %d\n", p->q[i].matricula);
        printf("Nota G1: %.2lf\n", p->q[i].g1);
        printf("Nota G2: %.2lf\n", p->q[i].g2);
        printf("Média Final: %.2lf\n", p->q[i].media);
      }
    }

    printf("Digite a matrícula a pesquisa (Digite 0 para sair):");
    scanf("%d", &pesquisa);

  }

  printf("Encerrando o Programa...");

  free(p->q);
  free(p);

}
