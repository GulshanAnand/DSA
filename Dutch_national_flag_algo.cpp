#include <bits/stdc++.h>

using namespace std;

//sort an array of 0s, 1s, 2s
/*
    we maintain three pointers lo, mid, hi with lo and mid at start and hi at last.
    it follows that:
    >all numbers from 0 to (lo-1) are 0s
    >all numbers from (hi+1) to n are 2s
    >mid<=hi (always)

*/

int main(){
    cout<<"Enter the number of elements in the array:"<<endl;
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int lo=0;
    int hi=n-1;
    int mid=0;
    while(mid<=hi){
        if(arr[mid]==0){
            int temp=arr[mid];
            arr[mid]=arr[lo];
            arr[lo]=temp;
            mid++;
            lo++;
        }
        else if(arr[mid]==2){
            int temp=arr[mid];
            arr[mid]=arr[hi];
            arr[hi]=temp;
            hi--;
        }
        else{
            mid++;
        }
    }
    cout<<"sorted array is:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}