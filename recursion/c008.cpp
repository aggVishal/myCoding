#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;
 
int queen_by_combination_2d(vector<vector<bool>>&boxes,int qpsf,int tnq,int idx,string ans){
    if(qpsf==tnq){
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    for(int i=idx;i<boxes.size()*boxes[0].size();i++){
        int x = i / boxes[0].size();
        int y = i % boxes[0].size();
        count+=queen_by_combination_2d(boxes,qpsf+1,tnq,i+1,ans+"(" + to_string(x) + ", " + to_string(y) + ") ");
    }
    return count;
}

bool issafetoplacequeen(vector<vector<bool>> &boxes,int sr,int sc){
    vector<vector<int>> Qdir={{-1,1},{-1,0},{-1,-1},{0,-1}};
    for(int d=0;d<Qdir.size();d++){
        for(int rad=1;rad<boxes.size();rad++){
            int r=sr+rad*Qdir[d][0];
            int c=sc+rad*Qdir[d][1];
            if(r>=0&&c>=0&&r<boxes.size()&&c<boxes[0].size()){
                if(boxes[r][c]){
                    return false;
                }
            }
            else
            {
                break;
            }            
        }
    }
    return true;
}

int nqueen_01(vector<vector<bool>> &boxes, int qpsf, int tnq, int idx, string ans)   
{ //qpsf : queen place so far, tnq: total no of queen
    if (qpsf == tnq)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for (int i = idx; i < boxes.size() * boxes[0].size(); i++)
    {
        int x = i / boxes[0].size();
        int y = i % boxes[0].size();
        if(issafetoplacequeen(boxes,x,y)){
            boxes[x][y]=true;
            count += nqueen_01(boxes, qpsf + 1, tnq, i + 1, ans + "(" + to_string(x) + ", " + to_string(y) + ") ");
            boxes[x][y]=false;
        }
        
    }
    return count;
}

vector<bool> row(4,0);
vector<bool> col(4,0);
vector<bool> diag(7,0);
vector<bool> adiag(7,0);


int nqueen_02(vector<vector<bool>> &boxes, int qpsf, int tnq, int idx, string ans)    // is safe ko optimise kiya hai
{ //qpsf : queen place so far, tnq: total no of queen
    if (qpsf == tnq)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for (int i = idx; i < boxes.size() * boxes[0].size(); i++)
    {
        int x = i / boxes[0].size();
        int y = i % boxes[0].size();
        if(row[x]==false&&col[y]==false&&diag[x-y+boxes[0].size()]==false &&adiag[x+y]==false){
            row[x]=true;
            col[y]=true;
            diag[x-y+boxes[0].size()]=true;
            adiag[x+y]=true;
            count += nqueen_02(boxes, qpsf + 1, tnq, i + 1, ans + "(" + to_string(x) + ", " + to_string(y) + ") ");
            row[x]=false;
            col[y]=false;
            diag[x-y+boxes[0].size()]=false;
            adiag[x+y]=false;
        }
        
    }
    return count;
}

int maskR=0;
int maskC=0;
int maskDiag=0;
int maskAdiag=0;

int nqueen_03(vector<vector<bool>> &boxes, int qpsf, int tnq, int idx, string ans)   //   bit vaala
{ //qpsf : queen place so far, tnq: total no of queen
    if (qpsf == tnq)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for (int i = idx; i < boxes.size() * boxes[0].size(); i++)
    {
        int x = i / boxes[0].size();
        int y = i % boxes[0].size();
        int maskX=(1<<x);
        int maskY=(1<<y);
        int maskdiag=(1<<(x-y+boxes[0].size()-1));
        int maskadiag=(1<<(x+y));
        if((maskX&maskR)==0&&(maskY&maskC)==0&&(maskdiag&maskDiag)==0&&(maskAdiag&maskadiag)==0){
            maskR^=maskX;
            maskC^=maskY;
            maskDiag^=maskdiag;
            maskAdiag^=maskadiag;
            count += nqueen_03(boxes, qpsf + 1, tnq, i + 1, ans + "(" + to_string(x) + ", " + to_string(y) + ") ");
            maskR^=maskX;
            maskC^=maskY;
            maskDiag^=maskdiag;
            maskAdiag^=maskadiag;
        }
        
    }
    return count;
}
bool issafetoplacenum(vector<vector<bool>> board,int r,int c,int num){
    int x=(r/3)*3;
    int y=(c/3)*3;
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            if(board[x+i][y+j]==num) return false;
        }
    }
    for( int i=0;i<board[0].size();i++){
        if(board[r][i]==num)return false;
    }
    for(int i=0;i<board.size();i++){
        if(board[i][c]== num) return false;
    }
    return true;
}
void queenplacement2d(){
    row.resize(4,0);
    col.resize(4,0);
    diag.resize(7,0);
    adiag.resize(7,0);
    int tnq=4;
    vector<bool> v(4,0);
    vector<vector<bool>> boxes(4,v);
    cout<<nqueen_01(boxes,0,tnq,0,"");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void display(vector<vector<int>>&board){
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool issafetoplacenum(vector<vector<int>>&board,int r,int c,int num){
    int x=(r/3)*3;
    int y=(c/3)*3;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[x+i][y+j]==num){
                return false;
            }
        }        
    }
    for(int i=0;i<9;i++){
        if(board[r][i]==num||board[i][c]==num){
            return false;
        }
    }
    return true;
}

