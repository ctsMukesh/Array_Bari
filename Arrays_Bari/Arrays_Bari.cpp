#include <iostream>
#include "Arry.h"

using namespace std;

int safeExit()
{
	cout << endl << endl << endl << "Press Enter to continue..." << endl;
	cin.get();
	return 0;
}

int main()
{
	Arry<int> arr1(10);
	int a1[] = { 1, 2, 3, 4, 5, 6, 9, 10, 11 };
	arr1.setArray(a1, 9);
	Arry<int> arr2(10);
	int a2[9] = {2, 4, 6, 8, 10, 12, 14, 16, 18};
	arr2.setArray(a2, 9);
	Arry<int> arr3(10);
	int a3[7] = { 1, 3, 3, 3, 9, 11, 11 };
	arr3.setArray(a3, 7);
	Arry<int> arr4(10);
	int a4[8] = { 3, 6, 10, 8, 6, 4, 10, 6 };
	arr4.setArray(a4, 8);

	//arr1.Append(10);
	//arr1.Insert(8, 17);
	//cout << endl << arr1.Delete(8);
	//cout << endl << arr1.LinearSearch(8);
	//cout << endl << arr1.BinarySearch(20);
	//cout << endl << arr1.BinarySearchRc(4);

	//cout << endl << arr1.Get(1);
	//arr1.Set(1, 3);
	//cout << endl << arr1.Max();
	//cout << endl << arr1.Min();
	//cout << endl << arr1.Sum();
	//cout << endl << arr1.Avg();

	//arr1.Reverse2();

	//arr1.InsertSorted(1);
	//cout << endl << arr1.isSorted();

	//arr1.SeparateNegPosi();
	//arr1.Display();

	//arr3.Display();
	//arr1.Merge(arr3).Display();

	//arr1.FindMissingSorted();
	//arr4.FindMissingUnsorted(1, 10);
	//arr3.FindDuplicatedSorted();
	//arr3.Display();
	//arr3.FindDuplicatedSorted2();

	arr4.FindDuplicateUnsorted();

	return safeExit();
}
