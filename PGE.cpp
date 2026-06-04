#include<bits/stdc++.h>
#include<stack>
#include<vector>
using namespace std;
vector<int> pge(vector<int>s){ //Previous Greater Element
     stack<int> st;
     int n=s.size();
    vector<int> ans(n);
      for(int i=0;i<=n-1;i++){
    while(!st.empty()&&s[st.top()]<=s[i]){ //just reverse <= i.e use >= for previous smallest element
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
