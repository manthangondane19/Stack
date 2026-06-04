#include<bits/stdc++.h>
#include<stack>
#include<vector>
using namespace std;
vector<int> dailytemp(vector<int>s){
     stack<int> st;
     int n=s.size();
    vector<int>ans(n);

    st.push(0);
    for(int i=1;i<n;i++){
        while(!st.empty()&&s[st.top()]<s[i]){
            int idx=st.top();
            st.pop();
            ans[idx]=i-idx;
        }
             st.push(i);
    }
     while(!st.empty()){
            int idx=st.top();
            st.pop();
            ans[idx]=0;
        }
  return ans;
}
