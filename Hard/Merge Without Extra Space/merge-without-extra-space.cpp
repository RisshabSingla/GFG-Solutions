//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
    
        void swapElem(long long arr1[], long long arr2[], int index1, int index2){
            if(arr1[index1]> arr2[index2]){
                swap(arr1[index1], arr2[index2]);
            }
        }
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // code here 
            // Approach 1: Using 2 pointers 
            // int first = n-1;
            // int second = 0;
            // while(first>=0 && second<m){
            //     if(arr1[first] > arr2[second]){
            //         int temp = arr1[first];
            //         arr1[first] = arr2[second];
            //         arr2[second] = temp;
            //         first--;
            //         second++;
            //     }else{
            //         break;
            //     }
            // }
            
            // sort(arr1, arr1+n);
            // sort(arr2, arr2+m);
            
            
            // Approach 2: Using Gap Method -> Shell Sort
            int len = n+m;
            int gap = len/2 + len%2;
            while(gap>0){
               int left = 0;
               int right = left + gap;
               while(right<len){
                   if(left<n && right>= n){
                        // arr1 and arr2
                        swapElem(arr1, arr2, left, right-n);
                   }else if(left>=n){
                       // arr2 and arr2
                       swapElem(arr2,arr2, left-n, right-n);
                   }else{
                       // arr1 and arr1
                       swapElem(arr1,arr1, left, right);
                   }
                   left++;
                   right++;
               }
               if(gap == 1){
                   break;
               }
               gap = gap/2 + gap%2;
            }
        } 
};

//{ Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 

// } Driver Code Ends