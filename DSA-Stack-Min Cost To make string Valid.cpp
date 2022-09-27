// Problem link- https://www.codingninjas.com/codestudio/problems/minimum-cost-to-make-string-valid_1115770?leftPanelTab=0
// TC-O(N) SC-O(N)

#include <bits/stdc++.h> 
int findMinimumCost(string str) 
{
  // Write your code here
    stack<char>stk;
    int c=0;
    int ans=0;
    
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='{')
        {
            stk.push(str[i]);
        }
        else
        {
            if(!stk.empty())
            {
                stk.pop();
            }
            else
            {
                stk.push('{');
                ans+=1;
            }
        }
    }
    
    if(stk.empty())
    {
        return ans;
    }  
 
    while(!stk.empty())
    {
       c++;
       stk.pop();
    }
    
    if(c%2==0)
    {
        return (ans + c/2);
    }
    
    return -1;
}
