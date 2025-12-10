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

void inp(vector<ll> &a, ll n)
{
    loop(i, n)
    {
        ll d;
        cin >> d;
        a.push_back(d);
    }
}

//-------------------------------------

void solve(unordered_map<ll, vector<ll>> &m, ll n)
{
    vector<ll> ans(n, 0);

    // Step 1: Sort and add suffix sums directly
    for (auto &[key, temp] : m)
    {
        sort(temp.begin(), temp.end(), greater<>());
        temp.push_back(0); // append after sorting
        for (ll i = temp.size() - 2; i >= 0; i--)
            temp[i] += temp[i + 1];
    }

    // Step 2: Process only up to group size
    for (auto &[key, temp] : m)
    {
        ll size = temp.size() - 1;
        for (ll i = 1; i <= size; i++)
        {
            ll rem = size % i;
            ans[i - 1] += temp[0] - temp[size - rem];
        }
    }

    // Output
    for (ll i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ull t;
    cin >> t;
    while (t > 0)
    {
        t--;
        ll n;
        cin >> n;
        vector<ll> a;
        inp(a, n);
        vector<ll> b;
        inp(b, n);
        unordered_map<ll, vector<ll>> m;
        for (ll i = 0; i < n; i++)
        {
            m[a[i]].push_back(b[i]);
        }
        solve(m, n);
    }
}