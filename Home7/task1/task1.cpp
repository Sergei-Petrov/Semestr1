// author: Sergei Petrov

// email: sergei.petrov1994@gmail.com

// group №143

// homework №7 , task 1

// Получив домашнее задание по программированию, группа студентов приступила к решению задач. 
// Три студента с номерами 1, 2 и 3 честно сделали все задание самостоятельно, другие решили списать с кого-нибудь, 
// кто уже имеет готовое решение - либо решенное самостоятельно, либо уже списанное с другого. На следующем занятии 
// выяснилось, что некоторых студентов следует немедленно отчислить, т.к. они не только не написали решение сами, 
// но и поленились списать. Задача: Определить, какой студент какое решение сдавал, и кого надо отчислить.
// На входе: количество студентов и список пар чисел, где первое число - номер студента, второе - номер того, 
// с кого было списано решение. Требуется вывести список пар чисел, где первое число - номер студента, 
// второе - 1, 2 или 3 - сданный вариант.

#include "stdafx.h"
#include <iostream>

using namespace std;

void initialization(int spisok[], int number)
{
	for(int i = 0; i < number; i++)
		spisok[i] = 0;
}

int main()
{
	FILE *file;
	file = fopen("txt.txt","r");
	int number = 0;					// кол-во студентов
	fscanf(file, "%d", &number);
	int *spisok = new int[number];	// Список студентов. Индекс+1 - номер студента. Значение - номер студента, с которого списали.
	int student = 0;				// номер студента
	initialization(spisok, number);
	for(int i = 0; i < number; i++)
	{
		fscanf(file, "%d", &student);
		fscanf(file, "%d", &spisok[student - 1]);
	}
	fclose(file);
	for(int i = 0; i < number ; i++)
	{
		if(spisok[i] == 0)
			printf("%d send down\n", i + 1);
		else
		{
			while((spisok[i] != 1) && (spisok[i] != 2) && (spisok[i] != 3))
				spisok[i] = spisok[spisok[i] - 1];
			printf("%d : %d\n",i + 1, spisok[i]);
		}
	}
	cin.get();
	return 0;
}