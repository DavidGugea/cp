#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> v = {10,20,30,30,20,10,10,20};
    sort(v.begin(), v.end());

    auto low = lower_bound(v.begin(), v.end(), 20);
    auto high = upper_bound(v.begin(), v.end(), 20);

    cout << (low - v.begin()) << "\n";
    cout << (high - v.begin()) << "\n";

    return 0;
}