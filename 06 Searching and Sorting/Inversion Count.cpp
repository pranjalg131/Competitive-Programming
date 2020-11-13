/*
Inversion Count

For a given integer array/list of size N, find the total number of 'Inversions' that may exist.
An inversion is defined for a pair of integers in the array/list when the following two conditions are met.
A pair (arr[i], arr[j]) is said to be an inversion when,
1. arr[i] > arr[j] 
2. i < j

Where 'arr' is the input array/list, 'i' and 'j' denote the indices ranging from [0, N).
Input format :
The first line of input contains an integer N, denoting the size of the array.

The second line of input contains N integers separated by a single space, denoting the elements of the array.
Output format :
The only line of output prints the total count of inversions in the array.
Note:
You are not required to print anything. Return the total number of inversion count.
Constraints :
1 <= N <= 10^5 
1 <= arr[i] <= 10^9

Time Limit: 1sec

Sample Input 1 :
3
3 2 1
Sample Output 1 :
3
Explanation of Sample Input 1:
We have a total of three pairs which satisfy the condition of inversion. (3, 2), (2, 1) and (3, 1).

Sample Input 2 :
5
2 5 1 3 4
Sample Output 2 :
4
*/

#include <bits/stdc++.h>
using namespace std;

long long merge(long long *arr, int start , int mid , int end){
    int i = start,j = mid,k = 0;

    long long count = 0;
    long long temp[end - start + 1];

    while(i < mid && j <= end){
        if(arr[i] < arr[j]){
            temp[k++] = arr[i++];
        }else{
            temp[k++] = arr[j++];
            count += mid - i;
        }
    }

    while(i < mid)
        temp[k++] = arr[i++];

    while(j <= end)
        temp[k++] = arr[j++];
// Now the temp is sorted so since we need the final array to be sorted we again copy this into our orignal array.

    for (int i = start, k = 0; i <= end; i++,k++)
    {
        arr[i] = temp[k];
    }

    return count;
}

long long helper(long long *arr, int start, int end){
    long long count = 0;
    if(end > start){
        int mid = (start + end)/2;
        long long count1 = helper(arr,start,mid);
        long long count2 = helper(arr,mid+1,end);
        long long myCount = merge(arr,start,mid+1,end);

        return count1 + count2 + myCount;
    }

    return count;
}

long long getInversions(long long *arr, int n){
    return helper(arr,0,n-1);

}

int main(){
    int n;
    cin >> n;

    long long* arr = new long long[n];

    for(int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << getInversions(arr, n);

    delete arr;
}