// arr - input array
// n - size of array

#include<bits/stdc++.h>
#include <iostream>
using namespace std;

#include<bits/stdc++.h>
using namespace std;
int minAbsoluteDiff(int arr[], int n) {


        sort(arr, arr+n);
    
    int min= arr[1]-arr[0];
        for(int i=1;i<n;i++){
            if (min>=(arr[i]-arr[i-1])){
                min = arr[i]-arr[i-1];
            }
        }
    
    return min;
    
    
    
}    




int main() {

	int size;
	cin >> size;
	int *input = new int[1 + size];
	
	for(int i = 0; i < size; i++)
		cin >> input[i];
	
	cout<< minAbsoluteDiff(input,size) << endl;
	
	return 0;

}
