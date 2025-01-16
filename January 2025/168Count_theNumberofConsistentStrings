class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        string str;
        int check = 0, count = 0;
        for (int i = 0; i < words.size(); i++) {
            str = words[i];
            check = 0;
            for (int j = 0; j < str.length(); j++) {
                int pos = allowed.find(str[j]);
                if (pos == string::npos) {
                    check = 1;
                    break;
                }
            }

            if (!check) {
                count += 1;
            }
        }
        return count;
    }
};