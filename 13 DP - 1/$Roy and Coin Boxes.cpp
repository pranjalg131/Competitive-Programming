/*
Roy and Coin Boxes

Roy has N coin boxes numbered from 1 to N.
Every day he selects two indices [L,R] and adds 1 coin to each coin box starting from L to R (both inclusive).
He does this for M number of days.

After M days, Roy has a query: How many coin boxes have atleast X coins.
He has Q such queries.

Input
First line contains N - number of coin boxes.
Second line contains M - number of days. Each of the next M lines consists of two space separated integers L and R. Followed by integer Q - number of queries.
Each of next Q lines contain a single integer X.a

Output
For each query output the result in a new line.

Constraints
1 <= N <= 1000000
1 <= M <= 1000000
1 <= L <= R <= N
1 <= Q <= 1000000
1 <= X <= N

Sample Input
7
4
1 3
2 5
1 2
5 6
4
1
7
4
2
Sample Output
6
0
0
4
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

int n;
cin >> n;

vector<int> startIndex(n + 1,0);
vector<int> endIndex(n + 1,0);
int m;
cin >> m;
while (m--){
  int l, r;
  cin >> l >> r;
  startIndex[l]++;
  endIndex[r]++;
}

vector<int> noOfCoinsPerBox(n + 1,0);
noOfCoinsPerBox[1] = startIndex[1];

for (int i = 2; i < noOfCoinsPerBox.size(); i++){
  noOfCoinsPerBox[i] = startIndex[i] - endIndex[i - 1] + noOfCoinsPerBox[i - 1];
}

vector<int> noOfBoxesByCoins(n + 1, 0);

for(int i = 1; i < noOfCoinsPerBox.size(); i++){
  noOfBoxesByCoins[noOfCoinsPerBox[i]]++;
}

vector<ll int> answers(n + 1,0);

answers[n] = noOfBoxesByCoins[n];
for(int i = answers.size() - 2; i >= 0; i--){
  answers[i] = answers[i + 1] + noOfBoxesByCoins[i]; 
}
answers[0] = n;

int q;
cin >> q;
while (q--){
  int x;
  cin >> x;
  cout << answers[x] << "\n";
}

return 0;
}