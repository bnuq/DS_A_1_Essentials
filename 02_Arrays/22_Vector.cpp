#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> arr1 = { 1,2,3 };
	vector<int> arr2{ 4,5,6 };

	// Fill Constructor
	vector<int> arr3(5, 1);

	arr3.pop_back();
	arr3.push_back(10);
	arr3.emplace_back(20);
	arr3.emplace(arr3.end(), 30);

	cout << "Size is " << arr3.size() << endl;
	cout << "Capacity is " << arr3.capacity() << endl;

	for (auto x : arr3)
		cout << x << " ";
	cout << endl;

	return 0;

}