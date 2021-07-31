#include <bits/stdc++.h>

using namespace std;
//T - O(nlogn)
vector<int> a;

void merge(int l, int mid, int r){
    int i = l;
    int j = mid + 1;
    int k = 0;
    vector<int> b(l+r);
    while(i <= mid && j <= r){
        if(a[i] < a[j]){
            b[k] = a[i];
            i++;
            k++;
        }
        else{
            b[k] = a[j];
            j++;
            k++;
        }
    }
    while(i <= mid){
            b[k] = a[i];
            i++;
            k++;
    }
    while(j <= r){
            b[k] = a[j];
            j++;
            k++;
    }
    for(i = l; i <= r; i++){
        a[i] = b[i-l];
    }
}

void mergeSort(int l, int r){
    if(l<r){
        int mid = l + (r-l)/2;
        mergeSort(l, mid);
        mergeSort(mid+1, r);
        merge(l, mid, r);
    }
}

int main(){
    int n;
    cout<<"Enter size of array:"<<endl;
    cin>>n;
    a.resize(n);
    cout<<"Enter elements of array:"<<endl;
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    mergeSort(0, n-1);
    for(int i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}