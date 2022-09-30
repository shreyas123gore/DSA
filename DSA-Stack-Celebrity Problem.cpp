//CELEBRITY PROBLEM

//Approach-1 Brute Force

/*
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
     
        // code here 
        for(int i=0;i<n;i++)
       {
           int c=0;
           for(int j=0;j<n;j++)
           {
                   if(M[i][j]==0)
                   {
                       c++;
                   }
           }
           
           if(c==n)
           {
              c=0;
              for(int j=0 ;j<n;j++)
              {
                  if(M[j][i]==1)
                  {
                      c++;
                  }
              }
              
              if(c==(n-1))
              {
                  return i;
              }
           }
       }
       
       return -1;
      
    }
};
*/

//Approach-2 Using Stack

//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int> stk;
        
        for(int i=0;i<n;i++)
        {
            stk.push(i);
        }
        
        while(stk.size()>1)
        {
            int a=stk.top();
            stk.pop();
            int b=stk.top();
            stk.pop();
            
            if(M[a][b]==1 && M[b][a]==0)
            {
               stk.push(b);
            }
            
             if(M[a][b]==0 && M[b][a]==1)
            {
               stk.push(a);
            }
        }
        
        int k=stk.top();
        int c=0;
        
        for(int i=0;i<n;i++)
        {
            if(M[k][i]==0)
            {
               c++; 
            }
        }
        
        if(c==n)
        {
          c=0;
          for(int i=0;i<n;i++)
          {
            if(M[i][k]==1)
            {
               c++; 
            }
          }
          
          if(c==n-1)
          {
              return k;
          }
        }
        
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends