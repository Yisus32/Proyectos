#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include "libgame.h"

#define f 30
#define c 30

 //prototipo
void construir(int mapa[f][c], int nivel);
void imprimir (int mapa[f][c]);
void jugar(int mapa[f][c],int nivel);
void creditos();
void enemigos(int mapa[f][c]);
void color(int X);

int main(int argc, char** argv) {


    int mp[f][c], nivel=1;

    construir(mp, nivel);
    imprimir( mp);
    jugar(mp, nivel);

	system("pause>null");
	return 0;
}

void construir(int mapa[f][c], int nivel)
{
    int aux[f][c]={ { 5, 5, 5,5,5,5 ,5 , 5, 5,5, 5, 5, 5, 5, 5, 5, 5, 5,5 ,5,5 ,5 , 5, 5,5, 5, 5, 5, 5, 5 },
                    {5, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 },
			        {5, 0,7,7 ,7,7 ,7 , 7, 7,7, 7, 7, 7, 0, 0, 0, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 },
                    {5, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 },
                    {5, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 },
                    {5, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0,0 ,0,0 ,0 , 0, 8,8, 8, 8, 8, 0, 5 },
                    {5, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0,0 ,0,0 ,0 , 0, 8,8, 8, 8, 8, 0, 5 },
                    {5, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 },
                    {5, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 },
                    {5, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 },
                    {5, 0, 0,0 ,8,8 ,0, 0,0,0, 0, 0, 0, 0, 0, 0, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 },
                    {5, 0, 0,0 ,8,8 ,0 , 0, 0,8, 0, 0, 0, 0, 0, 0, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 },
                    {5, 0, 0,0 ,8,8 ,0 , 0, 0,8, 0, 0, 0, 0, 0, 0, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 },
                    {5, 0, 0,0 ,8,8 ,0 , 0, 0,0, 0, 7, 7, 7, 7, 7, 7, 7,7 ,7,7 ,7 , 0, 0,0, 0, 0, 0, 0, 5 },
                    {5, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 },
                    {5, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 },
                    {5, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 },
                    {5, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 },
                    {5, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 },
                    {5, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 7,7 ,7,7 ,7 , 7, 7,7, 7, 7, 7, 0, 5 },
                    {5, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 },
                    {5, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 },
                    {5, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 },
                    {5, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 0, 0, 8, 8,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 },
                    {5, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 0, 0, 8, 8,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 },
                    {5, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 0, 0, 8, 8,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 },
                    {5, 0, 0,7 ,7,7 ,7, 7, 7,7, 7, 7, 7, 0, 0, 0, 8, 8,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 },
                    {5, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 0, 0, 8, 8,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 },
                    {5, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 },
					{ 5, 5, 5,5 ,5,5 ,5 , 5, 5,5, 5, 5, 5, 5, 5, 5, 5, 5,5 ,5,5 ,5 , 5, 5,5, 5, 5, 5, 5, 5 }
                };

    int aux2[f][c]={ { 5, 5, 5,5,5,5 ,5 , 5, 5,5, 5, 5, 5, 5, 5, 5, 5, 5,5 ,5,5 ,5 , 5, 5,5, 5, 5, 5, 5, 5 },
                    {5, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 },
			        {5, 0,7,7 ,7,7 ,7 , 7, 7,7, 7, 7, 7, 7, 7, 7, 7, 7,7 ,7,7,7 , 0, 0,0, 0, 0, 0, 0, 5 },
                    {5, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0,0 ,0,0 ,7 , 0, 0,0, 0, 8, 0, 0, 5 },
                    {5, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0,0 ,0,0 ,7 , 0, 0,0, 8, 7, 8, 0, 5 },
                    {5, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 8, 0, 0, 0,0 ,0,0 ,7 , 0, 0,0, 0, 8, 0, 0, 5 },
                    {5, 0, 0,0 ,0,0 ,8 , 0, 0,0, 0, 0, 0, 8, 7, 8, 0, 0,0 ,0,0 ,7 , 0, 0,0, 0, 0, 0, 0, 5 },
                    {5, 0, 0,0 ,0,8, 7, 8, 0,0, 0, 0, 0, 0, 8, 0, 0, 0,0 ,0,0 ,7 , 0, 0,0, 0, 0, 0, 0, 5 },
                    {5, 0, 0,0 ,0,0 ,8 , 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0,0 ,0,0 ,7 , 0, 0,0, 0, 0, 0, 0, 5 },
                    {5, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0,0 ,0,0 ,7 , 0, 0,0, 0, 0, 0, 0, 5 },
                    {5, 0, 0,0 ,0,0 ,0, 0,0,0, 0, 0, 0, 0, 0, 0, 0, 0,0 ,0,0 ,7 , 0, 0,0, 0, 0, 0, 0, 5 },
                    {5, 0, 0,0,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0,0 ,0,0 ,7 , 0, 0,0, 0, 0, 0, 0, 5 },
                    {5, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0,0 ,0,0 ,7 , 0, 0,0, 0, 0, 0, 0, 5 },
                    {5, 0, 0,0 ,0,0 ,0 , 7, 7,7, 7, 7, 7, 7, 7, 7, 7, 7,7 ,7,7 ,7 , 0, 0,0, 0, 0, 0, 0, 5 },
                    {5, 0, 0,0 ,0,0 ,0 , 7, 0,0, 0, 0, 0, 0, 0, 0, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 },
                    {5, 0, 0,0 ,0,0 ,0 , 7, 0,0, 0, 0, 0, 0, 0, 0, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 },
                    {5, 0, 0,0 ,0,0 ,0 , 7, 0,0, 0, 0, 0, 8, 0, 0, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 },
                    {5, 0, 0,0 ,0,0 ,0 , 7, 0,0, 0, 0, 8, 8, 8, 0, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 },
                    {5, 0, 0,8 ,0,0 ,0 , 7, 0,0, 0, 0, 0, 8, 0, 0, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 },
                    {5, 0, 8,7 ,8,0 ,0 , 7, 0,0, 0, 0, 0, 0, 0, 0, 0, 7,7 ,7,7 ,7 , 7, 7,7, 7, 7, 7, 0, 5 },
                    {5, 0, 0,8 ,0,0 ,0 , 7, 0,0, 0, 8, 0, 0, 0, 0, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 },
                    {5, 0, 0,0 ,0,0 ,0 , 7, 0,0, 8, 7, 8, 0, 8, 0, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 },
                    {5, 0, 0,0 ,0,0 ,0 , 7, 0,0, 0, 8, 0, 0, 0, 0, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 },
                    {5, 0, 0,0 ,0,0 ,0 , 7, 0,0, 0, 0, 0, 0, 0, 0, 0, 8,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 },
                    {5, 0, 0,0 ,0,0 ,0 , 7, 0,0, 0, 0, 0, 0, 0, 0, 8, 7,8 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 },
                    {5, 0, 0,0 ,0,0 ,0 , 7, 0,0, 0, 0, 0, 0, 0, 0, 0, 8,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 },
                    {5, 0, 0,7 ,7,7 ,7, 7, 7,7, 7, 7, 7, 0, 0, 0, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 },
                    {5, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 },
                    {5, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0,0 ,0,0 ,0 , 0, 0,0, 0, 0, 0, 0, 5 },
					{ 5, 5, 5,5 ,5,5 ,5 , 5, 5,5, 5, 5, 5, 5, 5, 5, 5, 5,5 ,5,5 ,5 , 5, 5,5, 5, 5, 5, 5, 5 }
                };




        int i, j;

        for(i=0 ;i<f; i++)
        {
            for(j=0; j<c; j++)
            {
                if(nivel==1)
                {
                 mapa[i][j]=aux[i][j];
                }
                 if(nivel==2)
                 {
                  mapa[i][j]=aux2[i][j];
                 }

            }
        }



}

