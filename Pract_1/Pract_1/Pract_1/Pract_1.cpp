#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main()
{
	int size;
	cout << "Enter size of array: ";
	cin >> size;
	cout << endl;
	         
	int *arr = new int[size];

	for (int i = 0; i < size; i++) {
		arr[i] = rand()%100+1;
	}

	int cup;
	for (int k = 0; k < size; k++) {
		for (int j = 0; j < size - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				cup = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = cup;
			}
		}
	}

	for (int i = 0; i < size; i++) {
		cout << "Arr[" << i << "] = " << arr[i] << endl;
	}

	int find;
	cout << "What element you want to find? ";
	cin >> find;
	cout << endl;

	//Упражнение 1
	
	cout << "Task 1" << endl;

	int iter = 0;
	int i = 0;
	while ((i < size) && (arr[i] != find)) {
		i++;
		iter = iter + 2;
	}
	if (i != size) {
		cout << "Index of the element what you was found: " << i << endl;
	}
	else {
		cout << "Element was not found" << endl;
	}
	cout << endl;

	//Упражнение 2

	cout << "Task 2" << endl;

	int *arr1 = new int[size+1];
	for (int i = 0; i < size; i++) {
		arr1[i] = arr[i];
	}
	arr1[size] = find;

	int iter1 = 0;
	i = 0;
	while (arr1[i] != find) {
		i++;
		iter1++;
	}

	if (i != size) {
		cout << "Index of the element what you was found: " << i << endl;
	}
	else {
		cout << "Element was not found"<< endl;
	}
	cout << endl;
	
	//Упражнение 3

	cout << "Task 3" << endl;

	if (iter1 < iter) {
		cout << "Barrier search is better then brute force search" << endl;
		cout << "because it have less iterations: " << iter1 << " < " << iter << endl;
	}
	else {
		cout << "Barrier search and brute force search equally complex" << endl;
		cout << "because iterations are the same: " << iter1 << " = " << iter << endl;
	}
	cout << endl;

	//Упражнение 4

	cout << "Task 4" << endl;
	
	for (int i = 0; i < size; i++) {
		cout << "Arr[" << i << "] = " << arr[i] << endl;
	}

	int iter2 = 0;
	int L = 0;
	int R = size - 1;
	int Found = 0;
	int m;
	while ((L <= R) && (Found == 0)) {
		m = (L + R) / 2;
		if (arr[m] == find) {
			Found = 1;
			iter2++;
			cout << "Index of the element what you was found: " << m << endl;
		}
		else if (arr[m] < find) {
			L = m + 1;
			iter2++;
		}
		else {
			R = m - 1;
			iter2++;
		}
	}//Log2(n)
	cout << endl;                   

	//Упражнение 5
	
	cout << "Task 5" << endl;
	L = 0;
	R = size - 1;
	Found = 0;
	m = 1;
	const double Phi = (1 + sqrt(5)) / 2;
	while ((L <= R) && (Found == 0)) {
		m = ((R - L) / Phi)+L;
		if (m < size) {
			if (arr[m] == find) {
				Found = 1;
				cout << "Index of the element what you was found: " << m << endl;
			}
			else if (arr[m] < find) {
				L = m + 1;
			}
			else {
				R = m - 1;
			}
		}
		else {
			Found = 1;
			cout << "Impossible to find m using the golden section" << endl;
		}
	} 
	cout << endl;
	system("pause");

}