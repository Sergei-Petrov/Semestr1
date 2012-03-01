// author: Sergei Petrov

// email: sergei.petrov1994@gmail.com

// group №143

// homework №6 , task 2

// По дереву разбора арифметического выражения вычислить его значение. Дерево разбора хранится в файле в виде 
// (<операция> <операнд1> <операнд2>), где <операнд1> и <операнд2> сами могут быть деревьями, либо числами. 
// Например, выражение (1 + 1) * 2 представляется в виде (* (+ 1 1) 2). Должны поддерживаться операции +, -, *, / 
// и целые числа в качестве аргументов. Требуется построить дерево в явном виде, распечатать его (не обязательно так же, 
// как в файле), и посчитать значение выражения обходом дерева. Может быть полезна функция ungetc (если не '(', возвращаем
// символ в поток и читаем число fscanf-ом). Можно считать, что входной файл корректен. Пример - по входному файлу 
// (* (+ 1 1) 2) может печататься ( * ( + 1 1 ) 2 ) и выводиться 4

#include "stdafx.h"
#include <iostream>
#include "tree.h"

using namespace std;

const int length = 30;

void reading(char string[])
{
	FILE *file;
	file = fopen("text.txt", "r");
	fgets(string, length, file);
	fclose(file);
}

int calculate(Tree *tr)
{
	switch (tr->value)
	{
		case '+' : return calculate(tr->left) + calculate(tr->right); break; 
		case '-' : return calculate(tr->left) - calculate(tr->right); break;
		case '*' : return calculate(tr->left) * calculate(tr->right); break;
		case '/' : return calculate(tr->left) / calculate(tr->right); break;
		default : return tr->value - '0'; break;
	}
}

int main()
{
	Tree *tr = NULL;
	char string[length];
	reading(string);
	printf("In file : %s\n", string);
	int count = 0;
	add(tr, string, count);
	printf("Rezult = %d", calculate(tr));
	del(tr);
	cin.get();
	return 0;
}