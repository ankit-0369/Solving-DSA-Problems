#include<iostream>

using namespace std;

int partition(int *arr, int s, int e){
    int pivot= arr[s];
    int rightIndex=s, ct=0;
    for(int i=s+1; i<=e; i++){
        if(arr[i]<=pivot){
            ct++;
        }
    }
    rightIndex+= ct;
    swap(arr[rightIndex],arr[s]);
    int i=s, j=e;
    while(i<rightIndex && j>rightIndex){
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<rightIndex && j>rightIndex){
            swap(arr[i++], arr[j--]);
        }
    }
    return rightIndex;
}

void QuickSort(int *arr, int s, int e){
    if(s>=e)
    return;
    int p= partition(arr,s,e);
    QuickSort(arr,s,p-1);
    QuickSort(arr,p+1,e);
}

int main(){
 int n;
 cin>>n;
 int * arr= new int[n];
 for(int i=0; i<n; i++){
    cin>>arr[i];
 }
 QuickSort(arr,0,n-1);
 cout<<endl;
 for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
 }
 cout<<endl;
 delete []arr;
return 0;
}