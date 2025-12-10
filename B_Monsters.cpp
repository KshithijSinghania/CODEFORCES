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

void inp(vector<ll> &a, ll n)
{
    loop(i, n)
    {
        ll d;
        cin >> d;
        a.push_back(d);
    }
}

struct compare
{
    bool operator()(pair<ll, ll> p1, pair<ll, ll> p2)
    {
        if (p1.first != p2.first)
            return p1.first < p2.first; // min-heap by value
        return p1.second > p2.second;   // min-heap by index
    }
};

//-------------------------------------

void solve(vector<ll> a, ll n, ll k)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, compare> pq;
    vector<ll> ans;
    loop(i, n)
    {
        ll n = a[i] / k;
        ll temp = a[i] - (n * k);
        if (temp)
            pq.push({temp, i});
        else
            ans.push_back(i);
    }

    while (pq.size())
    {
        ll val = pq.top().first;
        ll idx = pq.top().second;
        pq.pop();
        if (val <= k)
        {
            ans.push_back(idx);
        }
        else
        {
            pq.push({val - k, idx});
        }
    }
    loop(i, n)
    {
        cout << ans[i] + 1 << " ";
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
        ll k;
        cin >> k;
        vector<ll> a;
        inp(a, n);
        solve(a, n, k);
    }
}