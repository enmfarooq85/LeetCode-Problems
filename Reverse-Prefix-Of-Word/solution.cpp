// 2000. Reverse Prefix of Word

// Proble statement:

// Given a 0-indexed string word and a character ch, reverse the segment of word that starts at index 0 and ends at the index of the first occurrence of ch (inclusive). If the character ch does not exist in word, do nothing. For example, if word = "abcdefd" and ch = "d", then you should reverse the segment that starts at 0 and ends at 3 (inclusive). The resulting string will be "dcbaefd". Return the resulting string.

// Understand the problem first:

// hme aik zero based indexed string dia gia hy string word aur aik character ch di gia hy. hum ne word segment ke start means zero index se le kr ch ke index tk us substring ko reverse kr ke return krna hy.

// Approach and Solution:

// Aik tu hum stack se kr skte hy aur dosra ye kr pehle character ka index find kr ke then two pointers use kr skte hy.

class Solution {
public:
    string reversePrefix(string word, char ch) {
        stack<char> st;
        int index = -1;

        for (int i = 0; i < word.size(); i++) {
            st.push(word[i]);

            if (word[i] == ch) {
                index = i;
                break;
            }
        }

        if (index == -1)
            return word;

        int i = 0;
        while (!st.empty()) {
            word[i++] = st.top();
            st.pop();
        }

        return word;
    }
};
