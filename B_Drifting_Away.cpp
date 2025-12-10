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

void solve(string s)
{

    string temp = "";
    ll n = s.size();
    loop(i, n)
    {
        if (s[i] != '*')
            temp += s[i];
    }
    loop(i, n - 1)
    {
        // cout << s[i] << endl;
        if (s[i] == '*' && s[i + 1] == '*')
        {
            cout << -1 << endl;
            return;
        }
    }
    if (temp.size() >= 2)
    {
        loop(i, temp.size() - 1)
        {
            // cout << temp.size() << endl;
            if (temp[i] == '>' && temp[i + 1] == '<')
            {
                cout << -1 << endl;
                return;
            }
        }
    }
    loop(i, n - 1)
    {
        if (s[i] == '>' && s[i + 1] == '*')
        {
            cout << -1 << endl;
            return;
        }
    }
    loop(i, n - 1)
    {
        if (s[i] == '*' && s[i + 1] == '<')
        {
            cout << -1 << endl;
            return;
        }
    }
    ll ans = 0;
    ll tem = 0;
    char prev = '*';
    loop(i, n)
    {
        if (s[i] == '*')
        {
            tem++;
            // prev = '*';
        }
        else if (s[i] == '<' && (prev == '<' || prev == '*'))
        {
            tem++;
            prev = '<';
        }
        else if (s[i] == '<' && prev == '>')
        {
            tem = 1;
            prev = '<';
        }
        else if (s[i] == '>' && (prev == '>' || prev == '*'))
        {
            tem++;
            prev = '>';
        }
        else
        {
            tem = 1;
            prev = '>';
        }
        ans = max(ans, tem);
    }
    tem = 0;
    prev = '*';
    loopr(i, n)
    {
        if (s[i] == '*')
        {
            tem++;
            // prev = '*';
        }
        else if (s[i] == '<' && (prev == '<' || prev == '*'))
        {
            tem++;
            prev = '<';
        }
        else if (s[i] == '<' && prev == '>')
        {
            tem = 1;
            prev = '<';
        }
        else if (s[i] == '>' && (prev == '>' || prev == '*'))
        {
            tem++;
            prev = '>';
        }
        else
        {
            tem = 1;
            prev = '>';
        }
        ans = max(ans, tem);
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
        string s;
        cin >> s;
        solve(s);
        // solve(a,n);
    }
}