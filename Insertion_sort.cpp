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
    for(int i=1;i<n;i++){
        int ce=arr[i];          // ce = current element
        int j=i-1;
        while(ce<arr[j] && j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=ce;
    }
    cout<<"sorted array is:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}