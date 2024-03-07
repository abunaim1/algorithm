#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int n2;
    cin >> n2;
    int arr2[n2 + 1];
    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }
    int result[n + n2];
    arr[n] = INT_MIN;
    arr2[n2] = INT_MIN;
    int lp = 0, rp = 0;
    for (int i = 0; i < n + n2; i++)
    {
        if (arr[lp] >= arr2[rp])
        {
            result[i] = arr[lp];
            lp++;
        }
        else
        {
            result[i] = arr2[rp];
            rp++;
        }
    }
    for (int i = 0; i < n + n2; i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}