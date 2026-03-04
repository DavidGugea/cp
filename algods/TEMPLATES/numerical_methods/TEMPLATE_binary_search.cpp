#include <bits/stdc++.h>
using namespace std;

// Find target in given array in O(log n). Return -1 if not found.
// Time complexity: O(log n)
int binarySearch(const vector<int>& arr, int target) {
    int n = arr.size();
    int low = 0, high = n-1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

// Find index of the first element in arr >= target
// Time complexity: O(log n)
int lower_bound(const vector<int>& arr, int target) {
    int n = arr.size();
    int low = 0, high = n;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= target) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    return low;
}

// Find index of the first element in arr > target
// Time complexity: O(log n)
int upper_bound(const vector<int>& arr, int target) {
    int n = arr.size();
    int low = 0, high = n;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] <= target) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    return low;
}