bool sudoku01(vector<vector<int>>&board,int idx){
    if(idx==81){
        display(board);
        return true;
    }
    bool count=false;
    int r=idx/9;
    int c=idx%9;
    if(board[r][c]==0){
        for(int num=1;num<=9;num++){
            if(issafetoplacenum(board,r,c,num)){
                board[r][c]=num;
                count=count||sudoku01(board,idx+1);
                board[r][c]=0;
            }
        }
    }
    else count=count||sudoku01(board,idx+1);
    return count;
}
vector<int> row1;
vector<int> col1;
vector<vector<int>> box1;

bool sudoku02(vector<vector<int>>&board,vector<int>&calls,int idx){
    if(idx==calls.size()){
        display(board);
        return true;
    }
    bool count=false;
    int r=calls[idx]/9;
    int c=calls[idx]%9;
    
    for(int num=1;num<=9;num++){
        if(issafetoplacenum(board,r,c,num)){
            board[r][c]=num;
            count=count||sudoku02(board,calls,idx+1);
            board[r][c]=0;
        }
    }
    return count;
}

bool sudoku03(vector<vector<int>>&board,vector<int>&calls,int idx){
    if(idx==calls.size()){
        display(board);
        return true;
    }
    bool count=false;
    int r=calls[idx]/9;
    int c=calls[idx]%9;
    
    for(int num=1;num<=9;num++){
        int mask=(1<<num);
        if((row1[r]&mask)==0&&(mask&col1[c])==0&&(mask&box1[r/3][c/3])==0){
            board[r][c]=num;
            row1[r]^=mask;
            col1[c]^=mask;
            box1[r/3][c/3]^=mask;
            count=count||sudoku03(board,calls,idx+1);
            board[r][c]=0;
            board[r][c]=num;
            row1[r]^=mask;
            col1[c]^=mask;
            box1[r/3][c/3]^=mask;
        }
    }
    return count;
}


void sudokuproblems(){
    vector<vector<int>> board={{3, 0, 0, 0, 0, 8, 4, 0, 0},  
        {5, 2, 0, 0, 0, 0, 0, 0, 0},  
        {0, 8, 7, 0, 0, 0, 0, 3, 1},  
        {0, 0, 3, 0, 1, 0, 0, 8, 0},  
        {9, 0, 0, 8, 6, 3, 0, 0, 5},  
        {0, 5, 0, 0, 9, 0, 6, 0, 0},  
        {1, 3, 0, 0, 0, 0, 2, 5, 0},  
        {0, 0, 0, 0, 0, 0, 0, 7, 4},  
        {0, 0, 5, 2, 0, 6, 3, 0, 0}};;
        
    row1.resize(9,0);
    col1.resize(9,0);
    vector<int>v(3,0);
    box1.resize(3,v);

        vector<int> calls;
        int mask;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]==0){
                    calls.push_back(i*9+j);
                }
                else{
                    mask=(1<<board[i][j]);
                    row1[i]^=mask;
                    col1[j]^=mask;
                    box1[i/3][j/3]^=mask;
                }
            }
        }
    cout<<sudoku03(board,calls,0);
}

// int nqueen65(vector<vector<int>>boxes,int qtbp,int tnq,int h,string ans){
//     if(h==boxes.size()||qtbp==tnq){
//         if(qtbp==tnq) return 1;
        
//         return 0;
//     }
//     int count=0;
//     for(int i=0;i<boxes[0].size();i++){
//         int r=h;
//         int c=i%boxes[0].size();        
//         if(row&(1<<r))
//     }
//     return count;
// }


// void nqueen(){

// }

/////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
//wordbreak(based on leetcode 139,140)
unordered_set<string> map;

