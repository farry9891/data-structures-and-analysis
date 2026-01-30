//Q1 Binary search for 23, arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91} 
#include <iostream>
using namespace std;

int main() {
    int nums[]= {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int len= sizeof(nums) / sizeof(nums[0]);
    int key= 23;

    int left= 0, right= len - 1;
    int index= -1;

    while (left <= right) {
        int center= left + (right - left) / 2;

        if (nums[center] == key) {
            index= center;
            break;
        } else if (nums[center] < key) {
            left= center + 1;
        } else {
            right= center - 1;
        }
    }

    cout << index << endl;
    return 0;
}

//Output= 5

//____________________________________________________________________________________________________//

//Q2 Merge Sort, arr[] = {12, 11, 13, 5, 6, 7}, arr2[] = {38, 27, 43, 3, 9, 82, 10}

#include <iostream>
using namespace std;

void combine(int data[], int low, int mid, int high) {
    int sizeA= mid - low + 1;
    int sizeB= high - mid;

    int first[sizeA], second[sizeB];

    for (int i= 0; i < sizeA; i++) first[i] = data[low + i];
    for (int j= 0; j < sizeB; j++) second[j] = data[mid + 1 + j];

    int i = 0, j = 0, k = low;

    while (i < sizeA && j < sizeB) {
        if (first[i] <= second[j]) {
            data[k++] = first[i++];
        } else {
            data[k++]= second[j++];
        }
    }

    while (i < sizeA) data[k++] = first[i++];
    while (j < sizeB) data[k++] = second[j++];
}

void mergeAlgo(int data[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeAlgo(data, low, mid);
        mergeAlgo(data, mid + 1, high);
        combine(data, low, mid, high);
    }
}

void show(int data[], int size) {
    for (int i= 0; i < size; i++) cout << data[i] << " ";
    cout << endl;
}

int main() {
    int list1[]= {12, 11, 13, 5, 6, 7};
    int n1 = sizeof(list1) / sizeof(list1[0]);
    mergeAlgo(list1, 0, n1 - 1);
    show(list1, n1);

    int list2[] = {38, 27, 43, 3, 9, 82, 10};
    int n2 = sizeof(list2) / sizeof(list2[0]);
    mergeAlgo(list2, 0, n2 - 1);
    show(list2, n2);

    return 0;
}


//Output= 5 6 7 11 12 13, 3 9 10 27 38 43 82 

//____________________________________________________________________________________________________//

//Q3 Quick Sort, arr[n] = { 4, 2, 6, 9, 2 }

#include <iostream>
using namespace std;

void swapVals(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

int divide(int arr[], int low, int high) {
    int pivotVal = arr[high];
    int idx = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivotVal) {
            idx++;
            swapVals(arr[idx], arr[j]);
        }
    }

    swapVals(arr[idx + 1], arr[high]);
    return idx + 1;
}

void quickAlgo(int arr[], int low, int high) {
    if (low < high) {
        int p = divide(arr, low, high);
        quickAlgo(arr, low, p - 1);
        quickAlgo(arr, p + 1, high);
    }
}

int main() {
    int values[] = {4, 2, 6, 9, 2};
    int n = sizeof(values) / sizeof(values[0]);

    quickAlgo(values, 0, n - 1);

    for (int i = 0; i < n; i++) cout << values[i] << " ";
    cout << endl;

    return 0;
}


//Output= 2 2 4 6 9 

//____________________________________________________________________________________________________//

//Q4 Maximum Subarray Sum
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int midSum(int arr[], int low, int mid, int high) {
    int total = 0;
    int leftMax = INT_MIN;

    for (int i = mid; i >= low; i--) {
        total += arr[i];
        leftMax = max(leftMax, total);
    }

    total = 0;
    int rightMax = INT_MIN;

    for (int i = mid + 1; i <= high; i++) {
        total += arr[i];
        rightMax = max(rightMax, total);
    }

    return leftMax + rightMax;
}

int maxSegment(int arr[], int low, int high) {
    if (low == high) return arr[low];

    int mid = low + (high - low) / 2;

    int leftAns = maxSegment(arr, low, mid);
    int rightAns = maxSegment(arr, mid + 1, high);
    int crossAns = midSum(arr, low, mid, high);

    return max({leftAns, rightAns, crossAns});
}

int main() {
    int nums[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int n = sizeof(nums) / sizeof(nums[0]);

    cout << maxSegment(nums, 0, n - 1) << endl;
    return 0;
}

//Output= 7
