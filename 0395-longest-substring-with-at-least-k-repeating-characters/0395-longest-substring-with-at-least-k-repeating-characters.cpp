class Solution {
public:
    int longestSubstring(string s, int k) {
        if (s.size() < k) return 0;

        
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;

        
        for (auto &p : freq) {
            if (p.second < k) {
                char badChar = p.first;
                int maxLen = 0;
                size_t start = 0, pos;

                
                while ((pos = s.find(badChar, start)) != string::npos) {
                    maxLen = max(maxLen, longestSubstring(s.substr(start, pos - start), k));
                    start = pos + 1;
                }
                
                maxLen = max(maxLen, longestSubstring(s.substr(start), k));
                return maxLen;
            }
        }

        
        return s.size();
    }
};
