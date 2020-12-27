#include<stdlib.h>
#include<stdio.h>
#include <string.h>

struct ElementoDaArvoreBinaria {
	char nome[30];
	char email[30];
	int RU;
	struct ElementoDaArvoreBinaria *direita, *esquerda; //ponteiro para direita e esquerda do tipo da nossa struct
}; 

//Declaração de vetores com os dados dos alunos
char nomes[10][30] = { "Jefferson", "Pepi", "Pedro", "Simas", "Alex",
						"Ravi", "Mikael", "Jose", "Suiamya", "Raphaell" };
char emails[10][30] = { "jefferson@uninter.com", "pepi@uninter.com",
						"pedro@uninter.com", "simas@uninter.com",
						"alex@uninter.com", "ravi@uninter.com",
						"mikael@uninter.com", "jose@uninter.com",
						"suiamya@uninter.com", "raphaell@uninter.com"
};

int RUs[10] = { 2400001, 2400002, 2400003, 2400004, 2400005,
2400006, 2400007, 2400008, 2400009, 2479021 };

ElementoDaArvoreBinaria *Buscar(ElementoDaArvoreBinaria** ElementoVarredura, int num);
void Consultar_EmOrdem(ElementoDaArvoreBinaria*);

void Inserir(ElementoDaArvoreBinaria **ElementoVarredura, char Nome[], char Email[], int num);

struct ElementoDaArvoreBinaria aluno[10];

int main() {
	int num, c;
	ElementoDaArvoreBinaria *root;
	root = (ElementoDaArvoreBinaria*)malloc(sizeof(ElementoDaArvoreBinaria)); //alocar um espaço de memória para a raiz
	root = NULL; //raiz da árvore, valor inicial nulo

	ElementoDaArvoreBinaria* ElementoBusca;
	ElementoBusca = (ElementoDaArvoreBinaria*)malloc(sizeof(ElementoDaArvoreBinaria));
		
	memset(&aluno, 0x0, sizeof(aluno)); //Inicialização de memória
	
	//Inserindo os dados na struct
	for (int i = 0; i < 10; i++)
	{
		Inserir(&root, nomes[i], emails[i], RUs[i]);
	}

	while (true)
	{
		printf("Digite o numero a ser buscado: ");
		scanf_s("%d", &num);
		while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.
		ElementoBusca = Buscar(&root, num);
		if (ElementoBusca != 0)
		{
			printf("Valor localizado.\n");
			printf("\n\n");
			printf("\n\nRU %d\t", ElementoBusca->RU);
			printf("\nNome %s\t", ElementoBusca->nome);
			printf("\nEmail %s\t", ElementoBusca->email);
			printf("\n\n");
		}			
		else
			printf("Valor nao encontrado na arvore.\n");
		system("pause");
	}
	return 0;
}

//** significa um ponteiro para um ponteiro para uma variável
// *ElementoVarredura aponta para *root, que por sua vez, aponta para um elemento da struct
void Inserir(ElementoDaArvoreBinaria **ElementoVarredura, char Nome[], char Email[], int Num) {
	
	if (*ElementoVarredura == NULL)
	{ //SE ESTÁ VAZIO, COLOCA NA ÁRVORE	
		ElementoDaArvoreBinaria *NovoElemento = NULL;
		NovoElemento = (ElementoDaArvoreBinaria*)malloc(sizeof(ElementoDaArvoreBinaria));
		NovoElemento->esquerda = NULL;
		NovoElemento->direita = NULL;

		NovoElemento->RU = Num;
		strcpy_s(NovoElemento->nome, Nome);
		strcpy_s(NovoElemento->email, Email);
		*ElementoVarredura = NovoElemento;
		return;
	}

	if (Num < (*ElementoVarredura)->RU) //* para acessar o conteúdo que a variável aponta
	{		
		Inserir(&(*ElementoVarredura)->esquerda, Nome, Email, Num);	//ponteiro para outro ponteiro
	}
	else
	{
		if (Num > (*ElementoVarredura)->RU)
		{
			Inserir(&(*ElementoVarredura)->direita, Nome, Email, Num);
		}
	}
}

ElementoDaArvoreBinaria *Buscar(ElementoDaArvoreBinaria **ElementoVarredura, int num)
{
	if (*ElementoVarredura == NULL)
		return NULL;

	if (num < (*ElementoVarredura)->RU)
	{
		Buscar(&((*ElementoVarredura)->esquerda), num);
	}
	else
	{
		if (num > (*ElementoVarredura)->RU)
		{
			Buscar(&((*ElementoVarredura)->direita), num);
		}
		else
		{
			if (num == (*ElementoVarredura)->RU)
			{				
				return *ElementoVarredura;				
			}			
		}
	}	
}

void Consultar_EmOrdem(ElementoDaArvoreBinaria *ElementoVarredura)
{
	if (ElementoVarredura)
	{
		Consultar_EmOrdem(ElementoVarredura->esquerda);
		printf("\n%d\t", ElementoVarredura->RU);
		printf("\n%c\t", ElementoVarredura->nome);
		printf("\n%c\t", ElementoVarredura->email);
		Consultar_EmOrdem(ElementoVarredura->direita);
	}
}