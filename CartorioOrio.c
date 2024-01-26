#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int registrar()
{
	setlocale(LC_ALL, "Portuguese");
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char idade[40];
	char cargo[40];
	
	printf("Voce Selecionou Registrar Nome!\n");
	printf("Informe o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf);
	
	FILE *file;
	file = fopen(arquivo, "w");
	fprintf(file, "CPF: %s\n", cpf);
	fclose(file);
	
	printf("Digite o Nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, "Nome: %s\n", nome);
	fclose(file);
	
	printf("Digite o Sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, "Sobrenome: %s\n", sobrenome);
	fclose(file);
	
	printf("Digite a Idade a ser cadastrada: ");
	scanf("%s", idade);
	
	file = fopen(arquivo, "a");
	fprintf(file, "Idade: %s\n", idade);
	fclose(file);
	
	printf("Digite o  Cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, "Cargo: %s\n", cargo);
	fclose(file);
	
	system("pause");	
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese");
	
	char conteudo[200];
	char cpf[40];
	
	printf("Voce Selecionou Consultar Nome!\n");
	printf("Digite o CPF a ser consultado: \n");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	system("cls");
	
	if (file == NULL)
	{
		printf("Cadastro nao enocntrado no sistema!\n");
		system("pause");
	}
	while (fgets(conteudo, 200, file) !=NULL)
	{
		printf("Essas sao as informacoes do Usuario: ");
		printf("%s", conteudo);
	
	}
	
	fclose(file);
	system("pause");
}


int deletar()
{
	char cpf[40];
	
	printf("Voce Selecionou Deletar Nome!\n");
	printf("Digite o CPF a ser DELETADO: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	if (file == NULL)
	{
		printf("Cadastro nao consta no Banco de Dados!\n");
		system("pause");
	}
	else
	{
		remove(cpf);
		printf("Cadastro DELETADO com sucesso!\n");
		system("pause");
	}
	
	
}


int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	int opcao=0;
	int x=1;
	
	for (x=1;x=1;)
	{
	
	system("cls");
	
	printf("-----Cartorio_Orio-----\n\n");
	printf("\t1-Registrar Nome\n");
	printf("\t2-Consultat Nome\n");
	printf("\t3-Deletar Nome\n");
	printf("\t4-Sair do Sistema\n");
	printf("Opcao: ");
	scanf("%d", &opcao);
	
	system("cls");
	
	switch(opcao)
	{
		case 1:
		registrar();
		break;
		
		case 2:
		consultar();
		break;
		
		case 3:
		deletar();
		break;
		
		case 4:
		printf("Obrigado por Utilizar o Sistema!\n");
		return 0;      //sair do sistema
		break;
		
		default:
		printf("Opcao selecionada esta invalida!\n");
		system("pause");
		break;
	}
	
	
    }
	
	
	
}

