#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
    int height;
};

class AvlTree{
public:
        struct Node * insert(struct Node *, int);
        struct Node * remove(struct Node *, int);
		struct Node * search(struct Node *, int);
		struct Node * LL(struct Node *);
		struct Node * RR(struct Node *);
		struct Node * LR(struct Node *);
		struct Node * RL(struct Node *);
        struct Node * findMin(struct Node *);
        struct Node * findMax(struct Node *);
		int height(struct Node *);
		void printTree(struct Node *,int);
		void inorder(struct Node *);
		void preorder(struct Node *);
		void postOrder(struct Node *);
		int big(int,int);
};
struct Node * AvlTree :: remove(struct Node *t,int val){
    struct Node *temp;
    if( t == NULL){
        return NULL;
    }
    else if(t->data > val){
        t->left  = remove(t->left,val);
        cout << height(t->left);
        if(height(t->right) - height(t->left) >=2 ){
            if(t->right->right != NULL){
                t = RR(t);
            } 
            else{
                t = RL(t);
            }
        }
    }
    else if(t->data < val){
        t->right = remove(t->right,val);
        cout << height(t->left) ;
        if (height(t->left) - height(t->right) >= 2)
        {
            if (t->left->left != NULL)
            {
                t = LL(t);
            }
            else
            {
                t = LR(t);
            }
        }
    }
    else{
        if(t->left!=NULL && t->right!=NULL){
            temp = findMax(t->left);
            t->data = temp->data;
            t->left = remove(t->left,temp->data);
            temp = NULL;
        }
        else{
            temp = t;
            if(t->left == NULL){
                t = t->right;
            }
            else if(t->right == NULL){
                t = t->left;
            }
            delete temp;
            temp = NULL;
        }
    }
    return t;
}
struct Node * AvlTree :: findMin(struct Node *root){
    if(root == NULL){
        return NULL;
    }
    else if(root->left == NULL && root->right == NULL){
        return root;
    }
    else if(root->left == NULL){
        return  root;
    }
    else{
        return findMin(root->left);
    }
}
struct Node * AvlTree :: findMax(struct Node *root){
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->left == NULL && root->right == NULL)
    {
        return root;
    }
    else if (root->right == NULL)
    {
        return root;
    }
    else
    {
        return findMax(root->right);
    }
}
struct Node * AvlTree :: insert(struct Node *root,int val){
    if(root == NULL){
        root = (struct Node *)malloc(sizeof(struct Node));
        root->data = val;
        root->left = root->right = NULL;
        root->height = 0;
        return root;
    }
    else if(root->data >val){
        root->left = insert(root->left,val);
        if((height(root->left) - height(root->right))>=2){
            if(val< root->left->data){
                root = LL(root);
            }
            else{
                root = LR(root);
            }
        }
    }
    else if(root->data < val){
        root->right = insert(root->right,val);
        if(height(root->right)-height(root->left) >= 2){
            if(val < root->right->data){
                root = RL(root);
            }
            else{
                root = RR(root);
            }
        }
    }
    else{
        cout<<"data already exist"<<endl;
        return root;
    }
    root->height = 1+ big(height(root->left),height(root->right));
    return root;
};
int AvlTree :: height(struct Node *root){
    if(root == NULL){
        return -1;
    }
    else if(root->left == NULL && root->right == NULL){
        return 0;
    }
    else if(root->left == NULL){
        return 1 + height(root->right);
    }
    else if(root->right == NULL){
        return 1 + height(root->left);
    }
    else{
        return 1 + big(height(root->left),height(root->right));
    }
}
struct Node * AvlTree :: LL(struct Node *t){
    struct Node *temp = t->left;
    t->left = temp->right;
    temp->right = t;

    temp->height = 1 + big(height(temp->left),height(temp->right));
    t->height = 1 + big(height(t->left),height(t->right));
    return temp;
}
struct Node * AvlTree :: RR(struct Node *t){
    struct Node *temp = t->right;
    t->right = temp->left;
    temp->left = t;
    temp->height = 1 + big(height(temp->left),height(temp->right));
    t->height = 1 + big(height(t->left),height(t->right));
    return temp;
}
struct Node * AvlTree :: LR(struct Node *t){
    t->left = RR(t->left);
    return LL(t);
}
struct Node * AvlTree :: RL(struct Node *t){
    t->right = LL(t->right);
    return RR(t);
}
int AvlTree :: big(int x,int y){
    return x>y?x:y;
}
void AvlTree :: inorder(struct Node *root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
void AvlTree :: printTree(struct Node *root,int level){
    if(root!=NULL){
        printTree(root->right,level + 1);
        for(int i=0;i<level;i++)
            cout<<"  ";
        cout<<root->data<<endl;
        printTree(root->left,level+1);
    }
}
struct Node * AvlTree :: search(struct Node *root,int val){
    if(root == NULL)
        return NULL;
    else if(root->data == val){
        return root;
    }
    else if(root->data < val){
        return search(root->right,val);
    }
    else if(root->data > val){
        return search(root->left,val);
    }
    return NULL;
}

void inorderNonrecursion(struct Node *t)
{
   if(t== NULL){
       return;
   }
   else{
       struct Node * stk[20];
       int top = -1;
       struct Node *curr = t;
       while(curr!=NULL || top != -1){
            while(curr!=NULL){
               stk[++top] = curr;
               curr = curr->left;
            }
            curr = stk[top--];
            cout<<curr->data<< " ";
            curr = curr->right;
       }
   }
}
int main(){
    struct Node *root = NULL;

    AvlTree obj;
    int n;
    for(int i=9;i>0;i--){
        root = obj.insert(root,i);
        
    }
    cout<<"The AVL Tree is"<<endl;
    obj.printTree(root,1);
    inorderNonrecursion(root);
}
