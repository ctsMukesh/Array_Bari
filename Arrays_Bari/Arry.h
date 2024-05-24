#include <iostream>

using namespace std;

#pragma once

template<class T>
class Arry
{
private:
	T* A;
	int size;
	int length;

	void Swap(T* a, T* b)
	{
		T temp = *a;
		*a = *b;
		*b = temp;
	}

	int BinarySearchRc(int l, int h, T key)
	{
		if (l <= h)
		{
			int mid = (l + h) / 2;
			if (A[mid] == key)
				return mid;
			else if (key < A[mid])
				return BinarySearchRc(l, mid - 1, key);
			else if (key > A[mid])
				return BinarySearchRc(mid + 1, h, key);
		}
		return -1;
	}
public:
	Arry()
	{
		size = 10;
		length = 0;
		A = new T[size];
	}
	Arry(int size)
	{
		this->size = size;
		length = 0;
		A = new T[this->size];
	}
	~Arry()
	{
		delete[] A;
	}
	void setArray(T* arr, int len)
	{
		if (len <= size)
		{
			for (int i = 0; i < len; i++)
			{
				A[i] = arr[i];
			}
			length = len;
		}
		else
			cout << endl << "Given array is bigger than size";
	}

	int LinearSearch(T key)
	{
		for (int i = 0; i < length; i++)
		{
			if (key == A[i])
			{
				if (i > 0)
				{
					Swap(&A[i], &A[i - 1]);
					return i - 1;
				}
				return i;
			}
		}
		return -1;
	}

	int BinarySearch(T key)
	{
		//if (A[0] == key)
		//	return 0;
		//if (A[length - 1] == key)
		//	return length - 1;
		int l = 0, h = length - 1, mid = 0;
		while (l <= h)
		{
			mid = (l + h) / 2;
			if (A[mid] == key)
				return mid;
			else if (key < A[mid])
				h = mid - 1;
			else if (key > A[mid])
				l = mid + 1;
		}
		return -1;
	}

	int BinarySearchRc(T key)
	{
		return BinarySearchRc(0, length - 1, key);
	}

	void Reverse2()
	{
		T temp = 0;
		for (int i = 0, j = length - 1; i < j; i++, j--)
		{
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}

	void InsertSorted(T ele)
	{
		int i = length;
		if (length >= size)
			return;
		length++;
		while (i > 0 && A[i - 1] > ele)
		{
			A[i] = A[i - 1];
			i--;
		}
		A[i] = ele;
	}

	bool isSorted()
	{
		for (int i = 0; i < length - 1; i++)
		{
			if (A[i] > A[i + 1])
				return false;
		}
		return true;
	}

	void SeparateNegPosi()
	{
		int i = 0, j = length - 1;
		while (i < j)
		{
			while (A[i] < 0)
				i++;

			while (A[j] > 0)
				j--;

			if (i < j)
				Swap(&A[i], &A[j]);
		}
	}

	Arry Merge(Arry arr2)
	{
		int i = 0, j = 0, k = 0;
		//struct Arry arrC = { NULL, arr1.size + arr2.size, 0 };
		//arrC.A = new int[arrC.size];
		Arry arrC(size + arr2.size);
		while (i < length && j < arr2.length)
		{
			if (A[i] <= arr2.A[j])
			{
				arrC.A[k] = A[i];
				arrC.length++;
				k++;
				i++;
			}
			else if (A[i] > arr2.A[j])
			{
				arrC.A[k] = arr2.A[j];
				arrC.length++;
				k++;
				j++;
			}
		}
		for (;i < length; i++, k++)
		{
			arrC.A[k] = A[i];
			arrC.length++;
		}
		for (;j < arr2.length; j++, k++)
		{
			arrC.A[k] = arr2.A[j];
			arrC.length++;
		}
		return arrC;
	}

	void Display();

	T Get(int index);

	void Set(int index, T ele);

	void Append(T ele);

	void Insert(int index, T ele);

	T Delete(int index);

	T Sum();

	float Avg();

	T Max();

	T Min();
};

template<class T>
void Arry<T>::Display()
{
	cout << endl << "The elements are:" << endl;
	for (int i = 0; i < length; i++)
	{
		cout << A[i] << " ";
	}
	return;
}

template<class T>
T Arry<T>::Get(int index)
{
	if (index >= 0 && index < length)
		return A[index];
	return -1;
}

template<class T>
void Arry<T>::Set(int index, T ele)
{
	if (index >= 0 && index < length)
		A[index] = ele;
}

template<class T>
void Arry<T>::Append(T ele)
{
	if (size < length)
		A[length++] = ele;
	return;
}

template<class T>
void Arry<T>::Insert(int index, T ele)
{
	if (length == size) {
		cout << "Array is full" << endl;
		return;

	}
	if (index >= 0 && index <= length)
	{
		for (int i = length; i > index; i--)
		{
			A[i] = A[i - 1];
		}
		A[index] = ele;
		length++;
	}
	return;
}

template<class T>
T Arry<T>::Delete(int index)
{
	int x = 0;
	if (index >= 0 && index >= length)
	{
		cout << "out of range" << endl;
		return x;
	}
	x = A[index];
	for (int i = index; i < length - 1; i++)
	{
		A[i] = A[i + 1];
	}
	length--;
	return x;
}

template<class T>
T Arry<T>::Sum()
{
	T sum = 0;
	for (int i = 0; i < length; i++)
	{
		sum = sum + A[i];
	}
	return sum;
}

template<class T>
float Arry<T>::Avg()
{
	return (float)Sum() / length;
}

template<class T>
T Arry<T>::Max()
{
	T max = A[0];
	for (int i = 0; i < length; i++)
	{
		if (max < A[i])
			max = A[i];
	}
	return max;
}

template<class T>
T Arry<T>::Min()
{
	T min = A[0];
	for (int i = 0; i < length; i++)
	{
		if (min > A[i])
			min = A[i];
	}
	return min;
}
