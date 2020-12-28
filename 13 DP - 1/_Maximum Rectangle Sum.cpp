/*
Maximum Sum Rectangle

Given a 2D array, find the maximum sum rectangle in it. In other words find maximum sum over all rectangles in the matrix.

Input
First line contains 2 numbers n and m denoting number of rows and number of columns. Next n lines contain m space separated integers denoting elements of matrix nxm.

Output
Output a single integer, maximum sum rectangle.
Constraints
1<=n,m<=100
Sample Input
4 5
1 2 -1 -4 -20
-8 -3 4 2 1
3 8 10 1 3
-4 -1 1 7 -6
Sample Output
29
*/

#include <bits/stdc++.h>
using namespace std;

long long int Ksum(long long int* arr, int size){
    long long int max_so_far = INT_MIN, max_ending_here = 0;
    
    for(int i = 0; i < size; i++){
        max_ending_here += arr[i];
        if(max_so_far < max_ending_here){
            max_so_far = max_ending_here;
        }
        if(max_ending_here < 0)
            max_ending_here = 0;
    }
    
    return max_so_far;
}

int main(){
    int m,n;
    cin >> m >> n;
    
	long long int **grid = new long long int*[m];
    for(int i = 0; i < m; i++)
        grid[i] = new long long int[n];
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    

    
    // this is for prefix sum , as updating the sums takes time rather just subtract 
    for(int i = 0; i < m; i++){
        for(int j = 1; j < n; j++){
            grid[i][j] = grid[i][j-1] + grid[i][j];
        }
    }
    
//         for(int i = 0; i < m; i++){
//         for(int j = 0; j < n; j++){
//             cout << grid[i][j] << " ";
//         }
//         cout << endl;
//     }
    
//     cout << endl;
    
    long long int ans = INT_MIN;
    
    for(int l = 0; l < n; l++){
        for(int r = l; r < n; r++){
            long long int *arr = new long long int[m];
            for(int i = 0; i < m; i++){
                if(l == 0)
                	arr[i] = grid[i][r];
                else
                    arr[i] = grid[i][r] - grid[i][l - 1];
            }
            long long int possibleAns = Ksum(arr,m);
            if(possibleAns > ans)
                ans = possibleAns;
            delete [] arr;
        }
    }
   	
    cout << ans << endl;
    
    for(int i = 0; i < m; i++)
        delete [] grid[i];
    delete [] grid;
    return 0;
}