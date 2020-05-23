#include<iostream>
#include<vector>
using namespace std;

//subsequence(combinations)******************************
vector<string> sub_ret(string str){
    vector<string> a;
    if(str.length()==0){
        a.push_back("");
        return a;
    }

    vector<string> smallans=sub_ret(str.substr(1));
    for(string s:smallans){
        a.push_back(str[0]+s);
        a.push_back(s);
    }
    return a;
}
int sub_void(string str,string ans){
    if(str.length()==0){
        cout<<ans<<" ";
        return 1;
    }
    int count=0;
    count+=sub_void(str.substr(1),ans+str[0]);
    count+=sub_void(str.substr(1),ans);
    return count;
}

//permutations******************************************
vector<string> permu_ret(string str){
    vector<string> ans;
    if(str.length()==0){
        ans.push_back("");
        return ans;
    }
    char ch=str[0];
    vector<string>smallans=permu_ret(str.substr(1));
    for(string s:smallans){
        for(int i=0;i<=s.length();i++){
            ans.push_back(s.substr(0,i)+ch+s.substr(i));
        }
    }
    return ans;
}
int permu_void(string str,string ans){
    if(str.length()==0){
        cout<<ans<<" ";
        return 1;
    }
    int count=0;
    for(int i=0;i<str.length();i++){
        count+=permu_void(str.substr(0,i)+str.substr(i+1),ans+str[i]);
    }
    return count;
}

//permutation without duplicacy****************************
int permu_void_with_dupli(string str,string ans){
    if(str.length()==0){
        cout<<ans<<" ";
        return 1;
    }
    vector<bool>vis(26,false);
    int count=0;
    for(int i=0;i<str.length();i++){
        if(!vis[str[i]-'a']){
            vis[str[i]-'a']=true;
            count+=permu_void_with_dupli(str.substr(0,i)+str.substr(i+1),ans+str[i]);
        }
    }
    return count;
}
//subsequence without duplicacy****************************
int sub_void_without_dupli(string str,string ans){
    if(str.length()==0){
        cout<<ans<<" ";
        return 1;
    }
    int count=0;
    vector<bool> vis(26);
    if(!vis[str[0]-'a']){
        vis[str[0]-'a']=true;
        count+=sub_void_without_dupli(str.substr(1),ans+str[0]);
    }
    count+=sub_void_without_dupli(str.substr(1),ans);
    return count;
}

bool issafetoplacequeen(int r,int c,vector<vector<bool>>& board){
    vector<vector<int>> dir={{-1,0},{0,-1},{-1,1},{-1,-1}};

    for(int d=0;d<4;d++){
        for(int rad=1;rad<=board.size();rad++){
            int x=r+rad*dir[d][0];
            int y=c+rad*dir[d][1];
            if(x>=0&&y>=0&&x<board.size()&&y<board.size()){
                if(board[x][y]==1) return false;
            }
            else break;
        }
    }
    return true;
}

void display(vector<vector<bool>>& board){
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int nqueen(vector<vector<bool>>& board,int tnq,int idx){
    if(tnq==0){
        display(board);
        return 1;
    }
    // int r=idx/board[0].size();
    // int c=idx%board[0].size();
    
    int count=0;
    for(int i=idx;i<board.size()*board[0].size();i++){
        int x=i/board[0].size();
        int y=i%board[0].size();
        if(issafetoplacequeen(x,y,board)){    
            board[x][y]=1;    //queen is placed at (r,c)        
            count+=nqueen(board,tnq-1,i+1);
            board[x][y]=0;
        }
    }        
    return count;
}

//*********************************************************************************************************************
//*********************************************************************************************************************
void solve(){
    // vector<string> s=sub_ret("abc");
    // for(string str:s){
    //     cout<<str<<" ";
    // }
    // cout<<sub_void("abc","")<<endl; 
    // vector<string> s=permu_ret("abc");
    // for(string str:s){
    //     cout<<str<<" ";
    // }
    // cout<<permu_void_with_dupli("aba","");
    // cout<<sub_void_without_dupli("aab","");
    vector<bool> b(4,false);
    vector<vector<bool>> board(4,b);
    // display(board);
    cout<<nqueen(board,4,0);
}
int main(){
    solve();
    return 0;
}