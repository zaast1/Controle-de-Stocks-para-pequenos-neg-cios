#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>

FILE *ListaEstoques;

int opMenu,opLerArquivo,opSimul; // Operações
int stockunits; // stockunits = unidade operativa para alterar o stockstorage, stockstorage = armazenamento
char buffer[1024];
// Buffer é uma região de memória. Vai ser usado pra ler todo o arquivo.

typedef struct {
    int stockstorage;
    int codigo;
    char name[24];
    char description[80];
    char expdate[10];
} Estoques;

void Menu();
int LerArquivo();
void RegistrarEstoque();
void GravandoEstoque(Estoques estoque);
void Simul();
void SimulVenda();
void SimulCompra();
// Declarando as funções de antemão para maior performance do código.

int LerArquivo(){
    ListaEstoques = fopen("ListaEstoques.txt","r");
	if(ListaEstoques==NULL){
		printf("Erro ao abrir o Arquivo\n");
        return 1;
	}
        while(fgets(buffer, sizeof(buffer),ListaEstoques) !=NULL){
        printf("%s", buffer);
    }
    fclose(ListaEstoques);
    do{
    printf("Digite 5 para retornar ao menu.\n");
    scanf("%i", &opLerArquivo);
    }while(opLerArquivo!=5);
    system("cls");
    Menu();
}

void Menu(){ // Menu de inicialização do programa.
    printf("+=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n");
    printf("|           CONTROLE DE ESTOQUES                 |\n");
    printf("|------------------------------------------------|\n");
    printf("|     1 - CADASTRAR    |    2 - LISTA            |\n");
    printf("|------------------------------------------------|\n");
    printf("|     3 - SIM COMP      |    4 - SIM VENDA       |\n");
    printf("|------------------------------------------------|\n");
    printf("| Selecione uma opcao ou digite 5 p/ sair.       |\n");
    printf("+=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n");
    scanf("%i", &opMenu); // Lê a opção inserida, e opera no switch na função main.

    // criar uma função que 
}

/* Avalia o preço de um único estoque e do estoque ao todo para o usuário
ver as possibilidades em seu negócio, realizando tipos de avaliações*/

void RegistrarEstoque() {
    Estoques estoque;

    for (int i = 0; i < 3; i++) {
        printf("Qual é o código do produto?: \n");
        scanf("%d", &estoque.codigo);

        printf("Qual é o nome do estoque?: \n");
        scanf(" %[^\n]", estoque.name);

        printf("Qual é a descrição do estoque?: \n");
        scanf(" %[^\n]", estoque.description);

        printf("Qual é o valor do estoque inicial?: \n");
        scanf("%d", &estoque.stockstorage);

        printf("Qual é a data de vencimento? (DD/MM/YYYY): \n");
        scanf("%s", estoque.expdate);

        GravandoEstoque(estoque);
    }
    system("cls");
    Menu();
}

//alterar quantidade aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
void GravandoEstoque(Estoques estoque) {

    FILE *ListaEstoques = fopen("ListaEstoques.txt", "a+");
    if (ListaEstoques == NULL) {
        printf("Erro ao abrir o arquivo para gravar.\n");
        return;
    }

    fprintf(ListaEstoques, "|==================================|\n");
    fprintf(ListaEstoques, "|Nome:.........%s|\n", estoque.name);
    fprintf(ListaEstoques, "|Codigo:......%03d|\n", estoque.codigo);
    fprintf(ListaEstoques, "|----------------------------------|\n");
    fprintf(ListaEstoques, "|Quantidade:....%d|\n", estoque.stockstorage);
    fprintf(ListaEstoques, "|Data de Venc:..%s|\n", estoque.expdate);
    fprintf(ListaEstoques, "|Descrição:.....%s|\n", estoque.description);
    fprintf(ListaEstoques, "|==================================|\n");
    fprintf(ListaEstoques, "\n");

    fclose(ListaEstoques);
}


