#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int opMenu; // Operações
int stockunits, stockstorage; // Unidades & Valores (em inteiro)
char name[24],description[200]; // Caracteres.

/*
Stocksunit = Unidades de estoque (a ser adicionada ou removida), Stock storage = Armazenamento de estoque.
*/

void Menu(){ // Menu de inicialização do programa.
    printf("+=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+\n");
    printf("|           CONTROLE DE ESTOQUES            |\n");
    printf("|-------------------------------------------|\n");
    printf("|       1 - CADASTRO |      2 - WIP         |\n");
    printf("|-------------------------------------------|\n");
    printf("|       3 - WIP      |      4 - WIP         |\n");
    printf("|-------------------------------------------|\n");
    printf("| Selecione uma opcao ou digite 5 p/ sair.  |\n");
    printf("+=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+\n");
    scanf("%i", &opMenu); // Lê a opção inserida, e opera no switch na função main.

}

void StockRegister(){ // Função de registro de estoque
    printf("Qual e o nome do estoque?: \n");
    scanf("%s", name);
    printf("Qual é a descricao do estoque?: \n");
    scanf("%s", description);
    printf("Qual e o valor do estoque inicial?: \n");
    scanf("%i", &stockstorage);
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
        StockRegister();
        break;
    }
        case 2:{ // 2 - WIP
        printf("Em desenvolvimento.\n");
        system("cls");
        Menu();
        }
        case 3:{ // 3 - WIP
        printf("Em desenvolvimento.\n");
        system("cls");
        }
        case 4:{ // 4 - WIP
        printf("Em desenvolvimento.\n");
        system("cls");
        }
    default:
        break;
    }
    }while(opMenu!=5); // Enquanto a escolha for diferente de 5, o código deve repetir.
    system("cls");
}