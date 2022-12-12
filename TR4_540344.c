#include <stdio.h>
#include <stdlib.h>
#include "ordvetor.h"

VETORORD * VETORD_create(int n, COMP * compara) {
   VETORORD * vetor = malloc(sizeof(VETORORD)); // armazena o espaço de um vetor de tamanho VETORORD
   vetor -> N = n; // inserindo o tamanho do vetor passado por parâmetro
   vetor -> P = 0; // zerando o número de elementos no vetor
   vetor -> elems = malloc(n * sizeof(void*)); // criando um vetor de elementos tipo void
   for (int i = 0; i < n; i++){ // percorrendo o vetor, deixando suas posições em valor NULL
        vetor -> elems [i] = NULL;
    } 
    vetor -> comparador = compara; // O ponteiro comparador recebe o valor por parâmetro
    return vetor; // retorna o vetor criado
}

void VETORD_add(VETORORD* vetor, void* newelem){
    if( vetor -> P < vetor -> N){ //  verifica se o número de elementos do vetor é menor que o tamanho dele
        if(vetor -> P == 0){ // se o número de elementos for igual a zero
           vetor -> elems [0] = newelem; // o vetor recebe um novo elemento
        }
        else{ // Caso haja um elemento existente checamos em qual posição do nosso vetor o newelem deve ser adicionado  
            int i; // variável utilizada para iterar os valores no vetor
            int p = vetor->P; // recebe o número de elementos do vetor
            vetor -> elems[p] = newelem; // 
            for(i = p; i > 0; i++){
                if(vetor->comparador(vetor->elems[i-1], vetor->elems[i]) == -1){
                    void* aux = vetor->elems[i-1];
                    vetor->elems[i-1] = vetor->elems[i];
                    vetor->elems[i] = aux;
                }else break;
            }
        }
        vetor -> P++;
        }
}

void* VETORD_remove(VETORORD* vetor){
   void * lixo = vetor -> elems[0];
   for(int i = 0; i < vetor -> P; i++){
      vetor -> elems[i] = vetor -> elems [i+1];

   }
   vetor -> P--;
   return lixo;
} 





























