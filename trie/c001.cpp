//Trie Basic

#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int wordlen;
    vector<Node*> child;
    string word;
    Node(){
        wordlen=0;
        child.resize(26,nullptr);
        word="";
    }
};
Node* root=nullptr;

//insert
void insert(string word){
    Node* curr=root;
    int n=word.length();
    for(int i=0;i<n;i++){
        int idx=word[i]-'a';
        if(curr->child[idx]==nullptr){
            curr->child[idx]=new Node;
        }
        curr=curr->child[idx];
    }
    curr->wordlen++;
    curr->word=word;
}

//search
bool search(string word){
    Node* curr=root;
    int n=word.length();
    for(int i=0;i<n;i++){
        int idx=word[i]-'a';
        if(curr->child[idx]==nullptr) return false;
        curr=curr->child[idx];
    }
    return curr->wordlen!=0;
}

//search prefix (leetcode 208)
bool startsWith(string word){
    int n=word.length();
    Node* curr=root;
    for(int i=0;i<n;i++){
        int idx=word[i]-'a';            
        if(curr->child[idx]==nullptr) return false;            
        curr=curr->child[idx];
    }
    return true; 
}

//search something word like (..ple) (leetcode 211)
bool searchSomething_(Node* root,int idx,string word){
    if(idx==word.length()){
        return root->wordlen>0;
    }
    char ch=word[idx];
    Node* curr=root;
    bool res=false;
    if(ch=='.'){
        for(int i=0;i<26;i++){
            if(curr->child[i]!=nullptr){
                res=res||searchSomething_(curr->child[i],idx+1,word);
            }
        }
    }
    else{
            int i2=ch-'a';
            if(curr->child[i2]!=nullptr){
                res=res||searchSomething_(curr->child[i2],idx+1,word);                
            }        
    }
    return res;
}
bool searchSomething(string word) {
    return searchSomething_(root,0,word);
}

//delete
void remove_once(string word){
    Node* curr=root;
    int n=word.length();
    for(int i=0;i<n;i++){
        int idx=word[i]-'a';
        if(curr->child[idx]==nullptr)  cout<<"word not found!!";
        curr=curr->child[idx];
    }
    if(curr->wordlen==0) cout<<"word not found";
    else{
        curr->wordlen--;
        cout<<"'word removed!";
    }
}

//leetcode 212
void dfs_212(vector<vector<char>>& board,Node* root,vector<bool>& vis,int r,int c,vector<string>& ans){
        if(root->wordlen!=0){
            ans.push_back(root->word);
            root->wordlen=0;
        }
        int n=board.size();
        int m=board[0].size();
        vis[r*m+c]=true;
        vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
        for(int d=0;d<4;d++){
            int x=r+dir[d][0];
            int y=c+dir[d][1];
            if(x>=0&&y>=0&&x<n&&y<m&&root->child[board[x][y]-'a']!=nullptr&&!vis[x*m+y]){
                dfs_212(board,root->child[board[x][y]-'a'],vis,x,y,ans);
            }
        }
        vis[r*m+c]=false;
        return;
}
vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root=new Node;
        vector<string>ans;
        int n=board.size();
        int m=board[0].size();
        for(string w:words){
            insert(w);
        }      
        vector<bool> vis(n*m,false);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(root->child[board[i][j]-'a']!=nullptr){
                    dfs_212(board,root->child[board[i][j]-'a'],vis,i,j,ans);
                }
            }
        }
        return ans;
}


