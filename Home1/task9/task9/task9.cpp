#include "stdafx.h"
#include <math.h>

int main()
{
	int a = 0;
	int n = 0;
	printf("Enter a:");
	scanf("%d", &a);
	printf("Enter n:");
	scanf("%d", &n);
	if (n > 0)
	{
		double s = 1;
		for (int i = 1; i <= n; i++)
		{
			s = s * a;
		}
		printf("itog:%g", s);
	}
	if (n == 0)
	{
		double s = 1;
		printf("itog:%g", s);
	}
	if (n < 0)
	{
		double s = 1.0;
		for (int i = 1; i <= abs(n); i++)
		{
			s=(double)s / a;
		}
		printf("itog:%g", s);
	}
	scanf("%");
	return 0;
}

