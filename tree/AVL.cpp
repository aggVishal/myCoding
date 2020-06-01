//AVL============================================================================================================

#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int data;
    Node* left = nullptr;  // Node* left=nullptr;
    Node* right = nullptr; // Node* right=nullptr;
    int height=0;
    int bal=0;
    Node(int data)
    {
        this->data = data;
        this->height=0;
        this->bal=0;
    }
    Node()
    {
    }

};


void updateHeightAndBalance(Node* node){
    int lh=-1;
    int rh=-1;
    if(node->left!=nullptr)lh=node->left->height;
    if(node->right!=nullptr)rh=node->right->height;
    node->height=max(lh,rh)+1;
    node->bal=lh-rh;
}

Node *constructBST(vector<int> &arr,int si,int ei)
{
    if(si>ei) return nullptr;
    int mid=(si+ei)/2;
    Node* node=new Node(arr[mid]);
    node->left=constructBST(arr,si,mid-1);
    node->right=constructBST(arr,mid+1,ei);    

    updateHeightAndBalance(node);
    return node;
}

void display(Node *node) // O(n)
{
    if (node == nullptr)
        return;

    string str = "";
    str += ((node->left != nullptr) ? to_string(node->left->data) + "[" + to_string(node->left->bal) + "," + to_string(node->left->height) + "]" : ".");
    str += " <- " + to_string(node->data) + "[" + to_string(node->bal) + "," + to_string(node->height) + "]" + " -> ";
    str += ((node->right != nullptr) ? to_string(node->right->data) + "[" + to_string(node->right->bal) + "," + to_string(node->right->height) + "]" : ".");
    cout << (str) << endl;

    display(node->left);
    display(node->right);
}


//left-left
Node* left_left(Node* A){
    Node* B=A->left;
    Node* BkaRight=B->right;
    B->right=A;
    A->left=BkaRight;

    updateHeightAndBalance(A);
    updateHeightAndBalance(B);    
    return B;
}

//right-right
Node* right_right(Node* A){
    Node* B=A->right;
    Node* BkaLeft=B->left;
    B->left=A;
    A->right=BkaLeft;

    updateHeightAndBalance(A);
    updateHeightAndBalance(B);        
    return B;
}

Node* check_Rotation(Node* node){
    updateHeightAndBalance(node);
    if(node->bal==2){  //lr or ll
        if(node->left->bal==1){   //ll
            return left_left(node);
        }
        else{ //lr
            node->left=right_right(node->left);
            return left_left(node);
        }
    }
    else if(node->bal==-2){ //rl or rr
        if(node->right->bal==-1){   //rr
            return right_right(node);
        }
        else{   //rl
            node->right=left_left(node->right);
            return right_right(node);            
        }
    }
    return node;
}
Node* addData(Node*node,int data){
    if(node==nullptr)return new Node(data);

    if(data<node->data) node->left=addData(node->left,data);
    else if(data>node->data) node->right=addData(node->right,data);
    return check_Rotation(node);
}
int maximunEle(Node* node){
    Node *curr = node;
    while (curr->right != nullptr)
        curr = curr->right;

    return curr->data;
}
Node* deleteData(Node* node,int data){
    if(node==nullptr)return nullptr;

    if(node->data>data) node->left= deleteData(node->left,data);
    else if(node->data<data) node->right= deleteData(node->right,data);
    else{
        node->data=maximunEle(node->left);
        node->left=deleteData(node->left,node->data);
    }
    return check_Rotation(node);
}

//===================================================================================================================

void set1(Node*root){
    root=addData(root,65);
    root=addData(root,66);
    root=addData(root,67);
    display(root);

}

void solve()
{
    vector<int> arr = {10,20,30,40,50,60,70,80,90,100,110,120,130};
    Node *root = constructBST(arr,0,arr.size()-1);
    display(root);
    cout<<endl<<endl<<endl;

    set1(root);
}

int main(){
    solve();
    return 0;
}