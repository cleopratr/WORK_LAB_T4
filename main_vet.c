#include <stdio.h>
#include <stdlib.h>
#include "ordvetor.h"
#include "TR4_540344.c"

//Função de comparação
int comparador(void* x, void* y){
	int ptx = *((int*)x);
	int pty = *((int*)y);
	if(ptx > pty){
		return -1;
	}else{
		if(ptx == pty) return 0;
		else return 1;
	}
}

//Print para a estrutura
void print(void** vetor, int P){
	int i;
	printf("VETOR DE %d TAMANHO:\n", P);
	for(i = 0; i < P; i++){
		printf(" %d ", *((int*)vetor[i]));
	}
	printf("\n");
}

int main(){
   	VETORORD* vetor = VETORD_create(10, comparador);
   	
   	int* x;
   	int i;
	int P = 8;

   	
   	printf("INCLUINDO... \n");
	for(i = 0; i < P; i++){
		x = malloc(sizeof(int));
		*x = i*10;
		VETORD_add(vetor, x);
	}
	
	print(vetor->elems, vetor->P);
  
  	printf("REMOVENDO!");
  	VETORD_remove(vetor);
  	
	print(vetor->elems, vetor->P);
   
	return 0;  
}
