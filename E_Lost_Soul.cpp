#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define ll long long int
using namespace std;

// Function to input a vector
void inputVector(vector<ll> &vec, ll n)
{
    for (ll i = 0; i < n; ++i)
    {
        ll value;
        cin >> value;
        vec.push_back(value);
    }
}

// Check the last mismatch index for array A
ll getMismatchIndexA(const vector<ll> &a, map<ll, vector<ll>> &indexMapA, ll n)
{
    for (ll i = n - 1; i >= 0; --i)
    {
        if (indexMapA[a[i]].back() > i)
            return i + 1;
    }
    return 0;
}

// Check the last mismatch index for array A against B
ll getMismatchIndexAwithB(const vector<ll> &a, const vector<ll> &b, map<ll, vector<ll>> &indexMapB, ll n)
{
    for (ll i = n - 1; i >= 0; --i)
    {
        if (a[i] == b[i])
            return i + 1;
        if (indexMapB.find(a[i]) != indexMapB.end() && indexMapB[a[i]].back() > i + 1)
            return i + 1;
    }
    return 0;
}

// Check the last mismatch index for array B
ll getMismatchIndexB(const vector<ll> &b, map<ll, vector<ll>> &indexMapB, ll n)
{
    for (ll i = n - 1; i >= 0; --i)
    {
        if (indexMapB[b[i]].back() > i)
            return i + 1;
    }
    return 0;
}

// Check the last mismatch index for array B against A
ll getMismatchIndexBwithA(const vector<ll> &a, const vector<ll> &b, map<ll, vector<ll>> &indexMapA, ll n)
{
    for (ll i = n - 1; i >= 0; --i)
    {
        if (a[i] == b[i])
            return i + 1;
        if (indexMapA.find(b[i]) != indexMapA.end() && indexMapA[b[i]].back() > i + 1)
            return i + 1;
    }
    return 0;
}

// Main solving function
void processArrays(const vector<ll> &a, const vector<ll> &b, ll n)
{
    map<ll, vector<ll>> indexMapA, indexMapB;

    for (ll i = 0; i < n; ++i)
        indexMapA[a[i]].push_back(i);

    for (ll i = 0; i < n; ++i)
        indexMapB[b[i]].push_back(i);

    ll ans1 = getMismatchIndexA(a, indexMapA, n);
    ll ans2 = getMismatchIndexAwithB(a, b, indexMapB, n);
    ll ans3 = getMismatchIndexB(b, indexMapB, n);
    ll ans4 = getMismatchIndexBwithA(a, b, indexMapA, n);

    ll finalAns = max({ans1, ans2, ans3, ans4});
    cout << finalAns << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> arrayA, arrayB;

        inputVector(arrayA, n);
        inputVector(arrayB, n);

        processArrays(arrayA, arrayB, n);
    }
    return 0;
}
