#include <iostream>

using namespace std;

void printarray(int a[], int n)
{

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "\t";
    }
}

void insertionSort(int a[], int n)
{

    for(int i=1; i<n; i++){

        int temp= a[i];
        int j=i-1;
        for(; j>=0; j--){

            if(a[j]>temp){
                a[j+1]= a[j];
            }else
                break;
        }
        a[j+1]= temp;
    }
   
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {

        cin >> arr[i];
    }
    insertionSort(arr, n);
    printarray(arr, n);
    return 0;
}