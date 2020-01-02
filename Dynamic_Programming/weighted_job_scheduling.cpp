#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class job{
    public:
    int start;
    int finish;
    int profit;
    
    void get_input(){
        cin>>start>>finish>>profit;
    };
    
    void show_output(){
        cout<<start<<" "<<finish<<" "<<profit;

        
    }
};


bool compare(job j1, job j2){
    return j1.finish<j2.finish;
}


int main()
{
    int n;
    cin>>n;
    job j[n];// array of jobs
    
    
    for(int i = 0;i<n;i++){
        j[i].get_input();
    }
    
    sort(j, j+n, compare);
    
    // for(int i = 0;i<n;i++){
    //     j[i].show_output();
    //     cout<<"\n";
    // }
    
    int dp[n];
    
    for(int i =0;i<n;i++){
        int c = 0;
        for (int k=i-1;k>=0;k--){
            
            if (j[k].finish<=j[i].start){
                // jobs available opportunities
                c = max(j[k].profit,c);
                
            }
        }
        dp[i] = j[i].profit + c ;
    }
    
    // for(int i = 0;i<n;i++){
    //     cout<<dp[i]<<" ";
    // }
    int maximum =0;
    for(int i = 0;i<n;i++){
        if (dp[i]>=maximum){
            maximum = dp[i];
        }
    }
    cout<<maximum;
    
    

    return 0;
}
