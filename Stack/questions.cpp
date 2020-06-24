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

//Leetcode 84. Largest Rectangle in Histogram
int largestRectangleArea1(vector<int>& heights) {
    vector<int> nsr=nsor(heights);
    vector<int> nsl=nsol(heights);
    int max_=0;
    for(int i=0;i<heights.size();i++){
        int w=nsr[i]-nsl[i]-1;
        max_=max(max_,w*heights[i]);
    }
    return max_;
}
int largestRectangleArea2(vector<int>& arr) {
    stack<int> st;
    st.push(-1);
    int n=arr.size();
    int area=0;
    for(int i=0;i<n;i++){
        while(st.top()!=-1 && arr[st.top()]>arr[i]){
            int idx=st.top();
            st.pop();
            int w=i-st.top()-1;
            area=max(area,w*arr[idx]);
        }
        st.push(i);
    }
    while(st.top()!=-1){
        int idx=st.top();
        st.pop();
        int w=n-st.top()-1;
        area=max(area,w*arr[idx]);
    }
    return area;
}

//Leetcode 85. Maximal Rectangle
int maximalRectangle(vector<vector<char>>& matrix) {
    if(matrix.size()==0||matrix[0].size()==0)return 0;
    int n=matrix.size();
    int m=matrix[0].size();
    vector<int> base(m,0);
    int max_=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int ch=matrix[i][j]-'0';
            if(ch==1){
                base[j]+=ch;
            }
            else{
                base[j]=0;
            }
        }
        max_=max(max_,maxrect(base));           
    }
    return max_;
}

//Leetcode 42. Trapping Rain Water
int trap1(vector<int>& height) {
    int n=height.size();
    if(n==0)return 0;
    vector<int>ngl(n,height[0]);
    vector<int>ngr(n,height[n-1]);
    for(int i=1;i<n;i++){
        if(height[i]>ngl[i-1]){
            ngl[i]=height[i];
        }     
        else{
            ngl[i]=ngl[i-1];
        }
    }
    for(int i=n-2;i>=0;i--){
        if(height[i]>ngr[i+1]){
            ngr[i]=height[i];
        }     
        else{
            ngr[i]=ngr[i+1];
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        int len=min(ngl[i],ngr[i]);
        ans+=len-height[i];
    }
    return ans;
}

int trap2(vector<int>& height) {

}

int trap3(vector<int>& height) {
    int n=height.size();
    int water=0;
    int li=0,ri=n-1,lmax=0,rmax=0;
    while(li<ri){
        lmax=max(height[li],lmax);
        rmax=max(height[ri],rmax);
        if(lmax>=rmax){
            water+=rmax-height[ri--];
        }
        else{
            water+=lmax-height[li++];
        }
    }
    return water;
}

// Leetcode 155. Min Stack
// One solution is by using two stacks
class MinStack {
    stack<long> st;
    long minsf=0; 
    public:
    MinStack() {
        minsf=0;
    }
    
    void push(int x) {
        if (st.size() == 0)
        {
            st.push(x);
            minsf = x;
            return;
        }
        if(x>=minsf){
            st.push(x);
        }              
        else{
            st.push(2*(long)x-minsf);
            minsf=x;            
        }
    }
    
    void pop() {
        if(st.top()<minsf){
            minsf=2*minsf - st.top();
        }
        st.pop();        
    }
    
    int top() {
        if(st.top()>minsf){
            return st.top();
        }
        else{
            return (int)minsf;
        }
    }
    
    int getMin() {
        return (int)minsf;        
    }
};


// Leetcode 946. Validate Stack Sequences
bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack<int> st;
    int idx=0;
    for(int i=0;i<pushed.size();i++){
        st.push(pushed[i]);
        while(st.size()!=0 && st.top()==popped[idx]){
            st.pop();
            idx++;
        }            
    }
    return st.size()==0;        
}

// Leetcode 402. Remove K Digits
string removeKdigits(string num, int k) {
    stack<char> st;
    for(int i=0;i<num.size();i++){
        while(st.size()!=0 && k>=1 && st.top()>num[i]){
            st.pop();
            k--;
        }
        st.push(num[i]);
    }
    while(k--){
        st.pop();
    }
    
    string ans="";
    while(st.size()!=0){
        ans+=st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    int idx=0;
    while(ans[idx]=='0'){
        ans=ans.substr(1);
    }
    return (ans.size()==0)?"0":ans;
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