//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int findOccurrence(vector<vector<char> > &mat, string target){
        int count = 0;
        for(int i = 0; i < mat.size() ; i++){
            for(int j = 0; j < mat[i].size(); j++){
                count += findPath(mat, target, i, j, 0);
            }
        }
        return count;
    }
    
    int findPath(vector<vector<char> > mat, string target, int startX, int startY, int targetIndex){
        
        if(startX < 0 || startY < 0 || startX >= mat.size() || startY >= mat[startX].size()){
            return 0;
        }
        
        char original = mat[startX][startY];
        

        if(original != target[targetIndex])
            return 0;
        
        if(targetIndex == target.size() - 1)
            return 1;

        int count = 0;
        mat[startX][startY] = '\0';

        count += findPath(mat, target, startX+1, startY, targetIndex+1);
        count += findPath(mat, target, startX, startY+1, targetIndex+1);
        count += findPath(mat, target, startX-1, startY, targetIndex+1);
        count += findPath(mat, target, startX, startY-1, targetIndex+1);
        
        mat[startX][startY] = original;
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin >> R >> C;
        vector<vector<char> > mat(R);
        for (int i = 0; i < R; i++) {
            mat[i].resize(C);
            for (int j = 0; j < C; j++) cin >> mat[i][j];
        }
        string target;
        cin >> target;
        Solution obj;
        cout<<obj.findOccurrence(mat,target)<<endl;
    }
}

// } Driver Code Ends