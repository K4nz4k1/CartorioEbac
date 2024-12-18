#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h>//biblioteca de aloca��o de espa�o em mem�ria 
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h>//Biblioteca de strings


int registro() //fun��o de Registro 
{
	setlocale(LC_ALL,"Portuguese");
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado:");
	scanf("%s",cpf);
	
	strcpy(arquivo,cpf); //responsavel por copiar os valores das strings
	
	FILE *file;
	file = fopen(arquivo,"w"); //cria arquivo 
	fprintf(file,cpf); //salvar o valor da variavel
	fclose(file); //fecha o arquivo
	
	
	file = fopen(arquivo, "a"); //essa parte do codigo separa as informa��es registradas
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
	system("cls");
	
}
int consulta() //fun��o de consulta
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
		printf("N�o foi poss�vel encontrar este CPF.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) // Fun��o usada para a procura de um conteudo da sua escolha
	{
		printf("\nEssas s�o as informa��es do Usu�rio: ");
		printf("%s",conteudo);
	}
	
	system("pause");
	system("cls");
}

int deletar() //fun��o de deletar
{
	setlocale(LC_ALL,"Portuguese");
	
	char cpf[40];
	
	printf("Digite o CPF � ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file==NULL)
	{
		printf("\n�suario n�o foi encontrado no Sistema.\n ");
		system("pause");
	}
}


int main() //fun��o principal N�cleo da Opera��o 
 {
    int opcao=0; //o que define variaveis
	int x=1;
	char senhadigitada[]="a";
	int comparacao;
	
	 printf("\t###Cart�rio da EBAC####\n\n");
	 printf("Login de administrador \n\nDigite a sua senha: ");
	 scanf("%s",senhadigitada);
	 
	 comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
    {
    	system("cls");
      for(x=1;x=1;)
      { 
         setlocale(LC_ALL, "Portuguese"); //Selecionado para entender Portugu�s 
	    
	     printf("\t###Cart�rio da EBAC####\n\n");
	     printf("Escolha a op��o desejada do menu:\n\n");
    	 printf("\t1 - Resgistrar Nomes\n");
	     printf("\t2 - Consultar Nomes\n");
	     printf("\t3 - Deletar Nomes\n");
	     printf("\t4 - Sair do sistema\n\n");
     	 printf("Op��o: "); //fim do menu
	
         scanf("%d", &opcao); //armazena a escolha do �suario
         system("cls"); //responsavel por limpar a tela
	
	       switch(opcao) //inicio de sele��o do menu
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
	 	      printf("\tAplica��o encerrada\n");
	 	      return 0;
	 	      break;
		
			
	     	  default:
	 	      printf("Essa op��o n�o est� dispon�vel");
	     	  system("pause");
	     	  break;
           }	
      }
    }
    else
     printf("Senha incorreta");


}
