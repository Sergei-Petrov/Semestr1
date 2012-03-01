// author: Sergei Petrov

// email: sergei.petrov1994@gmail.com

// group є143

// homework є3 , task 2

// "—читалочка" Ч за каждый раунд из циклического списка удал€ем k-й элемент, 
// пока в списке не останетс€ только один. ¬ывести значени€ k, при которых последним 
// останетс€ i-й элемент изначального списка

#include "stdafx.h"
#include "list.h"

int main()
{
	list *cycle = NULL;
	printf("Enter the sum of elements : ");
	int kol;
	scanf("%d", &kol);
	printf("Enter position : ");
	int pos;
	scanf("%d", &pos);
	bool flag = true;
	for(int j = 2; j <= kol; j++)
	{
		cycle = create(kol);
		del(cycle, pos, kol, j, flag);
	}
	if (flag)
		printf("There is no before %d", kol);
	scanf("%*s"); 
	return 0;
}