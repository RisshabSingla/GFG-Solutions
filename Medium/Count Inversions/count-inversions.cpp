//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    long long int merge(long long arr[], long long start, long long end, long long mid){
        vector<long long> temp;
        
        long long first = start;
        long long second = mid+1;
        long long int count = 0;
        
        while(first<=mid && second<=end){
            if(arr[first]<=arr[second]){
                temp.push_back(arr[first]);
                first++;
            }else{
                // right is smaller
                count+=(mid-first+1);
                temp.push_back(arr[second]);
                second++;
            }
        }
        
        while(first<=mid){
            temp.push_back(arr[first]);
            first++;
        }
        
        while(second<=end){
            temp.push_back(arr[second]);
            second++;
        }
        
        for(int i = start; i<=end; i++){
            arr[i] = temp[i-start];
        }
        return count;
        
    }
    
    long long int mergeSort(long long arr[], long long start, long long end){
        if(start == end){
            return 0;
        }
        long long mid = start + (end-start)/2;
        long long int a = mergeSort(arr, start, mid);
        long long int b = mergeSort(arr, mid+1, end);
        long long int c = merge(arr, start,end, mid);
        return (a+b+c);
    }
    
    
    long long int inversionCount(long long arr[], long long n)
    {
        // Approach 1: Brute Force
        // long long int count = 0;
        // for(int i = 0; i<n; i++){
        //     for(int j = i+1; j<n; j++){
        //         if(arr[i]> arr[j]){
        //             count++;
        //         }
        //     }
        // }
        // return count;
        
        return mergeSort(arr, 0, n-1);
        
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends