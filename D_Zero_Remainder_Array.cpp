#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll &x : a)
        cin >> x;

    unordered_map<ll, ll> freq;
    for (ll x : a)
    {
        ll rem = x % k;
        if (rem != 0)
        {
            ll need = k - rem;
            freq[need]++;
        }
    }

    ll ans = 0;
    for (auto [need, cnt] : freq)
    {
        // For cnt items with the same 'need'
        ll last_move = need + (cnt - 1) * k;
        ans = max(ans, last_move);
    }

    if (ans == 0)
        cout << 0 << "\n";
    else
        cout << ans + 1 << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
}
