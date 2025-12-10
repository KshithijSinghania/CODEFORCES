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
        ll q;
        cin >> q;
        vector<ll> a;
        inp(a, n);
        vector<ll> x;
        inp(x, q);
        vector<ll> y;
        loop(i, n)
        {
            ll val = a[i];
            ll first = 0;
            for (ll ls = 0; ls < 32; ls++)
            {
                if (((val >> ls) | 1) == (val >> ls))
                    break;
                first++;
            }
            y.push_back(first);
        }
        map<ll, ll> freq;
        loop(i, q)
        {
            freq[x[i]]++;
        }
        loop(i, n)
        {
            ll curr = y[i];
            for (ll power = 0; power <= curr; power++)
            {
                if (freq.find(power) != freq.end())
                    a[i] += pow(2, power - 1);
            }
        }
        loop(i, n)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}