//  Permutations of a String (all cases)

import java.util.*;
public class c002 {
    public static void main(String[]args){
        String s="abcd";
        Permutations_without_dupli01(s,"");
        //System.out.println(ans);
    }

    public static ArrayList<String> permutations_with_dupli_ret(String s) {
        if(s.length()==1){
            ArrayList<String> ans=new ArrayList<String>();
            ans.add(s);
            return ans;
        }
        char ch=s.charAt(0);
        ArrayList<String> smallans=new ArrayList<String>();
        ArrayList<String> ans=new ArrayList<String>();
        smallans=permutations_with_dupli_ret(s.substring(1));
        for(String ns:smallans){
            for(int i=0;i<=ns.length();i++){
                String a=ns.substring(0,i)+ch+ns.substring(i);
                ans.add(a);
            }            
        }
        return ans;
    } 
    
    public static void permutations_with_dupli_void(String str,String ans){
        if(str.length()==0){
            System.out.println(ans);
            return;
        }

        for(int i=0;i<str.length();i++){
            char ch=str.charAt(i);
            String smallstr=str.substring(0,i)+str.substring(i+1);
            permutations_with_dupli_void(smallstr, ans+ch);
        }
        return;
    }


    public static void Permutations_without_dupli01(String s,String ans){
        if(s.length()==0){
            System.out.println(ans);
            return;
        }
        int visited[] =new int[26];
        for(int i=0;i<s.length();i++){
            visited[i]=0;
        }
        for(int i=0;i<s.length();i++){
            char ch=s.charAt(i);
            int idx=ch-'a';            
            if(visited[idx]==0){
                visited[idx]++;
                String smallstr=s.substring(0,i)+s.substring(i+1);
                Permutations_without_dupli01(smallstr, ans+ch);
            }
        }
        return;
    } 
}