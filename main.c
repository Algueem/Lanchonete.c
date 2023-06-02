// Bibliotecas
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structs
typedef struct {
    char nome;
    int codigo;
    float preco;
    int quantidade;
} mantimento;

typedef struct {
    char nome;
    int codigo;
    float preco;
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

void line() {
    printf("--------------------------------------------------\n");
}

void display_options(char **options, int amount); // Mostrar Menu

int select_option(char **options, int amount); // Selecionar um número

// Funções principais

int main_menu(); // Abrir o menu principal

void gerenciar_mantimentos(); // Abrir menu de mantimentos

void gerenciar_cardapio(); // Abrir o menu do cardapio

void registrar_pedidos(); // Fazer

void ver_relatorios(); // Fazer

// Subfunções

void comprar_estoque(); // Fazer

// Código principal

int main() {
    // Fazer sistema de salvar/carregar
    // comida cardapio[n]; || Alocação dinamica
    // float saldo = 1000;

    clr(); // Limpar
    while ((main_option = main_menu()) != 0) { //Menu principal
        switch (main_option) { // Selecionar opções
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
                printf("|       Opção inválida! Digite uma dessas opções|\n");
                break;
            
        }
        if (main_option == 0) break; // Sair do programa
        //teste(t);
    }
    printf("Saindo...\n");
    return 0;
}

// Sistema de menus

void display_options(char **options, int amount) {
    line();
    for (int i = 0; i < amount; i++){
        printf("| Opção %d - %s", i, options[i]); // Listar as opções
        for (int k = 1; k < 38-strlen(options[i]); k++) printf(" "); // Enfeite
        printf("|\n"); // Enfeitee
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
                break;
            default:
                line();
                printf("|Opção inválida! Digite uma dessas opções        |\n");
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
                printf("| Opção inválida! Digite uma dessas opções        |\n");
                break;
        }
    }
}

void registrar_pedidos() { // Fazer

}

void ver_relatorios() { // Fazer

}
