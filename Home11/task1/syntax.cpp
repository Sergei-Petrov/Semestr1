#include "stdafx.h"
#include <stdlib.h>
#include "syntax.h"
#include "double.h"

bool plusOrMinus(char *&c)
{
	delSpace(c);
	if (!multOrDiv(c)) //проверка на наличие первого слагаемого
		return false;
	delSpace(c);
	while (*c == '+' || *c == '-')
	{
		c++;
		if (!multOrDiv(c)) //проверка на наличие последуюших слагаемых
			return false;
	}
	return true;
}

bool multOrDiv(char *&c)
{
	delSpace(c);
	if (!bracketOrNumber(c)) // проверка на наличие первого множителя
		return false;
	delSpace(c);
	while (*c == '*' || *c == '/')
	{
		c++;
		if (!bracketOrNumber(c)) //проверка на наличие последуюших множителей
			return false;
	}
	return true;
}

bool bracketOrNumber(char *&c)	// проверка на скобки или цифру
{
	delSpace(c);
	if (*c == '(')
	{
		c++;					//Если открывающаяся скобка, то
		if (!plusOrMinus(c))	//запускаем сначала
			return false;
		if (*c == 0)
			return false;
		if (*c != ')')
			return false;
		c++;
		return true;
	} else
		return checkDouble(c);
}

bool syntax(char *c)
{
	return plusOrMinus(c);
}

void delSpace(char *&c)
{
	while (*c == ' ')
		c++;
}