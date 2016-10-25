#ifndef lish_h
#define list_h
#include <iostream>

using namespace std;

struct list {
        int val;
        list *next;
};

struct list *list_add(struct list *Head, int val);
void list_add_num(struct list *node, int val, int num);
struct list *list_rem(struct list *Head, int num);
int list_calc(struct list *node);
void list_mov(struct list *node, int from, int to);
void list_print(struct list *node);
struct list *list_cp(list *node);
struct list *list_lookup(list *node, int val);
void list_antirep(struct list *Head);
#endif 
