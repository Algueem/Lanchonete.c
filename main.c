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
// Declaracao de funcoes

// Funcoes gerenciamento
void gerenciar_mantimentos(); // Abrir menu de mantimentos

void gerenciar_cardapio(); // Abrir o menu do cardapio

void registrar_pedidos(); // Fazer

void ver_relatorios(); // Fazer

// Subfuncoes

void comprar_estoque(); // Fazer

// Codigo principal

int main() {
    ler_dados(); // Ler os dados
    clr(); // Limpar
    // menu
    while ((main_option = main_menu()) != 0) { // Menu principal
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
    salvar_dados(); // Salvar os dados
    liberar(); // Liberar a memoria
    printf("Saindo...\n");
    return 0;
}

void alocar(int q_mant, int q_cardapio, int q_pedidos) { // Preparar a memoria
    dados.estoque = (mantimento*) calloc(q_mant, sizeof(mantimento));
    dados.cardapio = (comida*) calloc(q_cardapio, sizeof(comida));
    dados.pedidos = (pedido*) calloc(q_pedidos, sizeof(pedido));
    return;
}

void realocar() { // Mudar o tamanho dos vetores conforme o necessario
    dados.estoque = (mantimento*) realloc(dados.estoque, dados.qnt_mantimentos * sizeof(mantimento));
    dados.cardapio = (comida*) realloc(dados.cardapio, dados.qnt_comidas * sizeof(comida));
    dados.pedidos = (pedido*) realloc(dados.pedidos, dados.qnt_pedidos * sizeof(pedido));
    return;
}

void liberar() { // Liberar a memoria alocada
    free(dados.estoque);
    free(dados.cardapio);
    free(dados.pedidos);
}

// Arquivos

void salvar_dados() {
    FILE *arquivo; // Variavel arquivo e um ponteiro
    arquivo = fopen("dados.csv", "rb"); // Abrir o arquivo
    if (arquivo == NULL) { // Se nao conseguir abrir
        fprintf(stderr, "\nErro ao abrir arquivo\n");
        exit(1);
    };
    // Escrever tudo da struct no arquivo
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
    FILE *arquivo; // Variavel arquivo e um ponteiro
    arquivo = fopen("dados.csv", "rb"); // Abrir o arquivo
    if (arquivo == NULL) { // Se nao conseguir abrir
        fprintf(stderr, "\nErro ao abrir arquivo\n");
        exit(1);
    }
    // Dados padrao
    alocar(0,0,0); // Deixar a memoria pronta
    dados.qnt_mantimentos = 0;
    dados.qnt_pedidos = 0;
    dados.qnt_comidas = 0;
    // Carregando
    // Ler os dados para a variavel dados
    fread(&(dados.qnt_comidas), sizeof(int), 1, arquivo);
    fread(&(dados.qnt_pedidos), sizeof(int), 1, arquivo);
    fread(&(dados.qnt_mantimentos), sizeof(int), 1, arquivo);
    // Realocar o vetor dos dados para armazenar os mantimentos etc...
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
            case 0: // Voltar -- Feito
                break;
            case 1: // Adicionar -- Feito
                dados.qnt_mantimentos += 1;
                realocar();
                done = cadastrar_mantimento(); // Funcao para cadastrar, 1 = sem erro, 0 = erro
                if (done == 1) salvar_dados(); // Salvar os dados
                break;
            case 2: // Deletar -- Feito
                // Colocar o produto na ultima posição do vetor
                done = deletar_mantimento(); // Funcao para apagar, 1 = sem erro, 0 = erro
                if (done == 1){
                    dados.qnt_mantimentos -= 1; // Diminuir o tamanho do vetor
                    realocar(); // Realocar o vetor com 1 espaço a menos 
                    salvar_dados(); // Salvar os dados
                }
                break;
            case 3: // Ver -- Feito
                clr();
                for (int t = 0; t < dados.qnt_mantimentos; t++) { // Percorrer todos os produtos
                    mantimento m = dados.estoque[t]; // Pegar os dados
                    printf("Nome: %sPreco: %.2f\nCodigo: %d\n", m.nome, m.preco, m.codigo); // Mostrar
                }
                break;
            case 4: // Editar -- Fazer
                clr();
                printf("Digite a posicao: \n");
                //scanf("%d", &sel);
                printf("Digite o preco:\n");
                //scanf("%f", &p);
                //dados.estoque[sel].preco = p;
                printf("Editado");
                break;
            case 5: // Comprar -- Fazer
                break;
            default: // Feito
                error = 1;
                break;
        }
    }
    return;
}

void gerenciar_cardapio() { // Fazer sistema de cardapio
    int option;
    while ((option = cardapio_menu()) != 0) {
        int done;
        switch (option) { // a fazer
            case 0: // Voltar
                break;
            case 1: // Adicionar
                clr();
                dados.qnt_comidas += 1;
                realocar();

                fflush(stdin);
                printf("Digite o nome:");
                fgets(dados.cardapio[dados.qnt_comidas-1].nome, 30, stdin);
                printf("Digite o preco");
                scanf("%f", &dados.cardapio[dados.qnt_comidas-1].preco);
                printf("Digite o codigo");
                scanf("%d", &dados.cardapio[dados.qnt_comidas-1].codigo);
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
    //dados.qnt_pedidos += 1;
    //realocar();
    //dados.pedidos[dados.qnt_pedidos-1];
    return;
}

void ver_relatorios() { // Fazer
    return;
}
