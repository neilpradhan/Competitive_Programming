
#include <iostream>
// #include<bits/stdc++.h>
// #include<stdlib.h>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
// will fill visited but not print anything


// the path will be in reversed way

int* BFS_path(int** edge,int V, int sv, int ev){
    bool* visited  =  new bool[V];
    
    for(int i=0;i<V;i++){
        visited[i] =  false;
    }
    

    queue<int>q ;
    q.push(sv);
    visited[sv] = true;
    
    
    bool flag =  false;
    unordered_map<int,int> parent;
    while (!q.empty() && !flag){
        int front = q.front();
        q.pop();
        
        for(int i=0;i<V;i++){
            if (edge[front][i] ==1 && !visited[i]){
                parent[i] = front; 
                q.push(i);
                visited [i] = true;
                
                if (i==ev){
                    flag = true;
                    break;
                    
                }
            }
        }
    }
    
    if (!flag){
        return NULL;
    }
    
    else{
        int* arr =  new int[V];
        arr[0] = ev;
        int latestpath =  parent[ev];
        int i=0;
         while (latestpath!=sv){
             i+=1;
             arr[i] =  latestpath;
             latestpath = parent[latestpath];

             
         }
        arr[i+1]=sv;
        return arr;
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
    
    // find_end(sv,ev,edge,V)? cout<<"true": cout<<"false";
    // BFS(edge,V);

    int* output=BFS_path(edge,V, sv, ev);
    
    if (output!= NULL){
        for (int i = 0;i<V;i++){
            cout<<output[i]<<" ";
        }
    }
    else {
        cout<<" ";
    }

  return 0;
}
