#include "list.h"

int main()
{
    struct list *Head;
    Head = list_add(Head, 10);
    Head = list_add(Head, 228);
    Head = list_add(Head, 1337);
    Head = list_add(Head, 1488);
    list_add_num(Head, 4321, 0);
    list_print(Head);
    list_mov(Head, 0, 3);
    list_print(Head);
    Head = list_rem(Head, 0);
    list_print(Head);
	Head = list_rem(Head, 1);
    list_print(Head);
    Head = list_add(Head, 10);
    list_print(Head);
    list_antirep(Head);
    list_print(Head);
    return 0;
}
