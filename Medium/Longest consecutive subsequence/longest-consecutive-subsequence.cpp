//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
      //Your code here
      unordered_map<int, bool> freq;
      int min_element = INT_MAX;
      int max_element = INT_MIN;
      for(int i = 0; i<n ; i++){
          freq[arr[i]] = false;
          min_element = min(min_element, arr[i]);
          max_element = max(max_element, arr[i]);
      }
      int max_length = 1;
      for(int start = min_element; start<=max_element; start++){
          int length = 0;
          int number = start;
          if(freq.count(start) == 0 || freq[start]){
              continue;
          }
          
          while(freq.count(number)){
              freq[number] = true;
              number++;
              length++;
          }
          max_length = max(max_length, length);
      }
      return max_length;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends