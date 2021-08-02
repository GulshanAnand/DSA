#include <bits/stdc++.h>

using namespace std;

int maxim(int *a, int n){
    int max = a[0];
    for(int i=1;i<n;i++){
        if(a[i] > max) max = a[i];
    }
    return max;
}

void countSort(int *a, int n){
    int max = maxim(a, n);
    int count[max+1] ={0};
    for(int i=0;i<n;i++){
        count[a[i]]++;
    }
    for(int i = 1;i<n;i++){
        count[i] = count[i-1] + count[i];
    }
    int tmp[n];
    for(int i = 0;i<n;i++){
        tmp[--count[a[i]]] = a[i];
    }
    for(int i = 0;i<n;i++){
        a[i] = tmp[i];
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
    countSort(a, n);
    cout<<"Sorted array is:"<<endl;
    for(int i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}