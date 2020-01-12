#include <iostream>

using namespace std;



void print(int **edge,int sv, int n, bool* visited){
    cout<<sv<<" \n";
    visited[sv] = true;
    
    for (int i= 0;i<n;i++){
        
        if (edge[sv][i] == 0){
            continue;
        }    
        // for every vertex
        if (edge[sv][i] == 1){
            if (visited[i]== true){
               continue;
            }
            else{
            print(edge,i,n, visited);  
            }

        }
    }
}






int main()
{

int n;
int e;

int sv;



cin>>n;
cin>>e;


int **edge = new int*[n];


for (int i=0;i<n;i++){
    edge[i] = new int[n];
    
    for (int i = 0;i<n;i++){
        edge[i][i] == 0;
    }
}



for (int i = 0; i<e;i++){
    int f,s;
    cin>>f>>s;
    edge[f][s] = 1;
    edge[s][f] = 1;
}


bool* visited = new bool[n];

for (int i =0;i<n;i++){
    visited[i] = false;
}


cin>>sv;



print(edge,sv,n,visited);





   return 0;
}
