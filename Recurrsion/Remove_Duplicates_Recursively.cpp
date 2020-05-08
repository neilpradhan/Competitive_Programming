
#include <iostream>
using namespace std;


void removeConsecutiveDuplicates(char *input) {

    // if (input[0]=='\0'){
    //     return;     
    // }
    
    int size = 0;
    for (int i=0;input[i]!='\0';i++){
        size++;
    }
    
    if (size<=1){

    return;
    }
    

    
    removeConsecutiveDuplicates(input+1);
    
    if (input[0]!=input[1])
    {
        
        return;
        

    }
    
    else
    {
    int i=1;
    for (;i!='/0';i++){
        
        input[i-1] = input[i];
    }
      input[i-1] = input[i]; // to get i and make sure the null character is also  shifted
        

    
    }        
        
}





int main() {
    char s[100000];
    cin >> s;
    removeConsecutiveDuplicates(s);
    cout << s << endl;
}
