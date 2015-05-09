#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum{STACK_SIZE = 101};
 
struct stack{
  char arreglin[STACK_SIZE]; 
  struct stack* next;
};
 
struct stack_list{
  struct stack* head;
};


struct stack_list* push(struct stack_list* s, const char* c ){
  
  struct stack* p = malloc( 1 * sizeof *p );
   	
  if( NULL == p ) { //malloc fallo
      return s;
    }
 
  
  if( strlen(c) < STACK_SIZE ){   //si el array es mas grande que nuestra estructura
  	strcpy(p->arreglin, c);
  	p->next = NULL;
  }
 	
  if( NULL == s ){
      //la pila no se a inicializado
      free(p);
      return s;
    }
  else if( NULL == s->head ){ //si nuestra pila esta vacia
      
      s->head = p;
      return s;
    }
  else{
      p->next = s->head;
      s->head = p;  //agregamos nuevo elemento a la cabeza
    }
 
  return s;
}
struct stack_list* pop( struct stack_list* s ){

	struct stack* p = NULL;
  	if( NULL == s ){
    	  //no hay ninguna pila
    }
  	else if( NULL == s->head ){
    	  //no hay ningun elemento en la pila
    }
  	else{
		p = s->head;
        s->head = s->head->next;
        free(p);
    }
	return s;
}
struct stack* top( struct stack_list* s){
  if( NULL == s ){
      //no hay ninguna pila
      return NULL;
    }
  else if( NULL == s->head ){
      //no hay elementos en la pila
    }
  return s->head;
}

struct stack* is_empty( struct stack_list* s ){
  if( NULL == s ){
      //no hay ninguna pila
      return NULL;
    }
  else if( NULL == s->head ){
      //la pila esta vacia
    }
  else{
      //la pila no esta vacia
    }
   
  return s->head;
}


