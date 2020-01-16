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
