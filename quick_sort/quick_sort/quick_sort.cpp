// quick_sort.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include"stdlib.h"
#include"time.h"
int insert_arr(int a[],int index)
{
	int rand_n = rand() % 101;
	int i;
	for (i = 0; i < index; i++)
	{
		if (a[i] == rand_n)
			return index;
	}
	a[i] = rand_n;
	return index + 1;
}
void swap(int a[], int i1, int i2)
{
	int temp = a[i1];
	a[i1] = a[i2];
	a[i2] = temp;
}
int find_pivot(int a[], int start, int end)
{
	int pivot = 0;
	for (int i = start; i <= end; i++)
	{
		if (a[i] < a[start])
			pivot++;
	}
	return start + pivot;
}
int small_but_big(int a[],int start,int pivot)
{
	for (int i = start; i < pivot; i++)
	{
		if (a[i] > a[pivot])
			return i;
	}
	return -1;
}
int big_but_small(int a[], int pivot, int end)
{
	for (int i = pivot; i <= end; i++)
	{
		if (a[i] < a[pivot])
			return i;
	}
	return -1;
}
int partition(int a[], int start, int end)
{
	int pivot = find_pivot(a, start, end);
	int high, low;

	if (pivot != start)
	{
		swap(a, start, pivot);
		high = small_but_big(a, start, pivot);
		low = big_but_small(a, pivot, end);
		while (low != -1)
		{
			swap(a, high, low);
			high = small_but_big(a, start, pivot);
			low = big_but_small(a, pivot, end);
		}
	}
	return pivot;
}
void quick_sort(int a[], int start, int end)
{
	int n = end - start + 1, pivot;
	if (n <= 1)
		return;
	else if (n == 2)
	{
		if (a[start] > a[end])
			swap(a, start, end);
	}
	else
	{
		pivot = partition(a, start, end);
		quick_sort(a, start, pivot-1);
		quick_sort(a, pivot+1, end);
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	int a[20];
	srand(time(0));
	int index = 0;
	while (index < 20)
	{
		index = insert_arr(a, index);
	}	
	
	printf("before sorting:\n");
	for (int i = 0; i < 20; i++)
	{
		printf("%d ", a[i]);
	}
	quick_sort(a, 0, 19);
	printf("\nafter sorting:\n");
	for (int i = 0; i < 20; i++)
	{
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;
}

