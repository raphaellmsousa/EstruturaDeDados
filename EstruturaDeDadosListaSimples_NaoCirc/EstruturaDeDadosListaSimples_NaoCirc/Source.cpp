#include<stdio.h>							   
#include<stdlib.h>

int menu();
void InserirMusica();
void Listar();

struct ElementoDaLista_Simples {
	char nomeDaMusica[50];
	char nomeDoArtista[50];
	float duracao;
	struct ElementoDaLista_Simples* prox;
} *Head;

int  main() {
	int op, num, pos, c;
	Head = NULL;
	char musica[50];

	while (1) {
		op = menu();
		switch (op) {
		case 1:
			InserirMusica();
			break;				
		case 2:
			Listar();
			break;
		case 3:
			return 0;
		default:
			printf("Invalido\n");
		}
	}
	return 0;
}

//Função Menu
int menu() {
	int op, c;
	system("Cls");

	printf("1. Inserir Musica\n");	
	printf("2. Listar Musicas\n");
	printf("3. Sair\n");
	printf("Digite sua escolha: ");

	scanf_s("%d", &op);
	while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.

	system("Cls");
	return op;
}

//Insere músicas no início da lista
void InserirMusica()
{
	int c;
	ElementoDaLista_Simples* NovoElemento;
	NovoElemento = (struct ElementoDaLista_Simples*)malloc(sizeof(struct ElementoDaLista_Simples));
	
	printf("Inserir nome da musica: ");    
	fgets(NovoElemento->nomeDaMusica, 50, stdin); //Leitura do nome
	fflush(stdin);
	
	printf("Inserir nome do artista: ");  
	fgets(NovoElemento->nomeDoArtista, 50, stdin); //Leitura do nome
	fflush(stdin);

	printf("Inserir duracao da musica: ");    
	scanf_s("%f", &NovoElemento->duracao);    
	while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.

	if (Head == NULL)
	{
		Head = NovoElemento;
		Head->prox = NULL;
	}
	else
	{
		NovoElemento->prox = Head;
		Head = NovoElemento;
	}
}

//Função para apresentar a lista no terminal
void Listar() { //listar    
	ElementoDaLista_Simples* ElementoVarredura;
	ElementoVarredura = (struct ElementoDaLista_Simples*)malloc (sizeof(struct ElementoDaLista_Simples));
	ElementoVarredura = Head;    
	if (ElementoVarredura ==  NULL) {        
		printf("\n Lista vazia!" );        
		return;    
	}    
	while (ElementoVarredura !=  NULL) {       
		printf("\n###### MINHA PLAYLIST ATUAL ######\n\n");
		while (ElementoVarredura !=  NULL) {           
			printf("Musica: %s", ElementoVarredura->nomeDaMusica);
			printf("Artista: %s", ElementoVarredura->nomeDoArtista);            
			printf("Duracao: %f\n\n", ElementoVarredura->duracao);   
			ElementoVarredura = ElementoVarredura->prox;        
		}                    
	}    
	printf("\n");

	system("pause");
	return;
}