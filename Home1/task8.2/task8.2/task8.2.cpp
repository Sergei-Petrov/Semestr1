#include "stdafx.h"

int fact(int n)
{
	if ( n == 1)
		return 1; 
	else
		return (fact(n-1) * n);
}	

int main(int argc, _TCHAR* argv[])
{
	int n = 0;
	printf("Enter n:");
	scanf("%d", &n);
	printf("Factorial of %d = %d", n, fact(n));
	scanf("%");
	return 0;
}

