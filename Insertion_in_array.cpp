#include<bits/stdc++.h>

using namespace std;

// This displays the array
void display(int arr[], int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

//to insert a value at index ind
int indInsert(int arr[], int &size, int ind, int value){
    if(ind>=10||ind<0){
        cout<<"Index is out of bounds"<<endl;
        return -1;
    }
    else {
        for(int i=size-1;i>=ind;i--){
            arr[i+1]=arr[i];
        }
        arr[ind]=value;
        size++;
    }
}

int main(){
    int size=4;
    int arr[10]={1, 4, 7, 8};  
    display(arr,size);
    indInsert(arr,size,4,4);
    indInsert(arr,size,5,5);
    indInsert(arr,size,6,6);
    indInsert(arr,size,7,7);
    indInsert(arr,size,8,8);
    indInsert(arr,size,9,9);
    indInsert(arr,size,10,10);
    display(arr,size);
    return 0;
}