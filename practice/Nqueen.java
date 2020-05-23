class Nqueen{
    public static void main(){
        int N=4;
        int[]board=new int[N*N];
        int tnq=4;
        int qtbp=0,idx=0;
        int[][]ans=nqueen(board,idx,qtbp,tnq);
        for(int i=0;i<nqueen.length;i++){
            for(int j=0;j<nqueen[0].length;i++){
                System.out.print(nqueen[i][j]+" ");
            }
            System.out.println();
        }
    }

    public static int[] nqueen(int[] board,int idx,int qtbp,int tnq){
        for(int i=0;i<board.length;i++){
            if(board[i]==0&&qtbp!=tnq){
                board=function(board,i);
            }
        }
               
    }
}