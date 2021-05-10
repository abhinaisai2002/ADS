#include <iostream>
#define MAX 10
using namespace std;
class HashTable{
    private:
        int *ht;
    public:
        HastTable(){
            ht = (int *)calloc(MAX,sizeof(int));
        }
        int hashKey(int n){
            return n%MAX;
        }
        void insert(int val){
            ht[hashKey(val)] = val;
        }
        int search(int val){
            if(ht[hashKey(val)] == val)
                return hashKey(val);
            return -1;
        }
        void remove(int val){
            int i=search(val);
            if(i!=-1){
                ht[i] = 0;
                printf("Element removed \n");
            }
            else{
                printf("Element not found to delete \n");
            }
        }
};
int main()
{
    HashTable h1;
    int a[5] = {1,2,8,4,5};
    for(int i=0;i<5;i++){
        h1.insert(a[i]);
    }
    h1.remove(5);
    h1.remove(3);
    if(h1.search(1)!=-1)
        cout << "Found" <<endl;
    else
        cout<< "Not Found" << endl;
    if(h1.search(56)!=-1)
        cout << "Found" <<endl;
    else
        cout<< "Not Found" << endl;

    return 0;

}

