/*
  Prefix Sum : Calculating the sum of consicutive sub-arrays in O(n) time, and
               finding sum of any sub-array of range i,j index.
*/
int main()
{
    cout << "Enter the number of elements in the array : ";
    int n;
    cin >> n;
    cout << "Enter the elements of the array : ";
    int arr[n];
    for(int i=0; i<n; ) cin >> arr[i++];

    // Precomputing the prefix sum in the same array.
    for(int i=1; i<n; i++)
    {
        arr[i] = arr[i-1] + arr[i];
    }
    cout << "Enter the number of queries : ";

    int q;
    cin >> q;
    while(q--)
    {
        int start, end;
        cout << "Enter the start and end index value for the subarray to calculate sum of that sub-array : ";
        cin >> start >> end;
        // sum(arr[i],arr[j]) = arr[j] - arr[i-1]
        if(start != 0) cout << arr[end] - arr[start-1] << endl;
        // incase of i=0 arr[0-1] = arr[-1]; which may lead to segmentation fault.
        else cout << arr[end] << endl;
    }
}
