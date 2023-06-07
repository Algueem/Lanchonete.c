
// Bibliotecas
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "menu.h"

//#include "file.h"

// Arquivo

void salvar_dados();

void ler_dados();

void alocar(int q_mant, int q_cardapio, int q_pedidos);

void realocar();

void liberar();

// Variavel global
int main_option = -1;
Data dados;
int error = 0;
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
    alocar(0,0,0);
    ler_dados();
    //clr(); // Limpar
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
                error = 1;
                break;
        }
        if (main_option == 0) break; // Sair do programa
    }
    //dados.qnt_mantimentos = 0;
    salvar_dados();
    liberar();
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

void liberar() {
    free(dados.estoque);
    free(dados.cardapio);
    free(dados.pedidos);
}

// Arquivos

void salvar_dados() {
    FILE *arquivo;
    arquivo = fopen("dados.csv", "wb");
    if (arquivo == NULL) {
        fprintf(stderr, "\nErro ao abrir arquivo\n");
        exit(1);
    };
    fwrite(&(dados.qnt_comidas), sizeof(int), 1, arquivo);
    fwrite(&(dados.qnt_pedidos), sizeof(int), 1, arquivo);
    fwrite(&(dados.qnt_mantimentos), sizeof(int), 1, arquivo);
    fwrite(dados.estoque, sizeof(mantimento), dados.qnt_mantimentos, arquivo);
    fwrite(dados.pedidos, sizeof(pedido), dados.qnt_pedidos, arquivo);
    fwrite(dados.cardapio, sizeof(comida), dados.qnt_comidas, arquivo);
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
    while ((option = estoque_menu()) != 0) {
        int done;
        switch (option) { // a fazer
            case 0: // Voltar
                break;
            case 1: // Adicionar
                clr();
                dados.qnt_mantimentos += 1;
                realocar();

                //ler_nome(dados.estoque[dados.qnt_mantimentos-1]);


                fflush(stdin);
                printf("Digite o nome:");
                fgets(dados.estoque[dados.qnt_mantimentos-1].nome, 30, stdin);
                printf("Digite o preço");
                scanf("%f", &dados.estoque[dados.qnt_mantimentos-1].preco);
                printf("Digite o codigo");
                scanf("%d", &dados.estoque[dados.qnt_mantimentos-1].codigo);
                dados.estoque[dados.qnt_mantimentos-1].quantidade = 0;
                salvar_dados();
                break;
            case 2: // Deletar
                // Colocar o produto na ultima posição do vetor
                done = deletar_mantimento();
                if (done == 1){
                    dados.qnt_mantimentos -= 1;
                    realocar();
                    salvar_dados();
                }
                break;
            case 3: // Ver
                clr();
                for (int t = 0; t < dados.qnt_mantimentos; t++) {
                    mantimento m = dados.estoque[t];
                    printf("Nome: %sPreco: %.2f\nCodigo: %d\n", m.nome, m.preco, m.codigo);
                }
                break;
            case 4: // Editar
                clr();
                printf("Digite a posição: \n");
                //scanf("%d", &sel);
                printf("Digite o preco:\n");
                //scanf("%f", &p);
                //dados.estoque[sel].preco = p;
                printf("Editado");
                break;
            case 5: // Comprar
                break;
            default:
                error = 1;
                break;
        }
    }
    return;
}

void gerenciar_cardapio() { // Fazer sistema de cardapio
    int option;
    while ((option = cardapio_menu()) != 0) {
        switch (option) { // a fazer
            case 0: // Voltar
                break;
            case 1: // Adicionar
                int done;
                clr();
                dados.qnt_comidas += 1;
                realocar();
                done = adicionar_cardapio();
                if (done == 0) {
                    clr();
                    dados.qnt_comidas -= 1;
                    realocar();
                }
                salvar_dados();
                break;
            case 2: // Deletar
                break;
            case 3: // Ver
                break;
            case 4: // Editar
                break;
            case 5: // Preparar
                break;
            default:
                error = 1;
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
