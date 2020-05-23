#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> dir={{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2}};

bool isvalid(int r,int c,vector<vector<int>>& board){
    if(r<0||c<0||r>=board.size()||c>=board[0].size()||board[r][c]==0) return false;
    return true;
}
int knight(int sr,int sc,int n,vector<vector<int>>& ans){
    if(n==ans.size()*ans[0].size()){
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[0].size();j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
        return 1;
    }
    for(int d=0;d<dir.size();d++){
        int r=sr+dir[d][0];
        int c=sc+dir[d][1];
        if(isvalid(r,c,ans)){
            ans[r][c]=n;
            if(knight(r,c,n+1,ans)){
                return 1;
            }
            else{
                ans[r][c]=-1;
            }
        }
    }
    return 0;
}

int main(){
    vector<int> v(8,-1);
    vector<vector<int>> ans(8,v);
    if(knight(0,0,1,ans))
    {
        cout<<1;
    }
    else cout<<"not found";
}

int knight(int sr,int sc,vector<vector<int>> ans, int n){
    if(n==ans.size()*ans[0].size()){
        
    }
}