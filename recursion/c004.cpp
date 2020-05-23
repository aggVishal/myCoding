//decoding numeric data

#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<char> words={'\0','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

vector<string> possiblestrings(string s){
    vector<string> ans;
    if(s.size()==0){
        ans.push_back("");
        return ans;
    }
    if(s[0]=='0'){
        ans.push_back("");
        return ans;
    }
    int idx=s[0]-'0';
    int idx1=s[1]-'0';
    char word=words[idx];
    
    vector<string> smallans=possiblestrings(s.substr(1));
    for(string str: smallans){
        ans.push_back(word+str);
    }

    int id=10*idx+idx1;
    char word1=words[id];
    if(id>9 && id<27 && s.size()>=2 ){
        vector<string> smallans=possiblestrings(s.substr(2));
        for(string str: smallans){
            ans.push_back(word1+str);
        }        
    }
    return ans;
} 

int main(){
    string s="1234";
    vector<string> ans=possiblestrings(s);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}