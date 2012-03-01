#pragma once

struct list
{
	int degree;
	int coef;
	list *next;
}; 

list *create(int coef, int degree);
void add(list *&l, int coef, int degree);
void del(list *&l);
void print(list *l);

