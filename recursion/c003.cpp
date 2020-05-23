#include<iostream>
#include<vector>
using namespace std;

vector<string> words ={":;","abc","def","ghi","jkl","mno","pqrs","tuv","wx","yz","*#","&%@"};

vector<string> possiblestrings01(string s){
    vector<string> ans;
    if(s.size()==0){
        ans.push_back("");
        return ans;
    }
    int idx=s[0]-'0';
    int idx1=s[1]-'0';
    string word=words[idx];

    vector<string> smallans=possiblestrings01(s.substr(1));
    for(string str:smallans){
        for(int i=0;i<word.size();i++){
            ans.push_back(word[i]+str);
        }
    }
    if(idx==1&&idx1<2&&s.size()>=2){
        int id=10*idx + idx1;
        string word1=words[id];

        vector<string> smallans1=possiblestrings01(s.substr(2));
        for(string str:smallans1){
            for(int i=0;i<word1.size();i++){
                ans.push_back(word1[i]+str);
            }
        }
    }
    return ans;
}

void possiblestrings02(string s,string ans){
    if(s.size()==0){        
        cout<<ans<<endl;
        return;
    }
    int idx=s[0]-'0';
    int idx1=s[1]-'0';
    string word=words[idx];
    for(int i=0;i<word.size();i++){
        possiblestrings02(s.substr(1),ans+word[i]);
    }
    if(idx==1&&idx1<=1&&s.size()>=2){
        string word1=words[idx1];
        for(int i=0;i<word1.size();i++){
            possiblestrings02(s.substr(2),ans+word1[i]);
        }
    }
    return;
}



int main(){
    string s="234";
    possiblestrings02(s,"");
    return 0;
}