//Q1 Binary search for 23, arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91} 
#include <iostream>
using namespace std;

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 23;   
    int st = 0;
    int en = n - 1;
    int ans = -1;

    while (st <= en) {
        int mid = st + (en - st) / 2;

        if (arr[mid] == target) {
            ans = mid;
            break;
}
        
        if (arr[mid] < target) {
            st = mid + 1;
        } 
        else {
            en = mid - 1;
        }}

    if (ans != -1) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
//Output= 5

//____________________________________________________________________________________________________//

//Q2 Merge Sort, arr[] = {12, 11, 13, 5, 6, 7}, arr2[] = {38, 27, 43, 3, 9, 82, 10}

#include <iostream>
using namespace std;
void merge(int arr[], int st, int mid, int en) {
    int n1 = mid - st + 1;
    int n2 = en - mid;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[st + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = st;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;} 
        else {
            arr[k] = R[j];
            j++;}
        k++;}
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;}
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;}
}
void mergeSort(int arr[], int st, int en) {
    if (st < en) {
        int mid = st + (en - st) / 2;
        mergeSort(arr, st, mid);
        mergeSort(arr, mid + 1, en);
        merge(arr, st, mid, en); }
}
void display(int arr[], int size) {
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;}
int main() {
    int arr1[] = {12, 11, 13, 5, 6, 7};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    mergeSort(arr1, 0, n1 - 1);
    display(arr1, n1);
    int arr2[] = {38, 27, 43, 3, 9, 82, 10};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    mergeSort(arr2, 0, n2 - 1);
    display(arr2, n2);

    return 0;
}

//Output= 5 6 7 11 12 13, 3 9 10 27 38 43 82 

//____________________________________________________________________________________________________//

//Q3 Quick Sort, arr[n] = { 4, 2, 6, 9, 2 }

#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;}

int partition(int arr[], int st, int en) {
    int pivot = arr[en];
    int i = st - 1;

    for (int j = st; j < en; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }}
    swap(arr[i + 1], arr[en]);
    return i + 1;
}
void quickSort(int arr[], int st, int en) {
    if (st < en) {
        int pidx = partition(arr, st, en);
        quickSort(arr, st, pidx - 1);
        quickSort(arr, pidx + 1, en); }}

int main() {
    int arr[] = {4, 2, 6, 9, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";}
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

int crossSum(int arr[], int st, int mid, int en) {
    int sum = 0;
    int left_sum = INT_MIN;
    for (int i = mid; i >= st; i--) {
        sum += arr[i];
        if (sum > left_sum) left_sum = sum;
    }

    sum = 0;
    int right_sum = INT_MIN;
    for (int i = mid + 1; i <= en; i++) {
        sum += arr[i];
        if (sum > right_sum) right_sum = sum;}
    return left_sum + right_sum;
}

int maxSub(int arr[], int st, int en) {
    if (st == en) return arr[st];
    int mid = st + (en - st) / 2;

    int left_max = maxSub(arr, st, mid);
    int right_max = maxSub(arr, mid + 1, en);
    int mid_max = crossSum(arr, st, mid, en);
    return max({left_max, right_max, mid_max});
}

int main() {
    int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxSub(arr, 0, n - 1) << endl;
    return 0;
}
//Output= 7