#include <bits/stdc++.h>
using namespace std;





int  partition(int input[],int si,int ei){

    int count_smaller_ele = si-1; 
    for (int i=si;i<ei;i++){

        if(input[i]<=input[ei]){
            count_smaller_ele++;
            swap(input[i], input[count_smaller_ele]);
        }

    }


    swap(input[ei], input[count_smaller_ele+1]);
    return count_smaller_ele+1;
    // found numnber of elements less than the number in array
    int c;
    c = si + count_smaller_ele;//n right index of the element

    int temp;
    temp = input[c]; // initial swaping
    input[c] = input[si];// input[si] or first element is at c 
    input[si]=temp;






    int i=si;

    int j = ei;



    while(i<c && j>c){



        if (input[i]<input[c]){
            i++;          

        }

        else if (input[j]>input[c]){


            j--;

        }

        else{
            int temp;
            temp = input[i];
            input[i] = input[j];
            input[j] = temp;

            //       swap(input[i],input[j]);
        }
    }
    return c;
}




void quickSort_1(int input[], int si , int ei) {
    /* Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.
  */
    if(si<ei)
    {
        int c = partition(input,si,ei);
        quickSort_1(input,si,c-1);
        quickSort_1(input,c+1,ei);
    }




}





void quickSort(int input[],int size){

    if (size==0 || size==1){
        return;
    }

    else{
        return quickSort_1(input,0,size-1);

    }



}


#include<iostream>
using namespace std;


int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}

