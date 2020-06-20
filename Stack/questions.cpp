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

//leetcode 20: Valid Paranthesis
bool isValid(string s) {
    stack<char>st;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('||s[i]=='['||s[i]=='{'){
            st.push(s[i]);
        }
        else{
            if(st.size()==0)return false;
            else if(st.top()=='['&&s[i]!=']') return false;
            else if(st.top()=='{'&&s[i]!='}') return false;
            else if(st.top()=='('&&s[i]!=')') return false;
            else st.pop();
        }
    }
    return st.size()==0;        
}

// Leetcode 1021. Remove Outermost Parentheses
string removeOuterParentheses(string str) {
    string ans="";
    int count=0;
    for(int i=0;i<str.size();i++){
        if(str[i]=='('){
            if(count>0){
                ans+=str[i];
            }
            count++;
        }
        else if(str[i]==')'){
            if(count>1){
                ans+=str[i];
            }
            count--;
        }
    }
    return ans;
}

//leetcode 503. Next Greater Element 2
vector<int> nextGreaterElements(vector<int>& arr) {
    int n=arr.size();
    stack<int> st;  // we will push index
    vector<int> ans(n,-1);
    for(int i=0;i<2*n;i++){
        int idx=i%n;
        while(st.size()!=0 && arr[st.top()]<arr[idx]){
            ans[st.top()]=arr[idx];
            st.pop();    
        }
        st.push(idx);
    }
    return ans;
}

// leetcode 901. Online Stock Span

// class StockSpanner {
//     stack<pair<int,int>> st;    //first is position and second is price
//     int i;
// public:
//     StockSpanner() {
//         st.push({-1,-1});
//         i=0;
//     }
    
//     int next(int price) {
//         int ans=1;
//         while(st.top().first!=-1&&st.top().second<=price){
//             st.pop();
//         }
//         ans=i-st.top().first;
//         st.push({i,price});
//         i++;
//         return ans;
//     }
// };

// /**
//  * Your StockSpanner object will be instantiated and called as such:
//  * StockSpanner* obj = new StockSpanner();
//  * int param_1 = obj->next(price);
//  */

//Leetcode. 921 Minimum Add to Make Parentheses Valid
int minAddToMakeValid(string str) {
    stack<int> st;
    st.push(-1);
    for(int i=0;i<str.length();i++){            
        if(st.top()!=-1 && str[i]==')' && str[st.top()]=='('){
            st.pop();                              
        }
        else{
            st.push(i);
        }            
    }
    return st.size()-1;        
}

//Leetcode. 1249 Minimum Remove to Make Valid Parentheses
string minRemoveToMakeValid(string str) {
    stack<int> st;
    st.push(-1);
    vector<bool> marked(str.length(),false);
    for(int i=0;i<str.length();i++){
        if(st.top()!=-1&&str[i]==')'&&str[st.top()]=='('){
            marked[st.top()]=marked[i]=true;
            st.pop();
            
        }
        else if(str[i]=='(' || str[i]==')'){
            st.push(i);
        }
        else{
            marked[i]=true;
        }
    }
    string ans="";
    for(int i=0;i<str.length();i++){
        if(marked[i]){
            ans+=str[i];
        }
    }
    return ans;
}

//leetcode 32. Longest Valid Parentheses
int longestValidParentheses(string str) {
    stack<int>st;
    st.push(-1);
    int len=0;
    for(int i=0;i<str.length();i++){
        if(st.top()!=-1 && str[i]==')' && str[st.top()]=='('){
            st.pop();
            len=max(len,i-st.top());
        }
        else{
            st.push(i);
        }
    }
    return len;
}

//Leetcode 735. Asteroid Collision
vector<int> asteroidCollision(vector<int>& arr) {
    stack<int> st;
    st.push(-1);
    for(int i=0;i<arr.size();i++){
        if(arr[i]>0){
            st.push(arr[i]);
        }
        else{
            while(st.top()!=-1 && st.top()>0 && st.top()<-arr[i]){
                st.pop();
            }
            if(st.top()!=-1 && st.top()==-arr[i]){
                st.pop();
            }
            else if(st.top()==-1 || st.top()<0){
                st.push(arr[i]);
            }
        }
    }
    vector<int> ans(st.size()-1);
    for(int i=st.size()-2;i>=0;i--){
        ans[i]=st.top();
        st.pop();
    }
    return ans;
    
}


//===========================================================================================================
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