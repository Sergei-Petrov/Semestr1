// author: Sergei Petrov

// email: sergei.petrov1994@gmail.com

// group є143

// homework є1 , task 5

// Ќаписать программу проверки баланса скобок в исходной строке (т.е. число открывающих скобок равно 
// числу закрывающих и выполн€етс€ правило вложенности скобок).

#include "stdafx.h"

int main()
{
	char s[50];
	printf("Enter a string: ");
	scanf("%s", s);
	int i = 0;
	int a = 0;
	while ((s[i] != NULL) && (a >= 0))
	{
		if (s[i] == '(')
			a++;
		else if (s[i] == ')')
			a--;
		i++;
	}
	if (a == 0)
		printf("All right");
	else
		printf("Error");
	scanf("%");
	return 0;
}

