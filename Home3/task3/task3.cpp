// author: Sergei Petrov

// email: sergei.petrov1994@gmail.com

// group №143

// homework №3 , task 3

// Написать программу преобразования инфиксной формы выражения в постфиксную. 
// Известно, что каждый операнд занимает один символ.

#include "stdafx.h"
#include "stack.h"


int prior(char c)	// Определение приоритета операций 
{
	switch(c)
	{
		case '*':
		case '/':
			return 3;
		case '-':
		case '+':
			return 2;
		case '(':
			return 1;
	}
}

stack *operation(stack *head, char c, char b[], int &j)
{
	stack *tmp = head;
	if((c == '+') || (c == '-') || (c == '/') || (c == '*'))	// Если символ - операция, то
	{
		if(empty(tmp))			// если стек пуст, то
			tmp = push(tmp, c);	// записываем символ в стек;
		else					// иначе
			if(prior(tmp->value) < prior(c))	// если пpиоpитет опеpации больше пpиоpитета в стека, то             
				tmp = push(tmp, c);				// записываем в стек      
			else								// если пpиоpитет меньше
			{
				while((!empty(tmp)) && (prior(tmp->value) >= prior(c)))	// записываем в стpоку все опеpации
					b[j++] = pop(tmp);									// с большим или pавным пpиоpитетом
				tmp = push(tmp, c);		// записываем в стек поступившую опеpацию
			}
	}
	return tmp;
}

void operand(char c, char b[], int &j)
{
	if(((c >= 'a') && (c <= 'z')) || ((c >= '0') && (c <= '9')))
		b[j++] = c;
	return;
}

stack *openbracket(stack *head, char c)
{
	stack *tmp = head;
	if(c == '(')			// Если символ - '(', то
		tmp = push(tmp, '(');	// записываем его в стек
	return tmp;
}

stack *closebracket(stack *head, char c, char b[], int &j)
{
	stack *tmp = head;
	if(c == ')')						// Если символ - ')', то из стека достаём все элементы до "("             
	    {								// то из стека достаём все элементы до "("
			while((tmp->value) != '(')	//         
				b[j++] = pop(tmp);		//  
				pop(tmp);				// Удаляем из стека саму откpывающую скобку 
		}
	return tmp;
}

stack *end(stack *head, char b[], int &j)
{
	stack *tmp = head;
	while(!empty(tmp))		// Достаём из стека
		b[j++] = pop(tmp);	// оставшиеся элементы
	b[j]='\0';
	return tmp;
}

int main()
{
	stack *st = NULL;
	char a[20];
	char b[20];
	printf("Enter infix form : ");
	scanf("%s", a);
	int i = 0;	// Счётчик исходной строки
	int j = 0;	// Счётчик итоговой строки
	while(a[i] != '\0')           
	{
		st = closebracket(st, a[i], b, j);
		operand(a[i], b, j);
		st = openbracket(st, a[i]);
		st = operation(st, a[i], b, j);
		i++;                                    
	}
	st = end(st, b, j);
	printf("\nPostfix form : %s", b);
	scanf("%");
	return 0;
}
