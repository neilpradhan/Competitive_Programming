#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void find_connected_component(unordered_map<int,vector<int>*> & Adjacency_list,unordered_map<int,bool>& visited,vector<int>* smalloutput,int i){
    visited[i] = true;
    smalloutput->push_back(i);
    
    
    vector<int>* neighbours = new vector<int>;
    neighbours = Adjacency_list[i];
    // for all neighbours check if the tree can be expanded
    for(int i=0;i<neighbours->size();i++){
        if (visited.count(neighbours->at(i)) == 0){
            find_connected_component(Adjacency_list,visited,smalloutput,neighbours->at(i));
        }
    }
    
}

vector<vector<int>*>* connected_components(unordered_map<int,vector<int>*> & Adjacency_list){
    
    
        vector<vector<int>*>* output = new  vector<vector<int>*>;
        unordered_map<int,bool> visited;
    
    
        // logic visited cha map ahea jo paryanta eka vertex ni visited kartayael toh paryanta karaycha
    // visited has not covered all vertices
        while(visited.size() != Adjacency_list.size()){
            // for all the vertices if not visited
            for (int i=0;i<Adjacency_list.size();i++){
                if (visited.count(i)==0){
                    // vertex not found in visited 
                    vector<int>* smalloutput  =  new vector<int>;
                    find_connected_component(Adjacency_list,visited,smalloutput,i);
                    output->push_back(smalloutput);
                }
                
                
                
            }
        }
    return output;
    
    
    
    
    
}

int main()
{
//   cout << "Hello World" << endl; 
   // list of connections
   
   
   int V,E;
   cin>>V>>E;
   
   
   
   unordered_map<int,vector<int>*> Adjacency_list;
   
  for (int i=0;i<V;i++){
      vector<int>* v = new vector<int>;
      Adjacency_list[i] = v;
  }
   
   
      for (int i=0;i<E;i++){
          int src, dest;
          cin>>src>>dest;
          Adjacency_list[src]->push_back(dest);
          Adjacency_list[dest]->push_back(src);
      }
   
    // cout<<Adjacency_list.size();
   // dynamic array of arrays
   vector<vector<int>*>* output = connected_components(Adjacency_list); 
   
   
    for(int i=0;i<output->size();i++){
        vector<int>* component  = output->at(i);
        sort(component->begin(),component->end());
        for(int j=0;j<component->size();j++){
            cout<<component->at(j)<<" ";
        }
        cout<<"\n";
    }
   
   
   
   return 0;
}

