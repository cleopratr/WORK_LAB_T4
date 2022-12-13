# VETOR ORDENADO
<img src="http://img.shields.io/static/v1?label=STATUS&message=FINALIZADO&color=GREEN&style=for-the-badge"/>
</p>


# Índice 

* [Título](#vetor-ordenado)
* [Índice](#índice)
* [Descrição do Código](#descrição-do-código)
* [Como baixar](#como-baixar)
* [Como compilar e executar](#como-compilar-e-executar)
* [Funcionalidades do Código](#funcionalidades-do-código)

# DESCRIÇÃO DO CÓDIGO 

O código apresentado utiliza uma blibioteca nomeada **ordvetor.h** encontrada no repositório, utilizando as funções apresentadas na blibioteca o código permite ao usuário manipular um vetor ordenado, podendo criar este vetor, adicionar elementos a este, permitindo também a remoção de elementos.


# Como baixar 

> **Copie o comando abaixo:**
> 
> git clone https://github.com/cleopratr/WORK_LAB_T4

# Como compilar e executar

> **Após ascessar a pasta com o código no terminal, digite:**
> 
> ```cd WORK_LAB_T4```
>
> ```gcc TR4_540344.c main_vet.c -o T4_540344```
> 
> **Para executar seu código, ainda no terminal digite:** 
> 
> ```./T4_540344```

# Funcionalidades do código

- `VETORD_create`: Recebe um inteiro n e um ponteiro para uma função do tipo COMP. Esta função cria um vetor ordenado com uma função comparador interna para ordenação.
- `VETORD_add`: Recebe um ponteiro vetor VETORORD e um ponteiro newelem do tipo void. Esta função adiciona um elemento ao vetor.
- `VETORD_remove`: Recebe o ponteiro vetor do tipo VETORORD e retorna o primeiro elemento, removendo-o da lista.


