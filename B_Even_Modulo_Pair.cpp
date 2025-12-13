#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define all(x) (x).begin(), (x).end()
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
    vector<ll> even;
    vector<ll> odd;
    if (n < 1000)
    {
        for (ll i = 0; i < n - 1; i++)
        {
            for (ll j = i + 1; j < n; j++)
            {
                if ((a[j] % a[i]) % 2 == 0)
                {
                    cout << a[i] << " " << a[j] << endl;
                    return;
                }
            }
        }
    }
    loop(i, n)
    {
        if (a[i] % 2 == 0)
            even.push_back(a[i]);
        else
            odd.push_back(a[i]);
    }
    if (even.size() >= 2)
    {
        cout << even[0] << " " << even[1] << endl;
        return;
    }
    if (even.size() == 1)
    {
        loop(i, odd.size())
        {
            if (odd[i] > even[0] && (odd[i] % even[0]) % 2 == 0)
            {
                cout << even[0] << " " << odd[i] << endl;
                return;
            }
            if (odd[i] < even[0] && (even[0] % odd[i]) % 2 == 0)
            {
                cout << odd[i] << " " << even[0] << endl;
                return;
            }
        }
    }
    loop(i, odd.size() - 1)
    {
        if (odd[i + 1] <= (2 * odd[i]))
        {
            cout << odd[i] << " " << odd[i + 1] << endl;
            return;
        }
    }
    cout << -1 << endl;
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