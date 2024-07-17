//nlogn
class Solution {
public:
    int longestSubarray(vector<int>& A, int limit) {
        int i = 0, res = 0;
        multiset<int> m;
        for (int j = 0; j < A.size(); ++j) {
            m.insert(A[j]);
            while (*m.rbegin() - *m.begin() > limit)
                m.erase(m.find(A[i++]));
            res = max(res, j-i+1);
        }
        return res;
    }
};



//n
class Solution {
public:
    int longestSubarray(vector<int>& A, int limit) {
        deque<int> maxd, mind;
        int i = 0, res = 0;
        for (int j = 0; j < A.size(); ++j) {
            while (!maxd.empty() && A[j] > maxd.back()) maxd.pop_back();
            while (!mind.empty() && A[j] < mind.back()) mind.pop_back();
            maxd.push_back(A[j]);
            mind.push_back(A[j]);
            while (maxd.front() - mind.front() > limit) {
                if (maxd.front() == A[i]) maxd.pop_front();
                if (mind.front() == A[i]) mind.pop_front();
                ++i;
            }
            res = max(res, j-i+1);
        }
        return res;
    }
};