#include<stdlib.h>
#include<iostream>
#include<stdio.h>

using namespace std;
struct node{
    int data;
    struct node *previous;
    struct node *next;
};
typedef struct node Node;
class DoubleL{
private:
    Node *head;
    Node *tail;
    int length;
public:
    DoubleL(){
        head = tail = NULL;
        length = 0;
    }
    void display(){
        Node *temp = head;

        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<""<<endl;
    }
    void insert(int val){
        Node *n = (Node *)malloc(sizeof(Node));
        n->data = val;
        n->previous = n->next = NULL;
        if(head == NULL){
            head = tail = n;
        }
        else{
            tail->next = n;
            n->previous = tail;
            tail = n;
        }
        length++;
    }
    Node *search(int val){
        Node *temp = head;
        while(temp!=NULL){
            if(temp->data == val)
                return temp;
            temp = temp->next;
        }
        return NULL;
    }
    void remove(int val){
        Node *t = search(val);
        if(t!=NULL){
            Node *p = t->previous;
            Node *n = t->next;
            if(n!=NULL){
                n->previous = p;
            }
            else{
                tail = p;
            }
            if(p!=NULL){
                p->next = n;
            }
            else{
                head = n;
            }
            free(t);
        }
    }
};
void display(DoubleL [],int);
int main(){
    int length;
    cin>>length;
    DoubleL lst[length];
    while(1){
        cout<<"Enter choice"<<endl;
        int choice;
        cin>>choice;
        switch(choice){
        case 1: cout<<"enter element to insert"<<endl;
                int element;
                cin>>element;
                lst[element%length].insert(element);
                display(lst,length);
                break;
        case 2: cout<<"enter element to delete"<<endl;

                cin>>element;
                lst[element%length].remove(element);
                display(lst,length);
                break;
        case 3:cout<<"enter element to search"<<endl;

                cin>>element;
                if(lst[element%length].search(element)!=NULL)
                    cout<<"FOund"<<endl;
                else
                    cout<<"Not found"<<endl;
                break;
        default :
            exit(0);

        }
    }
    return 0;
}
void display(DoubleL l[],int n){
    for(int i=0;i<n;i++){
        cout<<i<<":";
        l[i].display();
    }
}
