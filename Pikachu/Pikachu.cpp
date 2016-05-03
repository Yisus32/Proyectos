#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define f 24
#define c 26

void color(int X);
void pikachu(int pika[f][c], int x, int y);
void pintar(int pika[f][c], int x, int y);
void gotoxy(int x, int y);
void jugar(int pika[f][c], int x, int y);

int main()
{
	system("color f0");

	int matriz[f][c], aux[f][c], x=20, y=20;

	pikachu(matriz, x, y);
	pintar(matriz, x, y);
	jugar(matriz, x, y);


	system("pause>null");
	return 1;
}


void pikachu(int pika[f][c], int x, int y){

	int i, j;

int	aux[f][c]={

	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,1,4,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,1,2,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0},			//1) NEGRO 2) AMARILLO) 3) MARRON 4) BEIGE 5) ROJO 6) BLANCO
	{0,0,0,0,1,2,2,4,1,1,1,1,1,1,1,1,1,2,2,4,1,1,0,0,0,0},
	{0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,0,0,0,0,0},
	{0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,2,2,1,1,0,0,0,0,0,0,0},
	{0,0,0,0,1,1,2,0,6,1,2,2,2,6,1,2,2,1,0,0,0,0,0,0,1,0},
	{0,0,0,0,0,1,2,2,1,1,2,2,2,1,1,2,2,1,0,0,0,0,0,1,1,0},
	{0,0,0,0,0,1,1,2,2,2,2,1,2,2,2,2,1,1,0,0,0,0,1,2,1,0},
	{0,0,0,0,0,1,2,5,2,2,2,2,2,2,2,5,2,1,1,0,0,1,2,2,1,0},
	{0,0,0,0,0,1,2,2,2,2,2,1,2,2,2,2,2,2,1,0,1,2,2,2,1,0},
	{0,0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,2,2,1,1,2,2,2,2,1,0},
	{0,0,0,0,1,1,2,2,2,2,2,2,2,2,2,2,2,2,1,1,4,4,2,2,1,0},
	{0,0,0,0,1,4,2,2,2,2,2,2,2,2,2,2,2,2,4,1,4,1,1,1,0,0},
	{0,0,0,0,1,2,2,4,2,2,2,2,2,2,2,2,4,2,2,1,1,0,0,0,0,0},
	{0,0,0,0,1,2,4,2,2,2,2,2,2,2,2,2,2,4,2,1,1,0,0,0,0,0},
	{0,0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,2,1,1,0,0,0,0,0,0,0},
	{0,0,0,0,0,1,1,2,2,2,4,4,4,2,2,2,1,1,1,0,0,0,0,0,0,0},
	{0,0,0,0,1,2,2,1,1,1,1,1,1,1,1,1,2,2,1,0,0,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},


	};

	for(i=0;i<f;i++)
	{
		for(j=0;j<c;j++)
		{
			pika[i][j]=aux[i][j];
		}
	}

	for(int k=0; k<80; k++)
	{
		gotoxy(k, 45);
		printf("%c", 220);
	}



}

void pintar(int pika[f][c], int x, int y){

	int i, j;

	gotoxy(x,y);

	for(i=0;i<f;i++)
	{

		gotoxy(x,++y);

		for(j=0;j<c;j++)
		{
		//	printf("%d",pika[i][j]);

			if(pika[i][j]==1)
			{
				color(15*16+0);
				printf("%c",219);
			}
			if(pika[i][j]==0)
			{
				printf(" ");
			}

			if(pika[i][j]==5)
			{
				color(4*16+4);
				printf("%c",254);
			}

				if(pika[i][j]==6)
			{
				color(15*16+15);
				printf("%c",254);
			}
				color(15*16+15);

			if(pika[i][j]==2)
			{
				color(14*16+14);
				printf("%c",219);
			}

				if(pika[i][j]==4)
			{
				color(6*16+6);
				printf("%c",219);
			}

		}

	}



}


void jugar(int pika[f][c],int x,int y)
{

	char tecla;

		if(kbhit)
		{
			while(1)
			{

			tecla=getch();

			if(tecla=='d' || tecla=='D')
			{
				if(x+1 !=55)
				{
					x++;
				gotoxy(x+1,y);
				printf("");
				}


			}

			if(tecla=='a' || tecla=='A')
			{
				if(x-1 !=0)
				{
				x--;
				gotoxy(x-1,y);
				printf(" ");

				}

			}

			if(tecla=='w' || tecla=='W')
			{

				for(int k=0; k<7; k++)
				{
					if(k<=3)
					{
						y--;
						gotoxy(x,y-1);
			        	printf("");
			        	pintar(pika,x,y);



					}
					if(k>=3)
					{
						y++;
						gotoxy(x,y+1);
			        	printf("");
			        	pintar(pika,x,y);
					}
					Sleep(105);
				}
			}



			pintar(pika, x, y);

		}

	}

}

void color(int X)
{
SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),X);
}


void gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
  }


