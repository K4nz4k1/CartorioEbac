#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h>//biblioteca de alocação de espaço em memória 
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h>//Biblioteca de strings


int registro() //função de Registro 
{
	setlocale(LC_ALL,"Portuguese");
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado:");
	scanf("%s",cpf);
	
	strcpy(arquivo,cpf); //responsavel por copiar os valores das strngs
	
	FILE *file;
	file = fopen(arquivo,"w"); //cria arquivo 
	fprintf(file,cpf); //salvar o valor da variavel
	fclose(file); //fecha o arquivo
	
	
	file = fopen(arquivo, "a"); //essa parte do codigo separa as informações registradas
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o Nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o Sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o Cargo a ser registrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause"); 
	
	
}
int consulta()
{
	setlocale(LC_ALL,"Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser Consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Não foi possível encontrar este CPF.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) // Função usada para a procura de um conteudo da sua escolha
	{
		printf("\nEssas são as informações do Usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
	system("pause");
}

int deletar()
{
	setlocale(LC_ALL,"Portuguese");
	
	char cpf[40];
	
	printf("Digite o CPF á ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file==NULL)
	{
		printf("\nÚsuario não foi encontrado no Sistema.\n ");
		system("pause");
	}
}


int main()//função principal Núcleo da Operação 
{
	int opcao=0;
	int x=1;
	
	for(x=1;x=1;)
 {
	system("cls");
	
	setlocale(LC_ALL, "Portuguese");//Selecionado para entender Português 
	
	printf("###Cartório da EBAC####\n\n");
	
	printf("Escolha a opção desejada do menu:\n\n");
	printf("\t1 - Resgistrar Nomes\n");
	printf("\t2 - Consultar Nomes\n");
	printf("\t3 - Deletar Nomes\n");
	printf("\t4 - Sair do sistema\n\n");
	printf("Opção: ");
	
    scanf("%d", &opcao);
	
	system("cls");
	
	switch(opcao)
	{
		case 1:
			
		registro();
		break;
		
		case 2:
		
		consulta();
		break;
		
		case 3:
			
		deletar();
		break;
	
		case 4:
		printf("\tPrograma encerrado\n\n");
		return 0;
		break;
		
			
		default:
		printf("Essa opção não está disponível");
		system("pause");
		break;
    }
	
 }
}
