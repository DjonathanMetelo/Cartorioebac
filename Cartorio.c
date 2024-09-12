#include <stdio.h>  //Biblioteca com fun��es de comunica��o com o usuario
#include <stdlib.h> //Biblioteca de aloca��o de espa�o de memoria para variaveis e arrays
#include <locale.h> //Biblioteca de aloca��o de Texto por regi�o
#include <string.h> //Biblioteca que possibilita o uso de strings ou seja variaveis do tipo char que aceitam receber mais de um caracter

int registro () //Cria a fun��o registro e atribui a ela a propriedade "int" de "integer" (ou inteiro)
{
	
	 setlocale(LC_ALL, "Portuguese"); //Avisa ao codigo que todo o texto daqui pra frente pode aceitar acentua��o e caracteres especias em portugues
	
	 char arquivo[40]; //cria a variavel "arquivo", atribui a ela a propriedade caracter ("char" de "character") e transforma ela em uma "string" aceitando um valor setado (no caso o valor entre [] que corresponde a "40") de mais de um caracter
	 char cpf[40];
	 char nome[40];
	 char sobrenome[40];
	 char cargo[40];
	 
	 printf("Digite o cpf a ser cadastrado: "); //"Printa" na tela o texto entre aspas desejado
	 scanf("%s", cpf); //"escaneia" a tela do usuario esperando ele inserir os dados para a variavel "cpf", sendo "%s" o aviso que a variavel vai receber em uma string
	
	 strcpy(arquivo, cpf); //Copia os dados dentro da string "cpf" para a string "arquivo", sendo a primeira variavel em referencia a que vai receber os dados e a segunda a que vai prover os dados
     
	 FILE *file; // cria um arquivo usando a fun��o "FILE", sendo "file" o nome do arquivo dentro desta fun��o
	 file = fopen(arquivo, "w"); //cria um arquivo na maquina setando como nome o conteudo dentro de uma variavel, sendo a variavel "arquivo" a referencia do nome do arquivo e "w" sendo o comando de escrever (do ingles "write")
	 fprintf(file, cpf); //Salva dentro do arquivo a variavel depois da virgula (nesse caso a variavel cpf)
	 fclose(file); //fecha o arquivo
	 
	 file =fopen(arquivo, "a"); //abre o arquivo, que tem seu nome correspondente setado pela variavel "arquivo"
	 fprintf(file,", "); //Salva dentro do arquivo a frase escrita entre aspas (nesse caso: ", ")
	 fclose(file);
	 
	 printf("Digite o nome a ser cadastrado: ");
	 scanf("%s", nome);
	 
	 file = fopen(arquivo, "a");
	 fprintf(file, nome);
	 fclose(file);
	 
	 file =fopen(arquivo, "a");
	 fprintf(file,", ");
	 fclose(file);
	 
	 printf("Digite o sobrenome a ser cadastrado: ");
	 scanf("%s", sobrenome);
	 
	 file = fopen(arquivo, "a");
	 fprintf(file, sobrenome);
	 fclose(file);
	 
	 file =fopen(arquivo, "a");
	 fprintf(file,", ");
	 fclose(file);
	 
	 printf("Digite o cargo a ser cadastrado: \n"); //"\n" pula para a proxima linha
	 scanf("%s", cargo);
	 
	 file = fopen(arquivo, "a");
	 fprintf(file, cargo);
	 fclose(file);
	 
	 system("pause"); //pausa a tela ate que o usuario pressione novamente o enter
		
}

