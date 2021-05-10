#include <iostream>

using namespace std;
void display(int a[],int );
void heapSort(int a[],int );
void buildHeap(int a[],int  ,int );
int main()
{
    int n;
    cout<<"Enter the array size " << endl;
    cin>>n;
    int a[n];
    cout<<"Enter the array elements"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"Before sorting .... "<<endl;
    display(a,n);
    heapSort(a,n-1);
    cout<<"After sorting .... "<<endl;
    display(a,n);
    return 0;
}
void display(int a[],int n){
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<""<<endl;
}
void heapSort(int a[],int n){
    // heap build max heap
    int i= (n%2==0?(n-1)/2:n/2);
    for(i;i>=0;i--){
        buildHeap(a,i,n);
    }
    // heap sort
    for(int j = n;j>=0;j--){
        int temp = a[0];
        a[0] = a[j];
        a[j] = temp;
        buildHeap(a,0,j-1);
    }
}
void buildHeap(int a[],int node ,int bottom ){

    int left = node*2 + 1;
    int right = node*2 + 2;
    int largest = node;
    if(left<=bottom && a[left] > a[largest])
        largest = left;
    if(right<=bottom && a[right] > a[largest])
        largest = right;
    if(largest!=node){
        int temp = a[node];
        a[node] = a[largest];
        a[largest] = temp;
        buildHeap(a,largest,bottom);
    }

}

