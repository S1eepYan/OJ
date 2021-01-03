class Solution {
  public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
      sort(boxTypes.begin(), boxTypes.end(), [](vector<int>& v1, vector<int>& v2) {
          return v1[1] > v2[1];
          });
      int count = 0;
      for (auto it = boxTypes.begin(); it != boxTypes.end(); ++it) {
        count += min(it->at(0), truckSize) * it->at(1);
        truckSize -= min(it.first, truckSize);
        if (truckSize <= 0) break;
      }
      return count;
    }
};
