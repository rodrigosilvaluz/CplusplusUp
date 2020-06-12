#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <time.h>


using namespace std;

struct vectorx{
	int *vetor;
	int tam;
};

void inicializa(vectorx *vec, int n){
	vec->vetor = new int[n];
	vec->tam = n;
}

void finaliza(vectorx *vec){
	delete[] vec->vetor;
	vec->tam = 0;
}

//fun��o para preencher o vetor com dados aleat�rios 
void preenche(vectorx *vec){
	for(int i = 0; i < vec->tam; i++){
		vec->vetor[i] = rand() % 100;
	}
}

//concatena dois vetores, vec1 e vec2 em vec

void concatena(vectorx *vec, vectorx *vec1, vectorx *vec2){
	int tam1 = vec1->tam;
	int tam2 = vec2->tam;
	
	for(int i = 0; i < tam1; i++){
		vec->vetor[i] = vec1->vetor[i];
		
	}
	for(int i = 0; i < tam2; i++){
		vec->vetor[i+tam1] = vec2->vetor[i];
	}
}

void imprime(vectorx *vec){
	for(int i = 0; i < vec->tam; i++){
		cout << vec->vetor[i] << " ";
	}
	cout << endl;
} 

void pular_linha(int x){
	int y;
	for(y = 1; y <= x; y++)
		cout << endl;
}

/* ================================================================ */


int main()
{
	//comando de regionaliza��o
	setlocale(LC_ALL, "Portuguese");
	
	system("color 17");
	
	
	
	vectorx vec1,vec2,vec3;
	int tam1,tam2;
	
	cout << "Digite os tamanhos dos vetores 1 e 2 :" << endl;
	cin >> tam1 >> tam2 ;
	
	//inicializando gerador de n�meros aleat�rios
	srand(time(NULL));
	
	//cria��o dos vetores
	inicializa(&vec1, tam1);
	inicializa(&vec2, tam2);
	inicializa(&vec3, tam1+tam2);
	
	//preenchimento dos dados
	preenche(&vec1);
	preenche(&vec2);
	concatena(&vec3,&vec1,&vec2);
	
	//imprimindo os vetores
	imprime(&vec1);
	imprime(&vec2);
	imprime(&vec3);
	
	//desaloca��o dos vetores
	finaliza(&vec1);
	finaliza(&vec2);
	finaliza(&vec3);
	
	
	system("PAUSE");
	return 0;
}  