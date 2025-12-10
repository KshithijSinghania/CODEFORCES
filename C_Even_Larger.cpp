#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define reverse(v) reverse(v.begin(), v.end())
#define sort1(v) sort(v.begin(), v.end())
#define ld long double
#define ull unsigned long long int
#define loop(i, n) for (ll i = 0; i < n; i++)
#define loop1(i, n) for (ll i = 1; i <= n; i++)
#define loopr(i, n) for (ll i = n - 1; i >= 0; i--)
#define loopr1(i, n) for (ll i = n; i > 0; i--)
using namespace std;

bool comp(pair<ll, ll> p1, pair<ll, ll> p2)
{
    return p1.first > p2.first;
}

void readInput(vector<ll> &nums, ll size)
{
    for (ll idx = 0; idx < size; idx++)
    {
        ll value;
        cin >> value;
        nums.push_back(value);
    }
}

//-------------------------------------

void processArray(vector<ll> arr, ll len)
{
    ll result = 0;
    for (ll pos = 1; pos < len; pos += 2)
    {
        if (pos == len - 1)
            result += max(0LL, arr[pos - 1] - arr[pos]);
        else
        {
            ll adjustment = arr[pos + 1] + arr[pos - 1] - arr[pos];
            adjustment = max(0LL, adjustment);

            if (arr[pos] >= arr[pos - 1])
            {
                arr[pos + 1] = max(0LL, arr[pos + 1] - adjustment);
            }
            else
            {
                arr[pos + 1] = 0;
                arr[pos - 1] = arr[pos];
            }
            result += max(0LL, adjustment);
        }
    }
    cout << result << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ull testCases;
    cin >> testCases;
    while (testCases > 0)
    {
        testCases--;
        ll arraySize;
        cin >> arraySize;
        vector<ll> numbers;
        readInput(numbers, arraySize);
        processArray(numbers, arraySize);
    }
}