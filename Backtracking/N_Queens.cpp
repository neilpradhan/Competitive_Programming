//N Queens

#include<bits/stdc++.h>




int board[11][11];








bool isposssible(int n, int row, int col){

	//constant col up
	for(int i=row-1;i>=0;i--){
		if(board[i][col]==1){
			return false;
		}
	}


//Upper Left Diagonal
  for(int i=row-1,j=col-1;i>=0 && j>=0 ; i--,j--){
    if(board[i][j] ==1){
      return false;
    }
  }

  // Upper Right Diagonal

  for(int i=row-1,j=col+1;i>=0 && j<n ; i--,j++){
    if(board[i][j] == 1){
      return false;
    }
  }

  return true;

}





// n is the number of rows available but check the index final would be n-1
void placing_queens(int n, int row){

	if (row == n){
		// base case we have reached now just print ou


		// and return
		for(int i =0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<board[i][j]<<" ";
			}
		}
		cout<<endl;
		return;
	}








	// for every row just place and then move on to next row

	for (int j =0;j<n;j++){
		// check for every column in a particular row it is possible and place it there
		if (isposssible(n, row, j)){
			board[row][j] = 1;
			placing_queens(n,row+1);
			// most important part force it to look in greater J and erase the previous one
			board[row][j] = 0;
		}
	}
	return;	


}



void placeNQueens(int n){
	memset(board,0,11*11*sizeof(int));

	placing_queens(n,0);
}


