#include "stdafx.h"
#include <stdlib.h>
#include "syntax.h"
#include "double.h"

bool plusOrMinus(char *&c)
{
	delSpace(c);
	if (!multOrDiv(c)) //�������� �� ������� ������� ����������
		return false;
	delSpace(c);
	while (*c == '+' || *c == '-')
	{
		c++;
		if (!multOrDiv(c)) //�������� �� ������� ����������� ���������
			return false;
	}
	return true;
}

bool multOrDiv(char *&c)
{
	delSpace(c);
	if (!bracketOrNumber(c)) // �������� �� ������� ������� ���������
		return false;
	delSpace(c);
	while (*c == '*' || *c == '/')
	{
		c++;
		if (!bracketOrNumber(c)) //�������� �� ������� ����������� ����������
			return false;
	}
	return true;
}

bool bracketOrNumber(char *&c)	// �������� �� ������ ��� �����
{
	delSpace(c);
	if (*c == '(')
	{
		c++;					//���� ������������� ������, ��
		if (!plusOrMinus(c))	//��������� �������
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