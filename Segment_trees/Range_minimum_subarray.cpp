#include<bits/stdc++.h>
#include<string>
using namespace std;


void build_tree_min(int* tree, int* arr,int  start,int end,int nodeindex){
    
    
    if (start ==end){
        tree[nodeindex] = arr[start];
        return;
    }
    
    int mid = (start+end)/2;
    
    build_tree_min(tree,arr,start,mid,2*nodeindex);
    build_tree_min(tree,arr,mid+1,end,2*nodeindex+1);
    
    
    tree[nodeindex] = min(tree[2* nodeindex] ,tree[2* nodeindex +1]);
}

void update_tree_min(int* tree, int* arr,int start,int end,int nodeindex,int idx,int value){
    
    if (start ==end){
        arr[idx] = value;
        tree[nodeindex] = value;
        return;
        
    }
    
    
    int mid = (start+end)/2;
    if (idx>= start &&idx<=mid){
    update_tree_min(tree,arr,start,mid,2*nodeindex,idx,value);        
    }
    else{
    update_tree_min(tree,arr,mid+1,end,2*nodeindex+1,idx,value);        
    }
    
    
    tree[nodeindex] = min(tree[2* nodeindex] ,tree[2* nodeindex +1]);
}




int minimum_query(int*tree, int start, int end, int left, int right, int nodeindex){
    
    
    // complete overlapping case
    if (start>=left && end<=right){
        return tree[nodeindex];
    }
    
    
    // non overlapping case
    if (end<left || start>right){
        return 10000000000e7;
    }
    
    // partial case
    int mid = (start + end)/2;
    int ans1 = minimum_query(tree,start,mid,left,right,2*nodeindex);
    int ans2 = minimum_query(tree,mid+1,end,left,right,2*nodeindex+1);
    return min(ans1,ans2);
}








int main() {
    int N,Q;
    cin>>N>>Q;
    
    int* arr =  new int[N+1];
    for(int i=0;i<N;i++){
        int k;
        cin>>k;
        arr[i] = k;
    }
    
    
    
    
    
    
    
    
    
    int* tree = new int[4*N];
    
    build_tree_min(tree,arr,0,N-1,1);
    
    // tree is filled
    
	while (Q--){
    string s;
    cin>>s;
    if (s=="q"){
        int left, right;
        cin>>left>>right;
        cout<<minimum_query(tree,0,N-1,left-1,right-1,1);
        cout<<"\n";
    }
    else{

        int idx,value;
        cin>>idx>>value;
        update_tree_min(tree,arr,0,N-1,1,idx-1,value);
    }


}

}
