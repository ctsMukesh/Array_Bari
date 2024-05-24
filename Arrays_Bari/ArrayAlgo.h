#pragma once

#ifndef ArrayAlgo

#define ArrayAlgo

int LinearSearch(struct Arry* arr, int key);

int BinarySearch(struct Arry arr, int key);

int BinarySearchRc(struct Arry arr, int l, int h, int key);

void Reverse2(struct Arry* arr);

bool isSorted(struct Arry arr);

void InsertSorted(struct Arry* arr, int ele);

void SeparateNegPosi(struct Arry* arr);

struct Arry* Merge(struct Arry arrA, struct Arry arrB);

#endif // !ArrayAlgo

