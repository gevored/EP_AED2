
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//INFORMAÇÕES DE EXECUÇÃO E COMPILAMENTO
//gcc main.c -o main    					isso compila
//main .entrada.txt saida.txt				isso executa

//variáveis globais utilizadas durante o código
FILE *arq;
double **matriz;
int qtdV ;
int *pai;

//método auxiliar para verificar como foi está a matriz de adjacência
void printMatriz(){
	
int j,x;

	for( j=0;j<qtdV;j++){
		for(x=0;x<qtdV;x++){			
		printf("%.2lf   ",matriz[j][x]);
		}
		printf("\n");
	}	
}

//Método utilizado pra definir o vértice de início do algoritmo de Prim
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

// verifica se há arestas  diretas entre os vértices i e j
int VrificaAresta(int i, int j){
	
	if(matriz[i][j] != 0 || matriz[j][i] != 0){
		return 1;
	}else{
		return 0;
	}	
}

//captura o peso entre as arestas i e j
float CapturaPeso(int i , int j){
	
	if(matriz[i][j] != 0){
		return matriz[i][j];
	}else{
		return matriz[j][i];
	}
}

//método pra gerar o txt de saída
GerarSaida(char *arquivoSaida){
	float somatoria =0;
	int i;
	
	for (i = 0; i<qtdV;i++){
		somatoria = somatoria + CapturaPeso(pai[i],i);	
	}		
	char *url= arquivoSaida;
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

//Algorítmo de Prim 
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
		for(i=0;i<qtdV;i++){ //percorre todos os vértices do array pai 
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
							}
							//caso não seja o primeiro vértice vizinho verificar se o mesmo possui uma aresta de menor  valor
							else{
								if(menorPeso > CapturaPeso (i,j)){
									menorPeso = CapturaPeso (i,j);
									origi =i;
									dist =j;
								}	
							}
						}
					}			
				}
			}			
		}		
		if(primeiro ==1){
				break;
		}		
		//aqui inputa os pares de vértices que possuem o menor  arestas
		pai[dist]=origi;		
	}		
}

// preenche a matriz com  os valores do txt
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

// método responsável por alocar espaço para a matriz que representará o grafo	
void InicializaMatriz(int qtdV){
	
	int i,j,x;
		
	matriz = (double **) malloc(qtdV*sizeof(double *));
	
	for(i = 0 ; i<qtdV;i++){
		matriz[i] = (double*) malloc (qtdV*sizeof(double));
		
		 for (j = 0; j < qtdV; j++){ //Percorre o Vetor de Inteiros atual.
           matriz[i][j] = 0; //Inicializa a matriz com 0.
       }	   
	}
}

//ler a primeira linha  capturando as informações de quantidade de vértice e quantidade de arestas
int LerPrimeiraLinha(char *entrada){
	
	int *qtdVertice ;
	int *qtdAresta ;

	char *url = entrada;
		
	arq = fopen(url, "r");
	
	if(arq == NULL)
			printf("Erro, nao foi possivel abrir o arquivo\n");
	else{
		while( (fscanf(arq,"%d %d\n", &qtdVertice, &qtdAresta))!=EOF ){
		//	printf("%d %d\n", qtdVertice, qtdAresta);
				
			qtdV = (int) qtdVertice;
			InicializaMatriz(qtdV);		
							
			 return 0;
		}
	}	
}

int main(int argc, char *argv[]) {
	
	//O PROGRAMA DEVE SER EXECUTADO VIA LINHA DE COMANDO PASSANDO DOIS PARÂMETROS, O PRIMEIRO O ARQUIVO DE ENTRADA.TXT E O DE SAIDA.TXT			
	LerPrimeiraLinha(argv[1]);
	PreencheMatriz();
	AlgPrim();
	GerarSaida(argv[2]);
	return 0;
}
