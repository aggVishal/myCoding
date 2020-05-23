import java.util.ArrayList;
class c007{
    public static void main(String[]args){
        //floodfill();
        // coinchange();
        //_();
        //queenplacement();
        //nqueen();
        sudokuproblems();
    }

    public static void floodfill(){
        int sr=0,sc=0,er=2,ec=2;
        int [][] board=new int[er+1][ec+1];
        //System.out.println(floodfill_height(sr,sc,er,ec,board));
        System.out.println(floodfill_longestpath(sr,sc,er,ec,board).str);
    }

    static int[][] dir={{0,1},{-1,-1},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1}};    
    static String[] dirN= {"R","E","U","N","L","W","D","S"};

    public static int floodfill_height(int sr,int sc,int er,int ec,int[][] board ){
        if(sr==er&&sc==ec){
            return 0;
        }
        board[sr][sc]=2;
        int height=0;
        for(int d=0;d<dir.length;d++){
            int r=sr+dir[d][0];
            int c=sc+dir[d][1];
            if(r>=0&&c>=0&&r<board.length&&c<board[0].length&&board[r][c]==0){
                int h=floodfill_height(r,c,er,ec,board);
                height=Math.max(height,h);         
            }
        }
        board[sr][sc]=0;
        return height+1;
    }
    static class pair{
        int len=0;
        String str="";
        pair(int l,String s){
            len=l;
            str=s;
        }
    };
    public static pair floodfill_shortestpath(int sr,int sc,int er,int ec,int[][] board){
        if(sr==er&&ec==sc){
            return new pair(0,"");
            // return base;
        }

        pair mypair=new pair(1000,"");
        board[sr][sc]=2;
        for(int d=0;d<dir.length;d++){
            int r=sr+dir[d][0];
            int c=sc+dir[d][1];
            if(r>=0&&c>=0&&r<board.length&&c<board[0].length&&board[r][c]==0){
                pair recp=floodfill_shortestpath(r, c, er, ec, board);
                if(recp.len+1<mypair.len){
                    mypair.len=recp.len+1;
                    mypair.str=recp.str+dirN[d];
                }     
            }            
        }
        board[sr][sc]=0;
        return mypair;
    }
    public static pair floodfill_longestpath(int sr,int sc,int er,int ec,int[][] board){
        if(sr==er&&ec==sc){
            return new pair(0,"");
            // return base;
        }

        pair mypair=new pair(0,"");
        board[sr][sc]=2;
        for(int d=0;d<dir.length;d++){
            int r=sr+dir[d][0];
            int c=sc+dir[d][1];
            if(r>=0&&c>=0&&r<board.length&&c<board[0].length&&board[r][c]==0){
                pair recp=floodfill_longestpath(r, c, er, ec, board);
                if(recp.len+1>=mypair.len){
                    mypair.len=recp.len+1;
                    mypair.str=recp.str+dirN[d];
                }     
            }            
        }
        board[sr][sc]=0;
        return mypair;
    }
    //===============================================================================================================
    //===============================================================================================================
    //coin change problems===================(Basics of NQueen Problem)==============================================
    //===============================================================================================================
    //===============================================================================================================
    public static void coinchange(){/////////////////////////////////////////////////////////////////////////////////
        int[] ar={2,3,5,7};/////////////////////////////////////////////////////////////////////////////////////////
        int tar=10;//////////////////////////////////////////////////////////////////////////////////////////////////
        boolean[] vis=new boolean[ar.length];///////////////////////////////////////////////////////////////////////
        System.out.println(combination_fin01(ar,tar,"",0));/////////////////////////////////////////////////////////

    }

    public static int permutation_infin01(int[] ar,int tar,String ans){
        if(tar==0){
            System.out.println(ans);
            return 1;
        }

        int count=0;
        for(int i=0;i<ar.length;i++){
            if(tar>=ar[i]){
                count+=permutation_infin01(ar, tar-ar[i], ans+ar[i]+" ");
            }
        }
        return count;
    }
    public static int permutation_fin01(int[] ar,int tar,String ans,int idx,boolean[] vis){
        if(tar==0){
            System.out.println(ans);
            return 1;
        }
        
        
        int count=0;
        for(int i=0;i<ar.length;i++){
            if(!vis[i]&&tar>=ar[i]){
                vis[idx]=true;
                count+=permutation_fin01(ar, tar-ar[i], ans+ar[i]+" ",i,vis);
                vis[idx]=false;
            }
        }
        return count;
    }
    public static int combination_infin01(int[] ar,int tar,String ans,int idx){
        if(tar==0){
            System.out.println(ans);
            return 1;
        }

        int count=0;
        for(int i=idx;i<ar.length;i++){
            if(tar>=ar[i]){
                count+=combination_infin01(ar, tar-ar[i], ans+ar[i]+" ",i);
            }
        }
        return count;
    }
    public static int combination_fin01(int[] ar,int tar,String ans,int idx){
        if(tar==0){
            System.out.println(ans);
            return 1;
        }

        int count=0;
        for(int i=idx;i<ar.length;i++){
            if(tar>=ar[i]){
                count+=combination_fin01(ar, tar-ar[i], ans+ar[i]+" ",i+1);
            }
        }
        return count;
    }
    //   01 represents combination or permutation methods and 02 represents subsequence method
    //same problems by using subsequence method=====================================================================
    public static void subsequence_method(){/////////////////////////////////////////////////////////////////////////
        int[] ar={2,3,5,7};//////////////////////////////////////////////////////////////////////////////////////////
        int tar=10;////////////////////////////////////////////////////////////////////////////////////////////////////
        boolean[] vis=new boolean[ar.length];/////////////////////////////////////////////////////////////////////////
        System.out.println(permutation_fin02(ar,tar,0,"",vis));//////////////////////////////////////////////////////
    }

    public static int combination_infin02(int[]ar,int tar,int idx,String ans){
        if(tar==0||idx==ar.length){
            if(tar==0){
                System.out.println(ans);
                return 1;
            }
            return 0;
        }
        int count=0;
        if(tar>=ar[idx]){    // coin at index idx will come
            count+=combination_infin02(ar,tar-ar[idx],idx,ans+ar[idx]+" ");
        }
        count+=combination_infin02(ar,tar,idx+1,ans);//coin at index idx will not come
        return count;
    }
    public static int combination_fin02(int[]ar,int tar,int idx,String ans){
        if(tar==0||idx==ar.length){
            if(tar==0){
                System.out.println(ans);
                return 1;
            }
            return 0;
        }
        int count=0;
        if(tar>=ar[idx]){    // coin at index idx will come
            count+=combination_fin02(ar,tar-ar[idx],idx+1,ans+ar[idx]+" ");
        }
        count+=combination_fin02(ar,tar,idx+1,ans);//coin at index idx will not come
        return count;
    }
    public static int permutation_infin02(int[]ar,int tar,int idx,String ans){
        if(tar==0||idx==ar.length){
            if(tar==0){
                System.out.println(ans);
                return 1;
            }
            return 0;
        }
        int count=0;
        if(tar>=ar[idx]){    // coin at index idx will come
            count+=permutation_infin02(ar,tar-ar[idx],0,ans+ar[idx]+" ");
        }
        count+=permutation_infin02(ar,tar,idx+1,ans);//coin at index idx will not come
        return count;
    }
    public static int permutation_fin02(int[]ar,int tar,int idx,String ans,boolean[] vis){
        if(tar==0||idx==ar.length){
            if(tar==0){
                System.out.println(ans);
                return 1;
            }
            return 0;
        }
        int count=0;
        if(tar>=ar[idx]&&!vis[idx]){    // coin at index idx will come
            vis[idx]=true;
            count+=permutation_fin02(ar,tar-ar[idx],0,ans+ar[idx]+" ",vis);
            vis[idx]=false;
        }
        count+=permutation_fin02(ar,tar,idx+1,ans,vis);//coin at index idx will not come
        return count;
    }
    //queen placement===============================================================================================
    public static void queenplacement(){///////////////////////////////////////////////////////////////////////////
        int N=3,M=3;//////////////////////////////////////////////////////////////////////////////////////////////
        int tnq=4;/////////////////////////////////////////////////////////////////////////////////////////////////
        //int[] box=new int[N];////////////////////////////////////////////////////////////////////////////////////////
        int[][] boxes=new int[N][M];//////////////////////////////////////////////////////////////////////////////////
        int qtbp=0,i=0;     //qtbp=queen to be placed///////////////////////////////////////////////////////////
        System.out.println(queen_by_subsequence_permu_2d(boxes,qtbp,tnq,i,""));/////////////////////////////////////
    }

    public static int queen_by_subsequence_combi_1D(int[] box,int qtbp,int tnq,int idx,String ans){
        if(idx==box.length||qtbp==tnq){
            if(qtbp==tnq){
                System.out.println(ans);
                return 1;
            }
            return 0;
        }
        int count=0;
        if(box[idx]==0){
            box[idx]=1;
            count+=queen_by_subsequence_combi_1D(box, qtbp+1,tnq, idx+1, ans+"B"+idx+"Q"+qtbp+" ");   // Queen is placed
            box[idx]=0;
        }
        count+=queen_by_subsequence_combi_1D(box, qtbp,tnq, idx+1, ans);   //Queen is not placed
        return count;
    }
    public static int queen_by_subsequence_permu_1D(int[] box,int qtbp,int tnq,int idx,String ans){
        if(idx==box.length||qtbp==tnq){
            if(qtbp==tnq){
                System.out.println(ans);
                return 1;
            }
            return 0;
        }
        int count=0;
        if(box[idx]==0){
            box[idx]=1;
            count+=queen_by_subsequence_permu_1D(box, qtbp+1,tnq, 0, ans+"B"+idx+"Q"+qtbp+" ");   // Queen is placed
            box[idx]=0;
        }
        count+=queen_by_subsequence_permu_1D(box, qtbp,tnq, idx+1, ans);   //Queen is not placed
        return count;
    }

    public static int queen_by_combinations_1d(int[] box,int qtbp,int tnq, int idx,String ans){
        if(qtbp==tnq){
            System.out.println(ans);
            return 1;
        }
        int count=0;
        for(int i=idx;i<box.length;i++){
            count+=queen_by_combinations_1d(box, qtbp+1, tnq, i+1, ans+"B"+i+"Q"+qtbp+" ");
        }
        return count;
    }

    public static int queen_by_permutations_1d(int[]box,int qtbp,int tnq,int idx,String ans){
        if(qtbp==tnq){
            System.out.println(ans);
            return 1;
        }
        int count=0;
        for(int i=0;i<box.length;i++){
            if(box[i]==0){
                box[i]=1;
                count+=queen_by_permutations_1d(box, qtbp+1, tnq,0, ans+"B"+i+"Q"+qtbp+" ");
                box[i]=0;
            }
              
        }
        return count;
    } 

    public static int queen_by_combinations_2d(int[][]boxes,int qtbp,int tnq,int idx,String ans){
        if(qtbp==tnq){
            System.out.println(ans);
            return 1;
        }
        int count=0;
        for(int i=idx;i<boxes.length*boxes[0].length;i++){
            int r=i/boxes[0].length;
            int c=i%boxes[0].length;
            count+=queen_by_combinations_2d(boxes, qtbp+1, tnq, i+1, ans+"("+r+","+c+") ");
        }
        return count;
    }

    public static int queen_by_permutation_2d(int[][]boxes,int qtbp,int tnq,String ans){
        if(qtbp==tnq){
            System.out.println(ans);
            return 1;
        }
        int count=0;
        for(int i=0;i<boxes.length*boxes[0].length;i++){
            int r=i/boxes[0].length;
            int c=i%boxes[0].length;
            if(boxes[r][c]==0){
                boxes[r][c]=1;
                count+=queen_by_permutation_2d(boxes, qtbp+1, tnq, ans+"("+r+","+c+") ");
                boxes[r][c]=0;
            }
        }
        return count;
    }

    public static int queen_by_subsequence_combi_2d(int[][]boxes,int qtbp,int tnq,int idx,String ans){
        if(idx==boxes.length*boxes[0].length||qtbp==tnq){
            if(qtbp==tnq){
                System.out.println(ans);
                return 1;
            }
            return 0;
        }
        int count=0;
        int r=idx/boxes[0].length;
        int c=idx%boxes[0].length;
        count+=queen_by_subsequence_combi_2d(boxes, qtbp+1, tnq, idx+1, ans+"("+r+","+c+") ");
        count+=queen_by_subsequence_combi_2d(boxes, qtbp, tnq, idx+1, ans);
        return count;
    }
    public static int queen_by_subsequence_permu_2d(int[][]boxes,int qtbp,int tnq,int idx,String ans){
        if(idx==boxes.length*boxes[0].length||qtbp==tnq){
            if(qtbp==tnq){
                System.out.println(ans);
                return 1;
            }
            return 0;
        }
        int count=0;
        int r=idx/boxes[0].length;
        int c=idx%boxes[0].length;
        if(boxes[r][c]==0){
            boxes[r][c]=1;
            count+=queen_by_subsequence_permu_2d(boxes, qtbp+1, tnq, 0, ans+"("+r+","+c+") ");
            boxes[r][c]=0;
        }        
        count+=queen_by_subsequence_permu_2d(boxes, qtbp, tnq, idx+1, ans);
        return count;
    }

    // NQueen=========================================================================================================
    public static void nqueen(){/////////////////////////////////////////////////////////////////////////////////////
        int N=4,M=4;/////////////////////////////////////////////////////////////////////////////////////////////////
        int tnq=4;///////////////////////////////////////////////////////////////////////////////////////////////////
        int[][] boxes=new int[N][M];////////////////////////////////////////////////////////////////////////////////
        int qtbp=0,i=0;     //qtbp=queen to be placed////////////////////////////////////////////////////////////
        //System.out.println(nqueen04_su(boxes,qtbp,tnq,i,""));///////////////////////////////////////////////////////////
    }
    //Only combinations are considered as permutations just increase the no of calls


    public static boolean issafetoplacequeen(int[][]boxes,int r,int c){
        int[][]Qdir={{-1,1},{-1,0},{-1,-1},{0,-1}};         
        for(int d=0;d<Qdir.length;d++){
            for(int rad=1;rad<boxes.length;rad++){
                int x=r+rad*Qdir[d][0];
                int y=c+rad*Qdir[d][1];
                if(x>=0&&y>=0&&x<boxes.length&&y<boxes[0].length){
                    if(boxes[x][y]==1){
                        return false;
                    }
                }           
                else break;     
            }           
        }
        return true;
    }

    public static int nqueen01(int[][]boxes,int qtbp,int tnq,int idx,String ans){
        if(qtbp==tnq){
            System.out.println(ans);
            return 1;
        }
        int count=0;
        for(int i=idx;i<boxes.length*boxes[0].length;i++){
            int r=i/boxes[0].length;
            int c=i%boxes[0].length;
            if(boxes[r][c]==0&&issafetoplacequeen(boxes,r,c)){
                boxes[r][c]=1;
                count+=nqueen01(boxes, qtbp+1, tnq, i+1, ans+"("+r+","+c+") ");
                boxes[r][c]=0;
            }
        }
        return count;
    }

    //more optimised version( Is safe function will be O(1) )========================================================================================
    
    static int[] row=new int[4];
    static int[] col=new int[4];
    static int[] diag=new int[7];
    static int[] adiag=new int[7];

    public static int nqueen02(int[][]boxes,int qtbp,int tnq,int idx,String ans){
        if(qtbp==tnq){
            System.out.println(ans);
            return 1;
        }
        int count=0;
        for(int i=idx;i<boxes.length*boxes[0].length;i++){
            int r=i/boxes[0].length;
            int c=i%boxes[0].length;
            if(row[r]==0&&col[c]==0&&diag[r-c+boxes[0].length-1]==0&&adiag[r+c]==0){
                row[r]=1;
                col[c]=1;
                diag[r-c+boxes[0].length-1]=1;
                adiag[r+c]=1;
                count+=nqueen02(boxes, qtbp+1, tnq, i+1, ans+"("+r+","+c+") ");
                row[r]=0;
                col[c]=0;
                diag[r-c+boxes[0].length-1]=0;
                adiag[r+c]=0;
            }
        }
        return count;
    }

    // same function using bits (using bits is efficient)==============================================================
    
    static int ROW=0;
    static int COL=0;
    static int DIAG=0;
    static int ADIAG=0;

    public static int nqueen03(int[][]boxes,int qtbp,int tnq,int idx,String ans){
        if(qtbp==tnq){
            System.out.println(ans);
            return 1;
        }
        int count=0;
        for(int i=idx;i<boxes.length*boxes[0].length;i++){
            int r=i/boxes[0].length;
            int c=i%boxes[0].length;
            int  maskR=(1<<r);
            int  maskC=(1<<c);
            int  maskD=(1<<(r-c+boxes[0].length-1));
            int  maskA=(1<<(r+c));
            if((ROW&maskR)==0&&(COL&maskC)==0&&(DIAG&maskD)==0&&(ADIAG&maskA)==0){
                ROW^=maskR;
                COL^=maskC;
                DIAG^=maskD;
                ADIAG^=maskA;
                count+=nqueen03(boxes, qtbp+1, tnq, i+1, ans+"("+r+","+c+") ");
                ROW^=maskR;
                COL^=maskC;
                DIAG^=maskD;
                ADIAG^=maskA;
            }
        }
        return count;
    }

    //Using Subsequence==============================================================================================

    public static int nqueen03_subs(int[][]boxes,int qtbp,int tnq,int idx,String ans){
        if(qtbp==tnq||idx==boxes.length*boxes[0].length){
            if(qtbp==tnq){
                System.out.println(ans);
                return 1;
            }
            return 0;
        }
        int count=0;
        int r=idx/boxes[0].length;
        int c=idx%boxes[0].length;
        int  maskR=(1<<r);
        int  maskC=(1<<c);
        int  maskD=(1<<(r-c+boxes[0].length-1));
        int  maskA=(1<<(r+c));
        if((ROW&maskR)==0&&(COL&maskC)==0&&(DIAG&maskD)==0&&(ADIAG&maskA)==0){
            ROW^=maskR;
            COL^=maskC;
            DIAG^=maskD;
            ADIAG^=maskA;
            count+=nqueen03_subs(boxes, qtbp+1, tnq, idx+1, ans+"("+r+","+c+") ");
            ROW^=maskR;
            COL^=maskC;
            DIAG^=maskD;
            ADIAG^=maskA;
        }
        count+=nqueen03_subs(boxes, qtbp, tnq, idx+1, ans);    
        return count;
    }
    
    //using row wise placement method(less calls...)==================================================================

    public static int nqueen04(int[][]boxes,int qtbp,int tnq,int h,String ans){
        if(qtbp==tnq||h==boxes.length){
            if(qtbp==tnq){
                System.out.println(ans);
                return 1;
            }
            return 0;
        }
        int count=0;
        for(int i=0;i<boxes[0].length;i++){
            int r=h;
            int c=i%boxes[0].length;
            int  maskR=(1<<r);
            int  maskC=(1<<c);
            int  maskD=(1<<(r-c+boxes[0].length-1));
            int  maskA=(1<<(r+c));
            if((ROW&maskR)==0&&(COL&maskC)==0&&(DIAG&maskD)==0&&(ADIAG&maskA)==0){
                ROW^=maskR;
                COL^=maskC;
                DIAG^=maskD;
                ADIAG^=maskA;
                count+=nqueen04(boxes, qtbp+1, tnq, h+1, ans+"("+r+","+c+") ");
                ROW^=maskR;
                COL^=maskC;
                DIAG^=maskD;
                ADIAG^=maskA;
            }
        }
        return count;
    }
    
    public static int nqueen04_subs(int[][]boxes,int qtbp,int tnq,int h,String ans){
        if(qtbp==tnq||h==boxes.length){
            if(qtbp==tnq){
                System.out.println(ans);
                return 1;
            }
            return 0;
        }
        int count=0;
        for(int i=0;i<boxes[0].length;i++){
            int r=h;
            int c=i%boxes[0].length;
            int  maskR=(1<<r);
            int  maskC=(1<<c);
            int  maskD=(1<<(r-c+boxes[0].length-1));
            int  maskA=(1<<(r+c));
            if((ROW&maskR)==0&&(COL&maskC)==0&&(DIAG&maskD)==0&&(ADIAG&maskA)==0){
                ROW^=maskR;
                COL^=maskC;
                DIAG^=maskD;
                ADIAG^=maskA;
                count+=nqueen04_subs(boxes, qtbp+1, tnq, h+1, ans+"("+r+","+c+") ");
                ROW^=maskR;
                COL^=maskC;
                DIAG^=maskD;
                ADIAG^=maskA;
            }
        }
        count+=nqueen04_subs(boxes, qtbp, tnq, h+1, ans);
        return count;
    }

    //********************************************end of NQueen problems***********************************************    
    public static void sudokuproblems(){
        int[][] board= {{3, 0, 0, 0, 0, 8, 4, 0, 0},  
        {5, 2, 0, 0, 0, 0, 0, 0, 0},  
        {0, 8, 7, 0, 0, 0, 0, 3, 1},  
        {0, 0, 3, 0, 1, 0, 0, 8, 0},  
        {9, 0, 0, 8, 6, 3, 0, 0, 5},  
        {0, 5, 0, 0, 9, 0, 6, 0, 0},  
        {1, 3, 0, 0, 0, 0, 2, 5, 0},  
        {0, 0, 0, 0, 0, 0, 0, 7, 4},  
        {0, 0, 5, 2, 0, 6, 3, 0, 0}};
        ArrayList<Integer> calls=new ArrayList<>();
        Row=new int[9];
        Col=new int[9];
        Box=new int[3][3];
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]==0){
                    calls.add(9*i+j);
                }
                else{
                    int mask=(1<<board[i][j]);
                    Row[i]^=mask;
                    Col[j]^=mask;
                    Box[i/3][j/3]^=mask;
                }
            }
        }
        
        System.out.println(sudoku02(board,calls,0));
        
    }

    public static void display(int[][] board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                System.out.print(board[i][j]+" ");
            }
            System.out.println();
        }
    }

    public static boolean issafetoplacenum(int[][] board,int r,int c,int num){
        int x=(r/3)*3;
        int y=(c/3)*3;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[x+i][y+j]==num) return false;
            }
        }
        for( int i=0;i<9;i++){
            if(board[r][i]==num)return false;
        }
        for(int i=0;i<9;i++){
            if(board[i][c]==num) return false;
        }
        return true;
    }

    public static boolean sudoku01(int[][]board,int idx){
        if(idx==81){
            display(board);
            return true;
        }
        int r=idx/9;
        int c=idx%9;
        boolean count=false;
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
    public static boolean sudoku02(int[][]board,ArrayList<Integer> calls,int idx){
        if(idx==calls.size()){
            display(board);
            return true;
        }
        int r=calls.get(idx)/9;
        int c=calls.get(idx)%9;
        boolean count=false;
        for(int num=1;num<=9;num++){
            if(issafetoplacenum(board,r,c,num)){
                board[r][c]=num;
                count=count||sudoku02(board,calls,idx+1);
                board[r][c]=0;
            }
        }
        return count;
    }

    static int[] Row;
    static int[] Col;
    static int[][] Box;


    public static boolean sudoku03(int[][]board,ArrayList<Integer> calls,int idx){
        if(idx==calls.size()){
            display(board);
            return true;
        }
        int r=calls.get(idx)/9;
        int c=calls.get(idx)%9;
        boolean count=false;
        for(int num=1;num<=9;num++){
            int mask=(1<<num);
            if((Row[r]&mask)==0&&(Col[c]&mask)==0&&(Box[r/3][c/3]&mask)==0){
                board[r][c]=num;
                Row[r]^=mask;
                Col[c]^=mask;
                Box[r/3][c/3]^=mask;
                count=count||sudoku03(board,calls,idx+1);
                board[r][c]=0;
                Row[r]^=mask;
                Col[c]^=mask;
                Box[r/3][c/3]^=mask;
                
            }
        }
        return count;
    }
}