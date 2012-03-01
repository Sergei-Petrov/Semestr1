#pragma once

struct list
{
	int value;
	list *next;
}; 

list *create(int n);
void del(list *l, int pos, int kol, int j, bool &flag);
