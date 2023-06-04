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

// Arquivo

void salvar_dados(Data d);

void ler_dados();

void alocar(int q_mant, int q_cardapio, int q_pedidos);

void realocar();

// Variavel global
int main_option = -1;
Data dados;
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
    alocar(0,0,0);
    //dados->saldo = 1000;
    //dados->qnt_comidas = 0;
    //dados->qnt_mantimentos = 1;
    //dados->qnt_pedidos = 0;
    //strcpy(dados->estoque[0].nome,"abc");
    //dados->estoque[0].codigo = 456;
    //dados->estoque[0].preco = 10.00;
    //dados->estoque[0].quantidade = 0;
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
    //dados.qnt_mantimentos = 0;
    salvar_dados(dados);
    printf("Saindo...\n");
    return 0;
}

void alocar(int q_mant, int q_cardapio, int q_pedidos) {
    //dados = (Data*) calloc(1, sizeof(Data));
    dados.estoque = (mantimento*) calloc(q_mant, sizeof(mantimento));
    dados.cardapio = (comida*) calloc(q_cardapio, sizeof(comida));
    dados.pedidos = (pedido*) calloc(q_pedidos, sizeof(pedido));
    return;
}

void realocar() {
    dados.estoque = (mantimento*) realloc(dados.estoque, dados.qnt_mantimentos * sizeof(mantimento));
    dados.cardapio = (comida*) realloc(dados.cardapio, dados.qnt_comidas * sizeof(comida));
    dados.pedidos = (pedido*) realloc(dados.pedidos, dados.qnt_pedidos * sizeof(pedido));
    return;
}

// Arquivos

void salvar_dados(Data d) {
    FILE *arquivo;
    arquivo = fopen("dados.csv", "wb");
    if (arquivo == NULL) {
        fprintf(stderr, "\nErro ao abrir arquivo\n");
        exit(1);
    };
    fwrite(&(d.qnt_comidas), sizeof(int), 1, arquivo);
    fwrite(&(d.qnt_pedidos), sizeof(int), 1, arquivo);
    fwrite(&(d.qnt_mantimentos), sizeof(int), 1, arquivo);
    fwrite(d.estoque, sizeof(mantimento), d.qnt_mantimentos, arquivo);
    fwrite(d.pedidos, sizeof(pedido), d.qnt_pedidos, arquivo);
    fwrite(d.cardapio, sizeof(comida), d.qnt_comidas, arquivo);
    fclose(arquivo);
    return;
}

void ler_dados() {
    FILE *arquivo;
    arquivo = fopen("dados.csv", "rb");
    if (arquivo == NULL) {
        fprintf(stderr, "\nErro ao abrir arquivo\n");
        exit(1);
    }
    // Dados padrão
    dados.qnt_mantimentos = 0;
    dados.qnt_pedidos = 0;
    dados.qnt_comidas = 0;
    // Carregando
    fread(&(dados.qnt_comidas), sizeof(int), 1, arquivo);
    fread(&(dados.qnt_pedidos), sizeof(int), 1, arquivo);
    fread(&(dados.qnt_mantimentos), sizeof(int), 1, arquivo);
    realocar(dados.qnt_mantimentos, dados.qnt_comidas,dados.qnt_pedidos);
    fread(dados.estoque, sizeof(mantimento), dados.qnt_mantimentos, arquivo);
    fread(dados.pedidos, sizeof(pedido), dados.qnt_pedidos, arquivo);
    fread(dados.cardapio, sizeof(comida), dados.qnt_comidas, arquivo);
    fclose(arquivo);
    return;
}

// Menus

void gerenciar_mantimentos() { // Fazer sistema de mantimentos
    int option;
    while ((option = gerenciar_menu(1)) != 0) {
        switch (option) { // a fazer
            case 0:
                break;
            case 1:
                clr();
                dados.qnt_mantimentos += 1;
                realocar();
                fflush(stdin);
                printf("Digite o nome:");
                fgets(dados.estoque[dados.qnt_mantimentos-1].nome, 30, stdin);
                printf("Digite o preço");
                scanf("%f", &dados.estoque[dados.qnt_mantimentos-1].preco);
                printf("Digite o codigo");
                scanf("%d", &dados.estoque[dados.qnt_mantimentos-1].codigo);
                dados.estoque[dados.qnt_mantimentos-1].quantidade = 0;
                break;
            case 2:
                break;
            case 3:
                clr();
                for (int t = 0; t < dados.qnt_mantimentos; t++) {
                    mantimento m = dados.estoque[t];
                    printf("Nome: %sPreco: %.2f\nCodigo: %d\n", m.nome, m.preco, m.codigo);
                }
                break;
            case 4:
                clr();
                
                scanf("%f", &dados.estoque[1].preco);
                printf("Editado");
                break;
            default:
                line();
                printf("| Opção inválida! Digite uma dessas opções       |\n");
                break;
        }
    }
    return;
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
  return;
}

void registrar_pedidos() { // Fazer
    return;
}

void ver_relatorios() { // Fazer
    return;
}
