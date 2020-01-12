#include <iostream>
#include<queue>


using namespace std;


void print(int** edge,bool* visited,int sv,int V){
    
    
      // queue<int>* q =  new  queue<int>;
        queue <int> q;
        
        q.push(sv);
        visited[sv] = true;
        // cout<<sv<<" ";
        while (!q.empty()){
            
            for (int i=0;i<V;i++){
                if ((edge[i][sv] ==1) && (visited[i]==false)) {
                    q.push(i);
                    visited[i] = true;                        
                    }
                    // else{
                    //     continue;
                    // }

                // }
                // else{
                //     continue;
                // }
            }
            
            cout<<q.front()<<" ";
            sv = q.front();
            q.pop();
                
            
            
        }
        
    
      
    
    
    
    
    
    

    
    
    
    
    
    
    
    
    
    
}




int main() {
    int V, E;
    cin >> V >> E;
    
    
    
    int** edge = new int*[V];
    for(int i =0;i<V;i++){
        edge[i]  = new int[V];
        for (int j=0;j<V;j++){
            edge[i][j]= 0;
        }
    }
    
    
    
    for (int i =0;i<E;i++){
        int f,s;
        cin>>f>>s;
        edge[f][s] =1;
        edge[s][f] =1;
    }

    bool* visited = new bool[V];
    // visited boolean array
     
    
    for(int i = 0;i<V;i++){
        visited[i] = false;
    }
 
    
    
    
    print(edge,visited,0,V);
    
    
    
    
  return 0;
}
