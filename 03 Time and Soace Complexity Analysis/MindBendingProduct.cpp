/*
Problem:
Given an array, the element at must be replced by the product of all the other elements in the array.
Catch :
1) Do not use division operator.
2) Do it in constant space.

Input:
First line is T testcases.
Second line is the size of the array N.
Third line has N elements of the array.

Output:
A single line with all the corresponding products.

Sample Input:
1
5
10 3 5 6 2

Sample Output:
180 600 360 300 900

Sample Input:
1
2
12 20

Sample Output:
20 12

*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void MindBendingProduct(int* arr,ll* product,int n){
    product[0] = 1;
    for(int i = 1; i < n; i++){
        product[i] = product[i-1] * arr[i-1];
    }

    ll leftProduct = 1;
    for(int i = n-1; i >= 0; i--){
        product[i] *= leftProduct;
        leftProduct *= arr[i];  
    }
    return;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        
        ll product[n];
        
        MindBendingProduct(arr,product,n);

        for(int i = 0; i < n; i++)
            cout << product[i] << " ";
        
        cout << "\n";
    }
}