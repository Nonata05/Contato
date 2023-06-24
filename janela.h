#ifndef TROCA_HEADER_
#define TROCA_HEADER_

#include <windows.h>
#include <stdio.h>


void gotoxy(int x, int y){
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){y-1,x-1});
}

void janela(int x1, int y1, int x2, int y2) {
    //--- SUPERIOR
    gotoxy(x1, y1);//canto superior esquerdo
    printf("%c" ,201);
    //printf("\═ ═\n");



    for(int i = y1+1; i < y2; i++){   // barra superior
        printf("%c",205);
    }

    gotoxy(x1, y2);// canto superior direito
    printf("%c", 187);

    //--- LATERAIS

    for(int i = x1+1; i < x2; i++){//lateral esquerda
        gotoxy(i, y1);
        printf("%c\n",186);
    }

    for(int i = x1+1; i < x2; i++){//lateral esquerda
        gotoxy(i, y2);
        printf("%c\n",186);
    }

    //inferior
    gotoxy(x2, y1);// canto inferior esquerdo
    printf("%c", 200);
    gotoxy(x2, y2);// canto inferior direito
    printf("%c", 188);

    // barra inferior
    for(int i = y1+1; i < y2; i++){
        gotoxy(x2, i);
        printf("%c",205);
    }

}

void label(int lin, int col, const char *texto) {
    gotoxy(lin, col);
    printf("%s", texto);
}

/*void ler_string(int lin, int col, const char *tamanho){
    printf("\033[%d;%dH%s", lin, col, tamanho);
}*/




#endif // TROCA_HEADER_

