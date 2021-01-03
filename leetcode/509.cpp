class Solution {
  public:
    int fib(int n) {
      if (n <= 1) return n;
      int l = 0, r = 1, tmp;
      while (n - 2 >= 0) {
        tmp = r;
        r = l + r;
        l = tmp;
        n--;
      }
      return r;
    }
};
