import java.util.*;
class c001{
    public static void main(String[] args){
        String s="abc";
        subsequence_void(s,"");
        //System.out.println(ans);
    }

    public static ArrayList<String> subsequence_ret(String s){
        if(s.length()==0){
            ArrayList<String> ans=new ArrayList<String>();
            ans.add("");
            return ans;
        }

        char ch=s.charAt(0);
        ArrayList<String> smallans=subsequence_ret(s.substring(1));
        ArrayList<String> ans=new ArrayList<String>();
        for(String ns:smallans){
            ans.add(ns);
            ans.add(ch+ns);
        }      
        return ans; 
    }
    public static void subsequence_void(String str,String ans){
        if(str.length()==0){
            System.out.println(ans);
            return;
        }

        //int count=0;
        subsequence_void(str.substring(1),ans);
        char ch=str.charAt(0);
        subsequence_void(str.substring(1), ans+ch);
        return;
    }
}