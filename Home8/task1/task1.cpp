// author: Sergei Petrov

// email: sergei.petrov1994@gmail.com

// group №143

// homework №8 , task 1

// Реализовать сортировку пузырьком

#include "stdafx.h"
#include <iostream>
#include "bubble.h"

void enter(int massiv[], int length)
{
	for(int i = 0; i < length; i++)
	{
		printf("Enter %d element : ", i + 1);
		scanf("%d", &massiv[i]);
	}
}

void print(int massiv[], int length)
{
	for(int i = 0; i < length; i++)
		printf("%d ", massiv[i]);
}

int main()
{
	int length = 0;
	printf("Enter length of array : ");
	scanf("%d", &length);
	int *array = new int[length];
	enter(array, length);
	bubble(array, length);
	print(array, length);
	delete []array;
	std :: cin.get();
	std :: cin.get();
	return 0;
}