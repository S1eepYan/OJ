class Solution {
  public:
    int lengthofLIS(vector<int> &vec) {
      if (vec.empty())
        return 0;
      int len = 1, n = vec.size();
      vector<int> d(n + 1, 0);
      d[len] = vec[0];
      for (int i = 1; i < n; i++) {
        if (vec[i] > d[len]) {
          d[++len] = vec[i];
        } else {
          int l = 1, r = len, pos = 0;
          while (l <= r) {
            int mid = (l + r) / 2;
            if (d[mid] < vec[i]) {
              pos = mid;
              l = mid + 1;
            } else {
              r = mid - 1;
            }
          }
          d[pos + 1] = vec[i];
        }
      }
      return len;
    }
    int minOperations(vector<int> &target, vector<int> &arr) {
      unordered_map<int, int> m;
      for (int i = 0; i < target.size(); i++)
        m[target[i]] = i;
      vector<int> vec;
      for (int x : arr) {
        if (m.find(x) != m.end()) {
          vec.push_back(m[x]);
        }
      }
      int lis = lengthofLIS(vec);
      return target.size() - lis;
    }
};
