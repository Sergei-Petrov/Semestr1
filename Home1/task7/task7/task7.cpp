#include "stdafx.h"
#include <math.h>

int main(int argc, _TCHAR* argv[])
{
	int n = 0;
	printf("Enter n:");
	scanf("%d",&n);
	printf("Prime numbers : ");
	
	for (int i = 2; i <= n; i++)
	{
		bool t = true;
		int	k = 2;
	while (k <= sqrt(double(i)) && (t == true))
	{
		if (i % k == 0) 
		{
			t = false;
		}
		k++;
	}
	if (t == true)
	{
		printf("%d ", i);
	}
}
	scanf("%d", n);
	return 0;
}

