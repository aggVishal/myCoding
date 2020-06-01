//BST============================================================================================================

#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int data;
    Node* left = nullptr;  // Node* left=nullptr;
    Node* right = nullptr; // Node* right=nullptr;

    Node(int data)
    {
        this->data = data;
    }

    Node()
    {
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

//Basic=====================================================================================================
int height(Node* node){
    if(node==nullptr)return -1;
    return 1+max(height(node->left),height(node->right));
}

int size(Node* node){
    if(node==nullptr)return 0;

    return 1+size(node->left)+size(node->right);
}

bool find(Node* node,int data){
    Node* curr=node;
    while(curr!=nullptr){
        if(curr->data==data) return true;
        else if(curr->data>data) curr=curr->left;
        else curr=curr->right;
    }
    return false;
}

bool find_recursion(Node* curr,int data){ //extra stack space of recursion
    if(curr->data==data) return true;
    else if(curr->data>data) find_recursion(curr->left,data);
    else find_recursion(curr->right,data);
    return false;
}

int max_element(Node* root){
    Node* curr=root;
    while(curr->right!=nullptr){
        curr=curr->right;
    }
    return curr->data;
}

int min_element(Node* root){
    Node* curr=root;
    while(curr->left!=nullptr){
        curr=curr->left;
    }
    return curr->data;
}

//Questions================================================================================================

//leetcode 235 (LCA of BST)

Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    Node* curr=root;
    while(curr!=nullptr){
        if(root->data > p->data && root->data > q->data){
            curr=curr->left;
        }
        else if(root->data < p->data && root->data < q->data){
            curr=curr->right;
        }
        else{
            return curr;
        }
    }
    return nullptr;
}

//Add all data in the range of 'a' and 'b'
void allNodesInRange_01(Node *node, int a, int b, vector<int> &ans){    //using Inorder property of BST
    if(node==nullptr)return;
    
    allNodesInRange_01(node->left,a,b,ans);

    if(node->data>=a&&node->data<=b){
        ans.push_back(node->data);
    }
    if(node->data>b)return;

    allNodesInRange_01(node->right,a,b,ans);
}

void allNodesInRange_02(Node *node, int a, int b, vector<int> &ans)
{
    if (node == nullptr)
        return;
    if (node->data >= a && node->data <= b)
        ans.push_back(node->data);

    if (b < node->data && a < node->data)
        allNodesInRange_02(node->left, a, b, ans);
    else if (a > node->data && b > node->data)
        allNodesInRange_02(node->right, a, b, ans);
    else //LCA Region.
    {
        allNodesInRange_02(node->left, a, b, ans);
        allNodesInRange_02(node->right, a, b, ans);
    }
}


//Leetcode: 98 - validate-binary-search-tree================

long long prevData = -1e12;
bool isValidBST(TreeNode *root)
{
    if (root == nullptr)
        return true;

    if (!isValidBST(root->left))
        return false;

    if (prevData >= root->val)
        return false;
        
    prevData = root->val;

    if (!isValidBST(root->right))
        return false;

    return true;
}

//Leetcode 99: recover-binary-search-tree==========================

TreeNode *a = nullptr;
TreeNode *b = nullptr;
TreeNode *c = nullptr; // previous.

bool recoverTree_(TreeNode *root)
{
    if (root == nullptr)
        return false;

    if (recoverTree_(root->left))
        return true;

    if (c != nullptr && c->val > root->val)
    {
        b = root; // first time it may be wrong.
        if (a == nullptr)
            a = c; // a always br previous
        else
            return true;
    }
    
    c = root;  // set previous.

    if (recoverTree_(root->right))
        return true;

    return false;
}

void recoverTree(TreeNode *root)
{
    recoverTree_(root);
    if (a != nullptr)
    {
        int temp = a->val;
        a->val = b->val;
        b->val = temp;
    }
}



//Predessor and Successor

class AllSolution{
    public:
    Node* pred=nullptr;
    Node* succ=nullptr;
    Node* prev=nullptr;
};

void allSol(Node* node,int data,AllSolution* pair){   //recursive approach or O(n) approach
    if(node==nullptr)return;                          // can be done iteratively also by O(n)

    allSol(node->left,data,pair);
    if(pair->prev==nullptr){
        pair->prev=node;
    }
    else{
        if(pair->prev->data==data) pair->succ=node;

        else if(node->data==data) pair->pred=pair->prev;
    }
    pair->prev=node;
    allSol(node->right,data,pair);
}

