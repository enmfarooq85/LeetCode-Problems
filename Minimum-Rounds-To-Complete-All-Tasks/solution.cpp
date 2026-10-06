// 244. Minimum Rounds to Complete All Tasks

// Problem statement:

// You are given a 0-indexed integer array tasks, where tasks[i] represents the difficulty level of a task. In each round, you can complete either 2 or 3 tasks of the same difficulty level. Return the minimum rounds required to complete all the tasks, or -1 if it is not possible to complete all the tasks.

// Understand the problem first:

// Hme aik 0 indexed integer array tasks dia gia hy jaha tasks[i] task ki difficulty level ko denote kr raha hy. Hme hr round me 2 ya 3 teen tasks krne hy jo ke same difficulty level ke ho. Yaad rahe sare kr sare krne hy agr koi aik bi na hua tu -1 return kr dena hy.

// Approach and Solution:

// Sb se pehle tu ye dekhe ke hme krna kia hy hme krna ye hy ke tasks ko jldi se jldi khatam krne hy minimum rounds me. Ye aik greedy algo ka question hy jaha hum log sb se pehle try kre ge ke same difficulty level ke teeno tasks pure krne ki koshih kre aur pir baqio ko. Ab ye dekhna hy kis trah hme same tasks wale select krne hy iske liye hum log hashmap use kre ge jis me key tasks[i] aur value tasks[i] frequency ko denote kre ga. Then pir jo tu tasks pure ko 3 3 ke groups me divide kr skte ho kr le ge aur then pir baqio ke liye hum log 2 aur 3 ke groups me divide kr ke miniimum rounds dekhe ge.

// class Solution {
// public:
//     int minimumRounds(vector<int>& tasks) {
//         unordered_map<int, int> mp;
//         for (int& task : tasks) {
//             mp[task]++;
//         }

//         int ans = 0;
//         for (const auto& [key, val] : mp) {
//             if (val == 1) {
//                 return -1;
//             }

//             if (val % 3 == 0) {
//                 ans += (val / 3);
//             } else {
//                 // 10
//                 // 3 + 3 + 2 + 2 => 4
//                 // 2 + 2 + 2 + 2 + 2 => 5
//                 // 10 / 3 + 1 => 4
//                 ans += val / 3 + 1;
//             }
//         }

//         return ans;
//     }
// };
