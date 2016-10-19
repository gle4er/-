#include "list.h"

struct list *list_add(struct list *Head, int val)
{
    if (Head == NULL) {
        list *node = new list;
        node->val = val;
        node->next = NULL;
        Head = node;
        return Head;
    } else {
        list *node = Head;
        while (node->next != NULL)
            node = node->next;
        list *tmp = new list;
        tmp->val = val;
        tmp->next = NULL;
        node->next = tmp;
    }
    return Head;
}

void list_add_num(struct list *node, int val, int num)
{
    for (int i = 0; i < num && node != NULL; i++)
        node = node->next;
    if (node == NULL)
        return;
    else {
        list *tmp = list_cp(node);
        node->val = val;
        node->next = tmp;
    }
    return;
}

struct list *list_rem(struct list *Head, int num)
{
    list *node = Head,*p=0;
    for (int i = 0; i < num && node != NULL; i++)
    {
		p = node;
	    node = node->next;
	}
    
	if (node == NULL)
        return NULL;
    else if(node==Head)
	{
		node = Head->next;
		delete Head;
		return node;
	}
	else {
		list *temp = node;
		p->next = node->next;
		delete temp;
    }
    return Head;
}

int list_calc(struct list *node)
{
    int i;
    for (i = 0; node != NULL; i++)
        node = node->next;
    return i;
}

void list_mov(struct list *node, int from, int to)
{
    int i;
    for (i = 0; i < from && node != NULL; i++)
        node = node->next;
    if (node == NULL)
        return;
    else {
        list *tmp = list_cp(node);
		for (; i < to && node != NULL; i++) {
            node->val = node->next->val;
            node = node->next;
        }
        node->val = tmp->val;
    }
}

void list_print(struct list *node)
{
    while (node != NULL) {
        cout<<node->val;
        if (node->next != NULL)
            cout<<" - ";
        node = node->next;
    }
    cout<<endl;
    return;
}

struct list *list_cp(struct list *node)
{
    list *tmp = new list;
    tmp->val = node->val;
    tmp->next = node->next;
    return tmp;
}

struct list *list_lookup(struct list *node, int val)
{
    while (node) 
        if (node->val == val)
            break;
        else
            node = node->next;
    return node;
}

void list_antirep(struct list *Head)
{
    int i, cnt = 0;
    list *node = Head;
    while (node) {
        int tmp = node->val;
        i = cnt + 1;
        for (i; node->next != NULL; i++) {
            node = node->next;
            if (node->val == tmp)
                Head = list_rem(Head, i);
        }
        cnt++;
        node = Head;
        for (i = 0; i < cnt; i++)
            node = node->next;
    }
    return;
}
