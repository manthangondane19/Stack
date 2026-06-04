#include<bits/stdc++.h>
#include<stack>
#include<vector>
using namespace std;
vector<int> nge_circular(vector<int>s){
     stack<int> st;
     int n=s.size();
    vector<int>ans(n);

   for(int i = 2*n-1; i >= 0; i--) //since we have to circle back to the start of the array to find nge of last array element we'll use i%n i from 2n-1 to 0 there we will encounter the same index twice ince i<n i%n==i
    {
        
        while(!st.empty() && s[st.top()] < s[i%n])
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
