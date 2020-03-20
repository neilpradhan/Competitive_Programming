#include <iostream>
#include<vector>
#include<unordered_set>


using namespace std;

void dfs(int start, bool *visited, unordered_set<int>* un_set_one, vector<int>* edges){
    

// visited unordered_set

// we will fill visited set here

    visited[start] = true;
    un_set_one->insert(start);
    
    
    vector<int> :: iterator it;
    
    
    
    
    for(it = edges[start].begin(); it!= edges[start].end(); it++){
    
    if (visited[*it] == true){
        continue;
    } 
    
    dfs(*it,visited,un_set_one,edges);
    
    
    }
    

    
    
    
    
}







unordered_set<unordered_set<int>*>* get_components(int V, vector<int>* edges){
    
    
    
    bool *visited =  new bool[V]; // creating visited 
    
    
	unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*>();
    
    for(int i=0;i<V;i++){
        if (visited[i] == false){
            
            unordered_set<int>* un_set_one =  new unordered_set<int>;
            dfs(i, visited,un_set_one, edges);
            output->insert(un_set_one);
        }
        continue;
    }
    
    return output;
}





int main()
{
//   cout << "Hello World" << endl; 

 int n;
 cin>>n;
 // no of vertices
 
 vector<int>* edges = new vector<int>[n];
 // array of vectors
 
 
 int m;
 cin>>m;
 
 for(int i=0;i<m;i++){
		int j, k;
		cin >> j >> k;
		edges[j - 1].push_back(k - 1);
		edges[k - 1].push_back(j - 1);
 }

 unordered_set<unordered_set<int>*>* components  = get_components(n,edges);



    unordered_set<unordered_set<int>*> :: iterator it  = components->begin();
    
    
    for(;it != components->end();it++){
        unordered_set<int>* component = *it;
        
        unordered_set<int> :: iterator jt  = component->begin();
        
        for(;jt != component->end();jt++){
            cout<<*jt +1<<" ";
        }
        cout<<"\n";
    }






   
   return 0;
}
