//https://practice.geeksforgeeks.org/problems/equal-sum0810/1

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string equilibrium(int *arr, int n)
    {
        // code 
        int totalsum=0;
        for(int i=0;i<n;i++)
        {
           totalsum+=arr[i];
        }
        
        int lsum=0;
        int rsum=totalsum;
        for(int i=0;i<n;i++)
        {
            rsum=rsum-arr[i];
            
            if(lsum==rsum)
            {
                return "YES";
            }
            
            lsum+=arr[i];
         
           
        }
        
        return "NO";
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.equilibrium(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
