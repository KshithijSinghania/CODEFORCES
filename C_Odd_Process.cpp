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

void solve(vector<ll> a, ll n)
{
    vector<ll> odd;
    vector<ll> even;
    loop(i, n)
    {
        if (a[i] % 2 == 0)
            even.push_back(a[i]);
        else
            odd.push_back(a[i]);
    }
    ll ne = even.size();
    ll no = odd.size();
    sort(even.begin(), even.end());
    reverse(even);
    sort(odd.begin(), odd.end());
    reverse(odd);
    ll pe = 0;
    ll po = 0;
    vector<ll> ans;
    vector<pair<ll, ll>> prev; // odd,even
    if (odd.size() == 0)
    {
        loop(i, n)
        {
            cout << 0 << " ";
        }
        cout << endl;
        return;
    }
    ans.push_back(odd[po]);
    prev.push_back({1, 0});
    if (n >= 2)
    {
        if (even.size())
        {
            ans.push_back(odd[0] + even[0]);
            prev.push_back({1, 1});
        }
        else
        {
            ans.push_back(0);
            prev.push_back({2, 0});
        }
        if (n > 2)
        {
            for (ll i = 2; i < n; i++)
            {
                ll val = ans[i - 2];
                ll prevo = prev[i - 2].first;
                ll preve = prev[i - 2].second;
                if (val == 0)
                {
                    ans.push_back(0);
                    if (preve == ne)
                        prev.push_back({prevo + 2, preve});
                    else
                        prev.push_back({prevo, preve + 2});
                }
                else
                {
                    if (ne - preve > 1 && no - prevo > 1)
                    {
                        ans.push_back(val + even[preve] + even[preve + 1]);
                        prev.push_back({prevo, preve + 2});
                    }
                    else if (ne - preve <= 1 && no - prevo > 1)
                    {
                        // use only odd
                        ans.push_back(val);
                        prev.push_back({prevo + 2, preve});
                    }
                    else if (no - prevo <= 1 && ne - preve > 1)
                    {
                        ans.push_back(val + even[preve] + even[preve + 1]);
                        prev.push_back({prevo, preve + 2});
                    }
                    else if (no - prevo <= 1 && ne - preve <= 1)
                    {
                        if (no - prevo == 1 && ne - preve == 1)
                        {
                            ans.push_back(0);
                            prev.push_back({prevo + 1, preve + 1});
                        }
                    }
                }
            }
        }
    }
    loop(i, n)
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
        vector<ll> a;
        inp(a, n);
        solve(a, n);
    }
}