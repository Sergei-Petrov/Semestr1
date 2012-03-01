#include "stdafx.h"

int main(int argc, _TCHAR* argv[])
{
	int n = 0;
	int	s = 1;
	printf("Enter n:");
	scanf("%d",&n);
	for (int i = 2; i <= n; i++)
	{
		s = i * s;
	}
	printf("Factorial of %d = %d", n, s);
	scanf("%");
	return 0;
}

