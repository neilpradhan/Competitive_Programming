#include <iostream>
using namespace std;




void replaceCharacter(char input[], char c1, char c2) {

    //base case 
    
    if (input[0]=='\0'){
        return;
    }
    
    if (input[0]!=c1){
        return replaceCharacter(input+1,c1,c2);
    }
    else {
        // int i=1;
        // for (;i!='\0';i++){
        //     input[i-1] = input[i];
        // }
        // input[i-1] = input[i];// we do this because we also want the null character to shift nd with this trick we can get the value of i untill null char occurs
        
        input[0]=c2;
       return replaceCharacter(input+1,c1,c2); 
        
    }
    


int main() {
    char input[1000000];
    char c1, c2;
    cin >> input;
    cin >> c1 >> c2;
    replaceCharacter(input, c1, c2);
    cout << input << endl;
}

    
    
    
    
    
    
    
    
    
    
    
    
    
    
}
