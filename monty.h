#ifndef MONTY_H
#define MONTY_H


/*STRUCTURE DEFINITIONS*/

/**                                                            
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer                                                 
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)   
 *
 * Description: doubly linked list node structure              
 * for stack, queues, LIFO, FIFO                               
 */                          
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next; 
} stack_t;


#define _GNU_SOURCE
#define _POSIX_C_SOURCE 200809L

/*HEADER FILES*/
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>



/*STRUCTURE DEFINITIONS*/


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_vars - structure for global variables
 * @buffer: A string buffer for holding input
 * @file: A varibale for holding opfile content
 * @op_args: holds the argument for an opcode
 */
typedef struct global_vars
{
	char *buffer;
	FILE *file;
	int op_args;
} global_vars;


/*EXTERNS*/
extern global_vars glob_vars;



/*FUNCTION PROTOTYPES*/
typedef void (*exect_instruct)(stack_t **stack, unsigned int line_number);
void get_input(stack_t **stack, char *filename);
char *line_split(char *input, int count);
exect_instruct call_func(char *command);
void free_dlistint(stack_t *head);
int check_num(char *str);


void pall(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);

void add(stack_t **stack, unsigned int line_number);

void sub(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);



#endif
