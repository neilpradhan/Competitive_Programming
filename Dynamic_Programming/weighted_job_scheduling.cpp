#include<bits/stdc++.h>
#include<iostream>
using namespace std;
// O(N^2)
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

int binary_search(job j,int index){
    
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
    
    int* dp = new int[n];
    dp[0] = j[0].profit;
    
    // for(int i = 1;i<n;i++){
    //     // dp[i] = j[i].profit;
    //     dp[i] = 0;
    // }
    
    for(int i =1;i<n;i++){
        int including = j[i].profit;
        int index_of_latest_conflict = -1;
        for (int k=i-1;k>=0;k--){
            
            if (j[k].finish<=j[i].start){
                // jobs available opportunities
                // non overlapping
                // we find latest non conflicting
                index_of_latest_conflict  = k;
                break;     
            }

        }
            if(index_of_latest_conflict!=-1){
            including+= dp[index_of_latest_conflict];
                
            }

        dp[i] = max(including,dp[i-1]);
        
    }
    
    
    int ans = dp[n-1];
    delete [] dp; 
    // for(int i = 0;i<n;i++){
    //     cout<<dp[i]<<" ";
    // }
    // int maximum =0;
    // for(int i = 0;i<n;i++){
    //     if (dp[i]>=maximum){
    //         maximum = dp[i];
    //     }
    // }
    // cout<<maximum;
    
    
    cout<<ans;
    
    //Write your code here
    return 0;
}
