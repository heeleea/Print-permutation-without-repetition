#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void printArray(int a[], int n);
void printsum(unsigned int n, unsigned int k);
void f(int n, int k, int a[], int used);

void main() 
{
	unsigned int n = 3;
	unsigned int k = 3;
	printsum(n, k);
}


void printArray(int a[], int n)
{
	for (int i = 0; i < (int)n; i++)
	{
		printf("%d", a[i]);
	}
	printf("\n");
}


void printsum(unsigned int n, unsigned int k) 
{
	unsigned int* a = (unsigned int*)malloc(k * sizeof(int));
	if (!a)
		return;

	f((int)n, (int)k, a, 0);
	free(a);
}


void f(int n, int k, int a[], int used)
{	
	unsigned int num_of_iter;

	if (k == 0)
	{
		if (n == 0)
		{
			printArray(a, used);
			return;
		}
		else
		{
			return;
		}
	}

	if (used > 0)
		num_of_iter = min(a[used - 1], n);
	else
		num_of_iter = n;


	for (int i= num_of_iter; i >= 0; i--)
	{
		a[used] = i;
		f(n - i, k - 1, a, used + 1);
	}
}