/*
LeetCode 642 (Design search autocomplete system)

https://leetcode.com/problems/design-search-autocomplete-system/description/

Design a search autocomplete system for a search engine. 
Users may input a sentence (at least one word and end with a special character '#'). 
For each character they type except '#', you need to return the top 3 historical hot sentences 
that have prefix the same as the part of sentence already typed. 
Here are the specific rules:
The hot degree for a sentence is defined as the number of times a user typed the exactly same sentence before.
The returned top 3 hot sentences should be sorted by hot degree (The first is the hottest one). 
If several sentences have the same degree of hot, you need to use ASCII-code order (smaller one appears first).
If less than 3 hot sentences exist, then just return as many as you can.
When the input is a special character, it means the sentence ends, and in this case, you need to return an empty list.
Your job is to implement the following functions:
The constructor function:
- AutocompleteSystem(String[] sentences, int[] times): This is the constructor. 
The input is historical data. Sentences is a string array consists of previously typed sentences. 
Times is the corresponding times a sentence has been typed. Your system should record these historical data.
- Now, the user wants to input a new sentence. The following function will provide the next character the user types:
List<String> input(char c): The input c is the next character typed by the user. 
The character will only be lower-case letters ('a' to 'z'), blank space (' ') or a special character ('#'). 
Also, the previously typed sentence should be recorded in your system. 
The output will be the top 3 historical hot sentences that have prefix the same as the part of sentence already typed.
Example:
Operation: AutocompleteSystem(["i love you", "island","ironman", "i love leetcode"], [5,3,2,2]) 
The system have already tracked down the following sentences and their corresponding times: 
"i love you" : 5 times 
"island" : 3 times 
"ironman" : 2 times 
"i love leetcode" : 2 times 
Now, the user begins another search: 
Operation: input('i') 
Output: ["i love you", "island","i love leetcode"] 
Explanation: 
There are four sentences that have prefix "i". Among them, "ironman" and "i love leetcode" have same hot degree. 
Since ' ' has ASCII code 32 and 'r' has ASCII code 114, "i love leetcode" should be in front of "ironman".
Also we only need to output top 3 hot sentences, so "ironman" will be ignored. 
Operation: input(' ') 
Output: ["i love you","i love leetcode"] 
Explanation: 
There are only two sentences that have prefix "i ". 
Operation: input('a') 
Output: [] 
Explanation: 
There are no sentences that have prefix "i a". 
Operation: input('#') 
Output: [] 
Explanation: 
The user finished the input, the sentence "i a" should be saved as a historical sentence in system. 
And the following input will be counted as a new search. 
Note:
The input sentence will always start with a letter and end with '#', and only one blank space will exist between two words.
The number of complete sentences that to be searched won't exceed 100. The length of each sentence including those in the historical data won't exceed 100.
Please use double-quote instead of single-quote when you write test cases even for a character input.
Please remember to RESET your class variables declared in class AutocompleteSystem, as static/class variables are persisted across multiple test cases. Please see here for more details.
*/

//leetcode 642 

vector<string> findpre(string word){
    int n=word.length();
    Node* curr=root;
    vector<string> ans;
    for(int i=0;i<n;i++){
        int idx=word[i]-'a';            
        if(curr->child[idx]==nullptr) return ans;            
        curr=curr->child[idx];
    }    
    // while(curr!=nullptr){
    //     if(curr->wordlen!=0){
    //         ans.push_back(curr->word);
    //     }
    //     int x=0;
    //     for(int i=0;i<26;i++){            
    //         if(curr->child[i]!=nullptr){
    //             curr=curr->child[i];
    //             x++;
    //         }           
    //     }
    //     if(x==0){
    //         break;
    //     }
    // }

    return ans;
}

void findbest3(){
    vector<string> words={"ababcd","abcd","acd","abbbbb","abcabc"};
    vector<int> times={2, 3, 7, 1, 6};
    //vector<string> ans;
    root=new Node;
    for(int i=0;i<words.size();i++){
        insert(words[i]);
    }
    string str="ab";             //to search prefix
    vector<string> ans=findpre(str);
    
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
}

//**********************************************************************************************************************
//**********************************************************************************************************************
void solve(){
    // root=new Node;
    // insert("apple");
    // insert("appli");
    // insert("app");
    // cout<<search("app")<<endl;
    // cout<<search("appl")<<endl;
    // cout<<startsWith("applei")<<endl;
    // cout<<searchSomething("a..")<<endl;
    findbest3();       // leetcode 642
}
int main(){
    solve();
}