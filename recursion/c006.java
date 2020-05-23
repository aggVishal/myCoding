// FLOODFILL HEIGHT, LONGEST AND SHORTEST PATH
// COIN PROBLEMS USING PERMUTATION AND COMBINATION


import java.util.*;
public class c006{
    
    // static class pair{
    //     int len;
    //     String s;
    //     pair(int l,String str){
    //         len=l;
    //         s=str;
    //     }
    // };

    // static int[][] dir={{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1}};
    // static String[] dirN={"R","E","U","N","L","W","D","S"};

    // public static int floodfill_height(int sr,int sc,int er,int ec,int [][] board){
    //     if(sr==er&&sc==ec){
    //         return 0;
    //     }
    //     int H=0;
    //     board[sr][sc]=2;
    //     for(int d=0;d<dir.size;d++){
    //         int r=sr+dir[d][0];
    //         int c=sc+dir[d][1];
    //         if(r>=0&&c>=0&&r<board.size&&c<board[0].size&&board[r][c]==0){
    //             int he=floodfill_height(r, c, er, ec, board);
    //             if(he>H){
    //                 H=he;
    //             }                
    //         }
            
    //         //H=Math.max(he,H);
    //     }
    //     board[sr][sc]=0;
    //     return H+1;        
    // }

    // public static pair shortestpath(int sr,int sc,int er,int ec,int [][]board){
    //     if(sr==er&&sc==ec){
    //         return new pair(0,"");
    //     }

    //     board[sr][sc]=2;
    //     pair mypair=new pair(Integer.MAX_VALUE,"");

    //     for(int d=0;d<dir.size;d++){
    //         int r=sr+dir[d][0];
    //         int c=sc+dir[d][1];
    //         if(r>=0&&c>=0&&r<board.size&&c<board[0].size&&board[r][c]==0){
    //             pair recp=longestpath(r, c, er, ec, board);
    //             if(recp.len+1<mypair.len){
    //                 mypair.len=recp.len+1;
    //                 mypair.s=recp.s+dirN[d];
    //             }                
    //         }
    //     }
    //     board[sr][sc]=0;
    //     return mypair;       
    // }
    // public static pair longestpath(int sr,int sc,int er,int ec,int [][]board){
    //     if(sr==er&&sc==ec){
    //         return new pair(0,"");
    //     }

    //     board[sr][sc]=2;
    //     pair mypair=new pair(0,"");

    //     for(int d=0;d<dir.size;d++){
    //         int r=sr+dir[d][0];
    //         int c=sc+dir[d][1];
    //         if(r>=0&&c>=0&&r<board.size&&c<board[0].size&&board[r][c]==0){
    //             pair recp=longestpath(r, c, er, ec, board);
    //             if(recp.len+1>mypair.len){
    //                 mypair.len=recp.len+1;
    //                 mypair.s=recp.s+dirN[d];
    //             }                
    //         }
    //     }
    //     board[sr][sc]=0;
    //     return mypair;       
    // }
    public static void main(String[]args){
        //int sr=0,sc=0,er=2,ec=2;
        //int [][] board=new int[er+1][ec+1];
        //pair ans=longestpath(sr,sc,er,ec,board);
        //System.out.println(ans.s);
        // pair ans=longestpath(sr,sc,er,ec,board);
        // System.out.println(ans.s);
        //System.out.println(floodfill_height(sr, sc, er, ec, board));    

        //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        int[] coin={2,3,5,7};
        
        boolean[] visited=new boolean[4];
        for(int i=0;i<4;i++){
            visited[i]=false;
        }
        System.out.println(combination_fin02(10, coin, "",0));

    }

    //COIN PROBLEMS FUNCTIONS===========================================================

    public static int permutation_infi(int tar,int[] coin,String ans){
        if(tar==0){
            System.out.println(ans);
            return 1;
        }
        int count=0;
        for(int i=0;i<4;i++){
            if(tar>=coin[i]){
                count+=permutation_infi(tar-coin[i], coin, ans+coin[i]+" ");
            }
        }
        return count;
    }

    public static int permutation_fin(int tar,int[] coin,String ans, boolean[] visited){
        if(tar==0){
            System.out.println(ans);
            return 1;
        }
        int count=0;
        for(int i=0;i<4;i++){
            if(!visited[i]&&tar>=coin[i]){
                visited[i]=true;
                count+=permutation_fin(tar-coin[i],coin,ans+coin[i]+" ",visited);
                visited[i]=false;
            }
        }        
        return count;
    }

    public static int combination_infi(int tar,int[] coin,String ans,int idx){
        if(tar==0){
            System.out.println(ans);
            return 1;
        }
        int count=0;
        for(int i=idx;i<4;i++){
            if(tar>=coin[i]){
                count+=combination_infi(tar-coin[i], coin, ans+coin[i]+" ",i);
            }
        }
        return count;
    }
    public static int combination_fin(int tar,int[] coin,String ans,int idx){
        if(tar==0){
            System.out.println(ans);
            return 1;
        }
        int count=0;
        for(int i=idx;i<4;i++){
            if(tar>=coin[i]){
                count+=combination_fin(tar-coin[i], coin, ans+coin[i]+" ",i+1);
            }
        }
        return count;
    }


    //coin change problems using bits tree
    public static int combination_fin02(int tar,int[] coin,String ans,int idx){
        if(tar==0&& idx>=4){
            if(tar==0){
                System.out.println(ans);
                return 1;
            }
            return 0;
        }
        int count=0;
        count+=combination_fin02(tar-coin[idx],coin,ans+coin[idx]+" ",idx+1);
        count+=combination_fin02(tar,coin,ans+coin[idx]+" ",idx+1);
        return count;
    }

    


}