#include <iostream>
using namespace std;
void binarySearch(int arr[], int target, int l, int r)
{
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] == target)
        {
            if (arr[mid + 1] == target)
            {
                cout << "Yes";
                return;
            }
            if (arr[mid - 1] == target)
            {
                cout << "Yes";
                return;
            }
        }
        else
        {
            if (target > arr[mid])
                l = mid + 1;
            else
                r = mid - 1;
        }
    }
    cout << "No";
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int target;
    cin >> target;
    binarySearch(arr, target, 0, n - 1);
    return 0;
}