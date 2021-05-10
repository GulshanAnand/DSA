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
    int ct=1;
    while(ct<n){
        for(int i=0;i<n-ct;i++){
            if(arr[i]>arr[i+1]){
                int temp=arr[i+1];
                arr[i+1]=arr[i];
                arr[i]=temp;
            }
        }
        ct++;
    }
    cout<<"sorted array is:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}