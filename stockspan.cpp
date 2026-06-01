#include<bits/stdc++.h>
#include<stack>
#include<vector>

vector<int> stockspan(vector<int>s){ 
     stack<int> st;
     int n=s.size();
    vector<int> ans(n);
     for(int i=0;i<n;i++){
        while(!st.empty()&&s[st.top()]<=s[i]){
            st.pop();
        }
        if(st.empty()){
            ans[i]=i+1;
        }else{
          ans[i]=i-st.top();
        }
        st.push(i);

    }
return ans;
}