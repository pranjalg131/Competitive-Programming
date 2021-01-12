/*
Min. Absolute Difference In Array

Given an integer array A of size N, find and return the minimum absolute
difference between any two elements in the array. We define the absolute
difference between two elements ai, and aj (where i != j ) is |ai - aj|.

Input format :
Line 1 : Integer N, Array Size
Line 2 : Array elements (separated by space)

Output Format :
Minimum difference

Constraints :
1 <= N <= 10^6

Sample Input :
5
2 9 0 4 5

Sample Output :
1
*/

#include <bits/stdc++.h>
using namespace std;

int minAbsoluteDiff(int* arr, int n) {
    sort(arr, arr + n);
    if (n == 1) {
        return arr[0];
    } else {
        int i = 0;
        int j = 1;
        int ans = INT_MAX;
        for (; j < n; i++, j++) {
            if (abs(arr[j] - arr[i]) < ans) {
                ans = abs(arr[j] - arr[i]);
            }
        }

        return ans;
    }
}

int main() {
    int size;
    cin >> size;
    int* input = new int[1 + size];

    for (int i = 0; i < size; i++) cin >> input[i];

    cout << minAbsoluteDiff(input, size) << endl;

    return 0;
}
