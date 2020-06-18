#include<iostream>
#include<stack>
#include<vector>
using namespace std;

//next greater on right
vector<int> ngor(vector<int>& arr){
    stack<int> st;  // we will push index
    vector<int> ans(arr.size(),arr.size());
    for(int i=0;i<arr.size();i++){
        while(st.size()!=0 && arr[st.top()]<arr[i]){
            ans[st.top()]=i;
            st.pop();    
        }
        st.push(i);
    }
    return ans;
}

//next greater on left
vector<int> ngol(vector<int>& arr){
    stack<int> st;  // we will push index
    vector<int> ans(arr.size(),-1);
    for(int i=arr.size()-1;i>=0;i--){
        while(st.size()!=0 && arr[st.top()]<arr[i]){
            ans[st.top()]=i;
            st.pop();    
        }
        st.push(i);
    }
    return ans;
}

//next smaller on right
vector<int> nsor(vector<int>& arr){
    stack<int> st;  // we will push index
    vector<int> ans(arr.size(),arr.size());
    for(int i=0;i<arr.size();i++){
        while(st.size()!=0 && arr[st.top()]>arr[i]){
            ans[st.top()]=i;
            st.pop();    
        }
        st.push(i);
    }
    return ans;
}

//next smaller on left
vector<int> nsol(vector<int>& arr){
    stack<int> st;  // we will push index
    vector<int> ans(arr.size(),-1);
    for(int i=arr.size()-1;i>=0;i--){
        while(st.size()!=0 && arr[st.top()]>arr[i]){
            ans[st.top()]=i;
            st.pop();    
        }
        st.push(i);
    }
    return ans;
}
void solve(){
    vector<int> arr{-1,5,3,4,8,10,9,11,0};
    // vector<int>ans1=ngor(arr);
    // vector<int>ans2=ngol(arr);
    // vector<int>ans3=nsor(arr);
    // vector<int>ans4=nsol(arr);
    // for(int i=0;i<arr.size();i++){
    //     cout<<ans1[i]<<" ";
    // }
}

int main(){
    solve();
}