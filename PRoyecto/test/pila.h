
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
enum { STACK_ARR_SIZE = 3000 };  
 
struct my_stack{
  char arrc[STACK_ARR_SIZE]; 
  struct my_stack* next;
};
 
struct stack_list{
  struct my_stack* head;
};
 

struct stack_list* push(struct stack_list* s, const char* c ){
  struct my_stack* p = malloc( 1 * sizeof *p );
 
  if( NULL == p )
    {
      fprintf(stderr, "malloc() failed\n");
      return s;
    }
 
  if( strlen(c) < STACK_ARR_SIZE ) strcpy(p->arrc, c);
  p->next = NULL;
 
 
  if( NULL == s ){
      fprintf(stderr, "Stack not initialized ?\n");
      free(p);
      return s;
     }
  else if( NULL == s->head ){
      s->head = p;
      return s;
    }
  else{
      p->next = s->head;
      s->head = p;  
    }
 
  return s;
}
       
 
struct stack_list* pop( struct stack_list* s ){
  struct my_stack* p = NULL;
 
  if( NULL == s ) {
      printf("There is no stack list ?\n");
    }
  else if( NULL == s->head ) {
      printf("There is no element on the stack\n");
    }
  else{
      p = s->head;
      s->head = s->head->next;
      free(p);
    }
 
  return s;
}
 
 
struct my_stack* top( struct stack_list* s){
  if( NULL == s ){
      printf("There is no stack list ?\n");
      return NULL;
    }
  else if( NULL == s->head ){
      printf("There is no element on the stack\n");
    }
 
  return s->head;
}
 
struct my_stack* is_empty( struct stack_list* s ){
  if( NULL == s ){
      printf("There is no Stack\n");
      return NULL;
    }
  else if( NULL == s->head ){
      printf("Stack is Empty\n");
    }
  else{
      printf("Stack is not Empty\n");
    }
   
  return s->head;
}
   
struct stack_list* stack_new( void ){
  struct stack_list* p = malloc( 1 * sizeof *p );
 
  if( NULL == p ){
      fprintf(stderr, "malloc() in Stack Initialization failed\n");
      exit( EXIT_FAILURE ); 
    }
  
  p->head = NULL;
 
  return p;
}
 
void stack_print_element(const struct my_stack* s){
  if( s ) printf("arrc = %s\n", s->arrc);
}
