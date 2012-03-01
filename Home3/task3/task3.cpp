// author: Sergei Petrov

// email: sergei.petrov1994@gmail.com

// group �143

// homework �3 , task 3

// �������� ��������� �������������� ��������� ����� ��������� � �����������. 
// ��������, ��� ������ ������� �������� ���� ������.

#include "stdafx.h"
#include "stack.h"


int prior(char c)	// ����������� ���������� �������� 
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
	if((c == '+') || (c == '-') || (c == '/') || (c == '*'))	// ���� ������ - ��������, ��
	{
		if(empty(tmp))			// ���� ���� ����, ��
			tmp = push(tmp, c);	// ���������� ������ � ����;
		else					// �����
			if(prior(tmp->value) < prior(c))	// ���� �p��p���� ���p���� ������ �p��p����� � �����, ��             
				tmp = push(tmp, c);				// ���������� � ����      
			else								// ���� �p��p���� ������
			{
				while((!empty(tmp)) && (prior(tmp->value) >= prior(c)))	// ���������� � ��p��� ��� ���p����
					b[j++] = pop(tmp);									// � ������� ��� p����� �p��p������
				tmp = push(tmp, c);		// ���������� � ���� ����������� ���p����
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
	if(c == '(')			// ���� ������ - '(', ��
		tmp = push(tmp, '(');	// ���������� ��� � ����
	return tmp;
}

stack *closebracket(stack *head, char c, char b[], int &j)
{
	stack *tmp = head;
	if(c == ')')						// ���� ������ - ')', �� �� ����� ������ ��� �������� �� "("             
	    {								// �� �� ����� ������ ��� �������� �� "("
			while((tmp->value) != '(')	//         
				b[j++] = pop(tmp);		//  
				pop(tmp);				// ������� �� ����� ���� ���p������� ������ 
		}
	return tmp;
}

stack *end(stack *head, char b[], int &j)
{
	stack *tmp = head;
	while(!empty(tmp))		// ������ �� �����
		b[j++] = pop(tmp);	// ���������� ��������
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
	int i = 0;	// ������� �������� ������
	int j = 0;	// ������� �������� ������
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
