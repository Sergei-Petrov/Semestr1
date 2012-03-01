#pragma once

const int size = 100;	//размер хэш-таблицы

struct Node
{
	char string[50];
	int number;
	Node *next;
}; 

Node *create(char string[]);
bool check(char str[], char str2[]);
void add(Node *&tab, char string[]);
int hash(char string[]);
void delHash();
void printHash();
void addHash(char string[]);
void found(FILE *file, char string[], int &flag);
