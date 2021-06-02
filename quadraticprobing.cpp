#include<stdlib.h>
#include<iostream>
using namespace std;
class HashTable{
    private:
        int size;
        int *H;
    public:
        HashTable(int size){
            this->size = size;
            H = (int *)calloc(size,sizeof(int));
        }  
        int hashFunction(int val){
            return val%size;
        }
        void display(){
            for(int i=0;i<size;i++){
                cout<<"["<<i<<":"<<H[i]<<"]"<<endl;
            }
        }
        void insert(int val){
            int i = hashFunction(val);
            for (int j=0;j<size;j++){
                int k = (i+(j*j))%size;
                if(H[k] == 0 ){
                    H[k] = val;
                    break;
                }
            }
            display();
        }
        void deleteKey(int val){
            int k = search(val);
            if(k!=-1){
                H[k] = 0;
            }
            else{
                cout<<"element not found";
            }
        }
        int search(int val){
            int i = hashFunction(val);
            for(int j=0;j<size;j++){
                int k = (i+(j*j))%size;
                if(H[k] == val){
                    return k;
                }
            }
            return -1;
        }
};

int main()
{
    int size;
    cout << "Enter the size of the HashTable";
    cin >> size;
    HashTable table(size);
    int ele;
    cout << "1.Insert \n2.Remove \n3.Search \n4.Quit \n";
    while (1)
    {
        cout << "Enter choice";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the element to insert";
            cin >> ele;
            table.insert(ele);
            break;
        case 2:
            cout << "Enter the element to remove";
            cin >> ele;
            table.deleteKey(ele);
            table.display();
            break;
        case 3:
            cout << "Enter the element to search";
            cin >> ele;
            if (table.search(ele) != -1)
            {
                cout << "Element Found" << endl;
            }
            else
            {
                cout << "Element not Found" << endl;
            }
            break;
        case 4:
            exit(0);
        }
    }
    return 0;
}