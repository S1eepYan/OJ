class Solution {
  public:
    int mod = 1e9 + 7;
    int waysToSplit(vector<int> &nums) {
      int n = nums.size();
      vector<int> v(n + 1, 0);
      for (int i = 1; i <= n; i++) {
        v[i] = v[i - 1] + nums[i - 1];
      }
      long long ret = 0;
      for (int i = 1; i < n; i++) {
        if (v[i] * 3 > v[n])
          break;

        int l = i + 1, r = n - 1;
        while (l <= r) {
          int mid = (l + r) / 2;
          if (v[n] - v[mid] < v[mid] - v[i]) {
            r = mid - 1;
          } else {
            l = mid + 1;
          }
        }
        int ll = i + 1, rr = n - 1;
        while (ll <= rr) {
          int mid = (ll + rr) / 2;
          if (v[mid] - v[i] < v[i])
            ll = mid + 1;
          else
            rr = mid - 1;
        }
        ret = (ret + l - ll) % mod;
      }
      return static_cast<int>(ret);
    }
};
