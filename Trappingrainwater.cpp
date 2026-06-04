#include<bits/stdc++.h>
#include<stack>
#include<vector>
using namespace std;

int trapping(vector<int>s){
    int n=s.size();

    //left max
    vector<int>lefmax(n);
    leftmax[0]=s[0];
    
    for(int i=1;i<n;i++){
        leftmax[i]=max(leftmax[i-1],s[i]); //prefix max
    }
    
    //rightmax
    vector<int>rightmax(n);
    
    rightmax[n-1]=s[n-1];
    
    for(int i=n-2;i>=0;i--){
        rightmax[i]=max(rightmax[i+1],s[i]); //suffix max
    }

    //accumalation of ans
    vector<int>ans(n);

    for(int i=0;i<n;i++){
        ans[i]=min(leftmax[i],rightmax[i])-s[i];
    }

    int endans= accumulate(ans.begin(),ans.end(),0);
   
    return endans;
}
