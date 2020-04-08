#include<bits/stdc++.h>
// #include INT_MIN numerical_limits<min>
#define BIG_NUM 1000002
using namespace std;

// 1 solution
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

// 2 solution
#include <bits/stdc++.h>
#include <typeinfo>
#define BIT_SIZE 21
#define MAX_SIZE 1000002

using namespace std;



class trie{
    public:
    int cnt;
    trie* children[2];
    trie(){
        cnt =0;
        children[0] =NULL;
        children[1] =NULL;
        
    }
};

trie* root;
int A[MAX_SIZE];

void insert(int val){
    trie* node = root;
    trie* newnode;
    // trie temp;
    
    
    for(int i=BIT_SIZE-1;i>=0;i--){
        bool k =(val>> i) & 1;
        if (node->children[k]==NULL){
            newnode = new trie;
            newnode->cnt =1;
            node->children[k] = newnode;
        }
        else{
            node->children[k]->cnt++;
        }
        node = node->children[k];

    }

}
    

long long int query(int val){
    
    
    long long ans= 0;
    int i=BIT_SIZE -1;
    trie* node =root;
    if (root==NULL){
        return 0;
    }
    while(i>=0){
        bool p = (val>>i) &1;
        if (node->children[1-p]){
            node = node->children[1-p];
            ans = ans*2 +1;
        }else{
            node = node->children[p];
            ans =ans*2;
        }
        i--;
    }
    return ans;
}




int main()
{
//   cout << "Hello World" << endl; 
//   trie* node = root,*right,temp;
// //   int 6;
//   cout << typeid(root).name() << endl;
//   cout << typeid(right).name() << endl;
//   cout << typeid(temp).name() << endl;
// //   cout << typeid(6).name() << endl;
//     temp.cn =13;
//     cout<<temp.left;
   
    int n, i, mxor;
    long long ans;
    cin>>n;
    root = new  trie;
    ans = 0;
    mxor =0;
    insert(mxor);
    for(int i=0;i<n;i++){
        cin>>A[i];
        mxor = mxor ^ A[i];
        ans = max(ans, query(mxor));
        insert(mxor);
    }
    cout<<ans<<endl;
   
    
   return 0;
}
    
    
    
