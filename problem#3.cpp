#include<iostream>
#include<algorithm>
using namespace std;

class bitonicArray {
private:
    int comparisons = 0, swaps = 0;

public:
    void bitonicSort(int arr[], int size) {
        comparisons = 0;
        swaps = 0;
        int lHalf = size / 2;

        //  Bubble Sort
        for (int i = 0; i < lHalf - 1; i++) {
            for (int j = 0; j < lHalf - i - 1; j++) {
                comparisons++;
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    swaps++;
                }
            }
        }

        //  Selection Sort
        for (int i = lHalf; i < size - 1; i++) {
            int maxIdx = i;
            for (int j = i + 1; j < size; j++) {
                comparisons++;
                if (arr[j] > arr[maxIdx]) {
                    maxIdx = j;
                }
            }
            if (maxIdx != i) {
                swap(arr[i], arr[maxIdx]);
                swaps++;
            }
        }


        cout << "Sorted Bitonic Array: ";
        for (int i = 0; i < size; i++)
            {
            cout << arr[i] << " ";
        }

        cout << "\nComparisons: " << comparisons << " , Swaps: " << swaps << endl;


        int bPoint = arr[0];
        int bIdx = 0;
        for (int i = 1; i < size; i++) {
            if (arr[i] > bPoint) {
                bPoint = arr[i];
                bIdx = i;
            }
        }
        cout << "BITONIC POINT: " << bPoint << " at index: " << bIdx << endl;
    }

    bool bitonicFind(int arr[], int size, int target) {
        bitonicSort(arr, size);

        // Linear Search

        for (int i = 0; i < size; i++) {
            if (arr[i] == target) {
                cout << "Target: " << target << " found at index " << i << endl;
                return true;
            }
        }
        cout << "Target " << target << " NOT found" << endl;
        return false;
    }
};

int main() {


    // 1. Target at the bitonic point.
    cout << "=============CASE 1=============" << endl;
    int arr1[7] = {1, 3, 2, 9, 5, 6, 4};
    bitonicArray b1;
    b1.bitonicFind(arr1, 7, 9);


    // 2. Target in the left half (ascending portion).
    cout << "\n=============CASE 2=============" << endl;

    int arr2[6] = {6, 5, 9, 4, 7, 2};
    bitonicArray b2;
    b2.bitonicFind(arr2, 6, 5);


    // 3. Target in the right half (descending portion).
    cout << "\n=============CASE 3=============" << endl;

    int arr3[6] = {10, 40, 30, 70, 100, 1};
    bitonicArray b3;
    b3.bitonicFind(arr3, 6, 1);


    // 4. Target not present in the array
    cout << "\n=============CASE 4=============" << endl;

    int arr4[3] = {2, 5, 6};
    bitonicArray b4;
    b4.bitonicFind(arr4, 3, 4);



    // 5. Array with duplicate elements
    cout << "\n=============CASE 5=============" << endl;

    int arr5[7] = {3, 3, 2, 5, 5, 1, 0};
    bitonicArray b5;
    b5.bitonicFind(arr5, 7, 3);

    cout << endl;
    return 0;
}
