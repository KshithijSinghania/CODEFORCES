#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

const long long INF = 4e18; 

void solve() {
    int n;
    std::cin >> n;
    std::vector<long long> a(n);
    long long initial_S = 0;

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        if ((i + 1) % 2 != 0) {
            initial_S += a[i];
        } else { 
            initial_S -= a[i];
        }
    }

    if (n == 1) {
        std::cout << initial_S << "\n";
        return;
    }

    long long max_f = initial_S;

    long long max_cost_same_parity = (n % 2 != 0) ? (long long)n - 1 : (long long)n - 2;
    max_f = std::max(max_f, initial_S + max_cost_same_parity);

    long long max_change = -INF;

    std::vector<long long> min_l_prefix(n, INF);
    if (0 % 2 == 0) min_l_prefix[0] = 2 * a[0] + 0;
    for (int i = 1; i < n; ++i) {
        min_l_prefix[i] = min_l_prefix[i - 1];
        if (i % 2 == 0) {
            min_l_prefix[i] = std::min(min_l_prefix[i], 2LL * a[i] + i);
        }
    }
    for (int r_idx = 1; r_idx < n; ++r_idx) {
        if (r_idx % 2 != 0) {
            if (min_l_prefix[r_idx - 1] != INF) {
                long long current_change = (2LL * a[r_idx] + r_idx) - min_l_prefix[r_idx - 1];
                max_change = std::max(max_change, current_change);
            }
        }
    }

    std::vector<long long> max_l_prefix(n, -INF);
    if (n > 1 && 1 % 2 != 0) max_l_prefix[1] = 2 * a[1] - 1;
    for (int i = 2; i < n; ++i) {
        max_l_prefix[i] = max_l_prefix[i - 1];
        if (i % 2 != 0) {
            max_l_prefix[i] = std::max(max_l_prefix[i], 2LL * a[i] - i);
        }
    }
    for (int r_idx = 2; r_idx < n; ++r_idx) {
        if (r_idx % 2 == 0) {
            if (max_l_prefix[r_idx - 1] != -INF) {
                long long current_change = max_l_prefix[r_idx - 1] - (2LL * a[r_idx] - r_idx);
                max_change = std::max(max_change, current_change);
            }
        }
    }
    
    if (max_change > -INF) {
        max_f = std::max(max_f, initial_S + max_change);
    }

    std::cout << max_f << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
