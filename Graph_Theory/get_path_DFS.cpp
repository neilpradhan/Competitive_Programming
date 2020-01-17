## one way

#include <iostream>
#include<bits/stdc++.h>
using namespace std;


vector<int>* get_helper_path(int** edge,int V, int sv,int ev, bool* visited){

    
    if (sv==ev){
    vector<int>* output  = new vector<int>(); 
    output->push_back(sv);
    return output;    
    }


    visited[sv] = true;
    for(int i=0;i<V;i++){
        if (edge[sv][i] == 1 && !visited[i]){
        vector<int>* smalloutput = get_helper_path(edge,V,i,ev,visited);
        if (smalloutput!=NULL){
        smalloutput->push_back(sv);           
        
        return smalloutput;            
        
        }


        }
    }    

    return NULL;
    
}





vector<int>* get_path(int** edge,int V, int sv,int ev){
    
    
    bool* visited  =  new bool[V];
    
        
    for (int i =0 ;i<V;i++){
        visited[i] =  false;
    }
    
    return get_helper_path(edge,V, sv,ev, visited);
    
    
    
}



int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;
    
    
    
    
   int** edge = new int*[V];
    
    
    for (int i =0 ;i<V;i++){
        edge[i] = new int[V];
        for(int j =0;j<V;j++){
            edge[i][j] = 0;
        }
    }
    
  for(int i =0;i<E;i++){
      int f,s;
      cin>>f>>s;
      edge[f][s] = 1;
      edge[s][f] = 1;
      
  }
    
    int sv,ev; // start vertex and end vertex
    cin>>sv>>ev;

    
    
    vector<int>* output  =  new vector<int>();
    output=get_path(edge,V,sv,ev);
    
    if (output!=NULL){
        
    for(int i=0;i<output->size();i++){
        cout<<output->at(i)<<" ";
    } 
     delete output;   
        
    }
    
    else{cout<<" ";}
    
    

    
  return 0;
}


## second way

#include <iostream>
// #include<bits/stdc++.h>
// #include<stdlib.h>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
// will fill visited but not print anything



vector<int>* BFS_path(int** edge,int V, int sv, int ev){
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
        vector<int>* v = new vector<int>();
        v->push_back(ev);
        int latestpath =  parent[ev];
         while (latestpath!=sv){
             v->push_back(latestpath);
             latestpath = parent[latestpath];

             
         }
        v->push_back(sv);
        return v;
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

    vector<int>* output=BFS_path(edge,V, sv, ev);
    
    if (output!= NULL){
        for (int i = 0;i<output->size();i++){
            cout<<output->at(i)<<" ";
        }
    }
    else {
        cout<<" ";
    }

  return 0;
}




