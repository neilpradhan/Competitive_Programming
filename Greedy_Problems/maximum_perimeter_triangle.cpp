#include<bits/stdc++.h>
using namespace std;








int main() {


    
    int n;
    cin>>n;
    
    int*  arr =  new int[n];
    
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    
    sort(arr,arr+n, greater<int>());
    for(int i =0;i<n;i++){
   
        if (arr[i]<arr[i+1] + arr[i+2]){
        
        cout<<arr[i+2]<<" "<<arr[i+1]<<" "<<arr[i];
            
            break;
        }
        
        
        if (i==n-1){
            cout<<-1;
            break;
        }
    }
    // cout<<-1;
    
}
