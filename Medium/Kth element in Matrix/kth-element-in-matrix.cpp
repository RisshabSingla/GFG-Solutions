//{ Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}

// } Driver Code Ends



int kthSmallest(int matrix[MAX][MAX], int n, int k)
{
  //Your code here
  // Approach 1: Brute Force
//   priority_queue<int> pq;
//   for(int i = 0; i<n; i++){
//       for(int j = 0; j<n; j++){
//           pq.push(matrix[i][j]);
//       }
//       int size = pq.size();
//       while(size>k){
//           pq.pop();
//           size--;
//       }
//   }
  
//   return pq.top();
  
  // Approach 2: Binary Search
  
  int low = matrix[0][0];
  int high = matrix[n-1][n-1];
  while(low<high){
      int mid = low + (high-low)/2;
      int count = 0;
      for(int i = 0; i<n; i++){
          int t = upper_bound(matrix[i], matrix[i]+n, mid) - matrix[i];
          count+=t;
          if(t == 0){
              break;
          }
      }
      if(count< k){
          low = mid+1;
      }else{
          high = mid;
      }
  }
  return low;
  
  
}
