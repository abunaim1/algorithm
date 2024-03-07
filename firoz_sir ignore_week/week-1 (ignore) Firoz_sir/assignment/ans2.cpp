#include <iostream>
using namespace std;
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

    int l = 0;
    int r = n - 1;
    int f = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] == target)
        {
            cout << mid << endl;
            f++;
            break;
        }
        else
        {
            if (target > arr[mid])
                l = mid + 1;
            else
                r = mid - 1;
        }
    }
    if (f == 0)
        cout << "Not Found" << endl;
    return 0;
}