void allSol_Inorder(Node* node,int data){              //iterative approach or O(logn) approach
    Node* curr=node;                                   //cannot be done for preorder or by recursion
    Node* pred=nullptr;
    Node* succ=nullptr;              
    while(curr!=nullptr){
        if(curr->data==data){
            //for predessor
            if(curr->left==nullptr){
                cout<<"Pred: "<<((pred==nullptr)?-1:pred->data)<<endl;
            }
            else{
                pred=curr->left;
                while(pred->right!=nullptr){
                    pred=pred->right;
                }
                cout<<"Pred: "<<pred->data<<endl;
            }
            //for successor
            if(curr->right==nullptr){
                cout<<"Succ: "<<((succ==nullptr)?-1:succ->data)<<endl;
            }
            else{
                succ=curr->right;
                while(succ->left!=nullptr){
                    succ=succ->left;
                }
                cout<<"Succ: "<<succ->data<<endl;
            }
        }    
        if(data<curr->data){
            succ=curr;
            curr=curr->left;
        }  
        else{
            pred=curr;
            curr=curr->right;
        }  
    }
}

//leetcode 701     (in lintcode 448)
Node * inorderSuccessor(Node * root, Node * p) {
    Node* curr=root;
    Node* succ=nullptr;
    while(curr!=nullptr){
        if(curr->data==p->data){
            if(curr->right!=nullptr){
                succ=curr->right;
                while(succ->left!=nullptr){
                    succ=succ->left;
                }
            }
            break;
        }
        else if(curr->val>p->data){
            succ=curr;
            curr=curr->left;
        }
        else{
            curr=curr->right;
        }
    }
    return succ;
}

//leetcode 450     https://github.com/grandyang/leetcode/issues/510



//Leetcode 1008 :  Construct Binary Search Tree from Preorder Traversal of that BST
int idx=0;
Node* BSTfromPreorder(vector<int>& preorder,int l,int r){
    
    if(idx==preorder.size()||preorder[idx]<l||preorder[idx]>r){
        return nullptr;
    }
    int ele=preorder[idx];
    Node* node=new Node(ele);
    idx++;
    node->left=BSTfromPreorder(preorder,l,node->data);
    node->right=BSTfromPreorder(preorder,node->data,r);
    return node;    
}

int heightOfBSTPreorder(vector<int> &preOrder, int lb, int rb)
{
    if (idx == preOrder.size() || preOrder[idx] < lb || preOrder[idx] > rb)
        return -1;

    int ele = preOrder[idx];
    idx++;

    int lh = heightOfBSTPreorder(preOrder, lb, ele);
    int rh = heightOfBSTPreorder(preOrder, ele, rb);
    return max(lh, rh) + 1;
}

//leetcode 701
Node *addData(Node *root, int data)
{
    if (root == nullptr)
        return new Node(data);
    if (data < root->data)
        root->left = addData(root->left, data);
    else
        root->right = addData(root->right, data);

    return root;
}

//leetcode 450
Node *deleteNode(Node *root, int data)
{
    if (root == nullptr)
        return nullptr;  // never found data;
    
    if (data < root->data)
        root->left = removeData(root->left, data);
    else if(data > root->data)
        root->right = removeData(root->right, data);
    else{  // data found.
      
       if(root->left == nullptr || root->right == nullptr) 
       return root->left!=nullptr?root->left:root->right;
       
       int maxInleft=maximumEle(root->left);
       root->data=maxInleft;
       root->left=removeData(root->left,maxInleft);
    
    }
    return root;
}



//==================================================================================================================
//==================================================================================================================
void set1(Node* node){
    // vector<int> ans;
    // allNodesInRange_01(node,10,130,ans);
    // for(int i=0;i<ans.size();i++){
    //     cout<<ans[i]<<endl;
    // }
    
    // AllSolution* pair=new AllSolution();
    // allSol(node,30,pair);
    // cout<<pair->pred->data<<endl;
    // cout<<pair->succ->data;

    // allSol_Inorder(node,30);

    // vector<int> preorder={8,5,1,7,10,12};
    // display(BSTfromPreorder(preorder,-1e9,1e9));
    // cout<<heightOfBSTPreorder(preorder,-1e9,1e9);

    // display(addData(node,35));
    display(deleteNode(node,35));
    

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
