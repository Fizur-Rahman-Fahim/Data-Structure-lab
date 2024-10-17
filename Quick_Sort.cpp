#include<bits/stdc++.h>
using namespace std;
int partition(int array[], int low, int high)
{
    int pivot = array[high];
    int i = low-1;
    for(int j=low;j<high;j++)
    {
        if(array[j]<pivot)
        {
            i++;
            swap(array[i], array[j]);
        }
    }
    i++;
    swap(array[i], array[high]);
    return i;
}
void Quicksort(int array[], int low, int high)
{
    if(low<high)
    {
        int pivotIndex = partition(array, low, high);
        Quicksort(array, low, pivotIndex-1);
        Quicksort(array, pivotIndex+1, high);
    }

}
int main()
{
    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++)
    {
        cin>>array[i];
    }

    Quicksort(array,0, n-1);
    for(int i=0;i<n;i++)
    {
        cout<<array[i]<<" ";
    }
    return 0;
}