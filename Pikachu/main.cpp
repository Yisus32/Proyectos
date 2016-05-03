#include <iostream>
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*Uso de punteros y memoria dinamica*/
void funcion(int *p,int *q);

int main(int argc, char** argv) {
	
	int a,b,*p;// *p es un puntero
	int *vec,n,i,j,fil,col;
	int **mat; //puntero para la matriz
	p=&a; //p apunta a la direccion de memoria de a
	printf("\n\nValor de A (usando el puntero): ");
	scanf("%d",p);
	
	printf("\nEl valor de *p = %d y el valor de la variable A = %d",*p,a);
	
	printf("\n\n\t\tUsando una funcion para leer los valores de A y B");
	funcion(&a,&b); //se envia la direccion de memoria de a y de b
	printf("\n\nValor de A = %d y Valor de B = %d luego del llamado de la funcion.",a,b);
	
	//Vector dinamico
	printf("\n\nNumero de elementos del vector: ");
	scanf("%d",&n);
	//se reserva memoria para el puntero
	vec = (int *)malloc(n * sizeof(int) );
	
	for(i=0;i<n;i++){
		*vec=i+1;
 		 vec++;//se incremente la direccion de memoria
	}//for
	vec-=n;
	printf("\n\n");
	for(i=0;i<n;i++){
		printf(" %d ",*vec);
		vec++;		
	}//for
	
	//matriz dinamica
	printf("\n\nNumero de filas de la matriz: ");
	scanf("%d",&fil);
	printf("\n\nNumero de columnas de la matriz: ");
	scanf("%d",&col);	
	
	mat = (int**) malloc (fil * sizeof(int*)); //se asigna memoria a las filas
	for(i=0;i<fil;i++){
		mat[i]=(int*) malloc(col*sizeof(int));	//se asigna memoria a las columnas
	}
	//cargar matriz	
	for(i=0;i<fil;i++){
		for(j=0;j<col;j++){
			mat[i][j]=1;
		}
	}
	
	for(i=0;i<fil;i++){
		printf("\n");
		for(j=0;j<col;j++){
			printf(" %d ",mat[i][j]);
		}
	}
    
    free(vec);
	free(mat); 
	return 0;
}

void funcion(int *p,int *q){
	printf("\n\nValor de A: ");
	scanf("%d",p);
	printf("\n\nValor de B: ");
	scanf("%d",q);
	
}
