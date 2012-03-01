#include "stdafx.h"
#include "tree.h"

Tree *create(char x)
{
	Tree *tmp = new Tree;
	tmp->value = x;
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}

void add(Tree *&tr, char string[], int &count)
{
	if ((string[count] == '(') || (string[count] == ')'))
	{
		add(tr, string, ++count);
	}
	else
	{
		if(string[count] != '\0')
		{
			if((string[count] == '+') || (string[count] == '-') || (string[count] == '*') || (string[count] == '/'))
			{
				tr = create(string[count++]);
				add(tr->left, string, count);
				add(tr->right, string, count);
			}
			else
			{
				tr = create(string[count++]);
			}
		}
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
		printf("%c ", tr->value);
		symmUp(tr->right);
	}
}

void symmDown(Tree *tr)
{
	if(tr != NULL)
	{
		symmDown(tr->right);
		printf("%c ", tr->value);
		symmDown(tr->left);
	}
}

void check(Tree *tr, char x)
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

void delElement(Tree *&tr, char x)
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