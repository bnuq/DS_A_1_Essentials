#include <vector>
#include <iostream>
using namespace std;

int largestElement(vector<int> arr) {
    int largest{ arr[0] };

    for (size_t i = 1; i < arr.size(); i++)
        largest = (arr[i] > largest) ? arr[i] : largest;

    return largest;

}