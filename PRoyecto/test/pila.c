/* A Stack implementation of a singly linked list with 4 operations: Pop, Push, Top and Print elements in the list. 
 *
 * VERISON 0.4
 *
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
enum { STACK_ARR_SIZE = 101 };  
 
struct my_stack
{
  char arrc[STACK_ARR_SIZE]; /* Thar array must not have more than (STACK_ARR_SIZE - 1) elements */
  struct my_stack* next;
};
 
struct stack_list
{
  struct my_stack* head;
};
 
 
struct stack_list* push( struct stack_list*, const char* );
struct stack_list* pop( struct stack_list* );
struct my_stack* top( struct stack_list* );
struct my_stack* make_null( struct stack_list* );
struct my_stack* is_empty( struct stack_list* );
 
 
struct stack_list* stack_new( void );
void stack_print( const struct stack_list* ); 
void stack_print_element( const struct my_stack* ); 
struct stack_list* stack_free( struct stack_list* );
 
 
/*int main( void )
{
  struct my_stack* p = NULL;
  struct stack_list* ms = NULL;
  ms = stack_new();
 
  stack_print(ms);
 
  push(ms, "comppppppppppppppppp");
  push(ms, "(dot)");
  push(ms, "lang");
  push(ms, "(dot)");
  push(ms, "c");
   
  stack_print(ms);
   
  pop(ms);
  p = top(ms);
 
  stack_print(ms);  
  stack_free(ms);
  free(ms);
  ms = NULL;
 
  return 0;
}*/
 
 
struct stack_list* push(struct stack_list* s, const char* c )
{
  struct my_stack* p = malloc( 1 * sizeof *p );
 
  if( NULL == p )
    {
      fprintf(stderr, "malloc() failed\n");
      return s;
    }
 
  /* If use gave us more characters than what we want, then its his problem */
  if( strlen(c) < STACK_ARR_SIZE ) strcpy(p->arrc, c);
  p->next = NULL;
 
 
  if( NULL == s )
    {
      fprintf(stderr, "Stack not initialized ?\n");
      free(p);
      return s;
    }
  else if( NULL == s->head )
    {
      /*      printf("Stack is Empty, adding first element\n"); */
      s->head = p;
      return s;
    }
  else
    {
      /*      printf("Stack not Empty, adding in front of first element\n"); */
      p->next = s->head;
      s->head = p;  /* push new element onto the head */
    }
 
  return s;
}
       
 
struct stack_list* pop( struct stack_list* s )
{
  struct my_stack* p = NULL;
 
  if( NULL == s )
    {
      printf("There is no stack list ?\n");
    }
  else if( NULL == s->head )
    {
      printf("There is no element on the stack\n");
    }
  else
    {
      p = s->head;
      s->head = s->head->next;
      free(p);
    }
 
  return s;
}
 
 
struct my_stack* top( struct stack_list* s)
{
  if( NULL == s )
    {
      printf("There is no stack list ?\n");
      return NULL;
    }
  else if( NULL == s->head )
    {
      printf("There is no element on the stack\n");
    }
 
 
  return s->head;
}
 
 
/* Make a Stack empty */
struct my_stack* make_null( struct stack_list* s )
{
  if( NULL == s )
    {
      printf("Can not make NULL when there is no Stack List\n");
      return NULL;
    }
  else if( NULL == s->head )
    {
      printf("Stack is already Empty\n");
    }
  else
    {
      stack_free(s);
    }
 
  return s->head;
}
 
 
struct my_stack* is_empty( struct stack_list* s )
{
  if( NULL == s )
    {
      printf("There is no Stack\n");
      return NULL;
    }
  else if( NULL == s->head )
    {
      printf("Stack is Empty\n");
    }
  else
    {
      printf("Stack is not Empty\n");
    }
   
  return s->head;
}
   
 
 
/* ---------- small helper functions -------------------- */
struct stack_list* stack_free( struct stack_list* s )
{
  if( NULL == s )
    {
      printf("Can't free a NULL stack list\n");
    }
   
  while( s->head ) pop(s);
 
  return s;
}
   
 
struct stack_list* stack_new( void )
{
  struct stack_list* p = malloc( 1 * sizeof *p );
 
  if( NULL == p )
    {
      fprintf(stderr, "malloc() in Stack Initialization failed\n");
      exit( EXIT_FAILURE );  /* There is no point in going beyond this point */
    }
  
  p->head = NULL;
 
  return p;
}
 
 
void stack_print( const struct stack_list* s )
{
  struct my_stack* p = NULL;
 
  if( NULL == s ) 
    {
      printf("Can not print an Empty Stack\n");
    }
  else
    {
      for( p = s->head; p; p = p->next ) stack_print_element(p);
    }
 
  printf("-------------------------- \n");
}
 
 
void stack_print_element(const struct my_stack* s)
{
  if( s ) printf("arrc = %s\n", s->arrc);
}
