#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//gcc mainc -o main    isso compila
//main isso executa

int **matriz;

void printMatriz(int q){
	
int j,x;

	for( j=0;j<q;j++){
		for(x=0;x<q;x++){
		printf("%d",matriz[j][x]);	
		}
		printf("\n");
	}	
}
	
void InicializaMatriz(int qtdV){
	
	int i,j,x;
		
	matriz = (int **) malloc(qtdV*sizeof(int *));
	
	for(i = 0 ; i<qtdV;i++){
		matriz[i] = (int*) calloc (qtdV, sizeof(int));
		
		 for (j = 0; j < qtdV; j++){ //Percorre o Vetor de Inteiros atual.
           matriz[i][j] = 0; //Inicializa com 0.
       }
       
	}
	
	printMatriz(qtdV);
}

int LerPrimeiraLinha(){
	
	int *qtdVertice ;
	int *qtdAresta ;

	char url[] = "entrada.txt";
	FILE *arq;
		
	arq = fopen(url, "r");
	
	if(arq == NULL)
			printf("Erro, nao foi possivel abrir o arquivo\n");
	else{
		while( (fscanf(arq,"%d %d\n", &qtdVertice, &qtdAresta))!=EOF ){
		//	printf("%d %d\n", qtdVertice, qtdAresta);
				
			InicializaMatriz((int)qtdVertice);		
							
			 return 0;
		}
	}	
	//testando push
}


int main(int argc, char *argv[]) {
	
	LerPrimeiraLinha();
	return 0;
}
