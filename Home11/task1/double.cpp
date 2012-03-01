#include "stdafx.h"
#include <stdlib.h>
#include "double.h"

bool sign(char c)
{
	return c == '-' || c == '+';
}

bool digit(char c)
{
	return c >= '0' && c <= '9';
}

bool dot(char c)
{
	return c == '.';
}

bool e(char c)
{
	return c == 'e' || c == 'E';
}



bool checkDouble(char *&c)
{
	int state = 0;
	while(true)
	{
		switch (state)
		{
			case 0 :
				if(sign(*c))
					state = 1;
				else if(digit(*c))
					state = 2;
				else
					return false;
				break;
			case 1 :
				if(digit(*c))
					state = 2;
				else
					return false;
				break;
			case 2 :
				if(digit(*c))
					state = 3;
				else if(dot(*c))
					state = 4;
				else 
					return true;
				break;
			case 3 :
				if(!digit(*c))
					return true;
				break;
			case 4:
				if(digit(*c))
					state = 5;
				else
					return false;
				break;
			case 5:
				if(digit(*c))
					state = 5;
				else if(e(*c))
					state = 6;
				else
					return true;
				break;
			case 6:
				if(sign(*c))
					state = 7;
				else
					return false;
				break;
			case 7:
				if(digit(*c))
					state = 8;
				else
					return false;
				break;
			case 8:
				if(digit(*c))
					state = 8;
				else
					return true;
				break;
		}
		c++;
	}
}