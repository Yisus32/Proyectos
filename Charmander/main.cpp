#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define F 20
#define C 20

void construir(int alien[F][C]);
void pintar(int alien[F][C]);


int main()
{
  int alien[F][C];

  construir(alien);
  pintar(alien);

  system("pause>null");
  return 0;
}

void construir(int alien[F][C]){

    int aux[F][C]={
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,1,0,1,1,1,0,1,1,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
    {0,0,0,0,0,0,1,0,1,1,1,1,1,1,1,0,1,0,0,0},
    {0,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,0,0},
    {0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
    };

    int x, y;

    for(x=0;x<F;x++)
    {
        for(y=0;y<C;y++)
        {
            alien[x][y]=aux[x][y];
        }
    }


}

void pintar(int alien[F][C]){

int x, y;

    for(x=0;x<F;x++)
    {
        printf(" \n ");
        for(y=0;y<C;y++)
        {
            if(alien[x][y]==1)
                printf("%c",219);

            if(alien[x][y]==0)
                printf(" ");


        }
    }


}

void jugar(){




}
