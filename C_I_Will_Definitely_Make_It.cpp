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

//------------------------------------------------------------

bool isPositionGood(const vector<ll> &heights, ll pos)
{
    ll valAtPos = heights[pos];
    ll maxHeight = *max_element(heights.begin(), heights.end());

    if (valAtPos == maxHeight)
        return true;

    vector<ll> uniqueHeights = heights;
    sort1(uniqueHeights);
    uniqueHeights.erase(unique(uniqueHeights.begin(), uniqueHeights.end()), uniqueHeights.end());

    ll idx = lower_bound(uniqueHeights.begin(), uniqueHeights.end(), valAtPos) - uniqueHeights.begin();

    for (ll i = idx; i + 1 < uniqueHeights.size(); i++)
    {
        if (uniqueHeights[i + 1] - uniqueHeights[i] > valAtPos)
        {
            return false;
        }
    }

    return true;
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> heights;
    inp(heights, n);

    if (isPositionGood(heights, k - 1))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}

//------------------------------------------------------------

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ull t;
    cin >> t;
    while (t > 0)
    {
        t--;
        solve();
    }
}
