#include<iostream>
#include<vector>
#include<string>
using namespace std;

int permutations_void(string s,string ans){
    if(s.size()==0){
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    for(int  i=0;i<s.size();i++){
        string smallstr= s.substr(0,i) + s.substr(i+1);
        count += permutations_void(smallstr,ans+s[i]);
    }
    return count;
}

vector<string> permutations_ret(string s){    
    vector<string> ans;
    if(s.size()==1){
        ans.push_back(s);
        return ans;
    }
    char ch=s[0];
    vector<string> smallans=permutations_ret(s.substr(1));
    for(string str:smallans){
        for(int i=0;i<=str.size();i++){
            ans.push_back(str.substr(0,i)+ch+str.substr(i));
        }
    }
    return ans;
}
int main(){
    string s="abc";
    //cout<<permutations_void(s,"")<<endl;
    vector<string> ans=permutations_ret("abc");
    for(int i=0;i<s.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}