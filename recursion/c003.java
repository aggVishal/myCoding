// Keypad Problem

import java.util.*;
import java.util.ArrayList;
public class c003 {
    public static void main(String []args){
        String s="578";
        ArrayList<String> ans =possiblestrings(s);
        System.out.println(ans);
        return;
    }
    

    public static ArrayList<String> possiblestrings(String s){
        
        int idx=s.charAt(0)-'0';
        String word=words.get(idx);

        if(s.length()==0){
            ArrayList<String> ans=new ArrayList<String>();
            ans.add("");
            return ans;
        }        
        
        ArrayList<String> smallans=possiblestrings(s.substring(1));
        ArrayList<String> ans=new ArrayList<String>();
        for(String str: smallans){
            for(int i=0;i<word.length();i++){
                ans.add(str+word.charAt(i));
            }
        }
        return ans;
    }

}