#include <iostream>
#include <string>
#include<map>
#include<bits/stdc++.h>
using namespace std;

 const char hashTable[10][5] = {"", "", "abc", "def", "ghi", "jkl", 
                               "mno", "pqrs", "tuv", "wxyz"}; 

// void printkeypad1(int,string);
// void printKeypad

    map<int,string> mp;


// void print
void printkeypad1(int num,string output){
    
    
    
    
    int n =num%10;// last digit 3 for 23
    
    
    if (num ==0){
        cout<<output<<endl;
        return;
    }
    
    int t=3;
    int lastdigit = num%10;
    
    
    if (lastdigit == 7 or lastdigit ==9){t=4;}
    
    
    for (int i=0;i<t;i++){
        
        printkeypad1( num/10, hashTable[lastdigit][i]+output);
    }
    
    
    
    
    
    
}



void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */

    
    


    
//     int j=97;// a
    
    
    
    
//     for (int i=2;i<=9;i++){
//         string s="";
//         int p = j;
//         int t=0;
        
//         if (i==7 || i==9){
//             t++;
//         }
        
//         for(int p=0;p<j+2+t;p++){
            
//             s=s+(char)p;
//         }
//         j=p;
//         mp[i]=s;
//     }
    
    



        
    printkeypad1(num,"");        
        
        
        
        
    }
    
    
       
    
    
#include <iostream>
#include <string>

using namespace std;

int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}

    
    

