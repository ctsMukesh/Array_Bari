#include <iostream>
#include "Arry.h"
#include "BasicMethods.h"
#include "ArrayAlgo.h"


using namespace std;

int safeExit()
{
	cout << endl << endl << endl << "Press Enter to continue..." << endl;
	cin.get();
	return 0;
}


int main()
{
	struct Arry arr1 = {
		NULL,10,9
	};
	arr1.A = new int[arr1.size] {2, 4, 6, 8, 10, 12, 14, 16, 18};
	struct Arry arr2 = {
		NULL,10,7
	};
	arr2.A = new int[arr2.size] {1, 3, 5, 7, 9, 11, 14};

	//Append(&arr, 10);
	//Insert(&arr, 8, 17);
	//cout << endl << Delete(&arr, 8);
	//cout << endl << LinearSearch(&arr, 8);
	//cout << endl << BinarySearch(arr, 20);
	//cout << endl << BinarySearchRc(arr,0,arr.length - 1, 4);

	//cout << endl << Get(arr, 1);
	//Set(&arr, 1, 3);
	//cout << endl << Max(arr);
	//cout << endl << Min(arr);
	//cout << endl << Sum(arr);
	//cout << endl << Avg(arr);

	//Reverse2(&arr);

	//InsertSorted(&arr, 1);
	//cout << endl << isSorted(arr);

	//SeparateNegPosi(&arr1);
	Display(arr1);

	Display(*Merge(arr1, arr2));

	delete(arr1.A);
	arr1.A = NULL;
	return safeExit();
}
