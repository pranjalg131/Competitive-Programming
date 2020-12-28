/*
Magic Grid Problem

You are given a magic grid A with R rows and C columns. In the cells of the grid, you will either get magic juice, which increases your strength by |A[i][j]| points, or poison, which takes away |A[i][j]| strength points. If at any point of the journey, the strength points become less than or equal to zero, then you will die.
You have to start from the top-left corner cell (1,1) and reach at the bottom-right corner cell (R,C). From a cell (i,j), you can only move either one cell down or right i.e., to cell (i+1,j) or cell (i,j+1) and you can not move outside the magic grid. You have to find the minimum number of strength points with which you will be able to reach the destination cell.

Input format:
The first line contains the number of test cases T. T cases follow. Each test case consists of R C in the first line followed by the description of the grid in R lines, each containing C integers. Rows are numbered 1 to R from top to bottom and columns are numbered 1 to C from left to right. Cells with A[i][j] < 0 contain poison, others contain magic juice.

Output format:
Output T lines, one for each case containing the minimum strength you should start with from the cell (1,1) to have a positive strength through out his journey to the cell (R,C).

Constraints:
1 ≤ T ≤ 5
2 ≤ R, C ≤ 500
-10^3 ≤ A[i][j] ≤ 10^3
A[1][1] = A[R][C] = 0

Time Limit: 1 second

Sample Input 1:
3
2 3
0 1 -3
1 -2 0
2 2
0 1
2 0
3 4
0 -2 -3 1
-1 4 0 -2
1 -2 -3 0
Sample Output 1:
2
1
2
*/

#include <iostream>
using namespace std;

int getMinimumStrength(int** grid, int n, int m) {
	int **output = new int*[n + 1];
    for(int i = 0; i <= n; i++){
        output[i] = new int[m + 1];
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            output[i][j] = 0;
        }
    }
    
    for(int i = n - 2 ; i >= 0; i--){
        if(output[i + 1][m - 1] == 0){
            output[i][m - 1] = -grid[i][m - 1] + 1;
        }else
        	output[i][m - 1] = output[i + 1][m - 1] - grid[i][m - 1];
    }
    
    for(int j = m - 2 ; j >= 0; j--){
        if(output[n - 1][j + 1] == 0){
            output[n - 1][j] = -grid[n - 1][j] + 1;
        }else
        	output[n - 1][j] = output[n - 1][j + 1] - grid[n - 1][j];
    }
    
    for(int i = n - 2; i >= 0; i--){
        for(int j = m - 2; j >= 0; j--){
            if((min(output[i][j + 1] , output[i + 1][j]) - grid[i][j]) <= 0){
                output[i][j] = 1;
            }else if(min(output[i][j + 1] , output[i + 1][j]) == 0) {
                output[i][j] = -grid[i][j] + 1;
            }else
                output[i][j] = min(output[i][j + 1] , output[i + 1][j]) - grid[i][j];
        }
    }
    
    int ans = output[0][0];
    
    
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout << output[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    for(int i = 0; i <= n; i++)
        delete [] output[i];
    
    delete [] output;
    
    return ans;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        int **grid = new int *[n];

        for (int i = 0; i < n; ++i) {
            grid[i] = new int[m];
            for (int j = 0; j < m; ++j) {
                cin >> grid[i][j];
            }
        }

        cout << getMinimumStrength(grid, n, m) << "\n";

        for (int i = 0; i < n; ++i) {
            delete[] grid[i];
        }

        delete[] grid;
    }
}