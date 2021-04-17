#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cout<<"Enter number of elements:"<<endl;
    cin>>n;
    int A[n];
    cout<<"Enter the space seperated elements of array:"<<endl;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    int i=0;
    while(i<n/2){
        int temp=A[i];
        A[i]=A[n-i-1];
        A[n-i-1]=temp;
        i++;
    }
    cout<<"Reversed array is:"<<endl;
    for(int k=0;k<n;k++){
        cout<<A[k];
        if(k!=n-1){
            cout<<" ";
        }
    }
    return 0;
}
