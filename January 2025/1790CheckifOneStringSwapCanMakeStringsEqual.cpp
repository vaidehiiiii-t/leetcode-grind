class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int i = -1, j = -1;
        int cnt = 0;

        for (int k = 0; k < s1.length(); k++) {
            if (s1[k] != s2[k]) {
                cnt++;
                if (i == -1) {
                    i = k;
                } else if (j == -1) {
                    j = k;
                }
            }
        }

        if (cnt == 0) {
            return true;
        } else if (cnt == 2 && s1[i] == s2[j] && s1[j] == s2[i]) {
            return true;
        }

        return false;
    }
};


//2nd approach
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int count = 0;
        int freq1[26] = {0}, freq2[26] = {0};
        for (int i = 0; i < s1.length(); i++) {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i])
                return false;
        }
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i])
                count++;
        }
        return count <= 2;
    }
};
