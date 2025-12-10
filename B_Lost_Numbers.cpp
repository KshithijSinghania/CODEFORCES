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
    t = 1;
    while (t > 0)
    {
        t--;
        vector<ll> nums = {4, 8, 15, 16, 23, 42};
        map<ll, vector<ll>> m;
        loop(i, 6)
        {
            loop(j, 6)
            {
                if (i != j)
                {
                    m[nums[i]].push_back(nums[i] * nums[j]);
                }
            }
        }

        vector<ll> ans(6);
        cout << "? 1 2" << endl;
        ll a1;
        cin >> a1;
        ll val1 = 0;
        ll val2 = 0;
        for (auto it : m)
        {
            ll num = it.first;
            loop(i, it.second.size())
            {
                if (it.second[i] == a1)
                {
                    val1 = num;
                    val2 = a1 / num;
                    break;
                }
            }
        }
        cout << "? 1 3" << endl;
        ll a2;
        cin >> a2;
        ll val3 = 0;
        ll val4 = 0;
        for (auto it : m)
        {
            ll num = it.first;
            loop(i, it.second.size())
            {
                if (it.second[i] == a2)
                {
                    val3 = num;
                    val4 = a2 / num;
                    break;
                }
            }
        }
        map<ll, ll> m1;
        m1[val1]++;
        m1[val2]++;
        m1[val3]++;
        m1[val4]++;
        ll maxi = 0;
        ll maxc = 0;
        // cout << val1 << endl;
        for (auto it : m1)
        {
            if (it.second > maxc)
            {

                maxc = it.second;
                maxi = it.first;
            }
        }
        ans[0] = maxi;
        // cout << ans[0] << endl;
        if (maxi == val1)
        {
            ans[1] = val2;
        }
        else
        {
            ans[1] = val1;
        }
        if (maxi == val3)
        {
            ans[2] = val4;
        }
        else
        {
            ans[2] = val3;
        }
        ///

        cout << "? 4 5" << endl;
        ll a3;
        cin >> a3;
        val1 = 0;
        val2 = 0;
        for (auto it : m)
        {
            ll num = it.first;
            loop(i, it.second.size())
            {
                if (it.second[i] == a3)
                {
                    val1 = num;
                    val2 = a3 / num;
                    break;
                }
            }
        }
        cout << "? 4 6" << endl;
        ll a4;
        cin >> a4;
        val3 = 0;
        val4 = 0;
        for (auto it : m)
        {
            ll num = it.first;
            loop(i, it.second.size())
            {
                if (it.second[i] == a4)
                {
                    val3 = num;
                    val4 = a4 / num;
                    break;
                }
            }
        }
        map<ll, ll> m2;
        m2[val1]++;
        m2[val2]++;
        m2[val3]++;
        m2[val4]++;
        maxi = 0;
        maxc = 0;
        for (auto it : m2)
        {
            if (it.second > maxc)
            {
                maxc = it.second;
                maxi = it.first;
            }
        }
        ans[3] = maxi;
        if (maxi == val1)
        {
            ans[4] = val2;
        }
        else
        {
            ans[4] = val1;
        }
        if (maxi == val3)
        {
            ans[5] = val4;
        }
        else
        {
            ans[5] = val3;
        }
        cout << "! ";
        loop(i, 6)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}