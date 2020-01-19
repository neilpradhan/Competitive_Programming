#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void build_tree(int* arr, int* tree,int start, int end, int nodeindex){
    int mid = (start + end)/2;
    
    if (start == end){
        tree[nodeindex] = arr[start];
        return;
    }
    
    build_tree(arr,tree,start,mid,2*nodeindex);
    build_tree(arr, tree,mid+1,end,2*nodeindex+1);
    
    tree[nodeindex] = tree[2*nodeindex] + tree[2*nodeindex+1];
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    
    
    int* tree =  new int[18];
    build_tree(arr,tree,0,8, 1);
    
    for(int i=0;i<18;i++){
        cout<<tree[i]<<" ";
        // cout<<endl;
    }
    
}
