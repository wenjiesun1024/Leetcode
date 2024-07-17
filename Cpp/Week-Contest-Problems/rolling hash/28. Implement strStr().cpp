class Solution {
public:
    int strStr(string haystack, string needle) {
        using ul = unsigned long;
        ul mod = 1e9 + 7, p = 31;
        int n = haystack.length(), m = needle.length();
        if (m == 0 || n == 0 || m > n) 
            return m == 0 ? 0 : -1;

        ul a = haystack[0], b = needle[0];
        ul h = 1;

        for(int i = 1; i < m; i++) {
            h = (h*p) % mod;
            a = (a*p + haystack[i]) % mod;
            b = (b*p + needle[i]) % mod;
        }
        for (int i = 0; i <= n-m; i++) {
            if (a == b) {
                int j = 0;
                while (j < m && needle[j] == haystack[i+j]) ++j;
                if(j == m) return i;
            }

            if (i < n-m)
                a = (((a + mod - (haystack[i]*h)%mod) * p)%mod + haystack[i+m]) % mod;
        }
        return -1;
    }
};