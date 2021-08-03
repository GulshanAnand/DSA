#include <bits/stdc++.h>

using namespace std;

void waveSort(int *a, int n){
    for(int i=1;i<n;i+=2){
        if(a[i] > a[i-1]) swap(a[i],a[i-1]);
        if(i<=n-2 && a[i] > a[i+1]) swap(a[i],a[i+1]);
    }
}

int main(){
    int n;
    cout<<"Enter size of array:"<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter elements of array:"<<endl;
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    waveSort(a, n);
    cout<<"wave sorted array is:"<<endl;
    for(int i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}