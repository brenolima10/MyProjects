#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
 
typedef int bool;
enum { false, true };
 
typedef struct estr {
    char letra;
    struct estr *prox;
} NO;
 
typedef struct {
    NO *inicio;
} LISTA;
 
void inicializarLista(LISTA *l) {
    l->inicio = NULL;
}
 
void criarLista(LISTA *l, char plvr[]) {
    NO *ult = NULL;
    int i;
 
    for (i = 0; i < strlen(plvr); i++) {
        NO *novo = (NO *) malloc(sizeof(NO));
        novo->letra = plvr[i];
        novo->prox = NULL;
        if (ult) {
            ult->prox = novo;
        } else {
            l->inicio = novo;
        }
        ult = novo;
    }
}
 
void imprimirLista(LISTA *l) {
    NO *p = l->inicio;
    while(p) {
        printf("%c", p->letra);
        p = p->prox;
    }
}
 
LISTA* clonarLista(LISTA* l){
  LISTA* resp = malloc(sizeof(LISTA));
 
  NO *corrente = l->inicio;
  NO *anterior = NULL; 
 
  while(corrente){ 
    NO *novo = (NO *) malloc(sizeof(NO));
    novo->letra = corrente->letra;
    novo->prox = NULL;
 
    if (anterior == NULL){ 
        resp->inicio = novo;
    }
    else { 
        anterior->prox = corrente;
    }
 
    anterior = novo;
    corrente = corrente->prox;
  }
 
  return resp;
}

void inverter(LISTA* resp){
 
    NO* atual = resp->inicio;
 
    resp->inicio = NULL;
 
    while (atual->prox != NULL){ 
        NO* corrente = atual; 
        atual = atual->prox; 
 
        corrente->prox = resp->inicio; 
        resp->inicio = corrente; 
}
 
void inverterNvs(NO* elemento, NO* anteriorAoElemento, NO* fim) {
    if (elemento != fim) {
        inverterNvs(elemento->prox, elemento, fim);
    }
    elemento->prox = anteriorAoElemento;
}
 
bool verificaSequencia(NO* dado) {
    if (dado->letra != 'a' && dado->letra != 'e' && dado->letra != 'i' && dado->letra != 'o' && dado->letra != 'u'){
        return true;
    }
    else{
        return false;
    }
}

void decodificar(LISTA* resp) {
    NO* pNv = NULL; 
    NO* ultNv = NULL; 
 
    NO* atual = resp->inicio; 
    NO* anterior = NULL;
 
    while (atual != NULL) {
 
        if (verificaSequencia(atual)) {
            
            pNv = atual;

            while (atual->prox != NULL && verificaSequencia(atual->prox)) {
                atual = atual->prox;
            }
        
            ultNv = atual;
 
            if (pNv != ultNv) {
                
                NO* proximoOriginal = ultNv->prox;

                inverterNvs(pNv->prox, pNv, ultNv);
 
                pNv->prox = proximoOriginal;
 
                if (anterior == NULL){
                    resp->inicio = ultNv;
                }
                else {
                    anterior->prox = ultNv;
                }
 
                atual = pNv;
            }
        }
 
        anterior = atual;
        atual = atual->prox;
    }
}
 
int main() {
    LISTA l;
    inicializarLista(&l);

    char palavra[] = "eu construi um monstro"; 
    criarLista(&l, palavra);
 
    LISTA* resp = clonarLista(&l); 
 
    decodificar(resp);
    imprimirLista(resp);
 
    return 0;
}