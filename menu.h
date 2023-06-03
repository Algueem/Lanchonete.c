#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#ifndef MENU_H
#define MENU_H
#endif

// Prototipos

void display_options(char **options, int amount); // Mostrar Menu

int select_option(char **options, int amount); // Selecionar um número

int main_menu(); // Abrir o menu principal

// Funções

void clr() {
    system("clear");
}

void clear_buffer() {
    int c;
    while ((c=getchar()) != '\n' && c != EOF);
}

void line() {
    printf("--------------------------------------------------\n");
}

void display_options(char **options, int amount) {
    line();
    for (int i = 0; i < amount; i++){
        printf("| Opção %d - %s", i, options[i]); // Listar as opções
        for (int k = 1; k < 38-strlen(options[i]); k++) printf(" "); // Enfeite
        printf("|\n"); // Enfeite
    }
    line();
}

int select_option(char **options, int amount) { // Sistema de menu por numeros
    display_options(options, amount); // Mostrar as opções
    int selected;
    while (scanf("%d", &selected) != 1) { // Scan ate ser uma opcao valida
        clr(); // 
        line();
        printf("| Opção inválida! Digite uma dessas opções       |\n");
        display_options(options, amount);
        clear_buffer(); 
    }
    clr();
    clear_buffer();
    return selected; // Retornar o valor selecionado
}

int main_menu() { // Criar o menu principal
    char *menu[5] = {"Encerrar",
                     "Gerenciar mantimentos",
                     "Gerenciar cardapio", 
                     "Gerenciar pedidos", 
                     "Ver relatorios"};
    line();
    printf("|              Painel do Resturante              |\n");
    return select_option(menu, 5);
};

int gerenciar_menu(int opt) { // Criar o menu do mantimentos e cardapio
    line();
    switch (opt) {
        case 1:
            printf("|                   Mantimentos                  |\n");
            break;
        case 2:
            printf("|                   Cardápio                     |\n");
            break;
    }
    char *menu[5] = {"Voltar", "Adicionar", "Deletar", "Ver", "Editar"};
    return select_option(menu, 5);
}
