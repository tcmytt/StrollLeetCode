class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> wordCount;
        for (const string& word : words) {
            wordCount[word]++;
        }

        vector<int> ans;
        int n = s.length(), numWords = words.size(), wordLen = words[0].length(), totalLen = numWords * wordLen;

        for (int i = 0; i < wordLen; ++i) {
            int left = i, count = 0;
            unordered_map<string, int> currentCount;

            for (int j = i; j <= n - wordLen; j += wordLen) {
                string word = s.substr(j, wordLen);
                
                if (wordCount.find(word) != wordCount.end()) {
                    currentCount[word]++;
                    count++;

                    while (currentCount[word] > wordCount[word]) {
                        string leftWord = s.substr(left, wordLen);
                        currentCount[leftWord]--;
                        count--;
                        left += wordLen;
                    }

                    if (count == numWords) {
                        ans.push_back(left);
                        string leftWord = s.substr(left, wordLen);
                        currentCount[leftWord]--;
                        count--;
                        left += wordLen;
                    }
                } else {
                    currentCount.clear();
                    count = 0;
                    left = j + wordLen;
                }
            }
        }

        return ans;
    }
};
