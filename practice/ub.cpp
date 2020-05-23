#include<iostream>
#include<vector>
using namespace std;
vector<int> uberproblem(vector<int> ip){
    vector<int> ans(ip.size());
    int p=1;
    for(int i=0;i<ip.size();i++){
        p=p*ip[i];
    }
    for(int i=0;i<ip.size();i++){
        ans[i]=p/ip[i];
    }
    return ans;
}

int main(){
    vector<int>ip={1,2,3,4,5};
    vector<int> ans=uberproblem(ip);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}