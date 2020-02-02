#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// TIME COMPLEXITY IS E.LOG(E) + E.V

// int find_parent(int * parent,int obj, int V ){
    
// }

class edge{
    public:
    int src; // source 
    int dst; // destination
    int w; // weight
    public:
    void set_edge(int source,int   destination, int weight){

        src = source;
        dst = destination;
        w = weight;
    }
    
    
    void get_edge(){
        cout<<src<<" "<<dst<<" "<<w<<endl;
    }
    
    
};




bool compare (class edge  e1 , class edge e2){
    return (e1).w < (e2).w;
};






// int find_parent(int* parent, int vertex){
//     // vertex is source or destination
//     // recurrsion should be positive  0 to V-1;
//     int p = parent[vertex];
//     while (parent[p] == p){
//        find_parent(parent,p);
//     }
    
//     return p;
// }




int get_parent(int vertex, int* parent){
    
    
    while(vertex!=parent[vertex]){
        vertex = parent[vertex];
    }
    return vertex;

    
}

edge*  kruskals(edge* arr,int V, int E){
    sort(arr, arr+ E, compare);
    
    
    int* parent = new int[V];
    for(int i=0;i<V;i++){
        parent[i] = i;
    }
    
    
    edge* output = new edge[V-1];
    
    int count  = 0;
    int i= 0;
    while(count<(V-1)){
        
        edge current_edge = arr[i];
        int src_parent = get_parent(arr[i].src,parent);
        int dest_parent = get_parent(arr[i].dst, parent);
        
        if (src_parent!= dest_parent){
            output[count] = current_edge;
            count++;
            parent[src_parent] = dest_parent;
            
        }
        
        else{
            continue;
        }
        
        i++;
        
        
    }
    
    return output;
    
    
}



int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;
   // array of edges
   edge* arr= new edge[E];
    
    
   for(int i=0;i<E;i++){
       int src,dst,w;
       cin>>src>>dst>>w;
       edge e;
       e.set_edge(src,dst,w);
       arr[i] = e; 
       
   } 
    

    edge* output = kruskals(arr,V,E);

//    for(int i=0;i<E;i++){
//        arr[i].get_edge();
//    }   
    
    // after we successfully put all the edges in an array we will create an array of sorted edges with weight;
    
    // sort(arr,arr+E, compare);
    
    
    
//     int* parent=  new int [V];
    
//     for (int i =0;i<V;i++){
//         parent[i] = i;
//     }
    
//     // make a find_last_parent function
//     edge* mst =  new edge[V-1];
//     for (int i=0;i<V;i++){
//         mst[i].src = 0;
//         mst[i].dst = 0;
//         mst[i].w = 0;
//     }
    
//     int count = 0;
//     while(count==V-1){
//         for (int i = 0;i<E;i++){
//             // if source and destination doesnot have same parent then add it to the final result else skip it
//             // for every edge
//             if (find_parent(parent,arr[i].src) != find_parent(parent,arr[i].dst)){
                
//                 if (parent[arr[i].src] <=parent [arr[i].dst]){
//                     parent[arr[i].dst] = parent[arr[i].src];
//                 }
//                 else{
//                     parent[arr[i].src] = parent[arr[i].dst];                   
//                 }
                
//                 mst[count] = arr[i]; // add edge to the final result
//                 count++;
//             } 
//             else{
//                 continue;
//             }
//         }
//     }
    
//      for(int i=0;i<V-1;i++){
//          mst[i].get_edge();
//      }   
    
        for (int i=0;i<V-1;i++){
            if (output[i].src<output[i].dst){
            cout<<output[i].src<<" "<<output[i].dst<<" "<<output[i].w;
                cout<<"\n";
            }
            else{
            cout<<output[i].dst<<" "<<output[i].src<<" "<<output[i].w;
                cout<<"\n";
            }

        }

    
    
  return 0;
}
