#pragma once
struct stack
{
	char value;
	stack *next;
};

bool empty(stack *head); 
stack *push(stack *head, char c);
char pop(stack *&head);
