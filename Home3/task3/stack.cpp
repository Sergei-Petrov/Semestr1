#include "stdafx.h"
#include "stack.h"

bool empty(stack *head) 
{
	return (head == NULL);
}

stack *push(stack *head, char c)	
{
	stack *tmp = new stack;
	tmp->value = c;                                
	tmp->next = head; 
	return tmp;
}

char pop(stack *&head)	
{
	stack *tmp;
	char c;
	if(empty(head)) 
		return '\0'; 
	tmp = head;                   
	c = tmp->value;
	head = tmp->next;         
	delete(tmp);   
	return c;                   
}
