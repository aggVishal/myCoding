import java.util.ArrayList;
import java.util.Stack;
import java.util.LinkedList;
public class GTtree{
    public static void main(String[] args){
        solve();
    }

    public static class Node{
        int data;
        ArrayList<Node> childs=new ArrayList<>();
        Node(int data){
            this.data=data;            
        }
        Node(){
        }
    }

    public static Node constructGTtree(int[] ar){
        Stack<Node> st=new Stack<>();
        
        for(int i=0;i<ar.length-1;i++){
            if(ar[i]!=-1){
                Node node=new Node(ar[i]);
                st.push(node);
            }
            else{
                Node node=st.pop();
                st.peek().childs.add(node);
            }
        }
        return st.pop();
    }

    public static void preorder(Node node){
        System.out.print(node.data+" ");
        for(Node n:node.childs){
            preorder(n);
        }        
    }

    public static void display(Node node){
    
        String str="";
        str+=(node.data + " -> ");
        
        for(Node child:node.childs){
            str+=child.data + " ";
        }
    
        System.out.println(str);
        
        for(Node child:node.childs){
            display(child);
        }
    }

//Basic Questions===========================================================================================================================

    public static int height(Node node){
        int h=0;
        for(int i=0;i<node.childs.size();i++){
            h=Math.max(h,height(node.childs.get(i)));
        }
        return h+1;
    }

    public static int SizeofGT(Node node){
        int s=1;
        for(int i=0;i<node.childs.size();i++){
            s+=SizeofGT(node.childs.get(i));
        }
        return s;
    }

    public static boolean find(Node root,int data){
        if(root.data==data){
            return true;
        }
        boolean res=false;
        for(int i=0;i<root.childs.size();i++){
            res=res||find(root.childs.get(i),data);
        }
        return res;
    }

    public static boolean rootToNodePath(Node node,int data,ArrayList<Integer> path){
        if(node.data==data){
            path.add(data);
            return true;
        }
        boolean res=false;
        path.add(node.data);
        for(int i=0;i<node.childs.size();i++){
            res=res||rootToNodePath(node.childs.get(i), data, path);                      
        }
        if(res!=true){
            path.remove(path.size()-1);
        }  
        return res;
    }    

    public static void levelorder(Node node){
        LinkedList<Node> que=new LinkedList<>();
        que.addLast(node);
        while(que.size()!=0){
            int s=que.size();
            while(s-->0){
                Node idx=que.removeFirst();
                System.out.print(idx.data+" ");
                for(int i=0;i<idx.childs.size();i++){
                    que.addLast(idx.childs.get(i));
                }
            }
        }
    }

//Main Questions===================================================================================================================================

    public static boolean isMirror(Node root1,Node root2){
        if(root1.childs.size()!=root2.childs.size()||root1.data!=root2.data) return false;

        for(int i=0,j=root1.childs.size()-1;j>=0;i++,j--){
            if(!isMirror(root1.childs.get(i),root2.childs.get(j))) return false;
        }
        return true;
    }

    public static Node linearize(Node root){
        if(root.childs.size()==0)return root;
        Node last=linearize(root.childs.get(root.childs.size()-1));
        for(int i=root.childs.size()-2;i>=0;i--){
            Node secondLast=linearize(root.childs.get(i));
            secondLast.childs.add(root.childs.get(root.childs.size()-1));
            root.childs.remove(root.childs.size()-1);
        }
        return last;
    }

    public static void flattern(Node node){
        ArrayList<Node>newCH=new ArrayList<>();

        for(Node child:node.childs){
            flattern(child);
            newCH.add(child);
            for(Node ch:child.childs){
                newCH.add(ch);
            }
            child.childs.clear();
        }       
        node.childs.clear();
        node.childs=newCH; 
    }


//===============================================================================================================================================
    public static void set1(Node node){
        // preorder(node);
        // System.out.println(height(node));
        // System.out.println(SizeofGT(node));
        // System.out.println(find(node,900));

        // ArrayList<Integer> path=new ArrayList<>();
        // rootToNodePath(node,90,path);
        // System.out.print(path+ " ");

        // levelorder(node);

        // System.out.println(isMirror(node,node));

        // linearize(node);
        // display(node);

        flattern(node);
        display(node);
    }

    public static void solve(){
        int[] ar={10,20,50,-1,60,-1,-1,30,70,-1,80,100,-1,110,-1,-1,90,-1,-1,40,120,140,-1,150,-1,-1,-1,-1};
        // int[] ar={1,2,3,-1,-1,2,3,-1,-1,-1};
        Node node=constructGTtree(ar);
        display(node);
        System.out.println();
        set1(node);
        
    }
    
}