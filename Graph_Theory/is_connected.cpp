#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void DFS_traversal(int** edge,int V,int sv,bool* visited){
    
    visited[sv] = true;
    
    for (int i=0;i<V;i++){
        if (sv==i){
            continue;
        }
        if(!visited[i] && edge[sv][i]==1){
            DFS_traversal(edge,V,i,visited);
            visited[i] =  true;
        }
    }
}

bool isconnected(int** edge,int V){
    
    bool* visited = new bool[V];
    
    for (int i=0;i<V;i++){
        visited[i] =  false;
        
    }
    
    
    DFS_traversal(edge,V,0,visited);
    
    for (int i=0;i<V;i++){
        if (visited[i] ==  false){
            return false;
        }
        
    }
    return true;
    
    
    
}





int main() {
    int V, E;
    cin >> V >> E;
    // cin>>n>>e;
    
    int** edge = new int*[V];
    
    
    for (int i = 0;i<V;i++){
        edge[i] =  new int[V];
        for(int j=0;j<V;j++){
            edge[i][j] = 0;
        }
    }
    
    
    
    for(int i=0;i<E;i++){
        int f,s;
        cin>>f>>s;
        edge[f][s] = 1;
        edge[s][f] =1;
    
    }
    
    


    if(isconnected(edge,V)){
        cout<<"true";
     } 
    else{
        cout<<"false";
    }
 


  return 0;
}
