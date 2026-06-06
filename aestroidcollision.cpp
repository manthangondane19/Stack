   #include<bits/stdc++.h>
   using namespace std;
   vector<int> asteroidCollision(vector<int>& s) {
        stack<int>st;
        int n=s.size();
        st.push(s[0]);
        for(int i=1;i<n;i++){
     bool destroyed=false;
     while(!st.empty()&&st.top()>0&&s[i]<0){
        if(abs(st.top())==abs(s[i])){
            st.pop();
            destroyed=true;
            break;
        }else if(abs(st.top())<abs(s[i])){
                 st.pop();
        }else if(abs(st.top())>abs(s[i])){
            destroyed=true;
            break;
        }
     }
     if(!destroyed){
        st.push(s[i]);
     }
        }

        int p=st.size();
        vector<int>ans(p);
        for(int i=p-1;i>=0;i--){
            ans[i]=st.top();
            st.pop();
        }

        return ans;
        
    }