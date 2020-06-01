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

};

Node *constructBST(vector<int> &arr,int si,int ei)
{
    if(si>ei) return nullptr;
    int mid=(si+ei)/2;
    Node* node=new Node(arr[mid]);
    node->left=constructBST(arr,si,mid-1);
    node->right=constructBST(arr,mid+1,ei);    

    return node;
}

void display(Node *node)
{
    if (node == nullptr)
        return;

    string str = "";
    str += ((node->left != nullptr) ? to_string(node->left->data) : ".");
    str += " <- " + to_string(node->data) + " -> ";
    str += ((node->right != nullptr) ? to_string(node->right->data) : ".");
    cout << (str) << endl;

    display(node->left);
    display(node->right);
}

void updateHeightAndBalance(Node* node){
    int lh=-1;
    int rh=-1;
    if(node->left!=nullptr)lh=node->left->height;
    if(node->right!=nullptr)rh=node->right->height;
    node->height=max(lh,rh)+1;
    node->bal=lh-rh;
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


void set1(){
    
}

void solve()
{
    vector<int> arr = {10,20,30,40,50,60,70,80,90,100,110,120,130};
    Node *root = constructBST(arr,0,arr.size()-1);
    // display(root);

    set1(root);
}

int main(){
    solve();
    return 0;
}