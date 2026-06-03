#include<bits/stdc++.h>
#include<stack>
#include<vector>
using namespace std;
int histogram(vector<int> s)
{
    stack<int> st;

    int n = s.size();

    vector<int> left(n);
    vector<int> right(n);
    vector<int>ans(n);

    // Previous Smaller Element
    for(int i = 0; i < n; i++){
    
        while(!st.empty() && s[st.top()] >= s[i]){
            st.pop();
        }

        if(st.empty()){

            left[i] = -1;
        }
        else
        {
            left[i] = st.top();
        }

        st.push(i);
    }

    // Clear stack
    while(!st.empty()){
    
        st.pop();
    }

    // Next Smaller Element
    for(int i = n - 1; i >= 0; i--){
    
        while(!st.empty() && s[st.top()] >= s[i]){
        
            st.pop();
        }

        if(st.empty()){
        
            right[i] = n;
        }
        else
        {
            right[i] = st.top();
        }

        st.push(i);
    }

    int maxArea = 0;

    // Calculate maximum area
    for(int i = 0; i < n; i++){
    
        int width=0;
        int area=0;

         width = right[i] - left[i] - 1;

         area = width * s[i];

       ans[i]=area; 
    }

    int endans=0;
    endans=*max_element(ans.begin(),ans.end());
    return endans;
}


