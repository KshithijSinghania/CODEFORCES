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

void solve(vector<vector<ll>> adj, ll n)
{
    if (n == 3)
    {
        cout << 0 << endl;
        return;
    }
    vector<ll> leafnodes;
    unordered_map<ll, ll> nearleaf;
    loop(i, adj.size())
    {
        if (adj[i].size() == 1)
        {
            leafnodes.push_back(i);
            ll near = adj[i][0];
            nearleaf[near]++;
        }
    }
    ll totleaf = leafnodes.size();
    ll ans = LLONG_MAX;
    for (auto it : nearleaf)
    {
        ll near = it.first;
        ll numleaf = it.second;
        ans = min(ans, totleaf - numleaf);
    }
    if (ans == LLONG_MAX)
        cout << 0 << endl;
    else
        cout << ans << endl;
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
        vector<vector<ll>> adj(n + 1);
        loop(i, n - 1)
        {
            ll u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        solve(adj, n + 1);
    }
}