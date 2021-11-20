#include<iostream>

using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void max_heapify(int a[], int i, int n){
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if(l < n && a[l] > a[largest]) largest = l;
    if(r < n && a[r] > a[largest]) largest = r;
    if(largest != i){
        swap(a[largest], a[i]);
        max_heapify(a, largest, n);
    }
}

void build_max_heap(int a[], int n){
    for(int i=n/2;i>=0;i--){
        max_heapify(a, i, n);
    }
}

void delete_heap(int a[], int &n){
    a[0] = a[n-1];
    n--;
    max_heapify(a, 0, n);
}

void heapsort(int a[], int n){
    build_max_heap(a, n);
    for(int i=n-1;i>=0;i--){
        int temp = a[0];
        delete_heap(a, n);
        a[n] = temp;
    }
}

int main(){
    cout<<"Enter number of elements:";
    int n;
    cin>>n;
    cout<<"Enter the elements:\n";
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    heapsort(a, n);
    for(int i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}