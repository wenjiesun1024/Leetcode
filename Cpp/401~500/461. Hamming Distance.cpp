class Solution {
public:
    int hammingDistance(int x, int y) {
        //return bitset<32>(x^y).count();
        int res = 0;
        for (int i = 0; i < 32; i++) {
            if ((x&1) != (y&1)) res++;
            x >>= 1;
            y >>= 1;
        }
        return res;
    }
};