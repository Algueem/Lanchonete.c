// Bibliotecas
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "menu.h"
//#include "file.h"

// Structs
typedef struct {
    int codigo;
    float preco;
    int quantidade;
    char nome[];
} mantimento;

typedef struct {
    int codigo;
    float preco;
    mantimento *receita;
    char nome[];
} comida;

typedef struct {
    int lucro;
    int gasto;
} pedido;

typedef struct {
    int saldo;
    mantimento *estoque;
    comida *cardapio;
    pedido *pedidos;
} Data;

// Arquivo

void salvar_dados(Data *d);

void ler_dados();

void alocar();

// Variavel global
int main_option = -1;
Data *dados;
// Declaracao de funções

// Funções gerenciamento
void gerenciar_mantimentos(); // Abrir menu de mantimentos

void gerenciar_cardapio(); // Abrir o menu do cardapio

void registrar_pedidos(); // Fazer

void ver_relatorios(); // Fazer

// Subfuncoes

void comprar_estoque(); // Fazer

// Codigo principal

int main() {
    // Fazer sistema de salvar/carregar
    alocar();
    // float saldo = 1000;
    //dados->saldo = 1000;
    //strcpy(dados->estoque[0].nome,"abc");
    //dados->estoque[0].codigo = 456;
    //dados->estoque[0].preco = 10.00;
    //salvar_dados(dados);
    ler_dados();
    clr(); // Limpar
    while ((main_option = main_menu()) != 0) { //Menu principal
        switch (main_option) { // Selecionar opcoes
            case 1:
                gerenciar_mantimentos(); 
                break;
            case 2:
                gerenciar_cardapio();
                break;
            case 3:
                registrar_pedidos();
                break;
            case 4:
                ver_relatorios();
                break;
            default:
                line();
                printf("| Opção inválida! Digite uma dessas opções       |\n");
                break;
        }
        if (main_option == 0) break; // Sair do programa
    }
    printf("Saindo...\n");
    return 0;
}

void alocar() {
    dados = (Data*) calloc(1, sizeof(Data));
    dados->estoque = (mantimento*) calloc(1, sizeof(mantimento));
    dados->cardapio = (comida*) calloc(1, sizeof(comida));
    dados->pedidos = (pedido*) calloc(1, sizeof(pedido));
}

// Arquivos

void salvar_dados(Data *d) {
    FILE *arquivo;
    arquivo = fopen("dados.csv", "wb");
    if (arquivo == NULL) {
        fprintf(stderr, "\nErro ao abrir arquivo\n");
        exit(1);
    };
    fwrite(d, sizeof(Data), 1, arquivo);
    fclose(arquivo);
}

void ler_dados() {
    FILE *arquivo;
    arquivo = fopen("dados.csv", "rb");
    if (arquivo == NULL) {
        fprintf(stderr, "\nErro ao abrir arquivo\n");
        exit(1);
    }
    fread(dados, sizeof(Data), 1, arquivo);
}

// Menus

void gerenciar_mantimentos() { // Fazer sistema de mantimentos
    int option;
    while ((option = gerenciar_menu(1)) != 0) {
        switch (option) { // a fazer
            case 0:
                break;
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                clr();
                printf("Codigo %p", dados->estoque[0]);
                break;
            default:
                line();
                printf("| Opção inválida! Digite uma dessas opções       |\n");
                break;
        }
    }
}

void gerenciar_cardapio() { // Fazer sistema de cardapio
    int option;
    while ((option = gerenciar_menu(2)) != 0) {
        switch (option) { // a fazer
            case 0:
                break;
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            default:
                line();
                printf("| Opção inválida! Digite uma dessas opções       |\n");
                break;
        }
    }
}

void registrar_pedidos() { // Fazer

}

void ver_relatorios() { // Fazer

}
