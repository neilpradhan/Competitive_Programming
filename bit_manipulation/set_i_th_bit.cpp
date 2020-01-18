


#include <iostream>
using namespace std;




int turnOnIthBit(int n, int i){
      if ((n & (1<<i))==0){
            int k = n + (1<<i);
          return k;
      }
        else{
           return n; 
        }

}


int main() {
	int n, i;

	cin >> n >> i;
	
	cout<< turnOnIthBit(n, i) <<endl;
		
	return 0;
}

