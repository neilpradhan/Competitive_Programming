#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int  query(int* tree,int start,int end,int left, int right, int nodeindex){
    if (end<=left  || start>=right){
        //out of range
        return 0;
    }
        
    if ((start>=left) && (end<=right)){
        // completely within
        return tree[nodeindex];
    }
    
    
        // partially in range
        int mid = (start + end)/2;
        int ans1 = query(tree,start,mid,left,right, 2*nodeindex);
        int ans2 = query(tree,mid+1,end,left,right,2*nodeindex +1);

        return ans1 + ans2;

    
    
    
    
}

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


void update_tree(int* arr,int* tree, int start, int end, int nodeindex,int idx, int value ){
    
    if (start == end){
        // update array and update tree
        arr[idx] = value;
        tree[nodeindex] = value;
        return;
    }
    
    int mid = (start + end)/2;
    if (idx>mid){
        update_tree(arr,tree,mid+1,end,2*nodeindex+1,idx,value);
    }
    else{
    update_tree(arr,tree,start,mid,2*nodeindex,idx,value);        
    }

    
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
    
    cout<<"\n";
    
    // update_tree(arr,tree,0,8,1,2,15);    

    
    
    
    
    for(int i=0;i<18;i++){
        cout<<tree[i]<<" ";
        // cout<<endl;
    }
    cout<<"\n";
    
    // update_tree(arr,tree,0,8,1,2,15);
    // cout<<"see the arr";
    
    
    // queries are for interval sums;
    int ans  = query(tree,0,9,0,3, 1);
    cout<<ans;
    
    
}
