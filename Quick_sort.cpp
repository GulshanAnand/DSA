#include <bits/stdc++.h>

using namespace std;
vector<int> a;

int partition(int l, int h){
    int pi = a[l];
    int i = l;
    int j = h;
    while(i < j){
        while(a[i] <= pi) i++;
        while(a[j] > pi) j--;
        if(i < j){
            swap(a[i], a[j]);
        }
    }
    swap(a[l], a[j]);
    return j;
}

void quickSort(int l, int h){
    if(l < h){
        int pivot = partition(l, h);
        quickSort(l, pivot - 1);
        quickSort(pivot + 1, h);
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
    quickSort(0, n-1);
    for(int i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }	
	return 0;
}