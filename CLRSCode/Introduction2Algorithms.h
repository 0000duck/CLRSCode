//////////////////////////////////////////////////////////////////////////
//
//	Introduction2Algorithms.h
//
//	Written by Meng Zhu ,Zhejiang University (zhumeng1989@gmail.com)
//	Creation date: Sep.10 2012, 19:15
//
//	All Rights Reserved.
//
//////////////////////////////////////////////////////////////////////////

#ifndef Introduction2Algorithms_H
#define Introduction2Algorithms_H

#include <iostream>

namespace zm {

// NOTE: 
// 1. For supporting index 0, 'i' must be signed.
template <typename T>
void INSERTION_SORT(T *A, int A_length)
{
	for (int j(1); j < A_length; j++)
	{
		T key = A[j];
		int i = j-1;
		while (i >= 0 && A[i] > key) // $1
		{
			A[i+1] = A[i];
			i = i-1; // $1
		}
		A[i+1] = key;
	}
}

// NOTE: 
// 1. The infinite number using FLT_MAX violate typename T. updated by 2.3-2
// 2. For indexing from 0, note the change $2.
template <typename T>
void MERGE(T *A, int p, int q, int r)
{
	int n1 = q-p+1;
	int n2 = r-q;
	T *L = new T[n1];
	T *R = new T[n2];
	for (int i(0); i < n1; i++)
		L[i] = A[p+i]; // $2
	for (int j(0); j < n2; j++)
		R[j] = A[q+j+1]; // $2
	int i(0), j(0), k(p);
	for (; i < n1 && j < n2; k++)
	{
		if (L[i] <= R[j])
		{
			A[k] = L[i];
			i = i+1;
		} else {
			A[k] = R[j];
			j = j+1;
		}
	}
	for (; i < n1; i++,k++)
		A[k] = L[i];
	for (; j < n2; j++,k++)
		A[k] = R[j];
	delete []L;
	delete []R;
}

template <typename T>
void MERGE_SORT(T *A, int p, int r)
{
	if (p < r)
	{
		int q = (p+r)/2;
		MERGE_SORT(A, p, q);
		MERGE_SORT(A, q+1, r);
		MERGE(A, p, q, r);
	}
}

// NOTE: 
//
template <typename T>
int ITERATIVE_BINARY_SEARCH(T *A, T v, int low, int high)
{
	while (low <= high)
	{
		int mid = (low+high)/2;
		if (v == A[mid])
			return mid;
		else if (v > A[mid])
			low = mid+1;
		else
			high = mid-1;
	}
	return -1;
}

template <typename T>
int RECURSIVE_BINARY_SEARCH(T *A, T v, int low, int high)
{
	if (low > high)
		return -1;
	int mid = (low+high)/2;
	if (v == A[mid])
		return mid;
	else if (v > A[mid])
		return RECURSIVE_BINARY_SEARCH(A, v, mid+1, high);
	else
		return RECURSIVE_BINARY_SEARCH(A, v, low, mid-1);
}

template <typename T>
int PARTITION(T *A, int p, int r)
{
	T x = A[r];
	int i = p-1;
	for (int j(p); j < r; j++)
	{
		if (A[j] <= x)
		{
			i = i+1;
			T tmp = A[i]; A[i] = A[j]; A[j] = tmp;
		}
	}
	T tmp = A[i+1]; A[i+1] = A[r]; A[r] = tmp;
	return i+1;
}

template <typename T>
int RANDOMIZED_PARTITION(T *A, int p, int r)
{
	int i = p+int((float)rand()/(float)RAND_MAX*(r-p));
	T tmp = A[i]; A[i] = A[r]; A[r] = tmp;
	return PARTITION(A, p, r);
}

template <typename T>
void QUICKSORT(T *A, int p, int r)
{
	if (p < r)
	{
		int q = PARTITION(A, p, r);
		QUICKSORT(A, p, q-1);
		QUICKSORT(A, q+1, r);
	}
}

template <typename T>
void RANDOMIZED_QUICKSORT(T *A, int p, int r)
{
	if (p < r)
	{
		int q = RANDOMIZED_PARTITION(A, p, r);
		RANDOMIZED_QUICKSORT(A, p, q-1);
		RANDOMIZED_QUICKSORT(A, q+1, r);
	}
}

template <typename T>
void TAIL_RECURSIVE_QUICKSORT(T *A, int p, int r)
{
	while (p < r)
	{
		int q = PARTITION(A, p, r);
		TAIL_RECURSIVE_QUICKSORT(A, p, q-1);
		p = q+1;
	}
}

} // namespace

#endif