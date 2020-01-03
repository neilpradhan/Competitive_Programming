#include<bits/stdc++.h>
using namespace std;



void select_number(int s , int d, int* arr){
    
    assert (s>=0);

    
    if (d==0){
        return;
    }
    
    else{
        
        
    if (s>=9){
        arr[d-1] = 9;
        return select_number(s-9,d-1,arr);
    }
    
    else if (s>0 && s<9)
    {
        arr[d-1] =  s;
        return select_number(0,d-1,arr);
    }
    else{
        arr[d-1] = 0;
        return select_number(0,d-1,arr);
    }

    }

    
}

    
    
    

void print_array(int* arr, int d){
    for (int i =0;i<d;i++){
        cout<<arr[i];
    }
}

    
    
    
    
int main() {

    int s;
    int d;
    cin>>s;
    cin>>d;
    
    
    int* arr = new int[d];
    
    if(d==1){
        arr[0] = s;
    }
    
    else{
        select_number(s-1 , d-1, arr+1);
        arr[0]  = 1;
    }

    print_array(arr,d);
    
    return 0;    
    
}
