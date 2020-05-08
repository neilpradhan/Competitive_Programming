#include <iostream>
#include<bits/stdc++.h>
using namespace std;


// sort the edges 
// then use union find algorithm for MST




// int find_parent(int * parent,int obj, int V ){
    
// }






class edge{
    public:
    int src; // source 
    int dst; // destination
    int w; // weight
    // vector<int> v;
    public:
    void set_edge(int source,int   destination, int weight){

        src = source;
        dst = destination;
        w = weight;
    }
    
    
    void get_edge(){

        
        int minimum = min(src,dst);
        int maximum = max(src,dst);
        cout<<minimum<<" "<<maximum<<" "<<w<<endl;       
        // for the sake of displaying output
        // int minimum = min (min(src,dst),w);
        // int maximum  = max(max(src,dst),w);
        // if 
        // cout<<minimum<<
//         vector<int>  v;
//         v.push_back(src);
//         v.push_back(dst);
//         v.push_back(w);
//         sort(v.begin(), v.end());
//         vector<int> :: iterator it = v.begin();
        
//         for (;it!=v.end();it++){
//             cout<<*it<<" ";
//         }
//         cout<<endl;
    }
    
    // vector<int> sorted_edge(){
    //     v.push_back(src);
    //     v.push_back(dst);
    //     v.push_back(w);
    //     sort(v.begin(), v.end());
    //     return v;
    // }
    
    
};




bool compare (class edge  e1 , class edge e2){
    return (e1).w < (e2).w;
};



int finding(unordered_map<int, int> & parent, int i)  
{  
    // find root and make root as parent of i  
    // (path compression)  
    if (parent[i] != i)  
        parent[i] = finding(parent, parent[i]);  
  
    return parent[i];  
} 


// union(int x, int y,unordered_map<int, int> & parent ){
    
//     if (x<=y){
//         parent[]
//     }
    
    
// }

vector<edge>* kruskals(edge* arr,int V,int E){
    	vector<edge>* output = new vector<edge>();
        
        
        unordered_map<int, int> parent;
        
        for(int i=0;i<V;i++){
            parent[i] =  i; // all vertices will have different parents
        }
        
        
        
        
    	sort(arr,arr+E,compare);
        
        int count =0;
        int i = 0;
        while (count<V-1 && i<E){
            
            int src_parent = finding( parent,arr[i].src);
            int dst_parent = finding ( parent,arr[i].dst);
            
            if (src_parent!=dst_parent){
                if (src_parent<=dst_parent){
                     parent[arr[i].src] = src_parent;
                     parent[arr[i].dst] = src_parent;                   
                }else{
                      parent[arr[i].src] = dst_parent;
                      parent[arr[i].dst] = dst_parent;                    
                }
                
                output->push_back(arr[i]);
                count++;

             }else{
                 
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
   edge* arr= new edge[E];// array of edges
    
    
   for(int i=0;i<E;i++){
       int src,dst,w;
       cin>>src>>dst>>w;
       edge e;
       e.set_edge(src,dst,w);
       arr[i] = e; 
       
   } 
    
    vector<edge>* output = new vector<edge>();

    output = kruskals(arr,V,E);


    // sort(arr,arr+E,compare);
    
    vector<edge> :: iterator it = output->begin();
    for (;it!= output->end();it++){
        // vector<int> v = (*it).sorted_edge();
        // for(int i=0;i<v.end();i++){
        //     cout<<v[i];
        // }
        (*it).get_edge();
        
    }
		


    
    
  return 0;
}
