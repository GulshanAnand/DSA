#include<bits/stdc++.h>

using namespace std;

int binarySearch(int arr[], int n,int element){
    int lo=0;
    int hi=n-1;
    
    while(lo<=hi){

        int mid = lo + (hi-lo)/2;

        if(arr[mid]==element){
            return mid;
        }
        if(arr[mid]>element){
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
    }
    return -1;
}

int main(){
    int arr[8]={2,5,9,23,45,89,98,423};
    int n=sizeof(arr);
    int element;
    cout<<"Enter element to search:"<<endl;
    cin>>element;
    int ind=binarySearch(arr,n,element);
    if(ind!=-1)
        cout<<"Element found at index: "<<ind<<endl;
    else
        cout<<"Element not found in array."<<endl;    
    return 0;
}