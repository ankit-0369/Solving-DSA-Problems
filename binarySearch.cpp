#include <iostream>
#include <algorithm>

using namespace std;

int binarySearch(int a[], int n, int key)
{
    int start = 0;
    int end = n - 1;
    int mid = start + (end-start)/2;
    while (start <= end)
    {
        if (a[mid] == key)
        {
            return mid;
        }
        else if (key > a[mid])
        {
            start = mid + 1;
        }
        else
            end = mid - 1;
        mid = start + (end-start)/2;
    }

    return -1;
}

int main()
{
    int n, key;
    cin >> n >> key;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // sort(a, a + n); // to implement binary search we need monotonic array...
    cout << binarySearch(a, n, key);
    return 0;
}