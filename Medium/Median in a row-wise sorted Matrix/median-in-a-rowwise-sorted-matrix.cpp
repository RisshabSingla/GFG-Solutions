//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
// #include<algorithm>
class Solution{   
public:
    int findCount(vector<vector<int>> &matrix, int rows, int mid){
        int count = 0;
        for(int i = 0; i<rows;i++){
            auto itr = upper_bound(matrix[i].begin(),matrix[i].end(), mid );
            int index = itr- matrix[i].begin();
            count+=index;
        }
        return count;
    }
    int median(vector<vector<int>> &matrix, int rows, int cols){
        // code here    
        int total_elem = rows*cols;
        int low = INT_MAX;
        int high = INT_MIN;
        for(int i = 0;i<rows; i++){
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][cols-1]);
        }
        int req = total_elem/2;
        while(low<=high){
            int mid = low + (high-low)/2;
            int smallerThanMid = findCount(matrix, rows, mid);
            if(smallerThanMid<= req){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return low;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends