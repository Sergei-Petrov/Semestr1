#include "stdafx.h"
#include "hashtab.h"

Node *hashtab[size];	// хэш-таблица

Node *create(char word[])	// создание элемента хэш-таблицы
{
	Node *tmp = new Node;
	int count = 0;
	while(word[count - 1] != '\0')
		tmp->word[count] = word[count++];
	tmp->number = 1;
	tmp->next = NULL;
	return tmp;
}

bool check(char str[], char str2[])	// проверка равенства слов
{
	int count = 0;
	bool flag = true;
	while((str[count] != '\0') || (str2[count] != '\0'))
	{
		if(str[count] != str2[count])
			return false;
		count++;
	}
	return true;
}

void addHash(char word[])
{
	add(hashtab[hash(word)], word);
}

void add(Node *&tab, char word[])	// добавление в хэш-таблицу
{
	if(tab == NULL)
		tab = create(word);
	else
	{
		if(check(word, tab->word))
			tab->number++;
		else
			add(tab->next, word);
	}
}

int hash(char str[])	// хэш-функция
{
	int count = 0;
	int key = 0;
	while(str[count] != '\0')
		key = key + (str[count++] - 'A');
	return key % size;
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
				printf("%s %d\n", hashtab[i]->word, hashtab[i]->number);
				hashtab[i] = hashtab[i]->next;
			}
	}
}