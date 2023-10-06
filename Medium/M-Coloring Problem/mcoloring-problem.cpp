//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
        
    bool canColor(bool adj_mat[101][101], int index, int color, vector<int> &given_color, int nodes){
        bool possible = true;
        for(int i = 0; i<nodes; i++){
            if(adj_mat[index][i]){
                // edge between index and i 
                if(given_color[i] == color ){
                    // already given the color
                    return false;
                }
            }
        }
        return true;
    }
    bool isPossible(bool adj_mat[101][101], int nodes, int colors, int index, vector<int> &given_color){
        if(index == nodes){
            return true;
        }
        
        for(int i = 0; i<colors; i++){
            if(canColor(adj_mat, index, i, given_color,nodes)){
                given_color[index] = i;
                if(isPossible(adj_mat, nodes, colors, index+1, given_color)){
                    return true;
                }
                given_color[index] = -1;
            }
        }
        return false;
    }
    
    bool graphColoring(bool adj_mat[101][101], int colors, int nodes) {
        // your code here
        
        vector<int> given_color(nodes, -1);
        for(int i = 0; i<colors; i++){
            given_color[0] = i;
            if(isPossible(adj_mat, nodes, colors, 1, given_color)){
                return true;
            }
            given_color[0] = -1;
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends