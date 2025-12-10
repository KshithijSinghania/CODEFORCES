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

void solve1(unordered_set<ll> &st, string &s, ll idx, ll val)
{
    ll dr[] = {0, -1, -2, -3};
    loop(i, 4)
    {
        ll nidx = idx + dr[i];
        if (st.find(nidx) != st.end())
            st.erase(nidx);
    }
    s[idx] = (val == 1) ? '1' : '0';
    loop(i, 4)
    {
        ll sidx = idx + dr[i];
        if (sidx >= 0 && sidx + 3 < s.length())
        {
            if (s[sidx] == '1' && s[sidx + 1] == '1' && s[sidx + 2] == '0' && s[sidx + 3] == '0')
                st.insert(sidx);
        }
    }
    if (st.size())
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    // cout<<st.size()<<endl;
}

void solve(string &s)
{
    unordered_set<ll> st;
    ll n = s.length();
    loop(i, n - 3)
    {
        if (s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0')
            st.insert(i);
    }
    ll q;
    cin >> q;
    loop(i, q)
    {
        ll idx;
        cin >> idx;
        ll val;
        cin >> val;
        solve1(st, s, idx - 1, val);
    }
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
        string s;
        cin >> s;
        // vector <ll> a;
        // inp(a,n);
        solve(s);
    }
}