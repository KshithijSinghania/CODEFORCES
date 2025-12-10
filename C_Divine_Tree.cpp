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

void inp(vector<ll> &arr, ll size)
{
    loop(i, size)
    {
        ll val;
        cin >> val;
        arr.push_back(val);
    }
}

// ------------------------------------------------------------

void solve(ll n, ll m)
{
    if (m < n || m > n * (n + 1) / 2)
    {
        cout << -1 << endl;
        return;
    }
    ll root = -1;
    loop1(i, n)
    {
        ll rem_temp = m - i;
        ll mini = n - 1;
        ll maxi = (i - 1) * i / 2 + (n - i) * i;

        if (rem_temp >= mini && rem_temp <= maxi)
        {
            root = i;
            break;
        }
    }

    if (root == -1)
    {
        cout << -1 <<endl;
        return;
    }

    cout << root << endl;

    vector<pair<ll, ll>> gl;
    loop1(i, n)
    {
        if (i != root)
        {
            gl.push_back({min(i, root) - 1, i});
        }
    }

    sort(gl.begin(), gl.end(), greater<>());

    ll diff = (m - root) - (n - 1);
    vector<bool> connect_to_root(n + 1, false);

    for (auto &entry : gl)
    {
        ll gain = entry.first;
        ll node = entry.second;
        if (diff >= gain)
        {
            connect_to_root[node] = true;
            diff -= gain;
        }
    }

    if (diff != 0)
    {
        cout << -1 << endl;
        return;
    }

    vector<pair<ll, ll>> ans;
    vector<bool> check(n + 1, false);
    check[root] = true;

    ll pivot_node = -1;
    loop1(i, n)
    {
        if (i != root)
        {
            pivot_node = i;
            break;
        }
    }

    if (pivot_node != -1)
    {
        ans.push_back({root, pivot_node});
        check[pivot_node] = true;
    }

    loop1(i, n)
    {
        if (i == root)
            continue;
        if (connect_to_root[i] && !check[i])
        {
            ans.push_back({root, i});
            check[i] = true;
        }
    }

    loop1(i, n)
    {
        if (i == root || check[i])
            continue;
        ans.push_back({pivot_node, i});
        check[i] = true;
    }

    for (auto &edge : ans)
    {
        cout << edge.first << " " << edge.second << endl;
    }
}

// ------------------------------------------------------------

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ull test_cases;
    cin >> test_cases;

    while (test_cases--)
    {
        ll n, m;
        cin >> n >> m;
        solve(n, m);
    }

    return 0;
}
