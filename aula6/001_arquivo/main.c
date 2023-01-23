// #include <stdio.h>
// #include <stdlib.h>

// typedef struct Funcionario {
//     int cod;
//     char nome[50];
//     char cpf[15];
//     char data_nascimento[11];
//     double salario;
// } TFunc;

// void le_arquivo_caracteres() {
//     FILE *arq; //declara ponteiro para arquivo
    
//     arq = fopen("./aula06/001_arquivo/dados.txt", "r"); //abre arquivo para leitura
//     if (arq != NULL) { // checa se não deu erro na abertura do arquivo
//         char c;
//         while ((c = fgetc(arq)) != EOF) { //le char e testa se chegou ao fim
//             printf("%c", c); //imprime caractere lido no monitor
//         }
//         fclose(arq); //fecha arquivo
//     } 
//     else printf("Erro ao abrir arquivo\n");
// }

// void le_arquivo_strings(){
//     FILE *arq; //declara ponteiro para arquivo
    
//     arq = fopen("./aula06/001_arquivo/dados.txt", "r"); //abre arquivo para leitura
//     if (arq != NULL){ // checa se não deu erro na abertura do arquivo
//         char s[10];
//         // fscanf(arq, "%s", s);
//         while (!feof(arq)) { //testa se chegou ao final do arquivo
//             fscanf(arq, "%s", s);
//             printf("%s\n", s);
//             // fscanf(arq, "%s", s);
//         }
//         fclose(arq); //fecha arquivo
//     }
//     else printf("Erro ao abrir arquivo\n");
// }

// void grava_arquivo_strings(char* nomeArq) {
//     FILE *arq; //declara ponteiro para arquivo
//     //abre arquivo para gravação
//     arq = fopen(nomeArq, "w");
//     if (arq != NULL) {// checa se não deu erro na abertura do arquivo
//         for (int i = 10; i < 100; i = i + 3) {
//             fprintf(arq, "%d\n", i); //grava no arquivo
//         }
//         fclose(arq);
//     }
//     else printf("Erro ao abrir arquivo\n");
// }

// void le_arquivo_strings_de_numeros(){
// FILE *arq; //declara ponteiro para arquivo
    
//     arq = fopen("../numeros.txt", "r"); //abre arquivo para leitura
//     if (arq != NULL){ // checa se não deu erro na abertura do arquivo
//         int n;
//         fscanf(arq, "%d", &n);
//         while (!feof(arq)) { //testa se chegou ao final do arquivo
//             printf("%d\n", n);
//             fscanf(arq, "%d", &n);
//         }
//         fclose(arq); //fecha arquivo
//     }
//     else printf("Erro ao abrir arquivo\n");
// }

// // Salva no arquivo out, na posição atual do cursor
// void salva(TFunc *func, FILE *out) {
//     fwrite(&func->cod, sizeof(int), 1, out);
//     //func->nome ao invés de &func->nome, 
//     //pois string já é ponteiro
//     fwrite(func->nome, sizeof(char), sizeof(func->nome), out);
//     fwrite(func->cpf, sizeof(char), sizeof(func->cpf), out);
//     fwrite(func->data_nascimento, sizeof(char), sizeof(func->data_nascimento), out);
//     fwrite(&func->salario, sizeof(double), 1, out);
// }

// // // Lê do arquivo in na posição atual do cursor
// // // Retorna um ponteiro para funcionário lido do arquivo
// // TFunc *le(FILE *in) {
// //     TFunc *func = (Funcionario *) malloc(sizeof(Funcionario));
// //     if (0 >= fread(&func->cod, sizeof(int), 1, in)) {
// //         free(func);
// //         return NULL;
// //     }
// //     fread(func->nome, sizeof(char), sizeof(func->nome), in);
// //     fread(func->cpf, sizeof(char), sizeof(func->cpf), in);
// //     fread(func->data_nascimento, sizeof(char), 
// //         sizeof(func->data_nascimento), in);
// //     fread(&func->salario, sizeof(double), 1, in);
// //     return func;
// // }

// // /* 
// // * tamanho do registro, retornado pela função 
// // * tamanho_registro() é dado em bytes
// // */
// // int tamanho_arquivo(FILE *arq) {
// //     fseek(arq, 0, SEEK_END);
// //     int tam = trunc(ftell(arq) / tamanho_registro());
// //     return tam;
// // }

// // prova == merge() || tamanho_registro;
// void merge(char* nomeArq1, char* nomeArq2, char* nomeArqMerge);
// int tamanho_registro();

// void mergeTeste(char* nomeArq1, char* nomeArq2) {
// FILE *arq1, *arq2; //declara ponteiro para arquivo
    
//     arq1 = fopen("./numeros1.txt", "r"); //abre arquivo para leitura
//     arq2 = fopen("./numeros2.txt", "r"); //abre arquivo para leitura
//     if (arq1 != NULL){ // checa se não deu erro na abertura do arquivo
//         int n;
//         fscanf(arq1, "%d", &n);
//         while (!feof(arq1)) { //testa se chegou ao final do arquivo
//             printf("%d\n", n);
//             fscanf(arq1, "%d", &n);
//         }
//         fclose(arq1); //fecha arquivo
//     }
//     if (arq2 != NULL){ // checa se não deu erro na abertura do arquivo
//         int n;
//         fscanf(arq2, "%d", &n);
//         while (!feof(arq2)) { //testa se chegou ao final do arquivo
//             printf("%d\n", n);
//             fscanf(arq2, "%d", &n);
//         }
//         fclose(arq2); //fecha arquivo
//     }
//     else printf("Erro ao abrir arquivo\n");
// }

// int main(int argc, char** argv) {
//     // le_arquivo_caracteres();
//     // le_arquivo_strings();
//     // grava_arquivo_strings("./aula06/001_arquivo/Teste.txt");
//     mergeTeste("numeros1.txt", "numeros2.txt");
        
//     return 0;
// }