class Solution {
  public:
    int mod = 1e9 +7;
    int countPairs(vector<int>& deliciousness) {
      unordered_map<int, int> mm;
      int count = 0, len = deliciousness.size();
      for (int num : deliciousness) {
        int dst = 1;
        for (int i = 0; i <= 21; i++) {
          if (dst >= num && mm.find(dst - num) != mm.end())  {
            count  += mm.find(dst - num)->second;
            count %= mod;
          }
          dst *= 2;
        }
        mm[num]++;
      }
      return count;
    }
};
