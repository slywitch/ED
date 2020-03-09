#include <stdio.h>

#define max 50
#define erro -1
#define true 1
#define false 0

typedef int bool;
typedef int tipochave;

typedef struct {
    tipochave chave;
} registro;

typedef struct {
    registro a[max+1];
    int nroElem;
} lista;

void inicializarLista(lista* l){
    l->nroElem = 0;
}

void exibirLista(lista* l) {
    int i;

    printf("Lista: \" ");

    for (i=0; i <l->nroElem; i++) {
        printf("%i ", l->a[i].chave);
    }

    printf("\"\n");
}

int tamanho(lista* l) {
    return l->nroElem;
}

int tamanhoEmBytes(lista* l) {
    return sizeof(lista);
}

tipochave primeiroElem(lista* l) {
    if (l->nroElem > 0) {
        return l->a[0].chave;
    }
    else return erro;
}

tipochave ultimoElem(lista* l) {
  if(l->nroElem > 0) {
      return l->a[l->nroElem-1].chave;
  }
  else return erro;
}

tipochave enesimoElem(lista* l, int n) {
    if ((n>0) && (n<l->nroElem)) {
        return l->a[n].chave;
    }
    else return erro;
}

void reinicializarLista(lista* l) {
    l->nroElem = 0;
}

int buscaSequencial(lista* l, tipochave ch) {
    int i = 0;

    while (i < l->nroElem) {
        if(ch == l->a[i].chave) return i;
        else i++;
    }

    return erro;
}

int buscaSentinela(lista* l, tipochave ch) {
    int i = 0;

    l->a[l->nroElem].chave = ch;

    while (l->a[i].chave != ch) {
        i++;
    }

    if (i > l->nroElem -1) {
        return erro;
    }
    else return i;
}

int buscaBinaria(lista* l, tipochave ch){
  int esq, dir, meio;

  esq = 0;
  dir = l->nroElem-1;

  while(esq <= dir) {
    meio = ((esq + dir) / 2);
    if(l->a[meio].chave == ch) {
        return meio;
    }
    else {
      if(l->a[meio].chave < ch) esq = meio + 1;
      else dir = meio - 1;
    }
  }
  return erro;
}

bool excluirElemLista(lista* l, tipochave ch) { 
  int pos, j;

  pos = buscaSequencial(l,ch);

  if(pos == erro) {
      return false;
  }

  for(j = pos; j < l->nroElem-1; j++) l->a[j] = l->a[j+1];
    l->nroElem--;

  return true;
} 

bool excluirElemListaOrd(lista* l, tipochave ch) { 
  int pos, j;

  pos = buscaBinaria(l,ch);

  if(pos == erro) {
      return false;
  }

  for(j = pos; j < l->nroElem-1; j++) l->a[j] = l->a[j+1];
    l->nroElem--;

  return true;
} 

bool inserirElemListaOrd(lista* l, registro reg) {
  if(l->nroElem >= max) {
      return false;
  }

  int pos = l->nroElem;

  while(pos > 0 && l->a[pos-1].chave > reg.chave) {
    l->a[pos] = l->a[pos-1];
    pos--;
  }

  l->a[pos] = reg;
  l->nroElem++;
} 

bool inserirElemListaOrdSemDup(lista* l, registro reg) {
  if(l->nroElem >= max) {
      return false;
  }

  int pos;

  pos = buscaBinaria(l,reg.chave);

  if(pos != erro) {
      return false;
  }

  pos = l->nroElem-1;

  while(pos>0 && l->a[pos].chave > reg.chave) {
    l->a[pos+1] = l->a[pos];
    pos--;
  }

  l->a[pos+1] = reg;
  l->nroElem++;
}

int main(){
  lista lista;

  inicializarLista(&lista);
  exibirLista(&lista);
  printf("Numero de elementos na lista: %i.\n",tamanho(&lista));
  printf("Tamanho da lista (em bytes): %i.\n",tamanhoEmBytes(&lista));

  registro reg;
  reg.chave = 9;

  inserirElemListaOrd(&lista,reg);
  exibirLista(&lista);

  reg.chave=3;
  inserirElemListaOrd(&lista,reg);

  reg.chave=4;
  inserirElemListaOrd(&lista,reg);

  reg.chave=1;
  inserirElemListaOrd(&lista,reg);

  reg.chave=12;
  inserirElemListaOrd(&lista,reg);

  exibirLista(&lista);

  printf("Numero de elementos na lista: %i.\n",tamanho(&lista));
  printf("Tamanho da lista (em bytes): %i.\n",tamanhoEmBytes(&lista));
  printf("Chave 4 encontrada na posicao: %i do arranjo A.\n",buscaSequencial(&lista,4));
  printf("Chave 4 encontrada na posicao: %i do arranjo A.\n",buscaBinaria(&lista,4));
  printf("Chave 4 encontrada na posicao: %i do arranjo A.\n",buscaSentinela(&lista,4));

  if (excluirElemLista(&lista,4)) printf("Exclusao bem sucedida: 4.\n");
  if (excluirElemLista(&lista,8)) printf("Exclusao bem sucedida: 8.\n");
  if (excluirElemLista(&lista,9)) printf("Exclusao bem sucedida: 9.\n");

  exibirLista(&lista);

  printf("Numero de elementos na lista: %i.\n",tamanho(&lista));
  printf("Tamanho da lista (em bytes): %i.\n",tamanhoEmBytes(&lista));

  reinicializarLista(&lista);
  exibirLista(&lista);

  printf("Numero de elementos na lista: %i.\n",tamanho(&lista));
  printf("Tamanho da lista (em bytes): %i.\n",tamanhoEmBytes(&lista));

  return 0;
}