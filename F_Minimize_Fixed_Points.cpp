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

void solve(ll n)
{
    map<ll, ll> m;
    vector<ll> ans;
    ans.push_back(1);
    m[1] = 1;
    for (ll i = 2; i <= n; i++)
    {
        if (m.find(i) != m.end())
        {
            continue;
        }
        ll val = n / i;
        val = val * i;
        ll temp = 1;
        while (m.find(val) != m.end() && val > 0)
        {
            val = (n / i) - temp;
            val = val * i;
            temp++;
        }
        if (val == 0)
        {
            m[i] = i;
        }
        else
        {
            m[i] = val;
            m[val] = i;
        }
    }
    for (auto &entry : m)
    {
        ans.push_back(entry.second);
    }
    loop(i, ans.size())
    {
        cout << ans[i] << " ";
    }
    cout << endl;
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
        // vector <ll> a;
        // inp(a,n);
        solve(n);
    }
}