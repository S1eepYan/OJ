class Solution {
  public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
      flowerbed.push_back(0);
      flowerbed.push_back(1);
      int count = 0, num = 1;
      for (int i = 0; i < flowerbed.size(); i++) {
        if (flowerbed[i] == 1) {
          count += (num - 1) / 2;
          num = 0;
        } else {
          num++;
        }
      }
      return count >= n;
      }
};
