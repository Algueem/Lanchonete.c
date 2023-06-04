#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#ifndef MENU_H
#define MENU_H
#endif

// Structs
typedef struct {
    int codigo;
    float preco;
    int quantidade;
    char nome[30];
} mantimento;

typedef struct {
    int codigo;
    float preco;
    mantimento *receita;
    char nome[30];
} comida;

typedef struct {
    int lucro;
    int gasto;
} pedido;

typedef struct {
    float saldo;
    int qnt_mantimentos;
    int qnt_comidas;
    int qnt_pedidos;
    mantimento *estoque;
    comida *cardapio;
    pedido *pedidos;
} Data;

extern int error;
extern Data dados;

// Prototipos

void display_options(char **options, int amount); // Mostrar Menu

void display_header(int opt); //

int select_option(char **options, int amount, int menu); // Selecionar um número

int main_menu(); // Abrir o menu principal

int estoque_menu(); // Menu de mantimentos

int cardapio_menu(); // Menu do cardapio


// Funções

void clr() {
    system("clear");
    return;
}

void clear_buffer() {
    int c;
    while ((c=getchar()) != '\n' && c != EOF);
    return;
}

void line() {
    printf("--------------------------------------------------\n");
    return;
}

void display_options(char **options, int amount) {
    line();
    for (int i = 0; i < amount; i++){
        printf("| Opção %d - %s", i, options[i]); // Listar as opções
        for (int k = 1; k < 38-strlen(options[i]); k++) printf(" "); // Enfeite
        printf("|\n"); // Enfeite
    }
    line();
    return;
}

void display_header(int opt) {
    switch (opt) {
        case 0: // Menu
            printf("|              Painel do Resturante              |\n");
            break;
        case 1:
            printf("|                   Mantimentos                  |\n");
            break;
        case 2:
            printf("|                   Cardápio                     |\n");
            break;

        case 12: // 1->2 = Mantimentos -> Deletar
            printf("|            Deletando Mantimento                |\n");
            break;
        // Fazer mais se necessario
        case 99:
            printf("| Opção inválida! Digite uma dessas opções       |\n");
            break;
        default:
            break;
    }
}

int select_option(char **options, int amount, int menu) { // Sistema de menu por numeros
    display_options(options, amount); // Mostrar as opções
    int selected;
    while (scanf("%d", &selected) != 1) { // Scan ate ser uma opcao valida
        clr(); // 
        line();
        display_header(menu);
        line();
        display_header(99);
        display_options(options, amount);
        clear_buffer(); 
    }
    clr();
    clear_buffer();
    return selected; // Retornar o valor selecionado
}

int wait_for_input(int m, char *text) {
    int opt;
    line();
    display_header(m);
    line();
    printf("%s", text);
    while (scanf("%d", &opt) != 1) { // Scan ate ser uma opcao valida
        clr();
        line();
        display_header(m);
        line();
        display_header(99);
        line();
        printf("%s", text);
        clear_buffer(); 
    }
    clr();
    clear_buffer();
    return opt;
}

int main_menu() { // Criar o menu principal
    char *menu[5] = {"Encerrar",
                     "Gerenciar mantimentos",
                     "Gerenciar cardapio", 
                     "Gerenciar pedidos", 
                     "Ver relatorios"};
    line();
    display_header(0);
    if(error == 1) {
        line();
        display_header(99);
        error = 0;
    }
    return select_option(menu, 5, 0);
};

int estoque_menu() { // Criar o menu de mantimentos 
    line();
    display_header(1);
    if(error == 1) {
        line();
        display_header(99);
        error = 0;
    }
    char *menu[6] = {"Voltar", "Adicionar", "Deletar", "Ver", "Editar", "Comprar"};
    return select_option(menu, 6, 1);
}

void cadastrar_mantimento() {
    clr();
    printf("Você está cadastrando um mantimento\nDigite o nome:\n");
    return;
}

int deletar_mantimento() {
    int mant_cod;
    clr();
    mant_cod = wait_for_input(12, "Digite o codigo do produto que você quer deletar:\n");
    mantimento m, aux;
    for (int i = 0; i < dados.qnt_mantimentos; i++) {
        if (dados.estoque[i].codigo == mant_cod) {
            aux = dados.estoque[dados.qnt_mantimentos-1];
            dados.estoque[dados.qnt_mantimentos-1] = dados.estoque[i];
            dados.estoque[i] = aux;
            return 1;
        }
    }
    printf("Não foi encontrado o produto! Pressinone qualquer tecla para voltar ao menu...\n");
    getchar();
    return 0;
}

int cardapio_menu() { // Criar o menu do cardapio
    line();
    display_header(2);
    if(error == 1) {
        line();
        display_header(99);
        error = 0;
    }
    char *menu[6] = {"Voltar", "Adicionar", "Deletar", "Ver", "Editar", "Preparar"};
    return select_option(menu, 6, 2);
}
