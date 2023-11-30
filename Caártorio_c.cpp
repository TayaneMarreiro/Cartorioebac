#include <stdio.h> // biblioteca de comunicação com o usuário
#include<stdlib.h>// biblioteca de alocação de espaço de memória
#include<locale.h>//biblioteca de alocação de texto por região
#include<string.h>//biblioteca resposável por cuidar das string

int registro()// Função respónsavel por cadastrar os  usuários no sistema
{
	//inicio crição de variáveis/string
  char arquivo [40];
  char cpf[40];
  char nome[40];
  char sobrenome[40];
  char cargo [40];
  //final crição de variáveis/string
  
   printf("Digite o CPF a ser cadastrado: ");// coletando informção do usuário
   scanf("%s", cpf);//%s refere-se a string
   
   strcpy(arquivo,cpf);//Responsável por copiar os valores das string
  
   FILE *file;//cria o arquivo e o "w" signifiva escrever
   file = fopen(arquivo,"w");//cria o arquivo
   fprintf(file,cpf); // salvo o valor da variável
   fclose(file);//fecha o arquivo
   
   file = fopen(arquivo, "a");
   fprintf(file,",");
   fclose(file);
   
   printf("Digite o nome a ser cadastrado: ");
   scanf ("%s", nome);
   
   file= fopen(arquivo,"a");
   fprintf(file, nome);
   fclose(file);   
   
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
     
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s",sobrenome);
    
    file = fopen(arquivo,"a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,"," );
	fclose(file);
     
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s",cargo);
    
    file= fopen(arquivo, "a");
    fprintf(file,cargo); 
    fclose(file);
    
    system("pause");
    
  }

    int consulta()

{ 
   setlocale(LC_ALL, "portuguese"); // Definindo a linguagem
   char cpf[40];
   char conteudo[200];

    printf("Digite o CPF a ser consultado:  ");
    scanf("%s", cpf);

    FILE *file;
    file= fopen(cpf,"r");

    if(file ==NULL)
   {
   printf("Não foi possivel abrir o arquivo, não localizado.\n");
   
   }
   
   while(fgets(conteudo, 200, file)!= NULL )
   {
   
   printf("\nEssas são as informações do usuário: ");
   printf("%s", conteudo);
   printf("\n\n");
   
  	}
	
	system("pause");
  	
}

   int deletar()
{
   char cpf[40];
   
   printf("Digitar o CPF do usário a ser deletado: ");
   scanf("%s",cpf);
   
   FILE *file;
   file = fopen (cpf,"r");
   fclose(file);
   
   
   if(file == NULL)
   {
      printf("\nCPF não cadastrado!\n\n"); 
      system("pause");	
      
 }
 
    remove(cpf);
    
    if(file!=NULL)
    {
    	
    printf("\nUsuário deletado com sucesso!\n\n");
    system("pause");
    	
	}
}







    int main()
{
	int opcao=0; // Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
  	{
	setlocale(LC_ALL, "portuguese"); // Definindo a linguagem
	     
	     system("cls");

        printf("### Catório da EBAC###\n\n"); // inicio do menu
        printf("Escolha a opção desejada do menu:\n\n");
    	printf("\t1 - Registrar nomes\n");
    	printf("\t2 - Consultar os nomes\n");
    	printf("\t3 - Deletar os nomes\n\n"); 
    	printf("\Opção:"); // fim do menu
	
	
    	scanf("%d", &opcao); // armazenando a escolha do usuário
	
	    system("cls");// responsável por limpar a tela
	    
	      switch(opcao)//início da seleção do menu
	    {
		
	       case 1:
	       registro();//chamada de funções
	       break;
		
	  	  case 2:
	      consulta();
    	  break;
    	
    	   case 3:
           deletar();
       	   break;
    	
    	   
    	
    	
    	
    	default:
    	printf("Essa opção não está disponível!\n");
        system("pause");
	    break;
		
	}//fim da seleção
		
		
	}
}
	
