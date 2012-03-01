#include "stdafx.h"
#include "hashtab.h"

Node *hashtab[size];	// хэш-таблица

Node *create(char string[])	// создание элемента хэш-таблицы
{
	Node *tmp = new Node;
	int count = 0;
	while(string[count - 1] != '\0')
		tmp->string[count] = string[count++];
	tmp->number = 1;
	tmp->next = NULL;
	return tmp;
}

bool check(char str[], char str2[])	// проверка равенства слов
{
	int count = 0;
	while((str[count] != '\0') || (str2[count] != '\0'))
	{
		if(str[count] != str2[count])
			return false;
		count++;
	}
	return true;
}

void addHash(char string[])
{
	add(hashtab[hash(string)], string);
}

void add(Node *&tab, char string[])	// добавление в хэш-таблицу
{
	if(tab == NULL)
		tab = create(string);
	else
	{
		if(check(string, tab->string))
			tab->number++;
		else
			add(tab->next, string);
	}
}

int hash(char string[])	// хэш-функция
{
	int count = 0;
	int key = 0;
	while(string[count] != '\0')
		key = (key + string[count++]) % size;
	return key;
}

void delHash()	// очистка хэш-таблицы
{
	for(int i = 0; i < size; i++)
		if(hashtab[i] != NULL)
			while (hashtab[i] != NULL)
			{
				Node *tmp =	hashtab[i];
				hashtab[i] = tmp->next;
				delete(tmp);
			}
}

void printHash()	// вывод
{
	for(int i = 0; i < size; i++)
	{
		if(hashtab[i] != NULL)
			while (hashtab[i] != NULL)
			{
				printf("%s %d\n", hashtab[i]->string, hashtab[i]->number);
				hashtab[i] = hashtab[i]->next;
			}
	}
}

void found(FILE *file, char string[], int &flag)
{
	int key = hash(string);
	Node *tmp = hashtab[key];
	while(tmp != NULL)
		if(check(tmp->string, string))
			if(tmp->number  > 0)
			{
				fprintf(file, "%s\n", string);
				tmp->number--;
				flag++;
				return;
			}
			else
				return;
		else
			tmp = tmp->next;
}