#ifndef __MONTY_H__
#define __MONTY_H__

#include <stdio.h>
#include <stdlib.h>

#define STACK 0
#define QUEUE 1
#define DELIM " \n\t\a\b"

typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct globals_s
{
    char *token2;
    FILE *fd;
    char *line_buf;
} globals_t;

extern globals_t globalvar;

int main(int argc, char **argv);

stack_t *create_node_stackfirst(stack_t **stack, int n);
stack_t *create_node_stackend(stack_t **stack, int n);
void free_node_stack(stack_t **stack);

int get_builtin(char *token, stack_t **stack, unsigned int line_number);

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void div_m(stack_t **stack, unsigned int line_number);
void mod_m(stack_t **stack, unsigned int line_number);
void pstr_t(stack_t **stack, unsigned int line_number);
void rotrl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
stack_t *add_dnodeint(stack_t **head, int n);

void stderr_usage(void);
void stderr_malloc(void);
void stderr_fopen(char *fd);
void stderr_int(unsigned int line_number);
void stderr_unknown(char *token, unsigned int line_number);
void div_e(unsigned int line_number);
void op_e(unsigned int line_number, char *op);

void tokerr(int error_code);
unsigned int array_len(void);
char *get_int(int num);
unsigned int abs_m(int num);
int len_buff_uint(unsigned int num, unsigned int base);
void full_buff(unsigned int num, unsigned int base, char *buff, int buff_size);
void pop_e(unsigned int line_number);
void pint_e(unsigned int line_number);
void pchar_e(unsigned int line_number, char *msg);
int _isdigit(void);
void free_dlistint(stack_t *stack);
void free_globalvars(void);

#endif