int consulta ()
{
	
	 setlocale(LC_ALL, "Portuguese"); //Avisa ao codigo que todo o texto daqui pra frente pode aceitar acentua��o e caracteres especias em portugues
	 
	 char cpf[40];
	 char conteudo[200];
	 
	 printf("Digite o CPF a ser consultado: ");
	 scanf("%s", cpf);
	 
	 FILE *file;
	 file = fopen(cpf, "r"); //Abre e le o arquivo correspondente ao valor da variavel referenciada, sendo nesse caso a variavel "cpf" e "r" sendo o comando de ler
	 
	 if(file == NULL) //Adiciona uma condicional que vai realizar o codigo abaixo caso ocorra a consid��o setada entre parenteses, nesse caso caso o valor dentro de "file" seja igual a nulo ("NULL")
	 {
	 	
	 	 printf("N�o foi possivel abrir o arquivo, n�o localizado!. \n");
	 	
	 }
	 
	 while(fgets(conteudo, 200, file) != NULL) //Adiona uma condicional que vai se repetir enquanto a condi��o entre parenteses for verdadeira, nesse caso enquanto o valor n�o for nulo
	  //*fgets* -> pega os valores dentro do arquivo e copia eles pra uma variavel, sendo o arquivo a ser lido o arquivo "file" e a variavel conteudo a variavel que vai receber os dados

	 {
	 	
	 	 printf("\nEssas s�o as informa��es no usuario: ");
	 	 printf("%s", conteudo); //Printa na tela os valores contidos dentro da variavel sendo antes da virgula o tipo de variavel e apos a virgula o nome da variavel referenciado, nesse caso usando "%s" para dizer que � uma variavel do tipo "string" 
	 	 printf("\n\n");
	 	
	 }
	 
	 fclose(file);
	 
	 system("pause");
}

int deletar ()
{
	 setlocale(LC_ALL, "Portuguese");
	
	 char cpf[40];
	 
	 printf("Digite o CPF do usu�rio a ser deletado: ");
	 scanf("%s", cpf);
	 
	 FILE *file;
	 file = fopen(cpf, "r");
	 fclose(file);
	 
	 remove(cpf);
	
	 if(file == NULL)
	 {
	 	 printf("O usuario n�o se encontra no sistema!.\n");
	 }
      
    system("pause");
   	 
}

int main () //Cria a fun��o Main, que vai ser referenciada como sendo a principal, e atribui a ela a propriedade "int" de "integer" (ou inteiro)
    {
	
     setlocale(LC_ALL, "Portuguese");
	
 	 int opcao=0; //cria a variavel "opcao", atribui a ela a propriedade de numeros inteiros (int), e nesse caso, insere o valor 0 na variavel pra n�o deixala vaga para uso
 	 int laco=1;
 	 char senhaDigitada[10]="a";
 	 int comparacao;
 	 
 	 printf("\tCart�rio da EBAC\n\n");	//aonde "\t" centraliza o texto
 	 printf("Login de Administrador\n\nDigite a senha de acesso: ");
 	 scanf("%s", senhaDigitada);
 	 
 	 comparacao = strcmp(senhaDigitada, "admin");
 	 
 	 if(comparacao == 0)
	  {
 	 
 	     for(laco==1;laco==1;) //Cria a condi��o de gatilho relacionado a uma variavel (no caso "laco==1"),
	      {
	
             system ("cls"); //limpa a tela, nesse caso, todo o come�o do loop	
	
 	         setlocale(LC_ALL, "Portuguese"); 
	
 	         printf("\tCart�rio da EBAC\n\n");
 	         printf("Escolha a op��o desejada: \n\n");
 	         printf("\t1 - Registrar Nomes\n");	
 	         printf("\t2 - Consultar Nomes\n");	
 	         printf("\t3 - Deletar Nomes\n\n");	
 	         printf("\t4 - Sair do Sistema\n\n");
 	         printf("Op��o: ");		
	
 	         scanf("%d", &opcao); //"escaneia" a tela do usuario esperando ele inserir o valor para a variavel "opcao", sendo "%d" o aviso que a variavel vai receber numeros inteiros
	
     	     system("cls"); 
	
	         switch(opcao) //Condiciona a execu��o de uma linha de codigo baseado no valor dentro da variavel entre par�nteses (no caso a variavel "opcao")
	         {
	     	     case 1: //codigo que sera executado caso o valor dentro da variavel estipulada acima seja correspondente (nesse caso o valor "1")
	     	         registro(); //chama a uma fun��o, nesse caso a fun��o registro
		         break; //fecha a condi��o acima
		     
			     case 2:
	     	         consulta();
		         break;
			  
			     case 3:
	     	         deletar();
		         break;
		     
		         case 4:
		     	     printf("Obrigado por Utilizar o sistema!\n");
		     	     return 0;
		         break;
		      
		         default: //Caso o valor dentro tra variavel n�o corresponda a nenhum caso acima, se executa o codigo abaixo (nesse caso qualquer valor que n�o seja "1", "2" ou "3"
		    	     printf("Op��o indisponivel!\n");
		             system("pause");
		         break; 
		     }
	

 	      } 
      } 
	  
	else
	  system("cls");
	  printf("\n\nSenha Incorreta!\n\n");
      
    }


