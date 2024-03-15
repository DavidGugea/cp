#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int> arr, int target) {
    // serach for the value target in the **sorted** array arr
    int l = 0, r = arr.size()-1;
    while (l <= r) {
        int mid = (l+r) / 2;

        if (arr[mid] > target) {
            r = mid-1;
        } else if (arr[mid] < target) {
            l = mid + 1;
        } else {
            return mid;
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> arr = {1, 2, 3, 4, 5};
    int i = binary_search(arr, 4);
    cout << i << "\n";

    return 0;
}