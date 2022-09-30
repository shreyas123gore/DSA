//MAXIMUM RECTANGLE IN A BINARY MATRIX
//https://practice.geeksforgeeks.org/problems/max-rectangle/1

//T(N)=O(n*m)

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
  
     vector<int> findnextR(vector<int>heights,int n)
    {
        stack<int>stk;
        stk.push(-1);
        vector<int> ans(n);
    
        for(int i=n-1;i>=0;i--)
        {
            int curr=heights[i];
            
            /*reason-in stack top we will store index so when comparing we need to write a[i] for value              to be compared. Actual reason in our ans we need to store index of next smallest elements                after finding that heights[stk.top()]<curr which means it is smallest hence we store                    stk.top()(AS IT CONTAINS INDEX i.e WE REQUIRED) which is easy
            */
            while(stk.top()!=-1 && heights[stk.top()]>=curr) 
            {
               stk.pop();
            }
            
            ans[i]=stk.top();
            stk.push(i); 
        }
    
        return ans;
    }
    
    vector<int> findnextL(vector<int>heights,int n)
    {
        stack<int>stk;
        stk.push(-1);
        vector<int> ans(n);
    
      for(int i=0;i<n;i++)
        {
            int curr=heights[i];
            
            /*reason-in stack top we will store index so when comparing we need to write a[i] for value              to be compared. Actual reason in our ans we need to store index of next smallest elements                after finding that heights[stk.top()]<curr which means it is smallest hence we store                    stk.top()(AS IT CONTAINS INDEX i.e WE REQUIRED) which is easy
            */
            while(stk.top()!=-1 && heights[stk.top()]>=curr) 
            {
               stk.pop();
            }
            
            ans[i]=stk.top();
            stk.push(i); 
        }
    
        return ans;
    }
    
    
    
    
    int largestRectangleArea(vector<int>& heights)
    {
        int maxarea=0;
        int n=heights.size();
        
        vector<int>prev;
        prev=findnextL(heights,n);
        
        vector<int>next;
        next=findnextR(heights,n);
        
        for(int i=0;i<n;i++)
        {
           /*to handle [2 2 2] where next and prev for all -1 in such case make any one among prev and next to n so that when subtract length to get total breadth
           */
           if(next[i]==-1) 
           {
              next[i]=n;
           }
            
           maxarea=max(maxarea,(next[i]-prev[i]-1)*heights[i]);
        }
        
        return maxarea;
    }
 
    
    int maxArea(int M[MAX][MAX], int n, int m)
    {
        // Your code here
        vector<int> heights(m,0);
        int maxarea=INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(heights[j]!=0 && M[i][j]==0)
                {
                    heights[j]=0;
                }
                else
                {
                   heights[j]=heights[j]+M[i][j];  
                }
            }
            
            int area=largestRectangleArea(heights);
            
            maxarea=max(area,maxarea);
        }
        
        return maxarea;
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