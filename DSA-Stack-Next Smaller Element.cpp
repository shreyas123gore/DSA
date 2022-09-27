//T(N)=O(N) S(N)=O(N)
#include <stack>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int>stk;
    stk.push(-1);
    vector<int> ans(n);
    
    for(int i=n-1;i>=0;i--)
    {
            while(stk.top()>=arr[i])
            {
               stk.pop();
            }
            ans[i]=stk.top();
            stk.push(arr[i]); 
    }
    
    return ans;
}