#include<bits/stdc++.h>
using namespace std;


void swap(int arr[],int i,int j){
    cout<<"Swapping "<<arr[i]<<" and "<<arr[j]<<endl;
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

void partition(int arr[],int n,int pivot){
    // write your code
}

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    
    int n;
    cin>>n;
    
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int pivot;
    cin>>pivot;
    
    partition(arr,n,pivot);
    print(arr,n);
}