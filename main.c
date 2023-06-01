// Bibliotecas
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structs
typedef struct {
    char nome;
} mantimento;

typedef struct {
    mantimento receita[10];
} comida;

// Variavel global
int main_option = -1;

// Declaração de funções

// Funções úteis
void clr() {
    system("clear");
}

void clear_buffer() {
    int c;
    while ((c=getchar()) != '\n' && c != EOF);
}

void display_options(char **options, int amount); // Mostrar Menu

int select_option(char **options, int amount); // Selecionar um número

// Funções principais

int main_menu();

void gerenciar_mantimentos();

void gerenciar_cardapio();

void registrar_pedidos();

void ver_relatorios();

// Subfunções

void comprar_estoque();
//

void teste(char **abc) {
    printf("%s", abc[1]);
}

// Código principal

int main() {
    clr();
    while ((main_option = main_menu()) != 0) {
        switch (main_option) {
            case 1:
                gerenciar_mantimentos();
                break;
            case 2:
                //gerenciar_cardapio();
                break;
            case 3:
                //registrar_pedidos();
                break;
            case 4:
                //ver_relatorios();
                break;
            default:
                printf("Opção inválida! Digite uma dessas opções\n");
                break;
            
        }
        if (main_option == 0) break;
        //teste(t);
    }
    printf("Saindo...\n");
    return 0;
}

// Sistema de menus

void display_options(char **options, int amount) {
    for (int i = 0; i < amount; i++){
        printf("| Opção %d - %s", i, options[i]);
        for (int k = 1; k < 30-strlen(options[i]); k++) printf(" ");
        printf("|\n");
    }
    printf("------------------------------------------\n");
}

int select_option(char **options, int amount) {
    display_options(options, amount);
    int selected;
    while (scanf("%d", &selected) != 1) {
        clr();
        clear_buffer();
        printf("Opção inválida! Digite uma dessas opções\n");
        display_options(options, amount);
    }
    clr();
    clear_buffer();
    return selected;
}

int main_menu() {
    char *menu[5] = {"Encerrar",
                     "Gerenciar mantimentos",
                     "Gerenciar cardapio", 
                     "Gerenciar pedidos", 
                     "Ver relatorios"};
    printf("------------------------------------------\n");
    printf("|          Painel do Resturante          |\n");
    printf("------------------------------------------\n");
    return select_option(menu, 5);
};

int gerenciar_menu() {
    char *menu[5] = {"Voltar", "Adicionar", "Deletar", "Ver", "Editar"};
    return select_option(menu, 5);
}

void gerenciar_mantimentos() {
    int option;
    while ((option = gerenciar_menu()) != 0) {
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
                printf("Opção inválida! Digite uma dessas opções\n");
                break;
        }
    }
}

void gerenciar_cardapio() {

}
