#include<iostream>
using namespace std;

class mystack{
    int N=1000;
    int* arr;
    int sz=0;
    int idx=-1;

    public:
    mystack(){ 
        this->arr=new int[N];   
    }    
    mystack(int val){
        this->arr=new int [val];
        this->N=val;
    }

    int size(){
        return this->sz;
    }
    bool empty(){
        return this->sz==0;
    }

    void push(int data){
        if(this->sz==this->N){
            return;
        }
        this->idx++;
        this->sz++;
        this->arr[idx]=data;
    }

    void pop(){
        if(sz==0)return ;
        this->sz--;
        this->idx--;
    }

    int top(){
        if(sz==0)return -1;
        return this->arr[idx];
    }
};


void solve(){
    mystack st;
    for(int i=0;i<10;i++){
        st.push(i+10);
    }
    while(st.size()!=0){
        cout<<st.top()<<" ";
        st.pop();
    }
}

int main(){
    solve();
}