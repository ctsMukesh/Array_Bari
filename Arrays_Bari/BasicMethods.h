#pragma once

#ifndef BasicMethods

#define BasicMethods

void Display(struct Arry arr);

int Get(struct Arry arr, int index);

void Set(struct Arry* arr, int index, int ele);

void Append(struct Arry* arr, int ele);

void Insert(struct Arry* arr, int index, int ele);

int Delete(struct Arry* arr, int index);

int Max(struct Arry arr);

int Min(struct Arry arr);

#endif

