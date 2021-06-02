#include<stdlib.h>
#include<iostream>

using namespace std;

class HashTable{
    private:
        int size;
        int *H;
    public:
        HashTable(int n){
            this->size = n;
            H = (int *)calloc(size,sizeof(int));
        }
        int hashFunction(int val){
            return val%size;
        }
        void insert(int val){
            int i = hashFunction(val);
            for(int j =0;j<size;j++){
                int k = (i+j)%size;
                if(H[k] == 0){
                    H[k] = val;
                    break;
                }
            }
            display();
        }
        void deleteKey(int val){
            int i = searchKey(val);
            if(i!=-1){
                H[i] = 0;
            }
            else{
                cout<<"Element not found"<<endl;
            }
        }
        int searchKey(int val){
            int i = hashFunction(val);
            for(int j=0;j<size;j++){
                int k = (i + j)%size;
                if(H[k] == val){
                    return k;
                } 
            }
            return -1;
        }
        void display(){
            for(int i=0;i<size;i++){
                cout<< "[" << i << " : "<< H[i]<< "]"<<endl;
            }

        }
};

int main(){
    int size;
    cout<<"Enter the size of the HashTable";
    cin>>size;
    HashTable table(size);
    int ele;
    cout<<"1.Insert \n2.Remove \n3.Search \n4.Quit \n";
    while(1){
        cout<<"Enter choice";
        int choice;
        cin>>choice;
        switch(choice){
            case 1  :   cout<<"Enter the element to insert";
                        cin>>ele;
                        table.insert(ele);
                        break;
            case 2  :   cout << "Enter the element to remove";
                        cin >> ele;
                        table.deleteKey(ele);
                        table.display();
                        break;
            case 3  :   cout << "Enter the element to search";
                        cin >> ele;
                        if(table.searchKey(ele)!=-1){
                            cout<<"Element Found"<<endl;
                        }
                        else{
                            cout << "Element not Found" << endl;
                        }
                        break;
            case 4  :   exit(0);
        }
    }
    return 0;
}