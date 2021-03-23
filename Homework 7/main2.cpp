#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    int i, j, key;
    for (i=1; i<n; i++)
    {
        j = i-1;
        key = arr[i];
        while (arr[j] > key && j >= 0)
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}



int main() {
    const int size = 10;
    int arr[size] = {12342,122,25,2,6,10,4,132,93,33};
    cout<< "Before insertion sort:" <<endl;
    for (int i=0; i<size; i++) {
        cout<<arr[i] <<"\t";
    }
    insertionSort(arr, size);
    cout << endl <<endl;
    cout << "After insertion sort" <<endl;
    for (int i=0; i<size; i++) {
        cout<<arr[i] <<"\t";
    }
    cout <<endl <<endl;
    return 0;
}
