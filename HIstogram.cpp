#include<bits/stdc++.h>
#include<stack>
#include<vector>
void histogram( vector<int> s){
    stack<int> st;
    int n=s.size();
    vector<int>left(n);
    vector<int>right(n);

    for(int i=0;i<n;i++){
      while(!st.empty()&&s[st.top()]>=s[i]){
        st.pop();
      }
      if(st.empty()){
        left[i]=-1;
      }else{
        left[i]=st.top();
      }
      st.push(i);
    }

    for(int i=0;i<n;i++){
        cout<<left[i]<<" ";
    }
}

int main(){
    vector<int> s={2,1,5,6,2,3};
    histogram(s);
}