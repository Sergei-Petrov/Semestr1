#include "stdafx.h"
#include "tree.h"

Tree *create(int x)
{
	Tree *tmp = new Tree;
	tmp->value = x;
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}

void add(Tree *&tr, int x)
{
	if (tr == NULL)
		tr = create(x);
	else
	{
		if(x < tr->value)
			add(tr->left, x);
		else if(x > tr->value)
			add(tr->right, x);
		else
			return;
	}
}

void del(Tree *tr)
{
	if (tr != NULL)
	{
		del(tr->left);
		del(tr->right);
		delete(tr);
	}
}

void symmUp(Tree *tr)
{
	if(tr != NULL)
	{
		symmUp(tr->left);
		printf("%d ", tr->value);
		symmUp(tr->right);
	}
}

void symmDown(Tree *tr)
{
	if(tr != NULL)
	{
		symmDown(tr->right);
		printf("%d ", tr->value);
		symmDown(tr->left);
	}
}

void check(Tree *tr, int x)
{
	if(tr == NULL)
	{
		printf("NO\n");
		return;
	}
	if (x == tr->value)
		printf("YES\n");
	else
		if (x < tr->value)
			check(tr->left, x);
		else
			check(tr->right, x);
}

void delElement(Tree *&tr, int x)
{
	if (!tr)
		printf("NO\n");
	else if (x < tr->value)
		delElement(tr->left, x);
	else if (x > tr->value)
		delElement(tr->right, x);
	else
	{
		Tree *tmp = tr;
		if (!tr->right)
			tr = tr->left;
		else if (!tr->left)
			tr = tr->right;
		else
		{
			Tree *v = tr->left;
			if (v->right)
			{
				while (v->right->right)
					v = v->right;
				tr->value = v->right->value;
				tmp = v->right;
				v->right = v->right->left;
			}
			else
			{
				tr->value = v->value;
				tmp = v;
				tr->left=tr->left->left;
			}
	    }
		delete(tmp);
	}
}