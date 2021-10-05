#include<iostream>

using namespace std;

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

void min_heapify(int a[], int i, int n){
    int least = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if(l < n && a[l] < a[least]) least = l;
    if(r < n && a[r] < a[least]) least = r;
    if(least != i){
        swap(a[least], a[i]);
        min_heapify(a, least, n);
    }
}

void build_max_heap(int a[], int n){
    for(int i=n/2;i>=0;i--){
        max_heapify(a, i, n);
    }
}

void build_min_heap(int a[], int n){
    for(int i=n/2;i>=0;i--){
        min_heapify(a, i, n);
    }
}

void heapify_bu(int a[], int i){
    int parent = (i - 1)/2;
    if(parent >= 0){
        if(a[parent] < a[i]){
            swap(a[parent], a[i]);
            heapify_bu(a, parent);
        }
    }
}

void insert_heap(int a[], int &n, int val){
    n++;
    a[n-1] = val;
    heapify_bu(a, n-1);
}

void delete_heap(int a[], int &n){
    a[0] = a[n-1];
    n--;
    max_heapify(a, 0, n);
}

int main(){
    cout<<"Enter number of elements:";
    int n;
    cin>>n;
    cout<<"Enter the elements:\n";
    int a[n+20];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    build_max_heap(a, n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    insert_heap(a,n,79);
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    delete_heap(a,n);
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}