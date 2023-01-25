#include <stdio.h>
#include <stdlib.h>

// Dado um arquivo de funcionários ordenado, impplementar uma função que faz busca binária
// cod é a chave buscada
// *arq é o ponteiro pro arquivo
// tam é o número de registros do arquivo
TFunc *busca_binaria(int cod, FILE *arq, int tam);

// pseudocodigo insertion sort
// procedure insertionSort (A: array, size: int) {
//     // Entrada: A: array com as chaves (posições vão de [0, tam-1]);
//     //          size: tamanho do array
//     // Saída: A: array ordenado
//     for j := 1 to size-1 do {
//         key := A[j];
//         i := j - 1;
//         while (i >= 0) and (A[i] > key) do {
//             A[i+1] := A[i];
//             i := i-1;
//         }
//     A [i+1] := key;
//     }
// }

// int main(void) {
//     return 0;
// }

void insertion_sort (FILE *arq, int tam) {
    TFunc *v[tam];
    // lê o arquivo e coloca no vetor
    rewind(arq); // posiciona o cursor no início do arquivo
    TFunc *f = le(arq);
    int i = 0;
    while (!feof(arq)) {
        v[i] = f;
        f = le(arq);
        i++;
    }
    // faz o insertion sort
    for (int j = 1; j < tam; j++) {
        TFunc *f = v[j];
        i = j - 1;
        while ((i >= 0) && (v[i]->cod > f->cod)) {
            v[i + 1] = v[i];
            i = i - 1;
        }
        v[i + 1] = f;
    }
    // grava vetor no arquivo por cima do conteúdo anterior
    rewind(arq);
    for (int i = 0; i < tam; i) {
        salva(v[i], arq);
    }
    // descarrega o buffer para ter certeza que os dados foram gravados
    fflush(arq);
}

void insertion_sort_disco(FILE *arq, int tam) {
    int i;
    // faz o insertion sort
    for (int j = 2; j <= tam; j++) {
        // posicione o arquivo no registro j
        fseek(arq, (j-1) * tamanho(), SEEK_SET);
        TFunc *fj = le(arq);
        printf("\n********* Funcionário atual: %d", fj->cod);
        i = j - 1;
        // posiciona o cursor no registro i
        fseek(arq, (i-1) * tamanho_registro(), SEEK_SET);
        TFunc *fi = le(arq);
        printf("fi = %d\n", fi->cod);
        while ((i > 0) && (fi->cod > fj->cod)) {
            // posociona o cursor no registro i+1
            fseek(arq, 1 i * tamanho_registro(), SEEK_SET);
            printf("Salvando funcionário %d na posição %d\n", fi->cod, i+1);
            salva(fi, arq);
            i = i - 1;
            // lê registro i 
            fseek(arq, (i-1) * tamanho_registro(), SEEK_SET);
            fi = le(arq);
            printf("fi = %d; i = %d\n", fi->cod, i);
        }
        // posiciona cursor no registro i+1
    }
}

// implementar função que faz selection sort direto no disco
void selection_sort_disco(FILE *arq, int tam) {
    
}
