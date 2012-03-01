#pragma once
struct Tree
{
	char value;
	Tree *right;
	Tree *left;
};

void add(Tree *&tr, char string[], int &count);
void del(Tree *tr);
void symmUp(Tree *tr);
void symmDown(Tree *tr);
void check(Tree *tr, char x);
void delElement(Tree *&tr, char x);


