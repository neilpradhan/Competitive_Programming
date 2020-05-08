#include <string>

#include<iostream>
#include <string.h> 
using namespace std;





 const char hashTable[10][5] = {"", "", "abc", "def", "ghi", "jkl", 
                               "mno", "pqrs", "tuv", "wxyz"}; 






int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    int n =  (num%10);// my work 3
    
    

    if (n==0){
        output[0]="";
        return 1;
    }
    
    //comp work
     int size_comp;   
     size_comp =  keypad(num/10,output);// size of array the comp will solve 23
    
    
    
   //our work
    
    
    int j;
     j = strlen(hashTable[n]);// 4 or 3 
     
     for(int l=1;l<j;l++){
     for( int i=0;i<size_comp;i++){
         output[i+l*size_comp]+=output[i];
     }         
     }

    
    
      for( int k=0;k<j;k++){
    for(int i = 0;i<size_comp;i++){
        output[i+k*size_comp] =   output[i+k*size_comp] + hashTable[n][k] ;              
        }      
    }
    

    return (size_comp*j);




}



 #include <iostream>
#include <string>
using namespace std;

int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}





