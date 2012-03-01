#pragma once

const int size = 100;	//размер хэш-таблицы

struct Node
{
	char word[12];
	int number;
	Node *next;
}; 

Node *create(char word[]);
bool check(char str[], char str2[]);
void add(Node *&tab, char word[]);
int hash(char str[]);
void delHash();
void printHash();
void addHash(char word[]);