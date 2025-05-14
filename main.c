// Integrantes do grupo
// Giovanni Marcarini Silveira | 202410131 | giovanni.202410131@unilasalle.edu.br
// Arthur Contri Gasperin | 202410137 | arthur.202410137@unilasalle.edu.br
// Rafael Decarli Vargas | 202411103 | rafael.202411103@unilasalle.edu.br


#include <stdio.h>
#include <stdlib.h>

struct ALUNO {
  int matricula;
  double g1, g2, media;

};

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
    
  }
  
  return 200;
  
};

int main(){
  int qnt;
  struct ALUNO *alunos;

  printf("Quantos\n");
  scanf("%i", &qnt);

  alunos = malloc(qnt*sizeof(struct ALUNO));
  if (alunos == NULL) {
    //erro nao alocou
    return 10;
  }

  preenchendo_alunos(alunos, qnt);

  free(alunos);
}
