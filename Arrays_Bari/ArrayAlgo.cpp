#include <iostream>
#include "Arry.h"
#include "BasicMethods.h"

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

void Reverse2(struct Arry* arr)
{
	int temp = 0;
	for (int i = 0, j = arr->length - 1; i < j; i++, j--)
	{
		temp = arr->A[i];
		arr->A[i] = arr->A[j];
		arr->A[j] = temp;
	}
}

void InsertSorted(struct Arry* arr, int ele)
{
	int i = arr->length;
	if (arr->length >= arr->size)
		return;
	arr->length++;
	while (i > 0 && arr->A[i - 1] > ele)
	{
		arr->A[i] = arr->A[i - 1];
		i--;
	}
	arr->A[i] = ele;
}

bool isSorted(struct Arry arr)
{
	for (int i = 0; i < arr.length - 1; i++)
	{
		if (arr.A[i] > arr.A[i + 1])
			return false;
	}
	return true;
}

void SeparateNegPosi(struct Arry* arr)
{
	int i = 0, j = arr->length - 1;
	while (i < j)
	{
		while (arr->A[i] < 0)
			i++;

		while (arr->A[j] > 0)
			j--;

		if(i < j)
			Swap(&arr->A[i], &arr->A[j]);
	}
}

struct Arry* Merge(struct Arry arr1, struct Arry arr2)
{
	int i = 0, j = 0, k = 0;
	struct Arry arrC = { NULL, arr1.size + arr2.size, 0};
	arrC.A = new int[arrC.size];
	while (i < arr1.length && j < arr2.length)
	{
		if (arr1.A[i] <= arr2.A[j])
		{
			arrC.A[k] = arr1.A[i];
			arrC.length++;
			k++;
			i++;
		}
		else if (arr1.A[i] > arr2.A[j])
		{
			arrC.A[k] = arr2.A[j];
			arrC.length++;
			k++;
			j++;
		}
	}
	for (;i < arr1.length; i++, k++)
	{
		arrC.A[k] = arr1.A[i];
		arrC.length++;
	}
	for (;j < arr2.length; j++, k++)
	{
		arrC.A[k] = arr2.A[j];
		arrC.length++;
	}
	return &arrC;
}