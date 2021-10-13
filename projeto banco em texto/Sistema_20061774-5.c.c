#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

char url[50] = "../Armazenamento/arquivo.txt";
FILE * ler;
FILE * incluir;
char * armazenamento[200];

typedef struct //Dados a serem cadastrados no arquivo.
{
    char titulo[40];
    int edicao;
    char nomeAutor[30];
    char editora[30];
    char isbn[30];
    int exemplares;
    int ano;
    int tipo;
    int caixa;
}dados;
dados d1[200]; //Struct global de movimentação de dados.

imprimirDado(int dado){ //Imprimir um dado especifico

    printf("\nTitulo: %s", d1[dado].titulo);
    printf("Edicao: %s", d1[dado].edicao);
    printf("Autor: %s", d1[dado].nomeAutor);
    printf("Editora: %s", d1[dado].editora);
    printf("ISBN: %s", d1[dado].isbn);
    printf("Exemplares: %s", d1[dado].exemplares);
    printf("Ano: %s", d1[dado].ano);
    //Condição que identifica quando é livro ou quando é revista!
    if(strcmp(d1[dado].tipo, "1\n") == 0){
        printf("Tipo: Livro!\n");
    }else if(strcmp(d1[dado].tipo, "2\n") == 0){
        printf("Tipo: Revista!\n");
    }
    printf("Caixa: %s", d1[dado].caixa);
}

menu(){ //MENU
    int opcaoMenu= 0, teste= 0, i= 0, j= 0, contTeste= 0, erros= 0, testeMenu= 0, l=0, verificacaoBox=0;
    char caixa[1], tipo[1];
    int k= lerDados();
    setDados();
    int quantArray= k/9;     
    do{
        system("cls");
        //MENU
        printf("Autor: Henrique Fratoni Motton - RA: 20061774-5 - Engenharia de Software - Modulo 52\n");
        printf("1- Incluir o registro das obras\n");
        printf("2- Listar todos os livros\n");
        printf("3- Listar todas as revistas\n");
        printf("4- Listar as obras por caixa\n");
        printf("5- SAIR\n");
        fflush(stdin);
        scanf("%d", &opcaoMenu);

        if(opcaoMenu == 1){ //Incluir o registro das obras
            system("cls");
            incluirDados();
        }else if(opcaoMenu == 2){ //Listar todos os livros
            system("cls");
            strcpy(tipo, "1\n");
            listarLivros(tipo);
            system("PAUSE");
            system("cls");
        }else if(opcaoMenu == 3){ //Listar todas as revistas
            system("cls");
            strcpy(tipo, "2\n");
            listarRevistas(tipo);
            system("PAUSE");
            system("cls");
        }else if(opcaoMenu == 4){ //Listar as obras por caixa
            system("cls");
            do{
                verificacaoBox = 0;
                teste = 1;
                l = 0;
                printf("Digite o numero correspondente a caixa que deseja abrir: \n");
                printf("CAIXA: 1\n");
                printf("CAIXA: 2\n");
                printf("CAIXA: 3\n");
                printf("0- Voltar ao menu PRINCIPAL!\n");
                fflush(stdin);
                scanf("%s", &caixa);
                strcat(caixa, "\n");
                if(strcmp(caixa, "1\n") == 0 || strcmp(caixa, "2\n") == 0 || strcmp(caixa, "3\n") == 0){
                        verificacaoBox = 1;
                        system("cls");
                        porCaixa(caixa);
                        do{
                            erros = 1;
                            printf("[1] Escolher outra caixa        [2] Voltar ao MENU\n");
                            fflush(stdin);
                            scanf("%d", &erros);
                            if(erros == 1){
                                system("cls");
                                teste = 1;
                                erros = 0;
                            }else if(erros == 2){
                                system("cls");
                                teste = 0;
                                erros = 0;
                            }else if((erros != 1) || (erros != 2) ) {
                                printf("Esta opcao nao existe, digite uma opcao valida!\n");
                                erros = 1;
                            }
                            
                        }while(erros == 1);
                }else if(strcmp(caixa, "0\n") == 0){
                    teste = 0;
                    verificacaoBox = 1;
                }
                if(verificacaoBox == 0){
                        system("cls");
                        printf(">>>>> Por favor digite um valor valido! <<<<\n\n");
                }
                
            }while(teste == 1);
        }else if(opcaoMenu == 5){ //SAIR
            system("cls");
            printf("MENSAGEM DO APP: 'Obrigado por utilizar nosso software!'\n");
            system("\nPAUSE");
            exit(1);
        }else{
            printf(">> Opcao invalida! <<\n");
            system("PAUSE");
        }
    }while(testeMenu == 0);
}

listarRevistas(char tipo[]){ //Mostrar todas as revistas do arquivo.

int k = lerDados();
setDados();
int quantArray = k/9;
int i = 0;

printf("Autor: Henrique Fratoni Motton - RA: 20061774-5 - Engenharia de Software - Modulo 52\n");
printf("\n>>>> TODAS as Revistas: <<<<\n");

    for(i=0; i<quantArray; i++){
        if(strcmp(d1[i].tipo, tipo) == 0){
          imprimirDado(i);
        }

    }

}

