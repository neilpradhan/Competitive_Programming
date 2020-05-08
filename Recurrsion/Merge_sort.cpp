#include<iostream>
using namespace std;



void mergeSort(int input[], int size){
	// Write your code here
    
    
    if (size<=1){
        return;
    }
    
    int mid = size/2;
    
    mergeSort(input,mid);
    
    if (size%2==0) {mergeSort(input+mid,mid);} else{mergeSort(input+mid,mid+1);}  
        
    int* arr = new int[size];
    
    int  i=0; int j=mid;int k=0;
    
    
    while(i<mid && j<size){
        
        if (input[i]<=input[j]){
            arr[k++] = input[i++];

        }
        
        else {
            arr[k++]=input[j++];
            // k++;
            // j++;
            
            
        }
        
        
        
    }
    
    
     while (i < mid) 
        arr[k++] = input[i++]; 
  
    // Store remaining elements of second array 
    while (j < size) 
        arr[k++] = input[j++];    



for (int i=0;i<size;i++){
    input[i]=arr[i];
}
    
  delete [] arr;
  
  

}






int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}
