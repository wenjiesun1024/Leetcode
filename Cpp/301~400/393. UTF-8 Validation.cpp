class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int cnt = 0;
        for (auto c : data) {
            if (cnt == 0) {
                if ((c >> 5) == 0b110) cnt = 1;
                else if ((c >> 4) == 0b1110) cnt = 2;
                else if ((c >> 3) == 0b11110) cnt = 3;
                else if ((c >> 7) == 0b1) return false;
            } else {
                if ((c >> 6) != 0b10) return false;
                cnt--;
            }
        }
        return cnt == 0;
    }
};