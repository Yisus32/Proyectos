#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>

#define F 9
#define C 41




FILE *doc;
FILE *instruc;
FILE *creditos;

int** construir(int f, int c);
void menu(int* f, int* c, int tjugar, int **mat );
void comparar(int* f, int* c, int **mat);
void pintar(int* f, int* c, int **mat, int tjugar);
void instrucciones();
void cargar_score(int d);
void credi();
void color(int X);
void gotoxy(int x,int y);
//void guardar(int i, int j, int *f, int *c, int x);

int main()
{

	int filas, columnas, jugar=1,i,j;
	int **matriz, logo[F][C];
	char opc;

	//PlaySound(("04_All_of_Us"), NULL,SND_FILENAME|SND_LOOP|SND_ASYNC); //-lwinmm

	int k,l,p=17, q=26;

	srand(time(0));

    char tecla, resp;

    system("cls");

    int aux[F][C]={
     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
     {0,1,1,1,1,0,2,0,0,0,0,3,3,3,3,0,4,4,4,4,0,1,1,0,0,0,0,3,3,3,0,2,2,2,2,2,0,0},
     {0,1,0,0,0,0,2,0,0,0,0,3,0,0,3,0,4,0,0,4,0,1,0,1,0,0,0,0,3,0,0,0,0,2,0,0,0,0},
     {0,1,1,1,1,0,2,0,0,0,0,3,0,0,3,0,4,0,0,4,0,1,0,0,1,0,0,0,3,0,0,0,0,2,0,0,0,0},
     {0,1,0,0,0,0,2,0,0,0,0,3,0,0,3,0,4,0,0,4,0,1,0,0,1,0,0,0,3,0,0,0,0,2,0,0,0,0},
     {0,1,0,0,0,0,2,0,0,0,0,3,0,0,3,0,4,0,0,4,0,1,0,1,0,0,0,0,3,0,0,0,0,2,0,0,0,0},
     {0,1,0,0,0,0,2,2,2,2,0,3,3,3,3,0,4,4,4,4,0,1,1,0,0,0,0,3,3,3,0,0,0,2,0,0,0,0},
     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    };

    for(k=0;k<F;k++)
    {
        for(l=0;l<C;l++)
        {
            logo[k][l]=aux[k][l];
        }
    }

    for(k=0;k<F;k++)
    {
        gotoxy(p,++q);
        printf("\t");

        for(l=0;l<C;l++)
        {
            if(logo[k][l]==1)
            {
                color(10);
                printf("%c",219);
            }

            if(logo[k][l]==2)
            {
                color(11);
                printf("%c",219);
            }

            if(logo[k][l]==3)
            {
                color(12);
                printf("%c",219);
            }

            if(logo[k][l]==4)
            {
                color(13);
                printf("%c",219);
            }

            if(logo[k][l]==0)
            {
                printf(" ");
            }

        }

    }





    color(0*16+14); gotoxy(30,40);printf("A) NUEVA PARTIDA");
    color(0*16+10); gotoxy(30,41);printf("B) COMO JUGAR");
    color(0*16+12); gotoxy(30,42);printf("C) CREDITOS");
    color(0*16+13);	gotoxy(30,43);printf("X) SALIR DEL JUEGO");




        do{

        tecla=getch();
        tecla=tolower(tecla);


    	switch(tecla)
		{


			case 'a' :
			system("cls");
            gotoxy(26,4); color(0*16+13); printf(" ___MODO DE JUEGO___");
			gotoxy(28,6); color(0*16+11); printf("E) FACIL 10X10\n");
			gotoxy(28,7); color(0*16+12); printf("M) MEDIO 15X15\n");
			gotoxy(28,8); color(0*16+10); printf("D) DIFICIL 20X20\n");
			gotoxy(28,9); color(0*16+14); printf("X) MENU PRINCIPAL\n");


             do{
             fflush(stdin);
                resp=getch();
                resp=tolower(resp);

            switch(resp)
                {

                    case 'e':
                        //system("cls");
                        filas=10; //movimientos 17
                        columnas=10;

                matriz=construir(filas, columnas);
    			 pintar(&filas, &columnas, matriz, jugar);
     			comparar(&filas, &columnas, matriz);

                      break;

                      case 'm':
                        //system("cls");
                        filas=15; //movimientos 27
                        columnas=15;
                        matriz=construir(filas, columnas);
                    pintar(&filas, &columnas, matriz, jugar);
                    comparar(&filas, &columnas, matriz);

                     break;

                     case 'd':
                        //system("cls");
                        filas=20;	//movimientos 36
                        columnas=20;
                        matriz=construir(filas, columnas);
                        pintar(&filas, &columnas, matriz, jugar);
                        comparar(&filas, &columnas, matriz);
                    break;

                     case 'x':
                        main();
                        break;

                    }
                   }while(resp!='e' || resp!='m' || resp!='d' || resp!='x');

               break;




                     case 'b':
                        instrucciones();
                        printf("\n\nPresione x para regresar...\n\n");
                        int regresar;
                        regresar=tolower(regresar);
                        regresar=getch();

                        if(regresar=='x')
                        main();

                        break;

                    case 'c':
                        system("cls");
                        credi();
                        regresar=tolower(regresar);
                        regresar=getch();

                        if(regresar=='x')
                        main();
                    break;

                    case'x':
                    	system("cls");
                    	gotoxy(25,25); printf("Seguro que desea salir S/N?");

						do{

						regresar=tolower(regresar);
						regresar=getch();

						if(regresar=='s')
						{
						exit(1);
						system("cls");
						}

                    	else
						{
                    		if(regresar=='n')
                    		main();
						}

						}while(regresar!='s' || regresar!='n');





            }
        }while(tecla!='a' || tecla!='b' || tecla!='c' || tecla!='d' || tecla!='x' );




    system("pause>null");
    free(matriz);
	return 0;
}


