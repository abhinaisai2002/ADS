#include<iostream>
using namespace std;
void display(int [],int );
void heapSort(int [],int);
void buildHeap(int [],int ,int);
int main(){
    cout<<"Enter the size of the array";
    int n;
    cin>>n;
    int a[n];
    cout<<"Enter the array elements";
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"Before Sorting..."<<endl;
    display(a,n);
    heapSort(a,n-1);
    cout<<"After Sorting..."<<endl;
    display(a,n);
    return 0;
}
void display(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" "<<endl;
    }
}
void heapSort(int a[],int n){
    int low = (n%2==0)?(n-1)/2:n/2;
    for(int i = low;i>=0;i--){
        buildHeap(a,i,n);
    }
    for(int j=n;j>=0;j--){
        int temp = a[j];
        a[j] = a[0];
        a[0] = temp;
        buildHeap(a,0,j-1);
    }
}
void buildHeap(int a[],int node,int bottom){
    int left = node*2 + 1;
    int right = node*2 + 2;
    int smallest = node;
    if(left<=bottom && a[smallest] > a[left]){
        smallest = left;
    }
    if(right<=bottom && a[smallest] > a[right]){
        smallest = right;
    }
    if(smallest!=node){
        int temp = a[node];
        a[node] = a[smallest];
        a[smallest] = temp;
        buildHeap(a,smallest,bottom);
    }

}
