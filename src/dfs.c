/*
 * Search an expression using DFS.
 */

#include <stdio.h>		/* scanf, printf */
#include <stdlib.h>		/* abort */
#include <stdbool.h>		/* bool, true, false */
#include "dfs.h"


void DFT (node * root)
{
	// Implement DFS
	// Hint: You can use print_node, print_tree and/or print_stack.

  // first we creat a stack and let point to NULL
  // to store the values of the tree 

  stack *s=malloc(sizeof(stack));
  s->next = NULL;
  push(s, root); // to make sure it's empty 

  while (!isEmpty(s))
  {
    //now pop the top value in the stack 
    node *current = pop(s)->node; //the value at the top

    // if there is any right and left child to the stack push them to the s
    if (current->rchild != NULL) {
      push(s, current->rchild);
    } 
    if (current->lchild != NULL) {
      push(s, current->lchild);
      }
  }
}

node *make_node (int num, node * left, node * right)
{
  //allocat memory and give value to the new node
  node *n = malloc(sizeof(node));  // tree pointer 
  n->num = num;
  n->lchild = left;  // values to new nodes
  n->rchild = right;
  n->visited = false;
	return n;
}

void free_node (node * p){}


void print_node (node * p)
{

  if (p == NULL)
    printf ("NULL\n");
  else
    printf ("%d\t", p->num);
}


void print_tree (node *p, int depth)
{
  for (int i = 0; i < depth; i = i + 1)
    printf (" ");
  printf ("| ");

  if (p == NULL)
    printf ("NULL\n");
  else
    printf ("[%d]\n", p->num);


  if (p->lchild)
    {
      print_tree (p->lchild, depth + 1);
    }

  if (p->rchild)
    print_tree (p->rchild, depth + 1);
}

stack *push (stack *topp, node *node)
{
  //we allocat memory to the stack created, and give value 
  stack *s_d = malloc(sizeof(stack));
    s_d->node = node;
    s_d->next = topp->next;
    topp->next = s_d;

	return s_d;
}

bool isEmpty(stack *topp)
{
  return topp->next == NULL;
}

node *top (stack *topp)
{
	return 0;
}

// Utility function to pop topp  
// element from the stack 

stack *pop (stack * topp)
{
  stack *helper = topp->next;
  topp->next = topp->next->next;;
  return helper;
}

void print_stack (stack * topp)
{
  struct stack *temp = topp;

  while (temp != NULL)
    {

      print_node (temp->node);
      printf ("\n");

      temp = temp->next;
    }

  printf ("====\n");

  return;
}
