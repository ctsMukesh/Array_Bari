#include <iostream>

using namespace std;

int safeExit()
{
	cout << endl << endl << endl << "Press Enter to continue..." << endl;
	cin.get();
	return 0;
}

struct Arry
{
	int* A;
	int size;
	int length;
};

void display(struct Arry arr)
{
	cout << "The elements are:" << endl;
	for (int i = 0; i < arr.length; i++)
	{
		cout << arr.A[i] << " ";
	}
	return;
}

int main()
{
	struct Arry arr;
	arr.A = NULL;
	arr.length = 0;
	arr.size = 0;
	int n = 0;
	cout << endl << "Enter size of array" << endl;
	cin >> arr.size;
	arr.A = new int[arr.size];

	cout << "Enter number of elements" << endl;
	cin >> n;
	cout << "Enter all elements";
	for (int i = 0; i < n; i++)
	{
		cin >> arr.A[i];
	}
	arr.length = n;

	return safeExit();
}
