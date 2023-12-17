class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> m;
        for(auto a : A) {
            for(auto b : B) {
                ++m[a+b];
            }
        }
        int res = 0;
        for(auto c : C) {
            for(auto d : D) {
                auto it = m.find(-c-d);
                if (it != m.end()) {
                    res += it->second;
                }
            }
        }
        return res;
    }
};