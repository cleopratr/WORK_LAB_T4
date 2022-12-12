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
        }else{ // Caso haja um elemento existente checamos em qual posição do nosso vetor o newelem deve ser adicionado  
            int i; // Variável utilizada para iterar os valores no vetor
            int p = vetor->P; // Recebe o número de elementos do vetor
            vetor -> elems[p] = newelem; // Adiciona o novo valor na posição
            for(i = p; i > 0; i++){ // Percorrendo o vetor 
                if(vetor->comparador(vetor->elems[i-1], vetor->elems[i]) == -1){ // Verificando se o elemento que queremos adicionar está na posição correta
                    void* aux = vetor->elems[i-1]; // Acessamos o elemento anterior da posição atual, guardando no ponteiro aux
                    vetor->elems[i-1] = vetor->elems[i]; // Substitui a valor atual pelo valor da posição anterior
                    vetor->elems[i] = aux; // Na posição atual é inserido o valor guardado em aux
                }else break; // Se a condição não é satisfeita o for para
            }
        }
        vetor -> P++; // Acrescenta mais um ao valor de posições do vetor
        }
}

void* VETORD_remove(VETORORD* vetor){
   void * lixo = vetor -> elems[0]; // ponteiro que armazena o valor a ser removido
   for(int i = 0; i < vetor -> P; i++){ // Percorrendo o vetor
      vetor -> elems[i] = vetor -> elems [i+1]; // Encontra o valor no vetor e substitui por sua próxima posição
   }
   vetor -> P--; // Diminui um do valor de posições do vetor
    return lixo; // retorna o valor removido
} 
