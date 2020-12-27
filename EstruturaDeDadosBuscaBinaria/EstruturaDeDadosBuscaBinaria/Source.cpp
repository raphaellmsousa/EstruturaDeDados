#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int BuscaBinaria(int vet[], int inicio, int fim, int chave);

//Estrutura de dados Heterogênea
struct ElementoDaLista_Simples {
	char nome[30];
	char email[30];
	int RU;
}; 

//Declaração de vetores com os dados dos alunos
char nomes[10][30] = { "Jefferson", "Pepi", "Pedro", "Simas", "Alex",
					"Ravi", "Mikael", "Jose", "Suiamya", "Raphaell" };

char emails[10][30] = { "jefferson@uninter.com", "pepi@uninter.com", 
						"pedro@uninter.com", "simas@uninter.com",
						"alex@uninter.com", "ravi@uninter.com",
						"mikael@uninter.com", "jose@uninter.com",
						"suiamya@uninter.com", "raphaell@uninter.com" };

int RUs[10] = { 2400001, 2400002, 2400003, 2400004, 2400005,
					2400006, 2400007, 2400008, 2400009, 2479021 };

#define TAMANHOVETOR 10

int main()
{
	int buscado, achou, i;
	struct ElementoDaLista_Simples aluno[10];
	memset(&aluno, 0x0, sizeof(aluno)); //Inicialização de memória
	
	//Inserindo os dados na struct
	for (int i = 0; i < 10; i++)
	{
		strncpy_s(aluno[i].nome, nomes[i], 30);
		strncpy_s(aluno[i].email, emails[i], 30);
		aluno[i].RU = RUs[i];
	}
		
	//Impressão dos dados cadastrados
	printf("VETOR GERADO PREVIAMENTE ORDENADO:\n");
	for (int i = 0; i < 10; i++)
	{
		printf("Aluno Uninter: %s\n", aluno[i].nome);
		printf("Email: %s\n", aluno[i].email);
		printf("RU: %d\n", aluno[i].RU);
		printf("\n");
	}
		
	printf("Por favor, informe o RU do aluno: \n");
	scanf_s("%d", &buscado);

	//Busca binária
	achou = BuscaBinaria(RUs, 0, TAMANHOVETOR - 1, buscado);

	if (achou == -1)
		printf("Aluno nao encontrado. \n");
	else
	{
		printf("\nValor encontrado na posicao %d. \n", achou);
		printf("\nAluno Uninter: %s\n", aluno[achou].nome);
		printf("Email: %s\n", aluno[achou].email);
		printf("RU: %d\n", aluno[achou].RU);
		printf("\n");
	}

	system("pause");
	return 0;
}

int BuscaBinaria(int vet[], int inicio, int fim, int chave)
{
	while (inicio <= fim)
	{
		int meio = (inicio + fim) / 2;
		if (chave > vet[meio])
			inicio = meio + 1;
		else if (chave < vet[meio])
			fim = meio - 1;
		else
			return meio;
	}
	return -1;
}