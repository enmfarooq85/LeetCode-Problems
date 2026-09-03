// 1405. Longest Happy String

// Problem statement:

/*
A string s is called happy if it satisfies the following conditions:

s only contains the letters 'a', 'b', and 'c'.
s does not contain any of "aaa", "bbb", or "ccc" as a substring.
s contains at most a occurrences of the letter 'a'.
s contains at most b occurrences of the letter 'b'.
s contains at most c occurrences of the letter 'c'.
Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "".

A substring is a contiguous sequence of characters within a string.

*/

// Understand the problem statement first:

// hme a, b, aur c integer variabl diye gaye hy. Hme in se longest happy string form krna hy. Agr buht sare variant ke form ho rahe hy tu hum koi bi return kr skte hy nahi tu empty string. Uno ne happy string ki definatin di hui hy ke us me just a, b aur c ho ge aur us me in teeno me kisi character ka count greater than 3 nahi ho skta as a substring. Aur ap maximum a, b aur c times in a,b aur c ko use kr skte ho. Ye zaroori nahi ke hum tmam ke tmama characters ko hi use kr ke longest empty string bnana hy.  

// Approach and Solution:

// iske liye brute force approach lga skte hy ke hum log hr character ko tb tk final string me dalne ki koshih krte rahe jb tk ke last 2 character of final string is character ke same na ho. Agr same hy tu hum log koi aur next character chonne ki koshih kre ge. Lekin ye solution hme TLE de ga.

// hum log iske liye max heap ka use kr skte hy aur bilkul yahi intuition use kre ge jis character ki maxFreq hy usko pick krne ki tb tk koshih kre jb tk final string ke last 2 character same na ho otherwise hum log next top most character chone ge.

// Brute Force:

// T.C => O(3^N) 
// S.C => O(n)

// class Solution {
// public:
//     string longestString;

//     void backtrack(int a, int b, int c, string& current) {
//         if (current.length() > longestString.length()) {
//             longestString = current;
//         }

//         // Try 'a' till the count of just a should be not 2
//         if (a > 0) {
//             if (current.size() < 2 ||
//                 !(current[current.size() - 1] == 'a' &&
//                   current[current.size() - 2] == 'a')) {

//                 current.push_back('a');

//                 backtrack(a - 1, b, c, current);

//                 current.pop_back();
//             }
//         }

//         // Try 'b' till the count of just a should be not 2
//         if (b > 0) {
//             if (current.size() < 2 ||
//                 !(current[current.size() - 1] == 'b' &&
//                   current[current.size() - 2] == 'b')) {

//                 current.push_back('b');

//                 backtrack(a, b - 1, c, current);

//                 current.pop_back();
//             }
//         }

//         // Try 'c' till the count of just a should be not 2
//         if (c > 0) {
//             if (current.size() < 2 ||
//                 !(current[current.size() - 1] == 'c' &&
//                   current[current.size() - 2] == 'c')) {

//                 current.push_back('c');

//                 backtrack(a, b, c - 1, current);

//                 current.pop_back();
//             }
//         }
//     }

//     string longestDiverseString(int a, int b, int c) {
//         string current = "";

//         backtrack(a, b, c, current);

//         return longestString;
//     }
// };

// Using Max Heap & Greedy:

// T.C => O(a + b + c * log(3)) => O(a + b + c)
// S.C => O(1)

// class Solution {
// public:
//     typedef pair<int, int> P;
//     string longestDiverseString(int a, int b, int c) {
//         priority_queue<P> maxHeap;

//         if (a > 0) {
//             maxHeap.push({a, 'a'});
//         }
//         if (b > 0) {
//             maxHeap.push({b, 'b'});
//         }
//         if (c > 0) {
//             maxHeap.push({c, 'c'});
//         }

//         string ans = "";

//         while (maxHeap.size() > 0) {
//             // try to take top most character:
//             int currMaxFreqCount = maxHeap.top().first;
//             int currMaxFreqChar = maxHeap.top().second;
//             maxHeap.pop();

//             if (ans.length() >= 2 && ans[ans.length() - 1] == currMaxFreqChar &&
//                 ans[ans.length() - 2] == currMaxFreqChar) {
//                 // try to take the next top one make sure that priority queue
//                 // should not be empty as well as if empty then break;

//                 if (maxHeap.size() == 0) {
//                     break;
//                 }

//                 int nextMaxFreqCount = maxHeap.top().first;
//                 int nextMaxFreqChar = maxHeap.top().second;
//                 maxHeap.pop();

//                 ans.push_back(nextMaxFreqChar);

//                 nextMaxFreqCount--;
//                 if (nextMaxFreqCount > 0) {
//                     maxHeap.push({nextMaxFreqCount, nextMaxFreqChar});
//                 }
//                 maxHeap.push({currMaxFreqCount, currMaxFreqChar});
//             } else {
//                 ans.push_back(currMaxFreqChar);
//                 currMaxFreqCount--;
//                 if (currMaxFreqCount > 0) {
//                     maxHeap.push({currMaxFreqCount, currMaxFreqChar});
//                 }
//             }
//         }

//         return ans;
//     }
// };
