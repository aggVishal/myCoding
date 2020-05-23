#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Node{
    public:
    int data;
    Node* left=nullptr;
    Node* right=nullptr;
    Node(int data){
        this->data=data;
    }
    Node(){

    }
};
int idx=0;
Node* constructTree(vector<int>& arr){
    if(idx>=arr.size()||arr[idx]==-1){
        idx++;
        return nullptr;
    }
    Node* node=new Node(arr[idx++]);
    node->left=constructTree(arr);
    node->right=constructTree(arr);
    return node;
}

void display(Node* root){
    if(root==nullptr) return;
    string str="";
    str+=((root->left==nullptr)?".":to_string(root->left->data));
    str+="<-"+to_string(root->data)+"->";
    str+=((root->right==nullptr)?".":to_string(root->right->data));
    cout<<str<<endl;
    display(root->left);
    display(root->right);
}

//Basic==================================================================================================================

int size(Node* root){
    if(root==nullptr){
        return 0;
    }
    return (size(root->left)+size(root->right)+1);
}

int height(Node* root){
    if(root==nullptr) return -1;
    return 1+max(height(root->left),height(root->right));
}

int Maximum(Node* root){
    if(root==nullptr) return INT_MIN;
    return max(root->data,max(Maximum(root->left),Maximum(root->right)));
}

int Minimum(Node* root){
    if(root==nullptr) return INT_MAX;
    return min(root->data,min(Minimum(root->left),Minimum(root->right)));
}

int Minimum02(Node* root){
    int min_=root->data;

    if(root->left!=nullptr) min_=min(min_,Minimum02(root->left));
    if(root->right!=nullptr) min_=min(min_,Minimum02(root->right));

    return min_;
}

bool find(Node* root,int data){
    if(root==nullptr){
        return false;
    }
    if(root->data==data) return true;
    return find(root->left,data)||find(root->right,data);
}

//Traversal==============================================================================================================

void preorder(Node* root){
    if(root==nullptr) return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(root==nullptr) return;
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(Node* root){
    if(root==nullptr) return;
    
    postorder(root->left);    
    postorder(root->right);
    cout<<root->data<<" ";
}

//Quetions=============================================================================================================

bool rootToNodePath(Node* root,int data,vector<Node*>& path){
    if(root==nullptr) return false;

    if(root->data==data) {
        path.push_back(root);
        return true;
    }

    bool res= rootToNodePath(root->left,data,path)||rootToNodePath(root->right,data,path);
    if(res){
        path.push_back(root);        
    }
    return res;
}

//leetcode 236

Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    vector<Node*>path1;
    vector<Node*>path2;
    rootToNodePath(root,p->data,path1);
    rootToNodePath(root,q->data,path2);
    Node* prev=nullptr;
    int i=path1.size()-1;
    int j=path2.size()-1;
       
    while(i>=0 && j>=0){
        if(path1[i]->data!=path2[j]->data) break;
          
        prev=path1[i];
        i--;
        j--;
    }
    return prev;            
}

//************************************************************************************************************************
void solve(){
    vector<int> arr={10,20,40,-1,-1,50,80,-1,-1,90,-1,-1,30,60,100,-1,-1,-1,70,110,-1,-1,120,-1,-1};
    Node* root=constructTree(arr);
    display(root);
    // cout<<find(root,60)<<endl;

    // vector<Node*> path;
    // rootToNodePath(root,80,path);    
    // for(int i=0;i<path.size();i++){
    //     cout<<path[i]->data<<" ";
    // }

    
}

int main(){
    solve();
}