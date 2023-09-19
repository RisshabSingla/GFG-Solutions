//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    vector<int> calcPrev(vector<int>&height, int cols){
        stack<int> s;
        s.push(-1);
        vector<int> prev(cols);
        for(int i = 0; i< cols; i++){
            while(s.top() != -1 && height[s.top()] >= height[i]){
                s.pop();
            }
            prev[i] = s.top();
            s.push(i);
        }
        return prev;
    }
    
    
    vector<int> calcNext(vector<int>&height,  int cols){
        stack<int> s;
        s.push(-1);
        vector<int> next(cols);
        for(int i = cols-1; i>=0; i--){
            while(s.top() != -1 && height[s.top()] >= height[i]){
                s.pop();
            }
            next[i] = s.top();
            s.push(i);
        }
        return next;
    }
    
    
    
    int calcArea(vector<int>&heights, int cols){
        
        stack<int> s;
        int maxArea = INT_MIN;
        // int cols = heights.size();

        for(int i = 0;i<=cols; i++){

            while(!s.empty() && (i == cols || heights[s.top()] >= heights[i])){
                int h = heights[s.top()];
                s.pop();
                int width;
                if(s.empty()){
                    width = i;
                }else{
                    width = i-s.top()-1;
                }
                maxArea = max(maxArea, width*h);
            }
            s.push(i);
        }

        return maxArea;
        
        
        
        // int maxArea = INT_MIN;
        
        // vector<int> prev = calcPrev(height,cols);
        // vector<int> next = calcNext(height,cols);
        
        // cout<<"prev is: ";
        // for(auto i: prev){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        
        
        // cout<<"next is: ";
        // for(auto i: next){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        
        
        // for(int i = 0; i<cols; i++){
        //     if(next[i] == -1){
        //         next[i] = cols;
        //     }
        //     int breadth = next[i] - prev[i]-1;
        //     int area = height[i]*breadth;
        //     // cout<<"Area is: "<<area<<endl;
        //     maxArea = max(maxArea, area);
        // }
        
        // return maxArea;
    }
    
    int maxArea(int matrix[MAX][MAX], int n, int m) {
        // Your code here
        int maxArea = INT_MIN;
        vector<int> height(m, 0);
        for(int i = 0; i<n; i++){
            
            for(int j = 0; j<m; j++){
                if(matrix[i][j] == 1){
                    height[j]++;
                }else{
                    height[j] = 0;
                }
            }
            int area = calcArea(height,m);
            // cout<<"For i: "<<i<<" area: "<<area<<endl;
            maxArea = max(area, maxArea);
            
        }
        
        return maxArea;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends