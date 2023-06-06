#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#ifndef MENU_H
#define MENU_H
#endif

// Structs
typedef struct {
    int codigo; // Codigo do produto
    float preco; // Preço
    int quantidade; // Quantidade no estoque
    char nome[30]; // Nome
} mantimento;

typedef struct {
    int codigo; // Codigo da comida
    float preco; // Preço
    int *receita; // Vetor com os codigos dos mantimentos
    char nome[30]; // Nome
} comida;

typedef struct { // Salvar quanto cada pedido custou e lucrou
    int lucro;
    int gasto;
} pedido;

typedef struct { // Base de dados
    float saldo; // Dinheiro
    int qnt_mantimentos; // Usado para saber quanta memoria sera alocada
    int qnt_comidas;
    int qnt_pedidos;
    mantimento *estoque; // Vetor de mantimentos
    comida *cardapio; // Vetor de comidas
    pedido *pedidos; // Vetor de pedidos
} Data;

extern int error; // Importar variáveis da main
extern Data dados;

// Prototipos

void display_options(char **options, int amount); // Mostrar Menu

void display_header(int opt); //

int select_option(char **options, int amount, int menu); // Selecionar um número

int main_menu(); // Abrir o menu principal

int estoque_menu(); // Menu de mantimentos

int cardapio_menu(); // Menu do cardapio


// Funções

void clr() { // Limpar o console
    system("clear");
    return;
}

void clear_buffer() { // Limpar o buffer
    int c;
    while ((c=getchar()) != '\n' && c != EOF);
    return;
}

void line() { // Parte do menu 
    printf("--------------------------------------------------\n");
    return;
}

void display_options(char **options, int amount) { // Listar as opções
    line();
    for (int i = 0; i < amount; i++){
        printf("| Opção %d - %s", i, options[i]); // Listar as opções
        for (int k = 1; k < 38-strlen(options[i]); k++) printf(" "); // Enfeite
        printf("|\n"); // Enfeite
    }
    line();
    return;
}

void display_header(int opt) { // Função pra guardar os printf
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
        case 11: // 1->1 = Mantimentos -> Adicionar
            printf("|           Cadastrando Mantimento               |\n");
            break;
        case 12: // 1->2 = Mantimentos -> Deletar
            printf("|            Deletando Mantimento                |\n");
            break;
        // Fazer mais se necessario
        case 98:
            printf("| Não é uma entrada válida                       |\n");
            break;
        case 99:
            printf("| Opção inválida! Digite uma dessas opções       |\n");
            break;
        default:
            break;
    }
}

int select_option(char **options, int amount, int menu) { // Sistema de menu por numeros
    display_options(options, amount); // Mostrar as opções
    int selected; // Variavel para guardar a opção selecionada
    while (scanf("%d", &selected) != 1) { // Scan ate ser uma opcao valida
        clr(); // Limpar o console
        line(); // Recriar o menu
        display_header(menu);
        line();
        display_header(99);
        display_options(options, amount);
        clear_buffer(); // Limpar buffer
    }
    clr();
    clear_buffer();
    return selected; // Retornar o valor selecionado
}

int wait_for_input(int m, char *text) { // Função para ler numeros
    int opt; // Entrada do usuário
    line(); // Criar menu
    display_header(m);
    line();
    printf("%s", text);
    while (scanf("%d", &opt) != 1) { // Scan ate ser uma opcao valida
        clr(); // Limpar
        line(); // Criar menu
        display_header(m);
        line();
        display_header(98);
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
    line(); // Criar menu
    display_header(0);
    if(error == 1) {
        line();
        display_header(99);
        error = 0;
    }
    return select_option(menu, 5, 0); // Esperar a opção ser selecionada e retornar
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

int cadastrar_mantimento() {
    int mant_cod;
    float preco;
    clr();
    line();
    display_header(11);
    line();
    printf("Digite o nome:\n");
    fflush(stdin);
    fgets(dados.estoque[dados.qnt_mantimentos-1].nome, 30, stdin);
    clr();
    line();
    display_header(11);
    line();
    printf("Digite o preço: \n");
    while (scanf("%f", &preco) != 1) {
        clr();
        line();
        display_header(11);
        line();
        display_header(98);
        line();
        printf("Digite o preço: \n");
        clear_buffer();
    }
    clear_buffer();
    dados.estoque[dados.qnt_mantimentos-1].preco = preco;
    
    clr();
    mant_cod = wait_for_input(11, "Digite o código:");
    dados.estoque[dados.qnt_mantimentos-1].codigo = mant_cod;

    dados.estoque[dados.qnt_mantimentos-1].quantidade = 0;
    mantimento prod = dados.estoque[dados.qnt_mantimentos-1];
    printf("Produto cadastrado!\nNome: %sPreço %.2f\nCódigo: %d\n", prod.nome, prod.preco, prod.codigo);
    printf("Pressione qualquer tecla para continuar...");
    getchar();
    return 1;
}

int deletar_mantimento() {
    int mant_cod; // Codigo do produto a ser deletado
    mantimento aux; // Variaveis auxiliares
    clr(); // Limpar
    mant_cod = wait_for_input(12, "Digite o codigo do produto que você quer deletar:\n"); // Ler o codigo
    for (int i = 0; i < dados.qnt_mantimentos; i++) { // Procurar o produt
        if (dados.estoque[i].codigo == mant_cod) { // Se o produto for encontrado
            aux = dados.estoque[dados.qnt_mantimentos-1]; // Salvar o ultimo produto do vetor
            dados.estoque[dados.qnt_mantimentos-1] = dados.estoque[i]; // Trocar
            dados.estoque[i] = aux;
            printf("Produto deletado! Pressinone ENTER para voltar ao menu...\n");
            getchar();
            clr();
            return 1; // Quando acabar ele vai realocar com menos memoria pro produto sumir
        }
    }
    printf("Não foi encontrado o produto! Pressione ENTER para voltar ao menu...\n");
    getchar(); // Esperar uma entrada
    clr();
    return 0; // Nao encontrou nada
}

int editar_mantimento() { // Fazer
    return 0;
}

void ver_mantimentos() { // Fazer
    return;
}

int comprar_mantimento() { // Fazer
    return 0;
}

int cardapio_menu() { // Criar o menu do cardapio
    line(); // Criar menu
    display_header(2);
    if(error == 1) {
        line();
        display_header(99);
        error = 0;
    }
    char *menu[6] = {"Voltar", "Adicionar", "Deletar", "Ver", "Editar", "Preparar"};
    return select_option(menu, 6, 2);
}
