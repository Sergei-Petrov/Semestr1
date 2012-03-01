#include "stdafx.h"
#include <stdlib.h>
#include "isDouble.h"

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
	return c == 'e';
}

bool end(char c)
{
	return c == 0;
}

bool checkDouble(char *&string)
{
	int state = 0;
	while(true)
	{
		switch(state)
		{
			case 0:
				if(sign(*string))
					state = 1;
				else if(digit(*string))
					state = 2;
				else
					state = 3;
					break;
			case 1:
				if(digit(*string))
					state = 2;
				else
					state = 3;
				break;
			case 2:
				if(digit(*string))
					state = 2;
				else if(dot(*string))
					state = 4;
				else
					state = 3;
				break;
			case 3:
				return false;
				break;
			case 4:
				if(digit(*string))
					state = 5;
				else
					state = 3;
				break;
			case 5:
				if(digit(*string))
					state = 5;
				else if(e(*string))
					state = 6;
				else
					state = 3;
				break;
			case 6:
				if(sign(*string))
					state = 7;
				else
					state = 3;
				break;
			case 7:
				if(digit(*string))
					state = 8;
				else
					state =3;
				break;
			case 8:
				if(digit(*string))
					state = 8;
				else if(end(*string))
					state = 9;
				else
					state = 3;
				break;
			case 9:
				return true;
				break;
		}
		string++;
	}
}