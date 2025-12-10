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

void solve(vector<ll> a, ll n, ll p1, ll p2, ll q1, ll q2)
{
    double d = sqrt(((p1 - q1) * (p1 - q1) * 1.0) + ((p2 - q2) * (p2 - q2) * 1.0));
    vector<double> len;
    // cout << d << endl;
    len.push_back(d);
    loop(i, n)
    {
        len.push_back(a[i] * 1.0);
    }
    sort(len.begin(), len.end());
    double maxi = len[len.size() - 1];
    double temp = 0;
    for (ll i = 0; i < len.size() - 1; i++)
    {
        temp += len[i];
    }
    // cout << temp << endl;
    if (temp < maxi)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
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
        ll p1, p2, q1, q2;
        cin >> p1 >> p2 >> q1 >> q2;
        vector<ll> a;
        inp(a, n);
        solve(a, n, p1, p2, q1, q2);
    }
}