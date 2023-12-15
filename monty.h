#ifndef HEAD
#define HEAD

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>

#define BUF_SIZE 1024
#define SPACE 32

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


void __push(stack_t **h, int val);
void __pint(stack_t **h);
void __pop(stack_t **h);
void __swap(stack_t **h);
void __add(stack_t **h);
void __nop(stack_t **h);
void __sub(stack_t **h);
void __div(stack_t **h);
void __mul(stack_t **h);
void __mod(stack_t **h);
void __pchar(stack_t **h);
void __pstr(stack_t **h);
void __rotl(stack_t **h);
void __rotr(stack_t **h);
void __stack(stack_t **h);
void __queue(stack_t **h);
void __pall(stack_t **h);

void *my_malloc(size_t size);

size_t print_dlistint(stack_t *h);
size_t dlistint_len(const stack_t *h);
stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);
void free_dlistint(stack_t *head);
stack_t *get_dnodeint_at_index(stack_t *head, unsigned int index);
int sum_dlistint(stack_t *head);
stack_t *insert_dnodeint_at_index(stack_t **h, unsigned int idx, int n);
int delete_dnodeint_at_index(stack_t **head, unsigned int index);
#endif

