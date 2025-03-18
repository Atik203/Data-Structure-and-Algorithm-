#include <bits/stdc++.h>
using namespace std;

class Result
{
public:
    int maxSum;
    int low;
    int high;
};

Result findMaxCrossArray(int a[], int low, int mid, int high)
{
    Result res;
    int leftSum = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= low; i--)
    {
        sum += a[i];
        if (sum > leftSum)
        {
            leftSum = sum;
            res.low = i;
        }
    }
    int rightSum = INT_MIN;
    sum = 0;
    for (int i = mid + 1; i <= high; i++)
    {
        sum += a[i];
        if (sum > rightSum)
        {
            rightSum = sum;
            res.high = i;
        }
    }
    res.maxSum = leftSum + rightSum;
    return res;
}

Result findMaxSumSubArray(int a[], int low, int high)
{
    Result res;
    if (low == high)
    {
        res.low = low;
        res.high = high;
        res.maxSum = a[low];
        return res;
    }
    int mid = (low + high) / 2;
    Result left = findMaxSumSubArray(a, low, mid);
    Result right = findMaxSumSubArray(a, mid + 1, high);
    Result cross = findMaxCrossArray(a, low, mid, high);
    if (left.maxSum >= right.maxSum && left.maxSum >= cross.maxSum)
    {
        return left;
    }
    else if (right.maxSum >= left.maxSum && right.maxSum >= cross.maxSum)
    {
        return right;
    }
    else
    {
        return cross;
    }
}

int main()
{
    int a[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(a) / sizeof(a[0]);

    Result res = findMaxSumSubArray(a, 0, n - 1);

    cout << "Maximum sum: " << res.maxSum << endl;
    cout << "Array: ";
    for (int i = res.low; i <= res.high; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}