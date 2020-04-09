#include <iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;



class trie{
    public:
    int weight;
    trie* children[26];
    
    trie(){
        weight = 0;
        for(int i=25;i>=0;i--){
            children[i] =NULL;
        }
    }
};


// class trie{
//     public:
//     int weight;
//     trie** children;
    
//     trie(){
//         children = new trie*[26];
//         for(int i=0;i<26;i++){
//             children[i] =NULL;
//         }
//         weight =0;
//     }
// };




void insert (trie* root, string s, int weight){
    // trie* current = root;
    
	trie* current = root;
    int idx;
    for(int i=0;i<s.length();i++){
    	idx = s[i] - 'a';
    	if (current->children[idx]==NULL){
            current->children[idx] = new trie;
        }
        current =current->children[idx];// new current is the child then that child has to create more children
        
        current->weight = max(weight,current->weight);
        
        
    }


    
    
    
};




int searchBest(trie* root, string s){
    

    trie* current = root;
    int i=0; int idx;
    for(int i=0;i<s.length();i++){
        
        idx = s[i] - 'a';
        if (current->children[idx]==NULL){
			return -1;
        }
        current = current->children[idx];

           
    }
//     int bestweight = 0;
//     // trie* itr  = root;
//     for(int i=0;i<26;i++){
// 	if (current->children[i]!=NULL){
//         bestweight = max(bestweight,current->children[i]->weight);
//     }
        
//     }

//     return bestweight;
    
    return current->weight;
};

int main()
{
    int n,q;
    cin>>n>>q;
    
   trie* root = new trie();
//   insert(root,"baba",27);
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        int weight;
        cin>>weight;
        insert(root,s,weight);
    }
    for(int i=0;i<q;i++){
        string s;
        cin>>s;
        int ans  = searchBest(root,s);
        cout<<ans<<endl;
    }    



   return 0;
}