void imprimir(int mapa[f][c])
{
    int x, y;

    for(x=0; x<f; x++)
    {
        printf("\n");
        for(y=0; y<c; y++)
        {
            if(mapa[x][y]==0)
            {
                color(4);
                printf("%c", 178);

            }

            if(mapa[x][y]==5)
            {
                color(2);
                printf("%c", 254);


            }

            if(mapa[x][y]==2)
            {
                color(14);
                printf("%c", 16);
            }

            if(mapa[x][y]==8)
            {
                color(10);
                printf("%c", 4);
            }

            if(mapa[x][y]==7)
            	printf(" ");

        }
    }
}

void jugar(int mapa[f][c], int nivel)
{
    int fp=2, cp=2, puntos=0;
    char tecla;

    while(tecla!='x')
    {

    printf("\nPuntaje: %d",puntos);

       	tecla=getch();
       	if(tecla=='x')
            creditos();

    mapa[fp][cp]=7;

        if((tecla== 'd' || tecla== 'D')&& (mapa[fp][cp+1]==0 || mapa[fp][cp+1]==7 || mapa[fp][cp+1]==8))
        {
            cp++;
            //system("cls");
        }

        if((tecla== 'a' || tecla== 'A') && (mapa[fp][cp-1]==0 || mapa[fp][cp-1]==7 || mapa[fp][cp-1]==8))
        {
            cp--;
            //system("cls");
        }

        if((tecla== 's' || tecla== 'S') && (mapa[fp+1][cp]==0 || mapa[fp+1][cp]==7 || mapa[fp+1][cp]==8))
        {
            fp++;
            //system("cls");
        }

        if((tecla== 'w' || tecla== 'W')&&  (mapa[fp-1][cp]==0 || mapa[fp-1][cp]==7 || mapa[fp-1][cp]==8) )
        {
            fp--;
            //system("cls");
        }

        if(mapa[fp][cp]==8)
        {
            puntos=puntos+10;
        }



          if(puntos==300)
        {
            system("cls");
            nivel++;
            construir(mapa, nivel);
            puntos=0;


        }



        mapa[fp][cp]=2;
        system("cls");
        imprimir(mapa);
        Sleep(90);






    }

}

void creditos()
{
system("cls");
printf("FIN DEL JUEGO");
printf("\nDIGGER ALPHA 1.1\nGRACIAS POR JUGAR\n UNET 2016");
system("pause>null");


}

void color(int X)
{
SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),X);
}
