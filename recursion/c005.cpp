// MAZEPATH ALL CASES OF CLASS DATED 03/04/20

#include<iostream>
#include<vector>
using namespace std;

vector<string> mazepath_HV01(int sr,int sc,int er,int ec){
    vector<string> ans;
    if(sr==er&&sc==ec){
        ans.push_back("");
        return ans;
    }
    if(sc<ec){
        vector<string> smallpath=mazepath_HV01(sr,sc+1,er,ec);
        for(string str:smallpath){
            ans.push_back(str +'H');
        }
    }
    if(sr<er){
        vector<string> smallpath=mazepath_HV01(sr+1,sc,er,ec);
        for(string str:smallpath){
            ans.push_back(str + 'V');
        }
    }
    return ans;
}

int mazepath_HV02(int sr,int sc,int er,int ec,string ans){
    if(sr==er&&sc==ec){
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    if(sc<ec){
        count += mazepath_HV02(sr,sc+1,er,ec,ans+'H');
    }
    if(sr<er){
        count += mazepath_HV02(sr+1,sc,er,ec,ans+'V');
    }
    return count;
}

vector<string> mazepath_HVD01(int sr,int sc,int er,int ec){
    vector<string> ans;
    if(sr==er&&sc==ec){
        ans.push_back("");
        return ans;
    }
    if(sc<ec){
        vector<string> smallpath=mazepath_HVD01(sr,sc+1,er,ec);
        for(string str:smallpath){
            ans.push_back('H'+str);
        }
    }
    if(sr<er){
        vector<string> smallpath=mazepath_HVD01(sr+1,sc,er,ec);
        for(string str:smallpath){
            ans.push_back('V'+str);
        }
    }
    if(sr<er&&sc<ec){
        vector<string> smallpath=mazepath_HVD01(sr+1,sc+1,er,ec);
        for(string str:smallpath){
            ans.push_back('D'+str);
        }
    }
    return ans;
}

int mazepath_HVD02(int sr,int sc,int er,int ec,string ans){
    if(sr==er&&sc==ec){
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    if(sc<ec){
        count += mazepath_HVD02(sr,sc+1,er,ec,ans+'H');
    }
    if(sr<er){
        count += mazepath_HVD02(sr+1,sc,er,ec,ans+'V');
    }
    if(sr<er&&sc<ec){
        count += mazepath_HVD02(sr+1,sc+1,er,ec,ans+'D');
    }
    return count;
}

vector<string> mazepathmulti_HVD01(int sr,int sc,int er,int ec){
    vector<string> ans;
    if(sr==er&&sc==ec){
        ans.push_back("");
        return ans;
    }
    for(int jump=1;jump+sc<=ec;jump++){
        vector<string> smallpath=mazepathmulti_HVD01(sr,sc+jump,er,ec);
        for(string str:smallpath){
            ans.push_back('H'+ to_string(jump)+str);
        }
    }
    for(int jump=1;jump+sr<=er;jump++){
        vector<string> smallpath=mazepathmulti_HVD01(sr+jump,sc,er,ec);
        for(string str:smallpath){
            ans.push_back('V'+to_string(jump)+str);
        }
    }
    for(int jump=1;jump+sr<=er&&jump+sc<=ec;jump++){
        vector<string> smallpath=mazepathmulti_HVD01(sr+jump,sc+jump,er,ec);
        for(string str:smallpath){
            ans.push_back('D'+to_string(jump)+str);
        }
    }
    return ans;
}

int mazepathmulti_HVD02(int sr,int sc,int er,int ec,string ans){
    if(sr==er&&sc==ec){
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    for(int jump=1;jump+sc<=ec;jump++){
        count += mazepathmulti_HVD02(sr,sc+jump,er,ec,ans+'H'+to_string(jump));
    }
    for(int jump=1;jump+sr<=er;jump++){
        count += mazepathmulti_HVD02(sr+jump,sc,er,ec,ans+'V'+to_string(jump));
    }
    for(int jump=1;jump+sr<=er&&jump+sc<=ec;jump++){
        count += mazepathmulti_HVD02(sr+jump,sc+jump,er,ec,ans+'D'+to_string(jump));
    }
    return count;
}

//LEVEL UP STARTS

vector<vector<int>> dir8={{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1}};
vector<string> dir8N={"R","E","U","N","L","W","D","S"};

vector<vector<int>> dir4={{0,1},{-1,0},{0,-1},{1,0}};
vector<string> dir4N={"R","U","L","D"};

bool isvalid(int r,int c,vector<vector<int>>& board){
    if(r<0||c<0||r>=board.size()||c>=board[0].size()||board[r][c]==0||board[r][c]==2) return false;
    return true;
}

int floodfill(int sr,int sc,int er,int ec,vector<vector<int>>& board,string ans,int rad,string& max){
    
    if(sc==ec&&sr==er){
        cout<<ans<<endl;
        if(ans.size()>max.size()) max=ans;
        return 1;

    }
    int count =0;
    board[sr][sc]=0;

    for(int d=0;d<dir8.size();d++){
        for(int mag=1;mag<=rad;mag++){
            int r=sr+dir8[d][0];
            int c=sc+dir8[d][1];
            if(isvalid(r,c,board)){
                count+=floodfill(r,c,er,ec,board,ans+dir8N[d]+to_string(mag),rad,max);
            }
        }
    }
    board[sr][sc]=1;
    return count;   
}

int rat_in_maze(int sr,int sc,int er,int ec,string ans,vector<vector<int>> board){
    //same as flood fill, we just have to input our board array
}

void islandfunction(int i,int j,vector<vector<int>>& board){
    board[i][j]=2;
    for(int d=0;d<dir4.size();d++){
        int r=i+dir4[d][0];
        int c=j+dir4[d][1];
        if(isvalid(r,c,board)){
            islandfunction(r,c,board);
        }
    }
    return;
}

int no_of_islands(vector<vector<int>>& board){
    int count=0;
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            if(board[i][j]==1){
                count++;
                islandfunction(i,j,board);   
            }                 
        }
    }    
    return count;
}

void rotcycle(int i,int j,vector<vector<int>>& board){
    board[i][j]=2;
    for(int d=0;d<dir4.size();d++){
        int r=i+dir4[d][0];
        int c=j+dir4[d][1];
        if(isvalid(r,c,board)){
            rotcycle(r,c,board);
        }
    }
    return;
}

int not_rotten_oranges(vector<vector<int>>& board){
    //it will rot in 4 directions
    int count=0;
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            if(board[i][j]==2){
                rotcycle(i,j,board);   
            }                 
        }
    }    
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            if(board[i][j]==1){
                count++;   
            }                 
        }
    }    
    return count;
}



int main(){
    vector<vector<int>> board={{2,1,1,0,0,0},{0,1,1,0,1,0},{0,0,1,0,1,0},{0,1,0,0,0,0}};
    // vector<string> paths=mazepathmulti_HVD01(0,0,2,2);
    // for(int i=0;i<paths.size();i++){
    //     cout<<paths[i]<<endl;
    // }
    //  cout<<mazepathmulti_HVD02(0,0,2,2,"");    
    //vector<vector<int>> board(er+1,vector<int>(ec+1,1));
    int 
    cout<<floodfill(sr,sc,er,ec,board,"",rad,"")<<endl;
    
    //cout<<not_rotten_oranges(board);
        
    return 0;
}