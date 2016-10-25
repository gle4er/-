#include "stack.h"
#include "list.h"

void stack()
{
    stacknode *stack = NULL;
    stack = push(stack, 228);
    stack = push(stack, 1337);
    stack = push(stack, 1488);
    stack = push(stack, 24);
    stack_print(stack);
    stack_free(stack);
    return;
}

void quene()
{
    struct list *list = NULL;
    list = list_add(list, 228);
    list = list_add(list, 1337);
    list = list_add(list, 1488);
    list = list_add(list, 24);
    list_print(list);
    return;
}

int main()
{
    stack();
    quene();
    return 0;
}
