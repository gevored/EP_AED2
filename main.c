
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define INF 1000000000

//gcc mainc -o main    isso compila
//main isso executa

FILE *arq;
double **matriz;
int qtdV ;
int *pai;

int maximumCost = 65535;

void printMatriz(){
	
int j,x;

	for( j=0;j<qtdV;j++){
		for(x=0;x<qtdV;x++){			
		printf("%.2lf   ",matriz[j][x]);
		}
		printf("\n");
	}	
}

int BuscaPrimeiroElemento(){
	int coord [2];
	int i,j;
	
	for(i =0 ; i<qtdV;i++){
		for(j =0 ; j<qtdV;j++)
		if(matriz[i][j] != 0){
			
			coord[0]=i;
			coord[1]=j;
			float peso = matriz [i][j];
		//	printf("%d %d %lf",coord[0],coord[1], matriz[i][j]);
			return i;		
		}
	}
}

int VrificaAresta(int i, int j){
	
	if(matriz[i][j] != 0 || matriz[j][i] != 0){
		return 1;
	}else{
		return 0;
	}	
}

float CapturaPeso(int i , int j){
	
	if(matriz[i][j] != 0){
		return matriz[i][j];
	}else{
		return matriz[j][i];
	}
}

GerarSaida(){
	float somatoria =0;
	int i;
	
	for (i = 0; i<qtdV;i++){
		somatoria = somatoria + CapturaPeso(pai[i],i);	
	}		
	char url[]="saida.txt";
	char ch;
	FILE *arq;		
	
	arq = fopen(url, "w");
	
	if(arq == NULL)
		printf("Erro, nao foi possivel abrir o arquivo\n");
	else{
		fprintf(arq,"%.2lf\n",somatoria);		
		
		for(i=1;i<qtdV;i++){			
	
		fprintf(arq,"%d %d\n",pai[i],i);		
		//	printf("%d %d\n",pai[i],i);	
		}
	}	
}

void AlgPrim(){
	
	int origi = BuscaPrimeiroElemento();
	int i,j,dist,primeiro;
	double menorPeso;
	
	pai = (int *) malloc(qtdV*sizeof(int));
	
	for(i=0; i<qtdV;i++){
		pai[i]=-1;
	}
	pai[origi] = origi;
	
	while(1){
		primeiro =1;
		for(i=0;i<qtdV;i++){ //percorrer todos os vértices no array pai
			if(pai[i] != -1){ //indicador de vértice visitado
				for(j=0;j<qtdV;j++){
					//procurar o menor peso do vertice i
					if(VrificaAresta(i,j)){
						if(pai[j] ==-1){
							if(primeiro){
								menorPeso = CapturaPeso (i,j);
								origi = i;
								dist =j;
								primeiro = 0 ;								
							}// 1º if
							else{
								if(menorPeso > CapturaPeso (i,j)){
									menorPeso = CapturaPeso (i,j);
									origi =i;
									dist =j;
								}	
							}
						}//2º if 
					}			
				}
			}			
		}		
		if(primeiro ==1){
				break;
		}			
		pai[dist]=origi;		
	}		
}

PreencheMatriz(){
	
	int vOrigem,vDestino ;	
	double peso;
	
	while( (fscanf(arq,"%d %d %lf\n", &vOrigem, &vDestino, &peso))!=EOF ){
	 	
	int	i= (int) vOrigem;
	int	j= (int) vDestino;
	double d  = peso;
		
	matriz[i][j] = d;
	}
	//printMatriz();		
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
	   //printf("\n");       
	}
//printMatriz(qtdV);
}

int LerPrimeiraLinha(){
	
	int *qtdVertice ;
	int *qtdAresta ;

	char url[] = "entrada2.txt";
		
	arq = fopen(url, "r");
	
	if(arq == NULL)
			printf("Erro, nao foi possivel abrir o arquivo\n");
	else{
		while( (fscanf(arq,"%d %d\n", &qtdVertice, &qtdAresta))!=EOF ){
		//	printf("%d %d\n", qtdVertice, qtdAresta);
				
			qtdV = qtdVertice;
			InicializaMatriz(qtdV);		
							
			 return 0;
		}
	}	
}

int main(int argc, char *argv[]) {
	
	LerPrimeiraLinha();
	PreencheMatriz();
	AlgPrim();
	GerarSaida();
	return 0;
}
