#include "stack.h"

stacknode *stackinit(stacknode *node)
{
    node = new stacknode();
    node->prev = NULL;
    return node;
}

stacknode *push(stacknode *node, int val)
{
    stacknode *tmp = new stacknode;
    tmp->val = val;
    if (node == NULL)
        return tmp;
    else {
        tmp->prev = node;
        return tmp;
    }
}

stacknode *pop(stacknode *node)
{
    stacknode *head = node->prev;
    delete(node);
    return head;
}

stacknode *stack_lookup(stacknode *node, int val)
{
    while (node) {
        if (node->val == val)
            break;
        else
            node = node->prev;
    }
    return node;
}

void stack_print(stacknode *node)
{
    int cnt = 0;
    while (node != NULL) {
        for (int i = 0; i < cnt; i++)
            cout<<"-";
        cout<<"["<<node->val<<"]"<<endl;
        cnt++;
        node = node->prev;
    }
}

void stack_free(stacknode *node)
{
    while (node) {
        stacknode *next = node->prev;
        delete(node);
        node = next;
    }
}
