class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int len = s.size();
        int numWords = words.size();
        int wordLen = words[0].size();
        
        // Check if the input string length is less than the minimum required length
        if (len < (wordLen * numWords)) {
            return {};
        }
        
        vector<int> resultIndices;

        // Create a map to store the frequency of words
        unordered_map<string, int> wordFreqMap;
        for (string word : words) {
            wordFreqMap[word]++;
        }

        // Iterate through different starting positions for the substring
        for (int startPos = 0; startPos < wordLen; startPos++) {
            unordered_map<string, int> currWordFreqMap;
            int wordCount = 0;

            // Process each substring with a fixed starting position
            for (int i = startPos; i < startPos + (numWords * wordLen); i += wordLen) {
                string currentWord = s.substr(i, wordLen);
                currWordFreqMap[currentWord]++;
                if (currWordFreqMap[currentWord] <= wordFreqMap[currentWord]) {
                    wordCount++;
                }
            }

            if (wordCount == numWords) {
                resultIndices.push_back(startPos);
            }

            int endIndex = startPos + numWords * wordLen;
            for (int j = startPos + numWords * wordLen; j <= len - wordLen; j += wordLen) {
                string removedWord = s.substr(j - numWords * wordLen, wordLen);
                if (currWordFreqMap.find(removedWord) != currWordFreqMap.end()) {
                    currWordFreqMap[removedWord]--;
                    if (currWordFreqMap[removedWord] < wordFreqMap[removedWord]) {
                        wordCount--;
                    }
                }

                string addedWord = s.substr(j, wordLen);
                currWordFreqMap[addedWord]++;
                if (currWordFreqMap[addedWord] <= wordFreqMap[addedWord]) {
                    wordCount++;
                }

                if (wordCount == numWords) {
                    resultIndices.push_back(j - (numWords - 1) * wordLen);
                }
            }
        }

        return resultIndices;
    }
};