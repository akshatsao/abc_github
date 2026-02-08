// !! Hari Om Tatsat !!
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <numeric>

using namespace std;

#define fast_io() ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pb push_back
#define f(i,a,b) for(int i = a ; i < b ; ++i)
#define f1(i,a,b) for(int i = a ; i <= b ; ++i)
#define f2(i,a,b) for(int i = a ; i >= b ; i--)
#define f3(i,a,b) for(int i = a ; i > b ; i--)
#define nl cout << "\n";

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;

const int MOD = 1000000007;

int binarysearchRecursive(vector<int>& nums, int target, int low, int high) {
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) return mid;
        if (target < nums[mid]) return binarysearchRecursive(nums, target, low, mid - 1);
        return binarysearchRecursive(nums, target, mid + 1, high);
    }
    return -1;
}

int binarysearch(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    return binarysearchRecursive(nums, target, 0, (int)nums.size() - 1);
}

vector<vector<int>> makeSubarrays(const vector<int>& arr) {
    int n = arr.size();
    vector<vector<int>> result;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j + i <= n; ++j) {
            result.emplace_back(arr.begin() + j, arr.begin() + j + i);
        }
    }
    return result;
}

bool sieveOfEratosthenes(int n) {
    if (n <= 1) return false;
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) isPrime[j] = false;
        }
    }
    return isPrime[n];
}

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}

void solve() {
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for (int& num : nums) cin >> num;

    int index = binarysearch(nums, target);
    if (index != -1) {
        cout << "Element found at index: " << index << "\n";
    } else {
        cout << "Element not found in the array.\n";
    }

    vector<vector<int>> subarrays = makeSubarrays(nums);
    cout << "All subarrays:\n";
    for (const auto& subarray : subarrays) {
        for (int num : subarray) cout << num << " ";
        cout << "\n";
    }

    int primeCheck;
    cin >> primeCheck;
    if (sieveOfEratosthenes(primeCheck)) {
        cout << primeCheck << " is a prime number.\n";
    } else {
        cout << primeCheck << " is not a prime number.\n";
    }

    ll a, b;
    cin >> a >> b;
    cout << "GCD: " << gcd(a, b) << "\n";
    cout << "LCM: " << lcm(a, b) << "\n";
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
// Author : Sanyog Tripathi _India_