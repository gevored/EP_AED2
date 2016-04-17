#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//gcc mainc -o main    isso compila
//main isso executa

FILE *arq;
int **matriz;
int qtdV ;

void printMatriz(){
	
int j,x;

	for( j=0;j<qtdV;j++){
		for(x=0;x<qtdV;x++){
		printf("%d   ",matriz[j][x]);	
		}
		printf("\n");
	}	
}

PreencheMatriz(){
	
	int *vOrigem,vDestino ;
	
	int *peso;
	
	while( (fscanf(arq,"%d %d %d\n", &vOrigem, &vDestino, &peso))!=EOF ){
		
		printf("%d,%d,%d\n", vOrigem,vDestino,peso);

	int	i= (int) vOrigem;
	int	j= (int) vDestino;
	int x  = (int) peso;

		matriz[i][j] =x;
	}
	printMatriz();		
}
	
void InicializaMatriz(int qtdV){
	
	int i,j,x;
		
	matriz = (int **) malloc(qtdV*sizeof(int *));
	
	for(i = 0 ; i<qtdV;i++){
		matriz[i] = (int*) malloc (qtdV*sizeof(int));
		
		 for (j = 0; j < qtdV; j++){ //Percorre o Vetor de Inteiros atual.
           matriz[i][j] = 0; //Inicializa com 0.
       }       
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
	return 0;
}
