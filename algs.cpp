#include <iostream>
using namespace std;

int linear_search(int array[], int length, int item) 
{
    int count = 0;

    for (int i = 0; i < length; i++) {
        count++;
        if (array[i] == item) {
            cout << "Number of steps using linear: " << count << endl;
            return i;
        }
    }
    return 0;
}


int binarySearch(int array[], int length, int item) {
    int count = 0;
    int start = 0;
    int middle;;
    int found = false;
    int position = -1;
    
    while (found == false && start <= length) {
        count++;
        middle = (start + length) / 2;
        if (array[middle] == item) {
            found = true;
            position = middle;
            cout << "Number of steps using binary: " << count << endl;
            return position;
        }
        if (item < array[middle]) {
            length = middle - 1;
        } else {
            start = middle + 1;
        }
    }
    
    return position;
}

int recursiveCount1 = 0;
int recursiveBinarySearch(int array[], int length, int start, int end, int item) {
    

    int middle = (start + length) / 2;
    recursiveCount1++;

    if (item == array[middle]) {
        cout << "Number of steps using recursive binary: " << recursiveCount1 << endl;
        return middle;
    }
    if (item < array[middle]) {
        return recursiveBinarySearch(array, item, 0, middle - 1, item);
    } else {
        return recursiveBinarySearch(array, item, middle + 1, end, item);
    }
}



int main()
{
    int item;
    cout << "Input number to find in array: ";
    cin >> item;
    cout << endl;

    int sortedNumbers[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
    int unsortedNumbers[] = { 0,3,2,5,6,8,1,9,4,2,1,2,9,6,4,1,7,-1, -5, 23,6,2,35,6,3,32 };
    int sortedNumbersSize = sizeof(sortedNumbers)/sizeof(sortedNumbers[0]);
    int unsortedNumbersSize = sizeof(unsortedNumbers)/sizeof(unsortedNumbers[0]);

    int linear = linear_search(sortedNumbers, sortedNumbersSize, item);
    int binary = binarySearch(sortedNumbers, sortedNumbersSize, item);
    int recursiveBinary = recursiveBinarySearch(sortedNumbers, sortedNumbersSize, 0, sortedNumbersSize, item);
    cout << "Index of your number is " << binary << endl;

    return 0;
}
