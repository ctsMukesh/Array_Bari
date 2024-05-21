#include <iostream>
#include "Arry.h"

using namespace std;

void Display(struct Arry arr)
{
	cout << endl << "The elements are:" << endl;
	for (int i = 0; i < arr.length; i++)
	{
		cout << arr.A[i] << " ";
	}
	return;
}

int Get(struct Arry arr, int index)
{
	if (index >= 0 && index < arr.length)
		return arr.A[index];
	return -1;
}

void Set(struct Arry* arr, int index, int ele)
{
	if (index >= 0 && index < arr->length)
		arr->A[index] = ele;
}

void Append(struct Arry* arr, int ele)
{
	if (arr->size < arr->length)
		arr->A[arr->length++] = ele;
	return;
}

void Insert(struct Arry* arr, int index, int ele)
{
	if (arr->length == arr->size) {
		cout << "Array is full" << endl;
		return;

	}
	if (index >= 0 && index <= arr->length)
	{
		for (int i = arr->length; i > index; i--)
		{
			arr->A[i] = arr->A[i - 1];
		}
		arr->A[index] = ele;
		arr->length++;
	}
	return;
}

int Delete(struct Arry* arr, int index)
{
	int x = 0;
	if (index >= 0 && index >= arr->length)
	{
		cout << "out of range" << endl;
		return x;
	}
	x = arr->A[index];
	for (int i = index; i < arr->length - 1; i++)
	{
		arr->A[i] = arr->A[i + 1];
	}
	arr->length--;
	return x;
}

int Max(struct Arry arr)
{
	int max = arr.A[0];
	for (int i = 0; i < arr.length; i++)
	{
		if (max < arr.A[i])
			max = arr.A[i];
	}
	return max;
}

int Min(struct Arry arr)
{
	int min = arr.A[0];
	for (int i = 0; i < arr.length; i++)
	{
		if (min > arr.A[i])
			min = arr.A[i];
	}
	return min;
}