listarLivros(char tipo[]){ //Mostrar todos os livros do arquivo.

int k = lerDados();
setDados();
int quantArray = k/9;
int i = 0;

printf("Autor: Henrique Fratoni Motton - RA: 20061774-5 - Engenharia de Software - Modulo 52\n");
printf("\n>>>> TODOS os livros: <<<< \n");

    for(i=0; i<quantArray; i++){
        if(strcmp(d1[i].tipo, tipo) == 0){
          imprimirDado(i);
        }

    }

}

porCaixa(char caixa[]){ //Motrar dados do arquivo, por caixa.
int k = lerDados();
setDados();
int quantArray = k/9;
int i = 0;
char caixaView[1];

printf("Autor: Henrique Fratoni Motton - RA: 20061774-5 - Engenharia de Software - Modulo 52\n");

printf("\n>>>> CAIXA selecionada: %s", caixa);

    for(i=0; i<quantArray; i++){
        if(strcmp(d1[i].caixa, caixa) == 0){
          imprimirDado(i);
        }

    }
}

int lerDados(){ //ler dados do arquivo.
    char leitora[200];
    int i=0;

    ler = fopen(url, "r");
    if(ler == NULL){
        printf("ERRO na abertura do arquivo!! -- leitura");
    }else{  
            while(fgets(leitora, 3000, ler) != NULL && (i<3000)){   
                armazenamento[i] = malloc(sizeof(char) * 3000);
                strcpy(armazenamento[i], leitora);
                i=i+1;
            }
        
        fclose(ler);
    }
    return i; //Quantidade de linhas lidas no arquivo.
}

int setDados(){ //Cria os devidos Structs conforme uma caixa obtem um novo dado.
    int posInicial = 0;
    int teste = 0;
    int k = lerDados();
    int quantArray = k/9;

    while((posInicial<=k) && (teste<quantArray)){
        strcpy(d1[teste].titulo, armazenamento[posInicial]);
        d1[teste].edicao = armazenamento[posInicial = posInicial+1];
        strcpy(d1[teste].nomeAutor, armazenamento[posInicial = posInicial+1]);
        strcpy(d1[teste].editora, armazenamento[posInicial = posInicial+1]);
        strcpy(d1[teste].isbn, armazenamento[posInicial = posInicial+1]);
        d1[teste].exemplares = armazenamento[posInicial = posInicial+1];
        d1[teste].ano = armazenamento[posInicial = posInicial+1];
        d1[teste].tipo = armazenamento[posInicial = posInicial+1];
        d1[teste].caixa = armazenamento[posInicial = posInicial+1];
        posInicial = posInicial + 2;
        teste= teste+1;
    }
    return teste-1; //retorno do indice do ultimo dado cadastrado.
}

incluirDados(){ //Inclusão de novos dados no arquivo.
    int i=0, l=0,  verificacao = 0, validaCaixa = 0;
    char dados[200];
    incluir = fopen(url, "a");
    if(incluir == NULL){
        printf("ERRO na abertura do arquivo!! -- inclusão");
    }else{
        printf("Digite o titulo da obra: \n");
        fflush(stdin);
        fgets(dados, 200, stdin); 
        fprintf(incluir, "\n%s", dados);
        
        printf("Digite qual a edicao: \n");
        fflush(stdin);
        fgets(dados, 200, stdin); 
        fprintf(incluir, "%s", dados);
        
        printf("Digite o nome do autor: \n");
        fflush(stdin);
        fgets(dados, 200, stdin); 
        fprintf(incluir, "%s", dados);
        
        printf("Digite a editora: \n");
        fflush(stdin);
        fgets(dados, 200, stdin); 
        fprintf(incluir, "%s", dados);
        
        printf("Digite o ISBN da obra: \n");
        fflush(stdin);
        fgets(dados, 200, stdin); 
        fprintf(incluir, "%s", dados);
        
        printf("Quantidade de exemplares: \n");
        fflush(stdin);
        fgets(dados, 200, stdin); 
        fprintf(incluir, "%s", dados);
        
        printf("Digite o ano da obra: \n");
        fflush(stdin);
        fgets(dados, 200, stdin); 
        fprintf(incluir, "%s", dados);
        
        printf("Selecione o tipo da obra: \n");
        printf("[1] Livro       [2] Revista\n");
        fflush(stdin);
        fgets(dados, 200, stdin); 
        fprintf(incluir, "%s", dados);
        
        printf("Selecione o numero correspondente a caixa que deseja armazenar a obra: \n");
        printf("Caixa: 1\n");  
        printf("Caixa: 2\n");
        printf("Caixa: 3\n");
        fflush(stdin);
        fgets(dados, 200, stdin); 
        fprintf(incluir, "%s", dados); 
        fclose(incluir);

        printf("Registro incluido com sucesso!\n");
        system("PAUSE");
            
    }

}

int main(){
 menu();
}