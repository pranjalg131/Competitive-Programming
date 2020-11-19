/*
Return Keypad Code

Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.

Note : 
1. The order of strings are not important.
2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.

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

#include <string>
using namespace std;

int keypad(int num, string output[]){
    if(num == 0){
        output[0] = "";
        return 1;
    }
    int x = num/10;
    int y = num%10;
    
    int small = keypad(x,output);
    
    if(y == 7 || y == 9){
     	
        for(int i = 1;i <= 3;i++){
            for(int j = 0;j < small;j++)
                output[small*i + j] = output[j];
        }
        
        char s;
        if(y == 7)
            s = 'p';
        else s = 'w';
         
        for(int i = 0;i <= 3;i++){
            char p = s + i;
            for(int j = 0;j < small;j++)
                output[small*i + j] = output[small*i + j] + p;
        }
        
        return 4*small;
    }
    else{
        
        for(int i = 1;i <= 2;i++){
            for(int j = 0;j < small;j++)
                output[small*i + j] = output[j];
        }
        
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
                break;
        }
         
        for(int i = 0;i <= 2;i++){
            char p = s + i;
            for(int j = 0;j < small;j++)
                output[small*i + j] = output[small*i + j] + p;
        }
        
        return 3*small;   
    }
}
