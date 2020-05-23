#include<iostream>
#include<vector>
using namespace std;


vector<string> subsequence(string s){
    vector<string> ans;
    if(s.size()==0){
        ans.push_back("");
        return ans;
    }
    char ch=s[0];
    vector<string> smallans=subsequence(s.substr(1));
    for(string sa:smallans){
        ans.push_back(sa);
        ans.push_back(ch+sa);
    }
    return ans;
}

int main(){
    string s = {"abc"};
    vector<string> ans= subsequence(s);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}