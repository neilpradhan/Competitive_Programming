#include <iostream>
#include<bits/stdc++.h>
using namespace std;




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




int main()
{
//   cout << "Hello World" << endl; 

    int n;
    int e;
    
    cin>>n>>e;
    
    int** edge = new int*[n];
    
    
    for (int i = 0;i<n;i++){
        edge[i] =  new int[n];
        for(int j=0;j<n;j++){
            edge[i][j] = 0;
        }
    }
    
    
    
    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edge[f][s] = 1;
        edge[s][f] =1;
    
    }
    
    
    // print_BFS(edge,n,0);
    
    
    BFS(edge,n);
    
   
   return 0;
}
