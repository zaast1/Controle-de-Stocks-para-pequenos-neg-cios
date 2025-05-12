#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

FILE *ListaEstoques;

int opMenu,opLerArquivo; // Operações
int stockunits, stockstorage; // stockunits = unidade de operações, stockstorage = armazenamento
char name[24],description[200],buffer[1024];
// Buffer é uma região de memória. Vai ser usado pra ler todo o arquivo.
int ArquivoLista();
void Menu();
int LerArquivo();
void RegistrarEstoque();
void GravandoEstoque();
// Declarando as funções de antemão para maior performance do código.


int ArquivoLista(){
    FILE *ListaEstoques = fopen("ListaEstoques.txt","w+");
	if(ListaEstoques==NULL){
		printf("Erro ao abrir o Arquivo\n");
        return 1;
	}
    else{
		// Arquivo criado/aberto com sucesso, prosseguir.
	}
    fclose(ListaEstoques);
}

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
    printf("Digite 5 para retornar ao menu.");
    scanf("%i", &opLerArquivo);
    }while(opLerArquivo!=5);
    system("cls");
    Menu();
}

void Menu(){ // Menu de inicialização do programa.
    printf("+=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+\n");
    printf("|           CONTROLE DE ESTOQUES            |\n");
    printf("|-------------------------------------------|\n");
    printf("|     1 - CADASTRAR    |    2 - LISTA       |\n");
    printf("|-------------------------------------------|\n");
    printf("|     3 - ALTERAR      |    4 - AVALIAR     |\n");
    printf("|-------------------------------------------|\n");
    printf("| Selecione uma opcao ou digite 5 p/ sair.  |\n");
    printf("+=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+\n");
    scanf("%i", &opMenu); // Lê a opção inserida, e opera no switch na função main.

}

/* Avalia o preço de um único estoque e do estoque ao todo para o usuário
ver as possibilidades em seu negócio, realizando tipos de avaliações*/

void RegistrarEstoque(){ // Função de registro de estoque
    printf("Qual e o nome do estoque?: \n");
    scanf("%s", &name);
    printf("Qual é a descricao do estoque?: \n");
    scanf("%s", &description);
    printf("Qual e o valor do estoque inicial?: \n");
    scanf("%i", &stockstorage);
    GravandoEstoque();
    system("cls");
    Menu();
}

void GravandoEstoque(){
    FILE *ListaEstoques = fopen("ListaEstoques.txt","w+");
	fprintf(ListaEstoques,"|==================================|\n");
	fprintf(ListaEstoques,"|Nome:.......%s|\n",name);
	fprintf(ListaEstoques,"|----------------------------------|\n");
	fprintf(ListaEstoques,"|Quantidade: %i |\n",stockstorage);
	fprintf(ListaEstoques,"|Descrição:  %s |\n",description);
	fprintf(ListaEstoques,"|==================================|\n");
    fprintf(ListaEstoques,"\n");
    fclose(ListaEstoques);
}

int main(){
    setlocale(LC_ALL, "Portuguese"); // Coloca o idioma em português.
    ArquivoLista();
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