void SimulVenda() {
    FILE *temp;
    char codBusca[10], linha[1024];
    int codInt, qtdTemp;
    bool encontrou = false;

    ListaEstoques = fopen("ListaEstoques.txt", "r");
    if (ListaEstoques == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        printf("Erro ao criar o arquivo temporário.\n");
        fclose(ListaEstoques);
        return;
    }

    printf("Digite o código do produto (ex.: 001): ");
    scanf("%s", codBusca);

    printf("Digite a quantidade que deseja vender: ");
    scanf("%d", &stockunits);

    while (fgets(linha, sizeof(linha), ListaEstoques) != NULL) {
        if (strstr(linha, "|Codigo:") != NULL) {
            sscanf(linha, "|Codigo:......%d|", &codInt);
            if (codInt == atoi(codBusca)) {
                encontrou = true;
            }
        }

        if (encontrou && strstr(linha, "|Quantidade:") != NULL) {
            sscanf(linha, "|Quantidade:....%d|", &qtdTemp);
            qtdTemp -= stockunits;
            if (qtdTemp < 0) qtdTemp = 0;
            fprintf(temp, "|Quantidade:....%d|\n", qtdTemp);
            encontrou = false;
        } else {
            fprintf(temp, "%s", linha);
        }
    }

    fclose(ListaEstoques);
    fclose(temp);

    remove("ListaEstoques.txt");
    rename("temp.txt", "ListaEstoques.txt");

    printf("Venda concluída e estoque atualizado!\n");

    do {
        printf("Digite 5 para retornar ao menu.\n");
        scanf("%i", &opSimul);
    } while (opSimul != 5);

    system("cls");
    Menu();
}

void SimulCompra() {
    FILE *temp;
    char codBusca[10], linha[1024];
    int codInt, qtdTemp;
    bool encontrou = false;

    ListaEstoques = fopen("ListaEstoques.txt", "r");
    if (ListaEstoques == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        printf("Erro ao criar o arquivo temporário.\n");
        fclose(ListaEstoques);
        return;
    }

    printf("Digite o código do produto (ex.: 001): ");
    scanf("%s", codBusca);

    printf("Digite a quantidade que deseja adicionar: ");
    scanf("%d", &stockunits);

    while (fgets(linha, sizeof(linha), ListaEstoques) != NULL) {
        if (strstr(linha, "|Codigo:") != NULL) {
            sscanf(linha, "|Codigo:......%d|", &codInt);
            if (codInt == atoi(codBusca)) {
                encontrou = true;
            }
        }

        if (encontrou && strstr(linha, "|Quantidade:") != NULL) {
            sscanf(linha, "|Quantidade:....%d|", &qtdTemp);
            qtdTemp += stockunits;
            fprintf(temp, "|Quantidade:....%d|\n", qtdTemp);
            encontrou = false;
        } else {
            fprintf(temp, "%s", linha);
        }
    }

    fclose(ListaEstoques);
    fclose(temp);

    remove("ListaEstoques.txt");
    rename("temp.txt", "ListaEstoques.txt");

    printf("Compra concluída e estoque atualizado!\n");

    do {
        printf("Digite 5 para retornar ao menu.\n");
        scanf("%i", &opSimul);
    } while (opSimul != 5);

    system("cls");
    Menu();
}


int main(){
    setlocale(LC_ALL, "Portuguese"); // Coloca o idioma em português.
    Menu(); // Inicialização da função "menu".
    do{
    switch(opMenu) // Leitor das opções que pertencem ao menu.
    {
    case 1:{ // 1 - Cadastro
        system("cls");
        RegistrarEstoque();
        break;
    }
        case 2:{ // 2 - Lista dos estoques
        system("cls");
        LerArquivo(); // Vai ler os estoques cadastrados no arquivo.
        break;
        }
        case 3:{ // 3 - Simulação de compra
        system("cls");
        SimulCompra();
        break;
        }
        case 4:{ // 4 - Simulação de Venda
        system("cls");
        SimulVenda();
        }
    default:
        break;
    }
    }while(opMenu!=5); // Enquanto a escolha for diferente de 5, o código deve repetir.
    system("cls");
}