void instrucciones()
{
   int x;
   char s;
   system("cls");
    char lectura[200];

    instruc=fopen("instrucciones.txt","r");

    for(x=0;x<8;x++)
    {
    fscanf(instruc," %[^\n]",&lectura);
    printf("\n\n");
    printf(" %s ",lectura);
    }

     printf("\n\n Presione x para regresar...");


	do{

	s=getch();
    s=tolower(s);

	if(s=='x')
	{
		main();

	}

	}while(s!='x');



}

void credi()
{
    int y;
    char lectura[200], s;

    creditos=fopen("creditos.txt","r");

     for(y=0;y<3;y++)
    {
    fscanf(creditos," %[^\n]",&lectura);
    printf("\n\n");
    printf(" %s ",lectura);
    }

    printf("\n\n Presione x para regresar...");

    do{

	s=getch();
    s=tolower(s);

	if(s=='x')
	{
		main();

	}

	}while(s!='x');

}



void pintar(int* f, int* c, int **mat, int tjugar)
{


	int i, j, d=0,k=0,h=0,v=0;

	for(i=0;i<*f;i++)
	{
		printf("\n");

		for(j=0;j<*c;j++)
		{

	    //printf(" %d ",mat[i][j]);

	    	if(mat[i][j]==0)
            {
                if(tjugar==1)
				{
					color(0*16+13);
				}

				if(tjugar==2)
				{
					color(0*16+14);
				}

				if(tjugar==3)
				{
					color(0*16+12);
				}

				if(tjugar==4)
				{
					color(0*16+10);
				}

				if(tjugar==5)
				{
					color(0*16+3);
				}

				if(tjugar==6)
				{
					color(0*16+11);
				}

				//color(1);

                printf("%c",219);
                 printf("%c",219);

            }


            if(mat[i][j]==1)
            {
                color(13);

                printf("%c",219);
                printf("%c",219);

            }

            if(mat[i][j]==2)
            {
                color(14);

                printf("%c",219);
                 printf("%c",219);

            }

            if(mat[i][j]==3)
            {
                color(12);

                printf("%c",219);
                 printf("%c",219);

            }

            if(mat[i][j]==4)
            {
                color(10);
                printf("%c",219);
                 printf("%c",219);

            }

            if(mat[i][j]==5)
            {
                color(3);
                printf("%c",219);
                 printf("%c",219);

            }

            if(mat[i][j]==6)
            {
                color(11);
                printf("%c",219);
                 printf("%c",219);

            }
	    }
    }


    for(i=0;i<*f;i++)
    {
        for(j=0;j<*c;j++)
        {

        if(*f==10 && *c==10)
        {
            if(mat[i][j]==0)
            {
                 k++;

                if(k==100)
                {   system("cls");
                    color(15); printf(" GANASTE! ");
                    getch();
                    main();
                }
            }
        }

           if(*f==15 && *c==15)
            {
                if(mat[i][j]==0)
                {
                    k++;

                    if(k==225)
                    {
                    system("cls");
                    color(15); printf(" GANASTE! ");
                    getch();
                    main();
                    }
                }
            }

            if(*f==20 && *c==20)
            {
                if(mat[i][j]==0)
                {
                    k++;

                    if(k==400)
                    {
                    system("cls");
                    color(15); printf(" GANSTE! ");
                    getch();
                    main();
                    }
                }
            }
        }
    }






        printf("\n\n");
        gotoxy(40,4); color(0*16+13); printf(" 1 %c ",219);
        gotoxy(40,5); color(0*16+14); printf(" 2 %c ",219);
        gotoxy(40,6); color(0*16+12); printf(" 3 %c ",219);
        gotoxy(40,7); color(0*16+10); printf(" 4 %c ",219);
        gotoxy(40,8); color(0*16+3); printf(" 5 %c ",219);
        gotoxy(40,9); color(0*16+11); printf(" 6 %c ",219);


}



