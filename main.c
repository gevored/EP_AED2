#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//gcc mainc -o main    isso compila
//main isso executa

FILE *arq;
double **matriz;
int qtdV ;

void printMatriz(){
	
int j,x;

	for( j=0;j<qtdV;j++){
		for(x=0;x<qtdV;x++){			
		printf("%.2lf   ",matriz[j][x]);
		}
		printf("\n");
	}	
}

void AlgPrim(){
	
}

PreencheMatriz(){
	
	int vOrigem,vDestino ;	
	double peso;
	
	while( (fscanf(arq,"%d %d %lf\n", &vOrigem, &vDestino, &peso))!=EOF ){
	 	
	int	i= (int) vOrigem;
	int	j= (int) vDestino;
	double d  = peso;
		
	matriz[i][j] = d;
		
	//printf("%.2lf\n",matriz[i][j]);
	}
	printMatriz();		
}
	
void InicializaMatriz(int qtdV){
	
	int i,j,x;
		
	matriz = (double **) malloc(qtdV*sizeof(double *));
	
	for(i = 0 ; i<qtdV;i++){
		matriz[i] = (double*) malloc (qtdV*sizeof(double));
		
		 for (j = 0; j < qtdV; j++){ //Percorre o Vetor de Inteiros atual.
           matriz[i][j] = 0; //Inicializa com 0.
           
           //printf("%.2lf  ",matriz[i][j] );
       }
	   
	   printf("\n");       
	}
//printMatriz(qtdV);
}

int LerPrimeiraLinha(){
	
	int *qtdVertice ;
	int *qtdAresta ;

	char url[] = "entrada.txt";

		
	arq = fopen(url, "r");
	
	if(arq == NULL)
			printf("Erro, nao foi possivel abrir o arquivo\n");
	else{
		while( (fscanf(arq,"%d %d\n", &qtdVertice, &qtdAresta))!=EOF ){
		//	printf("%d %d\n", qtdVertice, qtdAresta);
				
			qtdV = (int)qtdVertice;
			InicializaMatriz(qtdV);		
							
			 return 0;
		}
	}	
}


int main(int argc, char *argv[]) {
	
	LerPrimeiraLinha();
	PreencheMatriz();
//	AlgPrim():
	return 0;
}
