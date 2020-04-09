#include <iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;



// class trie{
//     public:
//     int weight;
//     trie* children[26];
    
//     trie(){
//         weight = 0;
//         for(int i=25;i>=0;i--){
//             children[i] =NULL;
//         }
//     }
// };


class trie{
    public:
    int weight;
    trie** children;
    
    trie(){
        
    }
}




void insert (trie* root, string s, int weight){
    // trie* current = root;
    
    if (s.empty()){
        return;
    }
    
    int index = s[0] - 'a';
    // will be between 0 and 25;
    trie* child;
     if (root->children[index]){
         child = root->children[index];
        
        }else{
            child  = new trie();
            root->children[index] = child;
        }
        
    if (root->weight < weight){
        root->weight = weight;
    }
    insert(root,s.substr(1),weight);
};




int searchBest(trie* root, string s){
    int bestweight = -1;
    trie* current = root;
    trie* child;
    for(int i=0;i<s.length();i++){
        trie* child = current->children[i];
    }
    if(child){
        current = child;
        bestweight = child->weight;
    }else{
        return -1;
    }
    return bestweight;
}

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
