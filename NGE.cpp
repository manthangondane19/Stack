#include<bits/stdc++.h>
#include<stack>
#include<vector>
using namespace std;

vector<int> ngeLtoR(vector<int>s){
    stack<int> st;
    int n=s.size();
    vector<int>ans(n);
       st.push(0);
    for(int i=1;i<n; i++){ // (alternate) this approach is from left to right useful for previous greater, previous smaller questions
        while(!st.empty()&&s[st.top()]<s[i]){
            int idx=st.top();
           st.pop();
            ans[idx]=s[i];
        }
        st.push(i);

        }
        
        while(!st.empty()){

            int idx=st.top();
            ans[idx]=-1;
            st.pop();
    }

    return ans;
}

vector<int> ngeRtoL(vector<int>s){ //best appraoch going right to left
    stack<int> st;
    int n=s.size();
    vector<int>ans(n);

    for(int i=n-1;i>=0;i--){
        while(!st.empty()&&s[st.top()]<s[i]){
            st.pop();
        }

        if(st.empty()){
            ans[i]=-1;
            
        }else{
            ans[i]=s[st.top()];
        }

        st.push(i);
    }

    return ans;
}
