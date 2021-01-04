/*
Jon Snow and his favourite number

Jon Snow now has to fight with White Walkers. He has n rangers, each of which has his own strength. Also Jon Snow has his favourite number x. Each ranger can fight with a white walker only if the strength of the white walker equals his strength. He however thinks that his rangers are weak and need to improve. Jon now thinks that if he takes the bitwise XOR of strengths of some of rangers with his favourite number x, he might get soldiers of high strength. So, he decided to do the following operation k times:
Arrange all the rangers in a straight line in the order of increasing strengths.
Take the bitwise XOR of the strength of each alternate ranger with x and update it's strength.
Suppose, Jon has 5 rangers with strengths [9, 7, 11, 15, 5] and he performs the operation 1 time with x = 2. He first arranges them in the order of their strengths, [5, 7, 9, 11, 15]. Then he does the following:
The strength of first ranger is updated to 5 xor 2, i.e. 7.
The strength of second ranger remains the same, i.e. 7.
The strength of third ranger is updated to 9 xor 2, i.e. 11.
The strength of fourth ranger remains the same, i.e. 11.
The strength of fifth ranger is updated to 15 xor 2, i.e. 13.
The new strengths of the 5 rangers are [7, 7, 11, 11, 13]
Now, Jon wants to know the maximum and minimum strength of the rangers after performing the above operations k times. He wants your help for this task. Can you help him?
Input
First line consists of three integers n, k, x (1 ≤ n ≤ 10^5, 0 ≤ k ≤ 10^5, 0 ≤ x ≤ 10^3) — number of rangers Jon has, the number of times Jon will carry out the operation and Jon's favourite number respectively.

Second line consists of n integers representing the strengths of the rangers a1, a2, ..., an (0 ≤ ai ≤ 10^3).

Output
Output two integers, the maximum and the minimum strength of the rangers after performing the operation k times.
Sample Input
5 1 2
9 7 11 15 5
Sample Output
13 7
*/

#include<bits/stdc++.h>
#define rep(i,start,lim) for(int i=start;i<lim;i++)
using namespace std;
#define N 100005
int freq[1100],tmp[1024];
int main()
{
	int n,k,maxm=0,minm=INT_MAX,p,x;
	cin>>n>>k>>x;
	rep(i,0,n) cin>>p,freq[p]++;
	rep(i,0,k)
	{
		rep(j,0,1024) tmp[j]=freq[j];
		int par=0;
		rep(j,0,1024)
		{
			if(freq[j]>0)
			{
				int curr = (j^x),change = (freq[j]/2);
				if(par==0) change+=(freq[j]&1);
				tmp[j]-=change;
				tmp[curr]+=change;
				par^=(freq[j]&1);
			}
		}
		rep(j,0,1024) freq[j]=tmp[j]; 
	}
	rep(i,0,1024) if(freq[i]>0) minm=min(minm,i),maxm=max(maxm,i);
	cout<<maxm<<" "<<minm;
	return 0;
}