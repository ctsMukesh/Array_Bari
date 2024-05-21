#pragma once

#ifndef ArrayAlgo

#define ArrayAlgo

int Sum(struct Arry arr);

float Avg(struct Arry arr);

int LinearSearch(struct Arry* arr, int key);

int BinarySearch(struct Arry arr, int key);

int BinarySearchRc(struct Arry arr, int l, int h, int key);

#endif // !ArrayAlgo

