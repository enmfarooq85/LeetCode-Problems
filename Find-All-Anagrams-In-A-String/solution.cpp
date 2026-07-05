// 438. Find All Anagrams in a String

// Problem statemetn:

// Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

// Understand the problem first:

// hme do strings dia gaye hy hme array return krna hy start indices ka jo ke ke "p" ke anagrams "s" string me. anagrams mtlb aik word ke letters ke different arrangment but hamesha hr letter ke wahi frequency ho gi jo pehli arrangement me

// Approach and Solution:

// hum log islo sliding window se asani se solve kr skte hy. Aur sath hashmap use kre ge.

class Solution {
public:
    bool isAllZero(vector<int>& charIndices) {
        for (auto& i : charIndices) {
            if (i != 0) {
                return false;
            }
        }
        return true;
    };

    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int k = p.length();
        if (n < k)
            return {};

        vector<int> charIndices(26, 0);
        vector<int> ans;

        for (char i : p) {
            // picking character
            // finding correct position of the char means a will point to zero
            // and z will point to 26
            charIndices[i - 'a']++;
        }

        int i = 0, j = 0;
        while (j < n) {
            // decreasing freq
            charIndices[s[j] - 'a']--;
            // if reached to window size then chk if find anagrams then push the
            // starting index and shift the window
            if (j - i + 1 == k) {
                if (isAllZero(charIndices)) {
                    ans.push_back(i);
                }
                // increase the freq of extracted char
                charIndices[s[i] - 'a']++;
                // shift window
                i++;
            };

            // j will always move if window size reached or not
            j++;
        }

        return ans;
    };
};

