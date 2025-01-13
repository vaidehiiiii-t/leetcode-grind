class Solution {
public:
    int minimumLength(string s) {
        int len = s.length();  // Get the length of the string
        vector<int> freq(26, 0);  // Frequency array for 'a' to 'z'

        for (char c : s) {
            int curr = c - 'a';  // Get the index for the current character
            freq[curr]++;  // Increment its frequency

            // If the frequency reaches 3, remove two characters
            if (freq[curr] == 3) {
                freq[curr] -= 2;  // Simulate removing two characters
                len -= 2;  // Decrease the length of the string by 2
            }
        }

        return len;  // Return the final length
    }
};