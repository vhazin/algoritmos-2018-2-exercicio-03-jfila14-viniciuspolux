#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
  int num;
  struct lista *prox;
}lista;

lista *fila, *final;

void incluir(int num)
{
  lista *novo, *aux;
  
  novo = (lista *)malloc(1 * sizeof(lista));
  
  novo->num = num;
  novo->prox = NULL;
  
  if(!fila){
      fila = novo;
      final = fila;
      return;
  }else{
        aux = final;
        if(aux != NULL){
            if(aux->num == num){
              printf("Número Já existe");
              return;
            }               
        }
        aux->prox = novo;
        final = aux->prox; 
        return;
  }   
  
}

void excluir(int num)
{
  lista *ultimo, *aux;
  ultimo = fila;
  aux = NULL;
  
  while((ultimo != NULL ) && (ultimo->num != num)){
      aux = ultimo;
      ultimo = ultimo->prox;
  }
  if(ultimo == NULL){
      printf("Esse número não existe\n");
      return;
  }else{
      if(aux == NULL){      
        aux = ultimo->prox;
        fila = aux;
        free(ultimo);       
        return;
      }else{
        aux->prox = ultimo->prox;         
        free(ultimo);
        return;             
      }   
  }      
}

void display(lista *ultimo)
{
  if(ultimo != NULL){
      printf("%d ", ultimo->num);
      if(ultimo->prox != NULL)      
        display(ultimo->prox);
  }
  return;
}

void ingresso(int N)
{
  int num;
  
  if(N < 2){
      scanf("%i", &num);
      if(num <= 100000){
        incluir(num);            
        return;
      }
      printf("Valor muito alto");
      exit(2);   
  }else{
      scanf("%i", &num);
      if(num <= 100000){
        incluir(num);
        N--;
        ingresso(N);
        return;
      }
      printf("Valor muito alto");
      exit(2);          
  } 
}

void remover(int N)
{
  int num;
  
  if(N < 2){
      scanf("%i", &num);
      if(num <= 100000){
        excluir(num);
        return;
      }
      printf("Valor muito alto");
      exit(2);   
  }else{
      scanf("%i", &num);
      if(num <= 100000){
        excluir(num);
        N--;
        remover(N);
        return;
      }
      printf("Valor muito alto ");
      exit(2);
  }
}

int main()
{
  int i, num, N, M;
  

  scanf("%i", &N);
  
  if(N <= 50000){
      ingresso(N);
  }else{
      printf("Valor muito alto");
      return 2;
  }
            
  
  
  scanf("%i", &M);     
  if(M <= N){
      
      remover(M);
  }else{
      printf("Valor muito alto");
      return 2;
  }
  
  N -= M;
  
  lista *ultimo;
  
  ultimo = fila;
  
  
  display(ultimo);
  printf("\n");
  
  free(fila);

  return 0;
}
