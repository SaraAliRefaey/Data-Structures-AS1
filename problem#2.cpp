#include <iostream>
using namespace std;

int BinarySearchRotated(int arr[], int l, int h, int element) {
    int comparisons = 0;

    while (l <= h) {

        int m = l + (h - l) / 2;

        comparisons++;

        if (arr[m] == element)
            {

            cout << "Total comparisons : " << comparisons << endl;
            return m;

            }

        if (arr[l] == arr[m] && arr[h] == arr[m]) {
            l++;
            h--;
            continue;
        }


        if (arr[l] <= arr[m])
            {

            comparisons++;

            if (element >= arr[l] && element < arr[m])
                {
                h = m - 1;
                } else
                {
                l = m + 1;
                }

          }else

          {

            comparisons++;
            if (element > arr[m] && element <= arr[h])
            {
                l = m + 1;

            }else
            {
                h = m - 1;
            }
        }
    }

    cout << "Total comparisons : " << comparisons << endl;
    return -1;
}

int main() {


    int arr1[] = { 5, 6, 7, 1, 2, 3, 4 };
    int arr2[] = { 2, 2, 2, 0, 2, 2 };

    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    cout << "Case 1: Rotated Sorted Array : " << endl;

    int target1 = 1;
    int result1 = BinarySearchRotated(arr1, 0, n1 - 1, target1);
    if (result1 != -1) cout << "Target (" << target1 << ") found at index: " << result1 << endl;
    else cout << "Target not found!" << endl;

    cout<<"========================================================================================="<<endl;

    cout << "Case 2: Array with Duplicates : " << endl;

    int target2 = 0;
    int result2 = BinarySearchRotated(arr2, 0, n2 - 1, target2);
    if (result2 != -1) cout << "Target (" << target2 << ") found at index: " << result2 << endl;
    else cout << "Target not found!" << endl;

    return 0;
}
