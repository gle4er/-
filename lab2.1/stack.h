#ifndef STACK_H
#define STACK_H

#include <iostream>

using namespace std;

struct stacknode {
    int val;
    stacknode *prev;
};

stacknode *stackinit(stacknode *node);
stacknode *push(stacknode *node, int val);
stacknode *pop(stacknode *node);
stacknode *stack_lookup(stacknode *node);
void stack_print(stacknode *node);
void stack_free(stacknode *node);

#endif
