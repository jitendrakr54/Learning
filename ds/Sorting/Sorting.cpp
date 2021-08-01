#include "Sorting.h"
#include <iostream>

namespace ds {
namespace sorting {

//	7, 2, 4, 1, 8, 3
	void selectionSort(int a[], int n) {
		int iMin;
		int temp;
		for (int i=0; i<n-1; ++i) {
			iMin = i;
			for(int j=i+1; j<n; ++j) {
				if(a[j] < a[iMin]) {
					iMin = j;
				}
			}
			temp = a[i];
			a[i] = a[iMin];
			a[iMin] = temp;
		}
	}

	void bubbleSort(int a[], int n) {
		print(a, n);
		int flag;
		int temp;
		for(int i=0; i<n-1; ++i) {
			flag = 0;
			for(int j = 0; j<n-i-1; ++j) {
				if (a[j] > a[j+1]) {
					temp = a[j];
					a[j] = a[j+1];
					a[j+1] = temp;
					flag = 1;
				}
			}
			if(flag==0) break;
		}
	}

	void insertionSort(int a[], int n) {
		int value, hole;
		for(int i = 1; i<n; ++i) {
			value = a[i];
			hole = i;
			while (hole>0 && a[hole-1] > value) {
				a[hole-1] = value;
				hole = hole-1;
			}
			a[hole] = value;
		}
	}

	void print(int a[], int n) {
		for (int i=0; i<n; i++) {
			std::cout<<a[i]<<"\t";
		}
		std::cout<<"\n";
	}
}
}
