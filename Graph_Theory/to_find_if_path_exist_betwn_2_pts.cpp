#include <iostream>
#include<bits/stdc++.h>
using namespace std;
// will fill visited but not print anything
void non_print_BFS(int** edge, int n, int sv, bool* visited){
    queue<int> q;
    
    // bool* visited  = new bool[n];
    
    for(int i=0;i<n;i++){
        visited[i] = false;
    }
    
    q.push(sv);
    visited[sv] = true;
    
    while(!q.empty()){
        int current_index = q.front();
        q.pop();
        visited[current_index]=true;
        // cout<<current_index<<" ";
    
        
        for (int i =0;i<n;i++){
            if (i==current_index){
                continue;
            }
            if (!visited[i] && edge[current_index][i] ==1){
                q.push(i);
                visited[i]=true ;
            }    
        }
               
        
    }
      
    
    
}




bool find_end(int sv, int ev, int** edge, int n){
    
    bool* visited =  new  bool[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
    }
    
    
    
    non_print_BFS(edge,n,sv,visited);
    if (visited[ev]){
        return true;
    }
    else {return false;}
}
















void print_BFS(int** edge, int n, int sv, bool* visited){
    queue<int> q;
    
    // bool* visited  = new bool[n];
    
    for(int i=0;i<n;i++){
        visited[i] = false;
    }
    
    q.push(sv);
    visited[sv] = true;
    
    while(!q.empty()){
        int current_index = q.front();
        q.pop();
        visited[current_index]=true;
        cout<<current_index<<" ";
    
        
        for (int i =0;i<n;i++){
            if (!visited[i] && edge[current_index][i] ==1){
                q.push(i);
                visited[i];
            }    
        }
        
        
        
        
        
        
    }
    
    
    
    
    
    
    
    
}

void BFS(int** edge,int n){
    // sv = 0;
    bool* visited =  new  bool[n];
    for(int i = 0;i<n;i++){
        visited[i] = false;
    }
    
    for(int i = 0;i<n;i++){
        if (!visited[i]){
         print_BFS(edge,n,i,visited);           
        }

    }
    
    
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
    
    int sv,ev;
    cin>>sv>>ev;
    
    find_end(sv,ev,edge,V)? cout<<"true": cout<<"false";
    // BFS(edge,V);
    

  return 0;
}
