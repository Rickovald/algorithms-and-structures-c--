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
    return -1;
}


int binarySearch(int array[], int length, int item)
{
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
int recursiveBinarySearch(int array[], int length, int start, int end, int item)
{
    if (recursiveCount1 == length) {
        return -1;
    }
    int middle = (start + length) / 2;
    recursiveCount1++;

    if (item == array[middle]) {
        cout << "Number of steps using recursive binary: " << recursiveCount1 << endl;
        return middle;
    }
    if (item < array[middle]) {
        return recursiveBinarySearch(array, item, start, middle - 1, item);
    } else {
        return recursiveBinarySearch(array, item, middle + 1, end, item);
    }
}


int selectionSort(int array[], int length)
{
    int count = 0;
    for (int i = 0; i < length; i++) {
        int indexMin = i;
        for (int j = i + 1; j < length; j++)
        {
            count++;
            if (array[j] < array[indexMin])
            {
                indexMin = j;
            }
        }
        int temp = array[i];
        array[i] = array[indexMin];
        array[indexMin] = temp;
    }
    return 0;
}


int bubbleSort(int array[], int length)
{
    int count = 0;
    for (int i = 0; i < length; i++) {
        int indexMin = i;
        for (int j = 0; j < length; j++)
        {
            count++;
            if (array[j + 1] < array[j])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    return 0;
}

int hoareSort (int *array, int first, int last)
{
    int length = sizeof(array)/sizeof(array[0]);
    if (length <= 1) {
        return 0;
    }

    int pivotIndex = (first + last) / 2;
    int pivot = array[pivotIndex];
    int f = first, l = last;
    do 
    {
        
        while (array[f] < pivot) f++;
        while (array[l] > pivot) l--;
        if (f <= l)
        {
            int temp = array[f];
            array[f] = array[l];
            array[l] = temp;
            f++;
            l--;

        }
    } while (f < l);
    
    if (first<l) hoareSort(array, first, l);
    if (f<last) hoareSort(array, f, last);

    return 0;
}


int main()
{
    int item;
    cout << "Input number to find in array: ";
    cin >> item;
    cout << endl;

    int sortedNumbers[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
    int sortedNumbersSize = sizeof(sortedNumbers)/sizeof(sortedNumbers[0]);

    int linear = linear_search(sortedNumbers, sortedNumbersSize, item);
    int binary = binarySearch(sortedNumbers, sortedNumbersSize, item);
    int recursiveBinary = recursiveBinarySearch(sortedNumbers, sortedNumbersSize, 0, sortedNumbersSize, item);
    cout << "Index of your number is " << binary << endl;


    int unsortedNumbers1[] = { 0,3,2,5,6,8,1,9,4,2,1,2,9,6,4,1,7,-1, -5, 23,6,2,35,6,3,32 };
    int unsortedNumbersSize1 = sizeof(unsortedNumbers1)/sizeof(unsortedNumbers1[0]);
    selectionSort(unsortedNumbers1, unsortedNumbersSize1);
    cout << "Sorted array ..." << endl;
	for(int i = 0; i < unsortedNumbersSize1; i++) cout << unsortedNumbers1[i] << ' ';
    cout << endl;

    int unsortedNumbers2[] = { 0,3,2,5,6,8,23,9,4,2,1,2,9,6,4,1,7,-1, -5, 23,6,2,35,6,3,32,9,4,2,1,2,9,6,4,1,7,-1, -5, 23,9,4,2,1,2,9,6,4,1,7,-1, -5, 23, };
    int unsortedNumbersSize2 = sizeof(unsortedNumbers2)/sizeof(unsortedNumbers2[0]);
    bubbleSort(unsortedNumbers2, unsortedNumbersSize2);
    cout << "Sorted array ..." << endl;
	for(int i = 0; i < unsortedNumbersSize2; i++) cout << unsortedNumbers2[i] << ' ';
    cout << endl;


    int unsortedNumbers3[] = { 0,3,2,5,6,8,23,9,4,2,1,2,9,6,4,1,7,-1, -5, 23,6,2,35,6,3,32,9,4,2,1,2,9,6,4,1,7,-1, -5, 23,9,4,2,1,2,9,6,4,1,7,-1, -5, 23, };
    int unsortedNumbersSize3 = sizeof(unsortedNumbers3)/sizeof(unsortedNumbers3[0]);
    hoareSort(unsortedNumbers3, 0, unsortedNumbersSize3 - 1);
    cout << "Sorted array ..." << endl;
	for(int i = 0; i < unsortedNumbersSize3; i++) cout << unsortedNumbers3[i] << ' ';
    cout << endl;

    return 0;
}
