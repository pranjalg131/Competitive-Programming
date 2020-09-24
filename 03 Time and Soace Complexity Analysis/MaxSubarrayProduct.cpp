/*
Problem:
Given an array, find the sub - array wuth the maximum product. ie continuous elements.
Note : The array does not contain zeroes as elements.

Input:
First line is T testcases.
Second line is the size of the array N.
Third line has N elements of the array.

Output:
A single line with the maximum sub - array product.

Sample Input:
1
5
6 -3 -10 0 2

Sample Output:
180

Sample Input:
1
6
2 3 4 5 -1 0

Sample Output:
120

*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll maxSubarrayProduct(int* arr, int n){
    ll curr_minHere = 1;
    ll curr_maxHere = 1;
    ll curr_best = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] > 0){
            curr_maxHere *= arr[i];
            curr_minHere = min((ll)1,curr_minHere*arr[i]); 
        }
        else if(arr[i] < 0){
            ll temp = curr_maxHere;
            curr_maxHere = max((ll)1,curr_minHere*arr[i]);
            curr_minHere = temp*arr[i];
        }
        else{
            curr_maxHere = 1;
            curr_minHere = 0;
        }
        curr_best = max(curr_maxHere,curr_best);
    }
    return curr_best;
}

int main(){

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        ll ans = maxSubarrayProduct(arr,n);

        cout << ans << "\n";
    }

    return 0;
}