#include <iostream>
#include <cmath>

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
	int GetSize()
	{
		return size;
	}
	int GetLen()
	{
		return length;
	}
	void incLen()
	{
		length++;
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

	void SumOfPairEquals(T val)
	{
		for (int i = 0; i < GetLen() - 1; i++)
		{
			for (int j = i + 1; j < GetLen(); j++)
			{
				if (Get(i) + Get(j) == val)
					cout << endl << Get(i) << " + " << Get(j) << " = " << val;
			}
		}
	}

	void SumOfPairEqualsHsh(T val)
	{
		int H[] = new int[static_cast<int>(round(Max()))];
		for (int i = 0; i < GetLen(); i++)
		{
			H[static_cast<int>(round(Get(i)))]++;
			if(H[val - i] > 0)
				cout << endl << i << " + " << val - i << " = " << val;
				
		}
	}

	void SumOfPairEqualSorted(T val)
	{
		int i = 0; j = GetLen() - 1;
		while (i < j)
		{
			if (Get(i) + Get(j) > val)
				j--;
			else if (Get(i) + Get(j) == val)
			{
				cout << endl << Get(i) << " + " << Get(j) << " = " << val;
				i++;
				j--;
			}
			else if (Get(i) + Get(j) < val)
				i++;
		}
	}

	void FindDuplicateUnsorted2()
	{
		int H[] = new int[static_cast<int>(round(Max()))];
		for (int i = 0; i < GetLen(); i++)
		{
			H[static_cast<int>(round(Get(i))]++;
		}
		for (int i = 0;i < static_cast<int>(round(Max()));i++)
		{
			if (H[i] > 1)
				cout << endl << i << " repeated " << H[i] << " times";
		}
		delete[]H;
	}

	void FindDuplicateUnsorted()
	{
		for (int i = 0; i < length - 1; i++)
		{
			int count = 1;
			if (A[i] != -1)
			{
				for (int j = i + 1;j < length; j++)
				{
					if (A[i] == A[j])
					{
						count = count + 1;
						A[j] = -1;
					}
				}
			}
			if (count > 1)
				cout << endl << A[i] << " repeated " << count << " times.";
		}
	}

	void FindMissingSorted()
	{
		T diff = A[0];
		cout << endl;
		for (int i = 0; i < length; i++)
		{
			if (diff < A[i] - i)
			{
				while (diff < A[i] - i)
				{
					cout << diff + i << " ";
					diff++;
				}
			}
		}
	}

	void FindMissingUnsorted(int low, int high)
	{
		int* H = new int[high - low + 1] {0}; //Create array of all 0s
		if (is_floating_point_v<decltype(A[0])>)
		{
			cout << endl << "This method can't be used for float. Use FindMissingSorted";
			return;
		}
		cout << endl;
		for (int i = 0;i < length; i++)
		{
			int intVal = static_cast<int>(round(A[i]));
			H[intVal - low]++;
		}
		for (int i = low; i <= high; i++)
		{
			if (H[i - low] == 0)
				cout << i << " ";
		}
		delete[]H;
	}

	void FindDuplicatedSorted()
	{
		int lastFound = 0;
		cout << endl;
		for (int i = 0;i < length - 1; i++)
		{
			if (A[i] == A[i + 1])
			{
				int j = i + 1;
				while (A[j] == A[i])
					j++;
				cout << A[i] << " " << j - i << " times, ";
				i = j - 1;
			}
		}
	}

	void FindDuplicatedSorted2()
	{
		int* H = new int [static_cast<int>(round(Max()))] {0};
		if (is_floating_point_v<decltype(A[0])>)
		{
			cout << endl << "This method can't be used for float. Use FindDuplicatedSorted";
			return;
		}
		cout << endl;
		for (int i = 0; i < length; i++)
		{
			int intVal = static_cast<int>(round(A[i]));
			H[intVal]++;
		}
		for (int i = 0; i < 100; i++)
		{
			if (H[i] > 1)
				cout << i << " " << H[i] << " times, ";
		}
		delete[]H;
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
		//struct Arry arrC = { NULL, arr1.size + arr2.GetSize(), 0 };
		//arrC.A = new int[arrC.size];
		Arry arrC(GetSize + arr2.GetSize());
		while (i < GetLen() && j < arr2.GetLen())
		{
			if (Get(i) <= arr2.Get(j))
			{
				arrC.Set(k) = Get(i);
				arrC.incLen();
				k++;
				i++;
			}
			else if (Get(i) > arr2.Get(j))
			{
				arrC.Set(k) = arr2.Get(i);
				arrC.incLen();
				k++;
				j++;
			}
		}
		for (;i < GetLen(); i++, k++)
		{
			arrC.Set(k) = Get(i);
			arrC.incLen();
		}
		for (;j < arr2.GetLen(); j++, k++)
		{
			arrC.Set(k) = arr2.Get(j);
			arrC.incLen();
		}
		return arrC;
	}

	T Min()
	{
		T min = A[0];
		for (int i = 0; i < length; i++)
		{
			if (min > A[i])
				min = A[i];
		}
		return min;
	}

	T Max()
	{
		T max = A[0];
		for (int i = 0; i < length; i++)
		{
			if (max < A[i])
				max = A[i];
		}
		return max;
	}

	float Avg()
	{
		return (float)Sum() / length;
	}

	T Sum()
	{
		T sum = 0;
		for (int i = 0; i < length; i++)
		{
			sum = sum + A[i];
		}
		return sum;
	}

	T Delete(int index)
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

	void Insert(int index, T ele)
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

	void Append(T ele)
	{
		if (size < length)
			A[length++] = ele;
		return;
	}

	void Set(int index, T ele)
	{
		if (index >= 0 && index < length)
			A[index] = ele;
	}

	T Get(int index)
	{
		if (index >= 0 && index < length)
			return A[index];
		return -1;
	}

	void Display();
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
