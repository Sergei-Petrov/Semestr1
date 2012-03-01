#pragma once
struct Tree
{
	int value;
	Tree *right;
	Tree *left;
};

void add(Tree *&tr, int x);
void del(Tree *tr);
void symmUp(Tree *tr);
void symmDown(Tree *tr);
void check(Tree *tr, int x);
void delElement(Tree *&tr, int x);


