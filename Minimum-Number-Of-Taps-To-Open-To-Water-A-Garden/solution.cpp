// 1326. Minimum Number of Taps to Open to Water a Garden

// Problem statement:

/*
There is a one-dimensional garden on the x-axis. The garden starts at the point 0 and ends at the point n. (i.e., the length of the garden is n).

There are n + 1 taps located at points [0, 1, ..., n] in the garden.

Given an integer n and an integer array ranges of length n + 1 where ranges[i] (0-indexed) means the i-th tap can water the area [i - ranges[i], i + ranges[i]] if it was open.

Return the minimum number of taps that should be open to water the whole garden, If the garden cannot be watered return -1.
*/

// Understand the problem first:

// Hme aik garden dia gia hy jo ke x-axis pe mushtamil hy aur garden 0 se start ho raha hy aur n pe end ho raha hy. Hme n + 1 taps means tube well diye gaye hy jo ke 0 to n points pe located hy. Hme aik integer n bi dia gia hy aur integer array jis ki length n + 1 hy jaha ranges[i] means ith tube well can provide water to the i - ranges[i] and i + ranges[i]. Hme minimum number of tube well ka use kr ke pure garden ko pani dena hy. Agr possible nahi tu -1 return krna hy.  

// Approach and Solution:

// Approach ye hu ke hum log sare taps ki min aur max reach find kr le aur then pir greedy approach se minimum taps ke zariye pure garden ko water kr le. Lekin then pir hum sort kre ge min point ki base pe ta ke ye jana jaye optimally kaha tk jldi poncha jaye. Doosri approach hy hy ke hum log aik array me hr taps ke min end ko use kr ke maxEnd find kr le aur then pir greedly find kr le kitne min taps chahiye. Baqi ye ke asan problem nahi hy smjna asan but iske solution ko smjne ke liye extra focus chahiye.

// class Solution {
// public:
//     int minTaps(int n, vector<int>& ranges) {
//         vector<pair<int, int>> intervals;
//         for (int i = 0; i < ranges.size(); i++) {
//             intervals.push_back({i - ranges[i], i + ranges[i]});
//         }

//         sort(begin(intervals), end(intervals));

//         int ans = 0;
//         int i = 0;
//         int prevEnd = 0;

//         while (i < n + 1) {
//             ans += 1;
//             int curEnd = prevEnd;

//             if (intervals[i].first > prevEnd) {
//                 return -1;
//             }

//             while (i < n + 1 && intervals[i].first <= prevEnd) {
//                 curEnd = max(curEnd, intervals[i].second);
//                 i += 1;
//             }

//             if (curEnd >= n) {
//                 return ans;
//             }

//             prevEnd = curEnd;
//         }
        
//         return -1;
//     }
// };

// class Solution {
// public:
//     int minTaps(int n, vector<int>& ranges) {
//         // Store the farthest position each tap can reach from every starting
//         // point.
//         vector<int> maxReachFromStart(n + 1, 0);

//         // Calculate the coverage interval for each tap.
//         for (int i = 0; i < ranges.size(); i++) {
//             // Find the left boundary of the tap's coverage, limited to 0.
//             int start = max(0, i - ranges[i]);

//             // Find the right boundary of the tap's coverage, limited to n.
//             int end = min(n, i + ranges[i]);

//             // Keep the farthest right boundary for this starting position.
//             maxReachFromStart[start] = max(maxReachFromStart[start], end);
//         }

//         // Count the minimum number of taps needed.
//         int taps = 0;

//         // The farthest position covered by the taps already selected.
//         int currentEnd = 0;

//         // The farthest position reachable using all taps encountered so far.
//         int farthestReach = 0;

//         // Scan every position from 0 to n.
//         for (int i = 0; i <= n; i++) {
//             // If this position is beyond all reachable coverage, the garden
//             // cannot be covered.
//             if (i > farthestReach) {
//                 return -1;
//             }

//             // If we have reached the end of the current coverage,
//             // select another tap to extend the coverage.
//             if (i > currentEnd) {
//                 taps++;

//                 // Extend the current coverage as far as possible.
//                 currentEnd = farthestReach;
//             }

//             // Update the farthest reachable position using taps starting here.
//             farthestReach = max(farthestReach, maxReachFromStart[i]);
//         }

//         return taps;
//     }
// };
