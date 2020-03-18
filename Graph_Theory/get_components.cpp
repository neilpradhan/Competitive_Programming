#include <iostream>
#include<vector>
#include<unordered_map>


using namespace std;

unordered<set>* dfs(int start, bool *visited, unordered<set>* un_set_one, vector<int>* edges){
    

// visited unordered_set

// we will fill visited set here

    visited[start] = true;
    un_set_one.insert(start);
    
    
    
    
    
    dfs(edges->[start],visited,un_set_one,edges);
    
    
    
    
}







unordered_set<<unordered_set>*>* get_components(int V, vector<int>* edges){
    
    
    
    bool *visited =  new bool[V]; // creating visited 
    
    
    for(int i=0;i<V;i++){
        if (visited->at(i) == false){
            
            unordered_set<int>* un_set_one =  new unordered_set<int>;
            
            
            dfs(start, unordered_set, visited, edges);
        }
    }
}




int main()
{
//   cout << "Hello World" << endl; 

 int n;
 cin>>n;
 // no of vertices
 
 vector<int>* edges = new vector<int>[n];
 
 
 int m;
 cin>>m;
 
 for(int i=0;i<m;i++){
		int j, k;
		cin >> j >> k;
		edges[j - 1].push_back(k - 1);
		edges[k - 1].push_back(j - 1);
 }

 unordered_set<<unordered_set>*>* components  = get_components()
//  int** p = new int*[n];








   
   return 0;
}
