#include <stdio.h>
#include <stdlib.h>
#include "ordvetor.h"

VETORORD * VETORD_create(int n, COMP * compara) {
   VETORORD * vetor = malloc(sizeof(VETORORD));
   vetor -> N = n;
   vetor -> P = 0;
   vetor -> elems = malloc(n * sizeof(void*)); 
   for (int i = 0; i < n; i++){
        vetor -> elems [i] = NULL;
    } 
    vetor -> comparador = compara;
    return vetor; 
}

void VETORD_add(VETORORD* vetor, void* newelem){
    if( vetor -> P < vetor -> N){
        if(vetor -> P == 0){
           vetor -> elems [0] = newelem;
        }
        else{
            int i;
            int p = vetor->P;
            vetor -> elems[p] = newelem;
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





























