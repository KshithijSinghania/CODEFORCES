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

void inp(vector<vector<ll>> &a, ll n, ll m)
{
    loop(i, n)
    {
        vector<ll> temp;
        loop(j, m)
        {
            ll d;
            cin >> d;
            temp.push_back(d);
        }
        a.push_back(temp);
    }
}

//-------------------------------------

void solve(vector<vector<ll>> a, ll n, ll m)
{
    map<ll, vector<pair<ll, ll>>> pos;
    ll maxi = -1;
    loop(i, n)
    {
        loop(j, m)
        {
            maxi = max(maxi, a[i][j]);
            pos[a[i][j]].push_back({i, j});
        }
    }
    vector<pair<ll, ll>> temp = pos[maxi];
    if (temp.size() == 1)
    {
        cout << maxi - 1 << endl;
        return;
    }
    ll r = temp[0].first;
    ll c = temp[0].second;
    bool check1 = false;
    bool check2 = false;
    vector<ll> vis1(temp.size(), 0);
    vector<ll> vis2(temp.size(), 0);
    loop(i, temp.size())
    {
        if (temp[i].first == r)
        {
            vis1 = 1;
        }
    }
    ll count = 0;
    loop(i, temp.size())
    {
        if (vis1[i])
            count++;
    }
    if (count == temp.size())
    {
        cout << maxi - 1 << endl;
        return;
    }
    ll c1;
    loop(i, n)
    {
        if (!vis1[i])
        {
            c1 = temp[i].second;
            break;
        }
    }
    loop(i, n)
    {
        if (temp[i].second == c1)
        {
            vis1[i] = 1;
        }
    }
    count = 0;
    loop(i, temp.size())
    {
        if (vis1[i])
            count++;
    }
    if (count == temp.size())
    {
        cout << maxi - 1 << endl;
        return;
    }
    loop(i, temp.size())
    {
        if (temp[i].second == c)
        {
            vis2 = 1;
        }
    }
    count = 0;
    loop(i, temp.size())
    {
        if (vis2[i])
            count++;
    }
    if (count == temp.size())
    {
        cout << maxi - 1 << endl;
        return;
    }
    ll r1;
    loop(i, n)
    {
        if (!vis2[i])
        {
            r1 = temp[i].first;
            break;
        }
    }
    loop(i, n)
    {
        if (temp[i].first == r1)
        {
            vis2[i] = 1;
        }
    }
    count = 0;
    loop(i, temp.size())
    {
        if (vis2[i])
            count++;
    }
    if (count == temp.size())
    {
        cout << maxi - 1 << endl;
        return;
    }
    cout << maxi << endl;
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
        ll m;
        cin >> m;
        vector<vector<ll>> a;
        inp(a, n, m);
        solve(a, n, m);
    }
}