// author: Sergei Petrov

// email: sergei.petrov1994@gmail.com

// group №143

// homework №2 , task 4

// Напечатать в порядке возрастания все простые несократимые дроби, заключенные между 0 и 1, знаменатели которых не превышают N

#include "stdafx.h"

void fraction(int a, int b, int c, int d, int n, int m)
{
	if (n > m)
		return;
	if (((a + c) <= m) && ((b + d) <= m))
	{
		fraction(a, b, a + c, b + d, n + 1,m);
		printf("%d / %d\n", a + c, b + d);
		fraction(a + c, b + d, c, d, n + 1, m);
	}
}

int main()
{
	printf("Enter n : ");
	int n = 0;
	scanf("%d", &n);
	fraction(0, 1, 1, 1, 1, n);
	scanf("%");
	return 0;
}
