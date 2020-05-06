// the name should be found without lifting your pen which means should be connected


#include<bits/stdc++.h>
using namespace std;
#define MAXN 102
bool visited[MAXN][MAXN];
char to_find[11] = {'N','E','I','L'};


int a[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

bool isvalid(int x,int y, int N, int M){
    if (x>=0  || x<N || y>=0 || y<M){
        return true;
    }
    return false;
};









int dfs (char arr[MAXN][MAXN],int x, int y, int index,int N, int M){
        cout<<endl;
    // cout<<"index  "<<index<<"  ";
    // cout<<endl;
    // cout<<"x y"<<x<<y;
    // cout<<endl;
    // int found  = 0;
    visited[x][y] = true;
    if (index ==10){
        return 1;
    }
    int new_x,new_y;
    
    for (int i = 0;i<8;i++){
        
        new_x = x + a[i][0]; 
        new_y = y + a[i][1];
        
        if (isvalid(new_x,new_y,N,M) && arr[new_x][new_y] == to_find[index+1] && !visited[new_x][new_y]){
            if (dfs (arr, new_x, new_y, index+1,N,M) == 1){return 1;}
            // found = found | dfs (arr, new_x, new_y, index+1,N,M);
        }
        
        
        
    }
    
    visited[x][y] = 0;
    // cout<<"found"<<found;    
    // return found;
    return 0;
};



int solve(char Graph[][MAXN],int N, int M)
{

    
    int found = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if (Graph[i][j] == 'C'){
                found=dfs(Graph,i,j,0,N,M);
                if (found){break;}
            }
        }    
        if (found){break;}
    }    
    // cout<<"found"<<found;

	return found;
    
}
