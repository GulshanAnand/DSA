#include <bits/stdc++.h>

using namespace std;

/*
    given an array of integers(containing positive as well as negative numbers)
    task- to find the maximum possible sum among all nonempty contiguous subarrays
    ex-{2, -1, 2, 3, 4, -5}
    ans- maxsum=10 (and the subarray is {2, -1, 2, 3, 4})
*/

int maxSum(vector<int> arr){
    int n=arr.size();
    int maxsum=arr[0];
    int sum=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]+sum>=arr[i]){
            sum+=arr[i];
        }
        else{
            sum=arr[i];
        }
        if(sum>maxsum) maxsum=sum;
    }
    return maxsum;
}

int main(){
    cout<<"Enter number of elements in your array:"<<endl;
    int n;
    cin>>n;
    cout<<"Enter "<<n<<" space seperated integers:"<<endl;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=maxSum(arr);
    cout<<"Maximum sum is "<<ans<<endl;

    return 0;
}