int** construir(int f, int c)
{

    srand(time(0));

	int n,i,j,fil,col;
	int **mat; //puntero para la matriz

	mat = (int**) malloc (f*sizeof(int*)); //se asigna memoria a las filas

	for(i=0;i<f;i++)
	{
		mat[i]=(int*) malloc(c*sizeof(int));	//se asigna memoria a las columnas
	}

	//cargar matriz
	for(i=0;i<f;i++)
	{
		for(j=0;j<c;j++)
		{
			mat[0][0]=0;
			mat[i][j]=2+rand()%6-1;
		}
	}


	return mat;
}



void comparar(int* f, int* c, int **mat)
{
	printf("\n\n");

	int tjugar,d=0;
	int i, j, t;

	do{

    system("cls");


    if(tjugar>=1 || tjugar<=6)
		{

        if(tjugar>=1 && tjugar<=6)
		{
        d++;

		}

		if(*f==10 && *c==10)
		{
		    t=22;

		if(d>=22)
			{
				system("cls");
				printf("GAME OVER!");
				getch();
                main();
			}
	    }

		if(*f==15 && *c==15)
		{
		    t=36;

		if(d>=36)
			{
				system("cls");
				printf("GAME OVER!");
				getch();
                main();
			}
	    }

		if(*f==20 && *c==20)
		{
		    t=42;

		if(d>=42)
			{
				system("cls");
				printf("GAME OVER!");
				getch();
                main();
			}
	    }

         color(0*16+15);printf("Movimientos: %d/%d \n",d,t);
         color(11);
		}

	pintar(f,c,mat, tjugar);



	do{
       char opc;
    gotoxy(50,10); //scanf("%d",&tjugar);
    scanf("%c",&opc);
    if(isdigit(opc)){
    	tjugar  = opc-48;
	}
	else{
		tjugar=7;
	}


	}while(tjugar<1 || tjugar>6 );

	for(i=0;i<*f;i++)
	{
		for(j=0;j<*c;j++)
		{

		if(mat[i][j]==0){

				if(i+1<*f &&  mat[i+1][j]==tjugar)
			{
				mat[i+1][j]=0;

			}

			if(i-1>=0 && mat[i-1][j]==tjugar)
			{
				mat[i-1][j]=0;

			}

			if(j+1<*c && mat[i][j+1]==tjugar)
			{
				mat[i][j+1]=0;

			}

			if(j-1>=0 && mat[i][j-1]==tjugar)
			{
				mat[i][j-1]=0;

			}
        }
      }
    }

	}while(tjugar>=1 || tjugar<=6);






}

void cargar_score(int d)
{

	int x;
   char s, q;

   system("cls");


    instruc=fopen("score.txt","a");

    fscanf(doc," %c\n",q);
    printf("\n\n");

    getch();




     printf("\n\n Presione x para regresar...");


}


void color(int X)
{
SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),X);
}

void gotoxy(int x,int y)
{
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
  }


