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

void solve(string s1, string s2)
{
    ll n1 = s1.size();
    ll n2 = s2.size();
    map<char, ll> m1;
    map<char, ll> m2;
    loop(i, n1)
    {
        m1[s1[i]]++;
    }
    loop(i, n2)
    {
        m2[s2[i]]++;
    }
    ll ptr = 0;
    string ans = "";
    map<char, ll> done;
    for (auto it : m2)
    {

        char ch = it.first;
        ll total = it.second;
        ll req = m1[ch];
        ll left = total - req;
        if (left < 0)
        {
            cout << "Impossible" << endl;
            return;
        }
        done[ch]++;
        while (done.find(s1[ptr]) != done.end() && ptr != n1)
        {
            // cout << s1[ptr] << endl;
            m1[s1[ptr]]--;
            m2[s1[ptr]]--;
            ans += s1[ptr];
            ptr++;
        }
        loop(i, left)
        {
            ans += ch;
        }
        m2[ch] -= left;
    }
    if (ptr < n1)
    {
        cout << "Impossible" << endl;
        return;
    }
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
        // ll n;
        // cin>>n;
        // vector <ll> a;
        // inp(a,n);
        string s1;
        string s2;
        cin >> s1;
        cin >> s2;
        solve(s1, s2);
    }
}