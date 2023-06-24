#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "janela.h"


typedef struct {
    char fone[15];
    char nome[30];
}Contato;

//cadicionar contato;

void adicionarContato(){

    FILE * cont;
    cont = fopen("nome.txt","ab");
    Contato ctt;

    if(cont ==NULL){
        printf("ERRO...\n");
    }
    else{
        do{
            //char c;
            fflush(stdin);
            label(4,5," Adicionar Contato");
            label(5,5," Nome: ");
            gets(ctt.nome);

            fflush(stdin);
            label(6,5," Telefone: ");
            gets(ctt.fone);

            fwrite(&ctt, sizeof(Contato), 1, cont);

            label(8,5," Deseja continuar (s /n)?");
            if(getch()=='s'){
                system("cls");
                tela();
                adicionarContato();

            }


        }while(getche() == 's');
        fclose(cont);
        system("cls");

    }

}
//listar contato
void listar(){
    FILE * cont;
    cont = fopen("nome.txt","rb");
    Contato ctt;

    if(cont ==NULL){
        printf("ERRO...\n");
    }
    else{
        label(3,15,"Lista de Contatos.");
        label(5,5,"Nomes:");
        label(5,35,"Telefones:");
        int linha = 7;
        while( fread(&ctt, sizeof(Contato),1, cont)==1 ){
            label(linha,5,ctt.nome);

            label(linha,35,ctt.fone);
            linha = linha + 1;
        }
    fclose(cont);
    getch();

    }
//excluir contato
}

void excluir(){
    FILE*cont;//original
    FILE*CONT;//temporário
    Contato ctt;
    char nome[30];
    system("cls");
    tela();

    cont = fopen("nome.txt","rb");
    CONT= fopen("nomeTemporario.txt","ab");

    if(cont == NULL || CONT == NULL){
        printf("Erro...");
    }
    else{
        fflush(stdin);
        label(5,5,"Digite o contato a ser excluido: ");
        gets(nome);

        while(fread(&ctt, sizeof(Contato), 1, cont)==1){
            if(strcmp(nome, ctt.nome)!=0){
                fwrite(&ctt, sizeof(Contato), 1, CONT);
             }
         }
      }
    fclose(cont);
    fclose(CONT);
    remove("nome.txt");
    rename("nomeTemporario.txt","nome.txt" );
    label(7,5,"Contato excluido!\n");
    getch();
    system("cls");
    tela();
}

void tela(){
    system("cls");
    janela(1,1,24,80);
    label(2,35, "Contatos\n");
}



int main(){

    //setlocale(LC_ALL,"Portuguese");


    Contato contato;
    int op;
    do{

        tela();
        label(4,5," 1- Novo Contato\n");
        label(5,5," 2- Listar contato\n");
        label(6,5," 3- Excluir\n");
        label(7,5," 0- sair\n\n");
        label(9,5,"Digite a sua opcao: ");
        scanf( "%d",&op);



        switch (op){
        case 1:
            system("cls");
            tela();
            adicionarContato(&contato);
            tela();

            break;
        case 2:
            system("cls");
            tela();
            listar(&contato);

            break;
        case 3:

            excluir();
            break;

        case 0:

            tela();
            label(5,5,"Saindo...\n");
            system("PAUSE");
            system("cls");
            break;
         default:
            system("cls");
            tela();
            label(5,5,"Invalido...\n");
            system("PAUSE");

            break;
        }


    }while(op!= 0);


    return 0;
}




