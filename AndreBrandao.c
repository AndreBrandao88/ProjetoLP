#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include<conio.h>
 

	void login();
	void pedido();
	void cadastro();
	void menuprincipal();
	void cabecalho();
	
	
	struct cadastro
	{
		int cod;
		char descricao[30]; 	
		float preco;
				
	};
	
	struct cadastro menu[2];
	int i;
	
int main(){
	
	setlocale (LC_ALL, "Portuguese"); //ACENTUACAO CORRETA 
	
	
	login();
	
	menuprincipal();
	
							
	
	return 0; 
} 

void login(){ 

cabecalho();

char name[20], user[6], userc[6] = "admin", senha [6], senhac[6] = "admin";
int login_efetuado = 0 ; //0 - Falso e 1 - Verdadeiro 

	
	printf("\n\n\t  Bem vindo a Lanchonete Fome Zero");
	
	while  (!login_efetuado){
	
	printf ("\n\n\t Digite a seu login: "); 
	fflush(stdin);
	gets(user);
	
	printf ("\t Digite a sua senha: ");
	fflush(stdin);
	gets(senha);
	
	if ( strcmp (user,userc)== 0 && strcmp (senha, senhac) == 0 ) {
		
		
		printf ("\nAcesso autorizado\n\n\n\n\n\n\n\n\n");
		printf ("===============================================================================\n");	
		

		login_efetuado = 1;
	
	}
			
		
	else 
	
	
	printf ("\n\nDados incorretos!!\n\n Digite a senha novamente:  \n\n");
	system ("pause");
	system ("cls");
	
				
			  }
			  
	
	printf ("\n\n\n\n Digite o seu nome:       ");
	fflush(stdin);
	gets(name);	
	system ("cls");

	printf ("\n\n\n\n                     Bem vindo ao sistema %s  O que deseja fazer?  \n\n\n", name);
	system("\n\n\n\n\n\n\npause");
	  
	  }



void pedido(){
	
	system ("cls");
	cabecalho();
	
	float total;
	int opcao, quant;

	printf ("\n===============================MENU==============================================");
	for (i=0;i<2;i++){
		printf ("===============================");
		printf ("\n\nCod: %i", menu[i].cod);
		printf ("\nDescrição: %s", menu[i].descricao);
		printf ("\nPreço: R$ %.2f\n", menu[i].preco);
		
	}
	
	printf ("\n\nDigite o seu pedido:  ");
		scanf ("%i", &opcao);
	
	
		
		total = menu[opcao-1].preco;
	
	
	printf ("\n\nDigite a quantidade:  ");
		scanf ("%i", &quant);
		
	total = total * quant;
	
	printf ("\nPedido abaixo\n");
	
	printf ("Voce pediu %i %s onde deu o valor total de R$ %.2f", quant, menu[opcao-1].descricao, total);
	
	FILE* arquivo;
	
	arquivo = fopen("pedido.txt", "a");
	
	if(arquivo){
	fprintf(arquivo, "\n=====================\n\n");	
	fprintf(arquivo, "\nCodigo do produto: %i", menu[opcao-1].cod);
	fprintf(arquivo, "\nDescrição do produto: %s", menu[opcao-1].descricao);
	fprintf(arquivo, "\nPreço total: R$ %.2f \n", menu[opcao-1].preco);
		
	fprintf(arquivo, "\n");
	
		printf("\nVenda realizada\n");
			system ("pause");
						
	}
	fclose(arquivo);
	
	menuprincipal();
	
	

}

void cadastro (){
	
	cabecalho();
	printf ("\n                               Bem vindo a tela de cadastro!!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	system ("pause");
	
	
	setlocale (LC_ALL, "Portuguese");
		
	FILE* arquivo;
	
	arquivo = fopen("menu.txt", "a");
	
	
	for (i=0;i<2;i++){
	
		system ("cls");
		cabecalho();
			
    printf ("\nDigite os dados do produto abaixo: \n");
	fflush (stdin);
	menu[i].cod = i+1;
	fflush (stdin);
	printf ("\nDescrição:  "); gets(menu[i].descricao);
	fflush (stdin);
	printf ("\n Preço: "); scanf ("%f", &menu[i].preco);
	
		
	if(arquivo){
		
	fprintf(arquivo, "Codigo do produto: %i", menu[i].cod);
	fprintf(arquivo, "Descrição do produto: %s", menu[i].descricao);
	fprintf(arquivo, "Preço: R$ %.2f \n", menu[i].preco);
		
	fprintf(arquivo, "\n");

		
		printf("Produto Cadastrado\n");
			system ("pause");
				
	}
	
	fclose(arquivo);
	
printf("Produto cadastrado\n\n\n");	
	}
	
	 menuprincipal();

}

void menuprincipal(){
	
	system ("cls");
	cabecalho();
	
	
	printf ("\n\n\n          1 - FAZER UM PEDIDO \n          2 - CADASTRAR PRODUTOS \n          3 - SAIR\n");
	int opcao;
	fflush(stdin);
	scanf ("\n\n%i", &opcao);
	
	switch (opcao){
		
			
			case 1:
				system ("cls"); 
		
				pedido(); 
				
				break;
			
			case 2:
				
				system ("cls");
							
				
				cadastro();
				
				break;
				
			case 3:
				
					system ("cls");
				
				printf ("\nObrigado por sua visita\n");
				
					system ("pause");				
								
				break;
								
	} 
	
} 

void cabecalho(){
	
	printf ("-----------------------------------------------------------------------------------------------------------\n");
	printf ("                                         LANCHONETE FOME ZERO\n");
	printf ("-----------------------------------------------------------------------------------------------------------\n\n");
}
