#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum{ARR_SIZE = 100};

typedef struct Queue{
	char arreglin[ARR_SIZE];
	struct Queue* next;
}COLA;

typedef struct Queue_list{
	struct Queue* head;
	struct Queue* tail;
}COLA_LISTA;



COLA_LISTA* push(COLA_LISTA* s, const char* c){
	COLA* temp = malloc(COLA);
	
	if(temp == NULL){
		//malloc fallo
		return s;
	}
	
	strcpy(temp->arreglin,c);
	temp->next = NULL;
	
	if(s == NULL){
		//no existe ninguna cola
		free(temp);
		return s;
	}
	else if(s->head == NULL && s->tail == NULL){
		
		s->head = s->tail = temp;
		return s;
	}
	else if(s->head == NULL || s->tail == NULL){	
		free(temp);
		return NULL;
	}
	else{
		s->tail->next = temp;
		s->tail = temp;
	}
	return s;
}

char* top(COLA_LISTA* n){
	/*char* aux = (char*) malloc(100);
	aux = ;*/
	return n->head->arreglin;
}
COLA_LISTA* pop(COLA_LISTA* s){
	COLA* h = NULL;
	COLA* p = NULL;
	if(s == NULL){
		//la cola esta vacia
		return s;
	}
	else if(s->head == NULL && s->tail == NULL){
		return s;
	}
	h = s->head;
	p = h->next;
	free(h);
	s->head = p;
	if(s->head == NULL){
		s->tail = s->head;
	}
	return s;
}
int get_size(const COLA_LISTA* ps){
	COLA* p = NULL;
	int x=0;
	if( ps ){
      for( p = ps->head; p; p = p->next ){
      	x++;
	  }
    }
    return x;
}
char* list_print( const COLA_LISTA* ps ){
	COLA* p = NULL;
 	char* buffer = (char*) malloc(get_size(ps)*ARR_SIZE);
	if( ps ){
      for( p = ps->head; p; p = p->next ){
      	strcat(buffer,p->arreglin);
	  }
    }
}

COLA_LISTA* NewQ(void){
	COLA_LISTA* temp = malloc(1 * sizeof(*temp));
	temp->head = temp->tail = NULL;
	return temp;
}

