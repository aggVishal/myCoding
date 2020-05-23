// #include<iostream>
// #include<vector>
// using namespace std;
// vector<vector<int>> kdir={{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2}};
// vector<char> dirname={'1','2','3','4','5','6','7','8'};

// bool isvalid(int r,int c,vector<vector<int>>& board){
//     if(r<0||c<0||r>=board.size()||c>=board[0].size()||board[r][c]==0) return false;
//     return true;
// }

// void knight(vector<vector<int>>& board,string ans,int sr,int sc,int s,int n){    
//     if(n==(s*s)-3){
//         cout<<ans<<endl;
//         return;        
//     }
//     board[sr][sc]=0;
    
//     for(int d=0;d<kdir.size();d++){
//         int r=sr+ kdir[d][0];
//         int c=sc+ kdir[d][1];
//         if(isvalid(r,c,board)){
//             knight(board,ans+dirname[d],r,c,s,n+1);                        
//         }
//     }    
//     board[sr][sc]=1;
//     return;
// }

// int main(){
//     int sr=0,sc=0,s=8,n=0;
//     vector<int> v(s,1);
//     vector<vector<int>> board(s,v);    
//     knight(board,"0",sr,sc,s,n);
// }
// C program for Knight Tour problem 
#include<stdio.h> 
#define N 8
  
int solveKTUtil(int x, int y, int movei, int sol[N][N], 
                int xMove[],  int yMove[]); 
  
/* A utility function to check if i,j are valid indexes 
   for N*N chessboard */
int isSafe(int x, int y, int sol[N][N]) 
{ 
    return ( x >= 0 && x < N && y >= 0 && 
             y < N && sol[x][y] == -1); 
} 
  
/* A utility function to print solution matrix sol[N][N] */
void printSolution(int sol[N][N]) 
{ 
    for (int x = 0; x < N; x++) 
    { 
        for (int y = 0; y < N; y++) 
            printf(" %2d ", sol[x][y]); 
        printf("\n"); 
    } 
} 
  
/* This function solves the Knight Tour problem using 
   Backtracking.  This function mainly uses solveKTUtil() 
   to solve the problem. It returns false if no complete 
   tour is possible, otherwise return true and prints the 
   tour. 
   Please note that there may be more than one solutions, 
   this function prints one of the feasible solutions.  */
int solveKT() 
{ 
    int sol[N][N]; 
  
    /* Initialization of solution matrix */
    for (int x = 0; x < N; x++) 
        for (int y = 0; y < N; y++) 
            sol[x][y] = -1; 
  
    /* xMove[] and yMove[] define next move of Knight. 
       xMove[] is for next value of x coordinate 
       yMove[] is for next value of y coordinate */
    int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 }; 
    int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 }; 
  
    // Since the Knight is initially at the first block 
    sol[0][0]  = 0; 
  
    /* Start from 0,0 and explore all tours using 
       solveKTUtil() */
    if (solveKTUtil(0, 0, 1, sol, xMove, yMove) == 0) 
    { 
        printf("Solution does not exist"); 
        return 0; 
    } 
    else
        printSolution(sol); 
  
    return 1; 
} 
  
/* A recursive utility function to solve Knight Tour 
   problem */
int solveKTUtil(int x, int y, int movei, int sol[N][N], 
                int xMove[N], int yMove[N]) 
{ 
   int k, next_x, next_y; 
   if (movei == N*N) 
       return 1; 
  
   /* Try all next moves from the current coordinate x, y */
   for (k = 0; k < 8; k++) 
   { 
       next_x = x + xMove[k]; 
       next_y = y + yMove[k]; 
       if (isSafe(next_x, next_y, sol)) 
       { 
         sol[next_x][next_y] = movei; 
         if (solveKTUtil(next_x, next_y, movei+1, sol, 
                         xMove, yMove) == 1) 
             return 1; 
         else
             sol[next_x][next_y] = -1;// backtracking 
       } 
   } 
  
   return 0; 
} 
  
/* Driver program to test above functions */
int main() 
{ 
    solveKT(); 
    return 0; 
} 