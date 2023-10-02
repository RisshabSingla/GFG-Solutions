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
        //iterating over the matrix elements.
        for(int i = 0; i < mat.size() ; i++){
            for(int j = 0; j < mat[i].size(); j++){
                //calling the findPath function to find if target string is present
                //starting from the current element.
                count += findPath(mat, target, i, j, 0);
            }
        }
        //returning the total count of occurrences of the target string.
        return count;
    }
    
    //Function to find the target string path starting from a particular element.
    int findPath(vector<vector<char> > mat, string target, int startX, int startY, int targetIndex){
        
        //if the current element is out of bounds, return 0.
        if(startX < 0 || startY < 0 || startX >= mat.size() || startY >= mat[startX].size()){
            return 0;
        }
        
        //storing the original value of the current element.
        char original = mat[startX][startY];
        
        //if the original value of the current element is not equal to the target character,
        //return 0.
        if(original != target[targetIndex])
            return 0;
        
        //if we reach the last character of the target string, return 1 as path found.
        if(targetIndex == target.size() - 1)
            return 1;

        int count = 0;
        //changing the value of the current element to '\0' to mark it as visited
        //and avoid returning back to this element.
        mat[startX][startY] = '\0';

        //recursively calling findPath function for all possible neighboring elements.
        count += findPath(mat, target, startX+1, startY, targetIndex+1);
        count += findPath(mat, target, startX, startY+1, targetIndex+1);
        count += findPath(mat, target, startX-1, startY, targetIndex+1);
        count += findPath(mat, target, startX, startY-1, targetIndex+1);
        
        //restoring the original value of the current element.
        mat[startX][startY] = original;
        //returning the count of paths found.
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