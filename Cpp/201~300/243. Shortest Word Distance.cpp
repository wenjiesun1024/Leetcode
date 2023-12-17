class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int p1 = -1, p2 = -1;
        int n = words.size(), res = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (words[i] == word1) p1 = i;
            else if (words[i] == word2) p2 = i;
            if (p1 != -1 && p2 != -1) res = min(res, abs(p1 - p2));
        }
        return res;
    }
};