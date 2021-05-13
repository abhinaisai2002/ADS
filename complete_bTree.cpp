#include<iostream>
#define MAX 20
using namespace std;
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

class CBT{
    public:
        struct Node * insertWithQ(struct Node *,int );
        int isEmpty(int f,int r);
        void printTree(struct Node *,int );
        void inorder(struct Node *);
};

struct Node * CBT :: insertWithQ(struct Node *t,int val){
    struct Node *temp;
    struct Node * q[MAX];
    if(t == NULL){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = val;
        t->left = t->right = NULL;
        return t;
    }
    else{
        int f = 0,r = 0;
        q[r++] = t;
        while(!isEmpty(f,r)){
            temp = q[f++];
            if(temp->left == NULL){
                temp->left = (struct Node *)malloc(sizeof(struct Node));
                temp = temp->left;
                temp->data = val;
                temp->left = temp->right = NULL;
                return t;
            }
            else if(temp->right == NULL){
                temp->right = (struct Node *)malloc(sizeof(struct Node));
                temp = temp->right;
                temp->data = val;
                temp->right = temp->left = NULL;
                return t;
            }
            else{
                q[r++] = temp->left;
                q[r++] = temp->right;
            }
        }
    }
    return t;
}
int CBT :: isEmpty(int f,int r){
    return (f==r);
}
void CBT :: inorder(struct Node *root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data;
        inorder(root->right);
    }
}
void CBT :: printTree(struct Node *root,int level){
    if(root != NULL){
        printTree(root->right,level + 1);
        for(int i=0;i<level;i++)
            cout<<"  ";
        cout<<root->data<<endl;
        printTree(root->left,level+1);
    }
}
int main(){
    CBT a ;
    struct Node *root = NULL;
    for(int i =0;i<5;i++){
        root = a.insertWithQ(root,i);
    }
    a.printTree(root,1);
}