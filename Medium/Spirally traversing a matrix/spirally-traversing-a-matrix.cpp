//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        int upper_row = 0;
        int lower_row = r-1;
        int left_col = 0;
        int right_col = c-1;
        int elem = r*c;
        vector<int> ans(elem);
        int index = 0;
        while(index<elem){
            // left to right
            for(int i = left_col; i<=right_col && index<elem;i++){
                ans[index++] = matrix[upper_row][i];
            }
            
            upper_row++;
            // top to bottom
            for(int i = upper_row; i<=lower_row && index<elem; i++){
                ans[index++] = matrix[i][right_col];
            }
            
            right_col--;
            
            // right to left
            for(int i = right_col; i>=left_col && index<elem; i--){
                ans[index++] = matrix[lower_row][i];
            }
            
            lower_row--;
            
            // bottom to top
            for(int i = lower_row; i>=upper_row && index<elem;i--){
                ans[index++] = matrix[i][left_col];
            }
            left_col++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends