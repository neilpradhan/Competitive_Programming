#include<bits/stdc++.h>
// #include INT_MIN numerical_limits<min>
#define BIG_NUM 1000002
using namespace std;


class Trie{
    public:
    Trie* left;
    Trie* right;    
};



void insert(Trie* head, int ele){
	    
    Trie* curr = head;
    for (int i=31;i>=0;i--){
        int b = (ele >>i) & 1;// for every bit
        if (b==0){
        if (!curr->left){
            curr->left = new Trie();   
        }
        curr = curr->left;
        }else{
            //b==1
            if (!curr->right){
                curr->right = new Trie();
            }
            curr = curr->right;
        }

        
    }
    

    
    
}




long long int  find_max_xor(Trie* head, int ele){
    
    long long maximum_xor = INT_MIN;
    // for(int i=0;i<n;i++){
	 	// every ele in array:
    	// ele = arr[i];
    	Trie* curr = head;
        int current_value =  0;
    	for (int i=31;i>=0;i--){
        // for every bit
    		int b = (ele >>i) & 1;
			if (b==0){
				if (curr->right){
                    current_value += pow(2,i);
                    curr=curr->right;
                }else{
                    curr =curr->left;
                }
        	}else{
                //b ==1;
                if (curr->left){
                    current_value += pow(2,i);
                    curr= curr->left;
                }else{
                    curr=curr->right;
                }
            }
            if(current_value>maximum_xor){
                maximum_xor = current_value;
            }
    
}
    return maximum_xor;

}  
    
int A[BIG_NUM];
Trie* root;


int main() {
int N;
cin>>N;

// int* arr = new int[N];
// for(int i=0;i<N;i++){
//     int n;
//     cin>>n;
//     arr[i] = n;
// }
 
    
//     Trie* head = new Trie();
// for(int i=0;i<N;i++){
//     insert(head,arr[i]);
    
// }
    
//     int ans = find_max_xor(head,arr,N);
//     cout<<ans;
    
// }
	Trie* root = new Trie;
    
    long long ans = 0;
    int mxor =0;
    insert(root,mxor);
    for(int i=0;i<N;i++){
        cin>>A[i];
        mxor = mxor ^ A[i];
        ans = max(ans, find_max_xor(root,mxor));
        insert(root,mxor);
    }
    cout<<ans<<endl;
    
	return 0;


}
    
    
    