int wordbreak_(string word,string ans){
    if(word.length()==0){
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    for(int i=1;i<=word.length();i++){
        string smallstr=word.substr(0,i);
        if(map.find(smallstr)!=map.end()){
            count+=wordbreak_(word.substr(i),ans+smallstr+" ");
        }
    }
    return count;
}
void wordbreak(){
    vector<string> words={"cat", "cats", "and", "sand", "dog"};
    string word="catsanddog";
    for(string wor:words){
        map.insert(wor);
    }
    cout<<wordbreak_(word,"")<<endl;
}

//cryptoarithmetic*************************************************************************************************

string str1="send";
string str2="more";
string str3="money";
string str;

vector<int> mapping(26,0);
int used=0;

int stringtonum(string& str){
    int res=0;
    for(int i=0;i<str.length();i++){
        int idx = str[i] - 'a';
        res = res * 10 + mapping[idx];
    }
    return res;
}
int crypto_(string str,int idx){
    if(idx==str.length()){
        int a=stringtonum(str1);
        int b=stringtonum(str2);
        int c=stringtonum(str3);
        if(a+b==c) {
            cout<<" "<<a<<endl<<"+ "<<b<<endl<<"-------"<<endl<<c<<endl<<endl;
            return 1;
        }
        return 0;
    }    
    int count=0;
    for(int i=0;i<=9;i++){
        if((used&(1<<i))==0){
            mapping[str[idx]-'a']=i;
            used^=(1<<i);
            count+=crypto_(str,idx+1);
            used^=(1<<i);
            mapping[str[idx]-'a']=0;
        }
    }
    return count;
}

void crypto(){
    
    str=str1+str2+str3;
    int freq=0;
    for(int i=0;i<str.length();i++){
        int idx=str[i]-'a';
        int mask=(1<<idx);
        freq|=mask;
    }
    str="";
    for(int i=0;i<26;i++){
        if((freq&(1<<i))!=0)
            str+=(char)(i+'a');
    }
    cout<<crypto_(str,0)<<endl;
}

//crossword******************************************************************************************************************************
vector<vector<char>> boardc{{'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
                               {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
                               {'+', '-', '-', '-', '-', '-', '-', '-', '+', '+'},
                               {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
                               {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
                               {'+', '-', '-', '-', '-', '-', '-', '+', '+', '+'},
                               {'+', '-', '+', '+', '+', '-', '+', '+', '+', '+'},
                               {'+', '+', '+', '+', '+', '-', '+', '+', '+', '+'},
                               {'+', '+', '+', '+', '+', '-', '+', '+', '+', '+'},
                               {'+', '+', '+', '+', '+', '+', '+', '+', '+', '+'}};
vector<string> words = {"agra", "norway", "england", "gwalior"};


bool canplaceH(int r,int c,string word){
    if(c+word.length()>=boardc[0].size()){
        return false;
    }
    if(boardc[r][c+word.length()]!='+'){
        return false;
    }
    if(boardc[r][c-1]!='+'&&c>0){
        return false;
    }    
    for(int i=0;i<word.length();i++){
        if(boardc[r][c+i]!=word[i]&&boardc[r][c+i]!='-'){
            return false;
        }
    }
    return true;
}
vector<bool> placewordH(int r,int c,string word){
    vector<bool> mark(word.length(),false);
    for(int i=0;i<word.length();i++){
        if(boardc[r][c+i]=='-'){
            boardc[r][c+i]=word[i];
            mark[i]=true;
        }
    }
    return mark;
}
void unplacewordH(int r,int c,string word,vector<bool> mark){
    for(int i=0;i<word.length();i++){
        if(mark[i]==true){
            boardc[r][c+i]='-';
        }
    }        
}
bool canplaceV(int r,int c,string word){
    for(int i=0;i<word.length();i++){
        if(boardc[r+i][c]!=word[i]&&boardc[r+i][c]!='-'){
            return false;
        }
    }
    return true;
}
vector<bool> placewordV(int r,int c,string word){
    vector<bool> mark(word.length(),false);
    for(int i=0;i<word.length();i++){
        if(boardc[r+i][c]=='-'){
            boardc[r+i][c]=word[i];
            mark[i]=true;
        }
    }
    return mark;
}
void unplacewordV(int r,int c,string word,vector<bool> mark){
    for(int i=0;i<word.length();i++){
        if(mark[i]==true){
            boardc[r+i][c]='-';
        }
    }   
}

bool crossword(int idx){
    if(idx==words.size()){
        for(int i=0;i<boardc.size();i++){
            for(int j=0;j<boardc[0].size();j++){
                cout<<boardc[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    bool res=false;
    for(int i=0;i<boardc.size();i++){
        for(int j=0;j<boardc[0].size();j++){
            if(boardc[i][j]!='+'){
                if(canplaceH(i,j,words[idx])){
                    vector<bool> mark=placewordH(i,j,words[idx]);
                    res=res||crossword(idx+1);
                    unplacewordH(i,j,words[idx],mark);
                }
                if(canplaceV(i,j,words[idx])){
                    vector<bool> mark=placewordV(i,j,words[idx]);
                    res=res||crossword(idx+1);
                    unplacewordV(i,j,words[idx],mark);
                }
            }
        }
    }
    return res;
}     



//***************************************************************************************************************

int main(){
    //queenplacement2d();
    //sudokuproblems();
    //wordbreak();
    //crypto();
    crossword(0);
    return 0;
}