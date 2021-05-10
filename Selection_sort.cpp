#include <bits/stdc++.h>

using namespace std;

int main(){
    cout<<"Enter the number of elements in the array:"<<endl;
    int n;
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter "<<n<<" space seperated elements:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int mi=0;
    for(int i=0;i<n-1;i++){
        mi=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[mi]){
                mi=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[mi];
        arr[mi]=temp;
    }
    cout<<"sorted array is:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}