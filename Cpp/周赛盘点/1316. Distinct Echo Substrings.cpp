class Solution {
public:
    int distinctEchoSubstrings(string text) {
        unordered_set<string_view> res;
        const char *p = text.c_str();
        for (int i=0; i<text.size(); ++i) {
            for (int len=1; i+len+len<=text.size(); ++len) {
                const string_view a(p+i    , len);
                const string_view b(p+i+len, len);
                if (a==b) {
                    res.insert(a);
                }
            }
        }
        return res.size();
    }
};




class Solution {
public:
    typedef long long ll;
    static constexpr int A = 1000000007, B = 1000000037;
    
    class Hash {
    public:
        Hash(const string &s) {
            h[0] = s[0] % B;
            p[0] = 1;
            for (int i=1; i<s.size(); ++i) {
                h[i] = (h[i-1]*A + s[i]) % B;
                p[i] = (p[i-1]*A) % B;
            }
        }
        
        // a and b are inclusive
        ll hash(const int a, const int b) {
            if (a) {
                const auto res = (h[b] - h[a-1] * p[b-a+1]) % B;
                return res < 0 ? B + res : res;
            }   else {
                return h[b];
            }
        }
    private:
        ll h[2000], p[2000];
    };
    
    int distinctEchoSubstrings(string text) {
        Hash h(text);
        
        unordered_set<string_view> res;
        const char *p = text.c_str();
        for (int i=0; i<text.size(); ++i) {
            for (int len=1; i+len+len<=text.size(); ++len) {
                if (h.hash(i, i+len-1) == h.hash(i+len, i+len+len-1)) {
                    res.insert(string_view(p+i, len));
                }
            }
        }
        return res.size();
    }
};






