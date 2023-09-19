//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int distinct(vector<vector<int>> matrix, int n)
    {
        // code here
        set<int> common;
        for(int i = 0;i<n; i++){
            // cout<<"Inserting: "<<matrix[0][i]<<endl;
            common.insert(matrix[0][i]);
        }
        
        for(int i = 1; i<n;i++){
            set<int> new_common;
            for(auto j: common){
                // cout<<j<<" ";
                if(find(matrix[i].begin(), matrix[i].end(), j) != matrix[i].end()){
                    // cout<<"Removing: "<<j<<endl;
                    // common.erase(j);
                    new_common.insert(j);
                }
            }
            common = new_common;
            // cout<<endl;
        }
        
        return common.size();
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> M(N, vector<int>(N, 0));
        for(int i = 0;i < N*N; i++)
            cin>>M[i/N][i%N];
        
        Solution ob;
        cout<<ob.distinct(M, N)<<"\n";
    }
    return 0;
}
// } Driver Code Ends