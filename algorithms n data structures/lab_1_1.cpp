
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	// Task 1:
	// sum of negative elements and product of elements btwn largest and smallest
	int size;
  int negative_sum = 0;

	cout << "How many elements in your array?: ";
	cin >> size;

	vector<int> v(size);

	cout << "Input your array: ";
	for (int i = 0; i < size; i++)
		cin >> v[i];

	int small = v[0];
	int big = v[0];
	int sum = 0;

	// negative elements sum
	for (int j = 0; j < size; j++)
		if (v[j] < 0)
			negative_sum += v[j];

		for (int i = 1; i < size; i++) {
			if (v[i] < small) {
				small = v[i];
			}

			if (v[i] > big) {
				big = v[i];
			}
		}

		for (int k = 0; k < size; k++)
			sum += v[k];

	
		sum = (sum - (big + small));


		cout << "The sum of negative elements is: " << negative_sum << endl;
		cout << "The smallest element is: " << small << endl;
		cout << "The biggest elements is: " << big << endl;
		cout << "The sum between biggest and smallest numbers = " << sum << endl;

}
