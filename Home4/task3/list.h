#pragma once

struct list
{
	int value;
	list *next;
}; 

list *create(int n);
void add(list *&l, int x);
void del(list *&l);
void print(list *l);
list *search(list *l, int x);
void der(list *&l, int x);
