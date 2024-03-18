# -------------------------- TASK 3 -----------------------------------------------------


#include <iostream>
#include <vector>
using namespace std;


int main()
{
	// Task 3
	// Insert the number x before the smallest element of array

	int size;

	cout << "How many elements in your array?: ";
	cin >> size;

	vector<int> v(size);

	cout << "Input your array: ";
	for (int i = 0; i < size; i++)
		cin >> v[i];

	int small = v[0];
	int sum = 0;

	// finding smallest element
	for (int i = 1; i < size; i++) {

		if (v[i] < small) {
			small = v[i];
		}
	}


	cout << "\nThe smallest element is: " << small << endl;
	cout << "Here is the updated array: " << endl;

	int index;
	// put "x" before smallst number in array
	for (int i = 0; i < size; i++) {
		if (v[i] == small)
			index = i;
	}

	if (index == 0) {
		cout << "x" << " ";
		for (int i = 0; i < size; i++) {
			cout << v[i] << " ";
		}
	}

	else {

		for (int i = 0; i < size; i++) {
			if (i < index) {
				cout << v[i] << " ";
			}

			if (i == index) {
				cout << "x" << " ";
				cout << v[i] << " ";
			}

			if (i > index) {
				cout << v[i] << " ";
			}
		}
	}
}
