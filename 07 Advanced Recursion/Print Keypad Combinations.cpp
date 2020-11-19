/*
Print Keypad Combinations Code
Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
Note : The order of strings are not important. Just print different strings in new lines.

Input Format :
Integer n

Output Format :
All possible strings in different lines

Constraints :
1 <= n <= 10^6

Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf
*/

#include <iostream>
#include <string>
using namespace std;

void print_keypad(int num, string str){
    if(num == 0){
        cout << str << "\n";
        return;
    }
    int x = num/10;
    int y = num%10;
    
    
    if(y == 7 || y == 9){
        char s;
        
        switch(y){
            case 7 : s = 'p';
                break;
            case 9 : s = 'w';
        }
        
        for(int i = 0;i < 4;i++){
            char p = s + i;
            print_keypad(x,p + str);
        }
        
    }
    else{
        
        char s;
        
        switch(y){
            case 2 : s = 'a';
                break;
            case 3 : s = 'd';
                break;
            case 4 : s = 'g';
                break;
            case 5 : s = 'j';
                break;
            case 6 : s = 'm';
                break;
            case 8 : s = 't';
        }
        
        for(int i = 0;i < 3;i++){
            char p = s + i;
            print_keypad(x,p + str);
        }
        
    }
}

void printKeypad(int num){
    string output = "";
  print_keypad(num,output);
}

