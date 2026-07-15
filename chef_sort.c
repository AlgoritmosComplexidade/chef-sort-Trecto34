#include <stdio.h>
#include <string.h>

// ANÁLISE DE ALGORITMO - Desafio Chef Sort
// Este é o arquivo inicial para o desafio.
// Dependendo do nível escolhido (Novato, Aventureiro ou Mestre),
// descomente e utilize as estruturas e funções correspondentes.

// ====================================================================
// ESTRUTURAS DE DADOS (Para Níveis Aventureiro e Mestre)
// ====================================================================

// Struct para o Nível Aventureiro
typedef struct {
    char nome[50];
    int qtd_ingredientes;
} Prato;

// Struct para o Nível Mestre
/*
typedef struct {
    char nome_prato[50];
    int numero_comanda;
} Comanda;
*/


// ====================================================================
// PROTÓTIPOS DAS FUNÇÕES DE ORDENAÇÃO
// ====================================================================

// Nível Novato: Bubble Sort para strings
// Dica: Use strcmp() da biblioteca <string.h> para comparar strings.
// Dica: Passe ponteiros para contadores de comparações e trocas se quiser alterá-los dentro da função.
void bubbleSortStrings(char arr[][50], int n, int *comparacoes, int *trocas) {
	int i, j, trocou;
	char temp[50];

	for (i = 0; i<n; i++){
		trocou = 0;
		for (j = 0; j<n - i - 1; j++){
			int comp = strcmp(arr[j], arr[j+1]);
			(*comparacoes)++;
			if (comp > 0) {
				strcpy(temp, arr[j]);
				strcpy(arr[j], arr[j+1]);
				strcpy(arr[j+1], temp);
				trocou = 1;
				(*trocas)++;
			}
		}
		if (!trocou)
			break;
	}
}

// Nível Aventureiro: Selection Sort para array de structs (Prato)
void selectionSortPratos(Prato arr[], int n) {
    for (int i=0; i<n; i++) {
        int indice_menor = i;
        for (int j=i+1; j<n; j++){
            if (arr[j].qtd_ingredientes < arr[indice_menor].qtd_ingredientes) {
                indice_menor=j;
            }
        }
        if (indice_menor != i) {
            Prato temp = arr[i];
            arr[i] = arr[indice_menor];
            arr[indice_menor] = temp;
        }
    }
}

// Nível Mestre: Recursive Insertion Sort para array de structs (Comanda)
// Dica: Lembre-se de definir o "caso base" (n <= 1) para parar a recursão!
/*
void recursiveInsertionSort(Comanda arr[], int n) {
    // Sua lógica do Insertion Sort Recursivo aqui
}
*/


// ====================================================================
// FUNÇÃO PRINCIPAL
// ====================================================================

int main() {
    printf("=== BEM-VINDO AO CHEF SORT ===\n\n");

    // ---------------------------------------------------------
    // ÁREA DO NÍVEL NOVATO (Despensa / Bubble Sort)
    // ---------------------------------------------------------
    char ingredientes[5][50] = {"Tomate", "Cebola", "Alho", "Cenoura", "Batata"};
    int num_ingredientes = 5;
    int comparacoes = 0;
    int trocas = 0;

    printf("--- Nivel Novato: Organizando a Despensa ---\n");
    printf("Lista ANTES da ordenacao:\n");
    // Laco para imprimir ingredientes antes

    int tamanho = sizeof(ingredientes)/sizeof(ingredientes[0]);
    for (int i=0; i<tamanho; i++){
	    printf("%s ",ingredientes[i]);
    };

	bubbleSortStrings(ingredientes, num_ingredientes, &comparacoes, &trocas);


    printf("\nLista DEPOIS da ordenacao:\n");
    // Laco para imprimir ingredientes depois
    // Imprimir totais de comparacoes e trocas
    //
    for (int i=0; i<num_ingredientes; i++){
	    printf("%s ", ingredientes[i]);
    }
    printf("Comparações: %d\nTrocas: %d", comparacoes, trocas);


    // ---------------------------------------------------------
    // ÁREA DO NÍVEL AVENTUREIRO (Pratos / Selection Sort)
    // ---------------------------------------------------------
    // Inicialize aqui o seu vetor de Pratos
    Prato lista_pratos[5] = {
        {"Macarronada", 5},
        {"Omelete", 2},
        {"Feijoada Completa", 12},
        {"Salada", 4},
        {"Lasanha", 8}
    };

    printf("\n\n\n--- Nivel Aventureiro: Organizando os Pratos ---\n");
    // Imprima antes, chame a funcao selectionSortPratos, imprima depois
    printf("LISTA ANTES DA ORDENACAO\n");
    for (int i=0; i<5; i++) {
        printf("%s - %d ingredientes\n", lista_pratos[i].nome, lista_pratos[i].qtd_ingredientes);
    }

    selectionSortPratos(lista_pratos, 5);

    printf("\nLISTA APOS DA ORDENACAO\n");
    for (int i=0; i<5; i++) {
        printf("%s - %d ingredientes\n", lista_pratos[i].nome, lista_pratos[i].qtd_ingredientes);
    }

    // ---------------------------------------------------------
    // ÁREA DO NÍVEL MESTRE (Comandas / Recursive Insertion Sort)
    // ---------------------------------------------------------
    /*
    // Inicialize aqui o seu vetor de Comandas

    printf("\n--- Nivel Mestre: Organizando as Comandas ---\n");
    // Imprima antes, chame a funcao recursiveInsertionSort, imprima depois
    */

    return 0;
}
