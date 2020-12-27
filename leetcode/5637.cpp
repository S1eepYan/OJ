class Solution {
public:
    bool halvesAreAlike(string s) {
        int len = s.size(), i = 0, l = 0, r = 0;
        for (; i < len; i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
                s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
                  if (i < len / 2) l++;
                  else r++;
            }
         }
        return l == r;
    }
};
