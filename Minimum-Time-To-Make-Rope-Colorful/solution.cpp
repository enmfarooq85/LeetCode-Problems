// 1578. Minimum Time to Make Rope Colorful

// Problem statement:

/*
lice has n balloons arranged on a rope. You are given a 0-indexed string colors where colors[i] is the color of the ith balloon.Alice wants the rope to be colorful. She does not want two consecutive balloons to be of the same color, so she asks Bob for help. Bob can remove some balloons from the rope to make it colorful. You are given a 0-indexed integer array neededTime where neededTime[i] is the time (in seconds) that Bob needs to remove the ith balloon from the rope. Return the minimum time Bob needs to make the rope colorful.
*/

// Understand the problem first:

// alice name ka aik bnda hy uske pas kuch "n" ballons hy aik rope pe. Hme aik 0 base indexed array colors dia gia hy jaha pe colors[i] denote kr raha hy ith ballon ko. Alice ye krna chahta hy ke ko rope ko colorful bnae. Mtlb ye ke same colors wale ballons aik sath na ho. Hme neededTime array dia gia hy jo ke ith ballon ko brust krte waqt lgne wala time denote kr raha hy. Hme as much as minimum time me rope colorful bnani hy.

// Approach and Solution:

// Hum log greedy approach ko follow kre ge. Is me greedy se means as much as minimum time lga ke rope ko colorful bnana hy. Brae mehrbani code me likhe gaye comments ko padhe aur sirf aik mrtaba copy pencil le ke dry run kre.

// Note:- First solution is just passing 33 testcases. Lekin ye help kre ga apko problem ko mazeed smjne me.

// class Solution {
// public:
//     int minCost(string colors, vector<int>& neededTime) {
//         int n = colors.size();
//         int minTime = 0;

//         for (int color = 1; color < n; color++) {
//             if (colors[color - 1] == colors[color]) {
//                 minTime += min(neededTime[color - 1], neededTime[color]);
//             }
//         }

//         return minTime;
//     }
// };

// class Solution {
// public:
//     int minCost(string colors, vector<int>& neededTime) {
//         int n = colors.size();
//         // Iska maqsad ktina minimum se minimum time lge ga ke me ballons
//         // ko bi brust kr sko aur rope colorful bi ho ske
//         int minTime = 0;
//         // same colors ke liye pechle kisi ballon ka max track kr raha hy
//         // ta ke hum log optimally minimum time wale ballon ko brust kr ske
//         int maxPrev = 0;

//         for (int color = 0; color < n; color++) {
//             // agr same color wale ballon nahi hy tu maxPrev ko reset kr do
//             // aur neeche line 20 pe new ballon ka color bi assign kr do
//             // ta ke agr koi same color wala ballon aye tu hum log optimally
//             // brust kr ske
//             if (color > 0 && colors[color - 1] != colors[color]) {
//                 maxPrev = 0;
//             }
            
//             // yaha pe hum ab tk ke minimum time wale same color wale ballon
//             // ko brust kr rahe hy agr che koi yaha same ki condition nahi hy
//             // lekin agr same hoa tu min nahi tu zero add ho jaye ga 
//             minTime += min(maxPrev, neededTime[color]);

//             // ye ab tk ke maximum time wale ballon ko find krne ki koshih
//             // kr raha hy
//             maxPrev = max(maxPrev, neededTime[color]);
//         }

//         return minTime;
//     }
// };
