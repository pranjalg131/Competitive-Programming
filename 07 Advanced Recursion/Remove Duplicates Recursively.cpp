/*
Remove Duplicates Recursively

Given a string S, remove consecutive duplicates from it recursively.

Input Format :
String S

Output Format :
Output string

Constraints :
1 <= |S| <= 10^3
where |S| represents the length of string

Sample Input 1 :
aabccba
Sample Output 1 :
abcba
Sample Input 2 :
xxxyyyzwwzzz
Sample Output 2 :
xyzwz
*/

#include <iostream>
using namespace std;

void removeConsecutiveDuplicates(char *input) {
	int i = 0;
    while(input[i] != NULL){
        i++;
    }
    if(i == 1){
        return;
    }
    
    removeConsecutiveDuplicates(input+1);
    
    if(input[0] == input[1]){
        for(int j = 0; j <= i; j++){
            input[j] = input[j + 1];
        }
    }

}

int main() {
    char s[100000];
    cin >> s;
    removeConsecutiveDuplicates(s);
    cout << s << endl;
}