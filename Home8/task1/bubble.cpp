#include "stdafx.h"
#include "bubble.h"

void bubble(int array[], int length)
{
	bool flag = true;
	while(flag)
	{
		flag = false;
		for(int i = 0; i < length - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				int tmp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = tmp;
				flag = true;
			}
		}
	}
}
