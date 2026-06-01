#include<bits/stdc++.h>
#include<stack>
#include<vector>

vector<int> nge_circular(vector<int>s){
     stack<int> st;
     int n=s.size();
    vector<int>ans(n);

   for(int i = 2*n-1; i >= 0; i--) // i=2n-1 to 0 
    {
        
        while(!st.empty() && s[st.top()] <= s[i%5])
        {
            st.pop();
        }

        if(i<n)
        {
            if(st.empty()){
                ans[i]=-1;
            }else{
                ans[i]=s[st.top()];
            }
        }
        
        st.push(i%n);
        
    }
    return ans;
}