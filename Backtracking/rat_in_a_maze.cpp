


#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void printfinal(int sol[20][20], int N){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
		cout<<sol[i][j]<<" ";			
		
	}

}
cout<<endl;    
    
}


bool valid_index(int maze[20][20],int sol[20][20], int x, int y, int N){
	if (x>=0 && x<N && y>=0 && y<N && maze[x][y] == 1 && sol[x][y]==0){
		return true;
	}
	return false;

}



void find_path(int maze[20][20], int x, int y, int sol[20][20], int N){


//base case
	if (x == N-1 && y == N-1){
			sol[x][y]=1;
			printfinal(sol,N);
        
		}

	
	if (valid_index(maze,sol, x, y,N)){
        sol[x][y]=1;
        
        
		find_path(maze,x-1,y,sol, N);
			

		find_path(maze,x+1,y,sol, N);
			
      	find_path(maze,x,y-1,sol, N);  
        
       	find_path(maze,x,y+1,sol, N);         

//backtrack

		sol[x][y]=0;
		
	}


	 // the index goes out of bound



}



void ratInAMaze(int maze[20][20],int n){

	int sol[20][20];


  for(int i = 0; i < n ;i++){
	for(int j = 0; j < n; j++){
        	sol[i][j]=0;
        }		
  }

 find_path(maze,0,0,sol,n);


  //cout<<"path not found";


}





















