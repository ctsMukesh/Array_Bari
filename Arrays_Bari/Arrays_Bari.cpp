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
	struct Arry arr = {
		NULL,10,9
	};
	arr.A = new int[arr.size] {2, 4, 6, 8, 10, 12, 14, 16, 18};

	//Append(&arr, 10);
	//Insert(&arr, 8, 17);
	//cout << endl << Delete(&arr, 8);
	//cout << endl << LinearSearch(&arr, 8);
	//cout << endl << BinarySearch(arr, 20);
	//cout << endl << BinarySearchRc(arr,0,arr.length - 1, 4);

	cout << endl << Get(arr, 1);
	Set(&arr, 1, 3);
	cout << endl << Max(arr);
	cout << endl << Min(arr);
	cout << endl << Sum(arr);
	cout << endl << Avg(arr);

	Display(arr);

	return safeExit();
}
