#include <iostream>
#include<bits/stdc++.h>


using namespace std;



void bfs(vector<int>*edges, int start, bool* visited, unordered_set<int>* component){
    
    visited[start]  =  true;
    queue<int> q;
    q.push(start);
    
    
    while (!q.empty()){
        int f = q.front();
        component->insert(f);
        q.pop();
        

        
        // for(int i=0;i<component->size();i++){
        //      int next = edges[start][i];
        //      if (!visited[next]){
        //          bfs(edges,next,visited,component);
        //         // visited[next] = true;
        //         // q.push(next);
        //      }
        // }
        
        
        vector<int> :: iterator it;
        
        
        
        for(it  = edges[start].begin(); it != edges[start].end(); it++){
            if (!visited[*it]){
                visited[*it] = true;
                q.push(*it);
            }
        }
        
    }
    
}


void dfs(vector<int>* edges,int start, bool *visited, unordered_set<int>* un_set_one){
    

// visited unordered_set

// we will fill visited set here

    visited[start] = true;
    un_set_one->insert(start);
    
    
    vector<int> :: iterator it;
    
    
    
    
    for(it = edges[start].begin(); it!= edges[start].end(); it++){
    
    if (visited[*it] == true){
        continue;
    } 
    
    dfs(edges,*it,visited,un_set_one);
    
    
    }
    

    
    
    
    
}




unordered_set<unordered_set<int>*>* get_connected_components(int v,vector<int>* edges){
    
    bool*  visited = new bool[v];
    
    for(int i=0;i<v;i++){
        visited[i] =  false; // for all vertices make  visited false
    }
    
    unordered_set<unordered_set<int>*>* output  = new  unordered_set<unordered_set<int>*>();
    
    //check for every vertex if not visited then bfs
    
    for(int i=0;i<v;i++){
    if (!visited[i]){
        unordered_set<int>* component = new unordered_set<int>();
        // bfs(edges,i,visited, component);
        dfs(edges,i,visited, component);
        output->insert(component);
    }
    
    
    
    
    }
    
    return output;

    
    
}







int main()
{
//   cout << "Hello World" << endl; 


int v;// no of vertices 
int e;// no of edges

cin>>v>>e;

vector<int>* edges =  new vector<int>[v]; // array of vectors adjacency list

for (int i=0;i<e;i++){
    int a,b;// numbering starts from 1 to n
    // our index is from 0 to n-1
    
    cin>>a>>b;
    edges[a-1].push_back(b-1);
    edges[b-1].push_back(a-1);    
}

// set of sets

unordered_set<unordered_set<int>*>* output  = get_connected_components(v,edges);

unordered_set<unordered_set<int>*> ::  iterator it1 =  output->begin();
// it1 is pointing to an un_set pointer which is pointing to an un_or_set;



for(; it1!= output->end();it1++){
    // de-ref it1 and get the address of pointer that points to a un_set
    
    
    unordered_set<int>* component = *it1;
    unordered_set<int> :: iterator it2 = component->begin();
    // component will have address to the un_ord_set
    for(;it2!=component->end();it2++){
        // cout<<component->at(i);
        cout<<(*it2) +1;
    }
    
    cout<<endl;
    
}



// while(it1!=output->end()){
//     unordered_set<int>* component = *it1;
//     unordered_set<int> :: iterator it2 = component->begin();
//     while(it2!=component->end()){
//         cout<<(*it2)+1;
//         it2++;
        
//     }
//     cout<<endl;
//     it1++;
// }
                

}
