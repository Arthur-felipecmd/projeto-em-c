
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
struct Struct_NO{
       int no;
       struct Struct_NO *No_Esquerda, *No_Direita, *No_Pai;
};

typedef struct Struct_NO ARVORE;
ARVORE *iniciar_arvore(){
    return NULL;
}


ARVORE *inserir_dados(ARVORE *arvore, int v);
int verificar_vazio(ARVORE *a);
void exibir_preOrdem(ARVORE *a);
void exibir_arvore(ARVORE *a);


int main(){
    ARVORE *a = iniciar_arvore();
    int opcao, no;
    
   setlocale(LC_ALL, ""); 	
	
  
   a = inserir_dados(a, 2);
   a = inserir_dados(a, 1);
   a = inserir_dados(a, 0);
   a = inserir_dados(a, 2);
   a = inserir_dados(a, 5);
   a = inserir_dados(a, 2);
   a = inserir_dados(a, 0);   
   a = inserir_dados(a, 9);  
   a = inserir_dados(a, 5);
   
   printf("RA  210252095\n");
   exibir_arvore(a);
   
   printf("\n\n\n");
   printf("\nRA: 210252095");
   
   printf(" - Visitação pré-ordem: ");
   exibir_preOrdem(a);
	
	
	return 0;                 
        
        
}

int verificar_vazio(ARVORE *a){
    return a == NULL;
}
void exibir_preOrdem(ARVORE *a){
    if(a != NULL){
    	printf("%d ", a->no);
        exibir_preOrdem(a->No_Esquerda);
        
        exibir_preOrdem(a->No_Direita);
        
        
    }
}
void exibir_arvore(ARVORE *a){
     printf("\n\n\t No_Pai %d \n",a->no);
     if(a->No_Esquerda != NULL){
     	printf("Esquerdo: %d\t",a->No_Esquerda->no);	
	 }       
     else{
     	printf("Esquerdo: NULL\t");
	 }
       
     if(a->No_Direita != NULL){
     	printf("\tDireito: %d\t",a->No_Direita->no);
	 }       
     else{
     	printf("Direito: NULL\t");
	 }
       
     if(a->No_Esquerda != NULL){
     	exibir_arvore(a->No_Esquerda);
	 }
      
     if(a->No_Direita != NULL){
     	exibir_arvore(a->No_Direita);
	 }
       
}
ARVORE *inserir_dados(ARVORE *arvore, int v){
    ARVORE *auxiliar;
    
    if(arvore == NULL){
       auxiliar = (ARVORE*)malloc(sizeof(ARVORE));
       auxiliar->no = v;
       auxiliar->No_Esquerda = iniciar_arvore();
       auxiliar->No_Direita = iniciar_arvore();
       return auxiliar;
       }
    else{
         int dir;
         auxiliar = arvore;
         ARVORE *No_Pai = NULL, *raiz = arvore;
         while(auxiliar != NULL){
           No_Pai = auxiliar;
           if(v <= auxiliar->no){
              dir = 0;
              auxiliar = auxiliar->No_Esquerda;
              }
           else{
              dir = 1;
              auxiliar = auxiliar->No_Direita;
              }
           }
    auxiliar = (ARVORE*)malloc(sizeof(ARVORE));
    auxiliar->no = v;
    auxiliar->No_Esquerda = iniciar_arvore();
    auxiliar->No_Direita = iniciar_arvore();
    
    if(dir)
      No_Pai->No_Direita = auxiliar;
    else
      No_Pai->No_Esquerda = auxiliar;
      return raiz;
    }
}



