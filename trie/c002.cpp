#include <iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int wordlen;
    vector<Node*> child;
    
    Node(){
        wordlen=0;
        child.resize(26,nullptr);
        
    }
};
Node* root=nullptr;
void insert(string word){
    int n=word.length();
    Node* curr=root;
    for(int i=0;i<n;i++){
        int idx=word[i]-'a';
        if(curr->child[idx]==nullptr){
            curr->child[idx]=new Node;
        }
        curr=curr->child[idx];
    }
    curr->wordlen++;
}



int question_(Node* head,int k,int l,bool& res){
    int count=0;
    if(head->wordlen!=0){
        count++;
    }
    for(int i=0;i<26;i++){
        if(head->child[i]!=nullptr){
            count+=question_(head->child[i],k,l-1,res);
        }
    }
    if(l==0){
        if(k<=count){
            res=true;
        }
    }
    return count;
}
bool question(int k,int l){
    bool res=false;
    int totalstr=question_(root,k,l,res);
    return res;
}

void remove(string word){
    Node* curr=root;
    int n=word.length();
    for(int i=0;i<n;i++){
        int idx=word[i]-'a';
        curr=curr->child[idx];
    }
    curr->wordlen--;
}

int main() {
    root=new Node;
    int q;
	cin>>q;
	vector<string> str;
	while(q-->0){
	    int n;
	    cin>>n;
	    string s="";
	    if(n==1){
	        cin>>s;
	        insert(s);
	    }
	    else if(n==2){
	        int k,l;
	        cin>>k>>l;
	        cout<<question(k,l)<<endl;
	    }
	    else if(n==3){
	        int no;
	        cin>>no;
	        if(str[no-1]!=""){
	            remove(str[no-1]);
	            str[no-1]="";
	        }
	    }
	    str.push_back(s);
	}
	return 0;
}
