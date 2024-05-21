#include "Arry.h"

int Sum(struct Arry arr)
{
	int sum = 0;
	for (int i = 0; i < arr.length; i++)
	{
		sum = sum + arr.A[i];
	}
	return sum;
}

float Avg(struct Arry arr)
{
	return (float)Sum(arr) / arr.length;
}

int LinearSearch(struct Arry* arr, int key)
{
	for (int i = 0; i < arr->length; i++)
	{
		if (key == arr->A[i])
		{
			arr->A[i] = arr->A[i - 1];
			arr->A[i - 1] = key;
			return i - 1;
		}
	}
	return -1;
}

int BinarySearch(struct Arry arr, int key)
{
	//if (arr.A[0] == key)
	//	return 0;
	//if (arr.A[arr.length - 1] == key)
	//	return arr.length - 1;
	int l = 0, h = arr.length - 1, mid = 0;
	while (l <= h)
	{
		mid = (l + h) / 2;
		if (arr.A[mid] == key)
			return mid;
		else if (key < arr.A[mid])
			h = mid - 1;
		else if (key > arr.A[mid])
			l = mid + 1;
	}
	return -1;
}

int BinarySearchRc(struct Arry arr, int l, int h, int key)
{
	if (l <= h)
	{
		int mid = (l + h) / 2;
		if (arr.A[mid] == key)
			return mid;
		else if (key < arr.A[mid])
			return BinarySearchRc(arr, l, mid - 1, key);
		else if (key > arr.A[mid])
			return BinarySearchRc(arr, mid + 1, h, key);
	}
	return -1;
}