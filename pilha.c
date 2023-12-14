#include <stdio.h>
#include <windows.h>
#define TAM 10

int topo, pilha[TAM];

int menuPilha()
{
	int opc;
	
	printf ("==== MENU ====\n");
	printf ("\n1 - Criar pilha");
	printf ("\n2 - Inserir Elemento");
	printf ("\n3 - Remover Elemento");
	printf ("\n4 - Tamanho da pilha");
	printf ("\n5 - Mostrar Pilha");
	printf ("\n6 - Exibir topo");
	printf ("\n7 - Retornar maior elemento");
	printf ("\n8 - Soma dos elementos da pilha");
	printf ("\n9 - Quantidade de numeros pares");
	printf ("\n10 - Media dos elementos da pilha");
	printf ("\n11 - Multiplos de 3 da pilha");
	printf ("\n0 - SAIR");
	printf ("\n\nOpcao: ");
	scanf("%d" , &opc);
	
	return opc;
}

void criar_pilha(){
	topo=-1;
	printf ("\nA pilha foi criada\n");
}

int pilha_vazia(){
	if (topo == -1)
		return 1; //verdade
	else
		return 0; //falso
}	

int pilha_cheia(){
	if(topo==TAM-1)
		return 1; // verdade
	else
		return 0; //falso
}


void inserir_pilha(){
	int elem;
	
	if (!pilha_cheia()){
		printf ("\nValor para inserir na pilha: ");
		scanf("%d" , &elem);
		
		topo++;
		pilha[topo]=elem;
		printf ("\nValor inserido com sucesso!\n");
	}
	else
		printf ("\nA pilha esta cheia!\n");
}

int remover_pilha(){
	int valor;
	if(!pilha_vazia()){
		valor=pilha[topo];
		topo--;
	}
	else
		printf ("\nA pilha esta vazia!\n");
	
	return valor;
}

int tamanho_pilha(){
	int tam;
	
	tam=topo+1;
	
	return tam;
	
}

void mostrar_pilha(){
	int i;
	if(!pilha_vazia()){
		for (i=topo;i>=0;i--)
			printf ("\n%d\n" , pilha[i]);
	}
	else
		printf ("\nA pilha esta vazia!\n");
	
}

void exibir_topo(){
	if(!pilha_vazia()){
		printf ("\nO topo da pilha e %d\n" , pilha[topo]);
	}
	else
		printf ("\nA pilha esta vazia!\n");
}

int maior_elemento(){
	int maior=0;
	
	if(!pilha_vazia()){
		if(pilha[topo] > maior)
			maior=pilha[topo];
	}
	else 
		printf ("\nA pilha esta vazia!\n");
		
	return maior;
}

int soma_pilha(){
	int soma=0;
	int i;
	
	if(!pilha_vazia()){
		for(i=topo;i>=0;i--){
			soma+= pilha[i];
		}		
	}
	else
		printf ("\nA pilha esta vazia!\n");
	
	return soma;
}

int pares_pilha(){
	int i, cont=0;
	
	if(!pilha_vazia()){
		for(i=topo;i>=0;i--){
			if(pilha[i]>0 && pilha[i] % 2 == 0){
				cont++;
			}
		}
	}
	
	return cont;
}

void media_pilha(){
	int soma = 0, i;
	float media;
	int tamanho = tamanho_pilha();
	
	if(!pilha_vazia()){
		for(i=topo;i>=0;i--){
			soma+=pilha[i];
		}
		media = (float)soma / tamanho;
		printf ("A media da pilha e: %.2f\n" , media);
	}
	else{
		media=0;
		printf ("\nA pilha esta vazia!\n");
	}
}

void tres()
{
	int i, pos=0;
	
	if (!pilha_vazia()){
		for (i=topo;i>=0;i--){
			if(pilha[i] % 3 == 0){
				printf ("\n%d\n" , pilha[i]);
				pos=1;
			}
		}
		if(pos == 0)
			printf ("Nao ha multiplos de 3 na pilha\n");
	}
	else
		printf ("\nA pilha esta vazia!\n");
}

main()
{
	int opc;
	
	opc = menuPilha();
	while(opc != 0)
	{
		switch(opc){
			case 1: criar_pilha();
					system("pause");
					system("cls");
					break;
			case 2: inserir_pilha();
					system("pause");
					system("cls");
					break;
			case 3: printf ("\nElemento %d Removido!\n", remover_pilha());
					system("pause");
					system("cls");
					break;
			case 4: printf ("\nTamanho da pilha %d\n" , tamanho_pilha());
					system("pause");
					system("cls");
					break;
			case 5: mostrar_pilha();
					system("pause");
					system("cls");
					break;
			case 6: exibir_topo();
					system("pause");
					system("cls");
					break;
			case 7: printf ("\nMaior elemento da pilha %d\n" , maior_elemento());
					system("pause");
					system("cls");
					break;
			case 8: printf ("\nA soma dos elementos da pilha: %d\n" , soma_pilha());
					system("pause");
					system("cls");
					break;
			case 9: printf ("\nQuantidade de numeros pares e positivos da pilha %d\n" , pares_pilha());
					system("pause");
					system("cls");
					break;
			case 10: media_pilha();
					system("pause");
					system("cls");
					break;
			case 11: tres();
					system("pause");
					system("cls");
					break;
		}
		
		opc = menuPilha();
	}
}
