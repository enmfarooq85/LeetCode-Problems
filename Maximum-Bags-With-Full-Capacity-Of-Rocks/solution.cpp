// 2279. Maximum Bags With Full Capacity of Rocks

// Problem statement:

// You have n bags numbered from 0 to n - 1. You are given two 0-indexed integer arrays capacity and rocks. The ith bag can hold a maximum of capacity[i] rocks and currently contains rocks[i] rocks. You are also given an integer additionalRocks, the number of additional rocks you can place in any of the bags. Return the maximum number of bags that could have full capacity after placing the additional rocks in some bags.

// Understand the problem frist:

// Hmare pas kuch n bags hy jo ke 0 se n - 1 se numbered hy. Hme do 0 base indexed integers diye hy rocks aur capacity. Aur ith bag me ziada se ziada capacity[i] rocks rakh skte hy aur currently wo ith bag rocks[i] rocks rakh raha hy. Hme aik aur additional blocks ka integer dia hua hy. Hmara goal hy ke hum logo ko ziada se ziada bags fill krne hy. Zaroori nahi ke sare bags me rocks dalne pade ge kuch bags pehle se hi apni capacity ke mutabiq fill hy.

// Approach and Solution:

// Hum log greedy approach ko follow kre ge. Mtlb sb se pehle un bags ko fill kre ge jin ko thode rocks chahie ho ta ke maximum bags fill ho ske. Bs isi cheeze ko follow krte hoe hum log sorting kre ge aur wo needed capacity jo ke bags ko chahie apne ap ko fill krne ke liye.

// class Solution {
// public:
//     int maximumBags(vector<int>& capacity, vector<int>& rocks,
//                     int additionalRocks) {
//         int n = rocks.size();
//         vector<vector<int>> rocksCapacity;

//         for (int i = 0; i < n; i++) {
//             rocksCapacity.push_back({capacity[i] - rocks[i],rocks[i], capacity[i]});
//         }

//         sort(begin(rocksCapacity), end(rocksCapacity));

//         for (int i = 0; i < rocksCapacity.size(); i++) {
//             cout << "{" << rocksCapacity[i][0] << "," << rocksCapacity[i][1] << "," << rocksCapacity[i][2]
//                  << "}" << " ";
//         }


//         int fullBags = 0;
//         for (int i = 0; i < rocksCapacity.size(); i++) {
//             int difference = rocksCapacity[i][0];
//             int currCapacity = rocksCapacity[i][1];
//             int maxCapacity = rocksCapacity[i][2];
//             int neededCapacity = maxCapacity - currCapacity;

//             if (currCapacity == maxCapacity) {
//                 fullBags += 1;
//                 continue;
//             }

//             if (neededCapacity <= additionalRocks) {
//                 fullBags += 1;
//                 additionalRocks -= neededCapacity;
//             }
//         };

//         return fullBags;
//     }
// };

// class Solution {
// public:
//     int maximumBags(vector<int>& capacity, vector<int>& rocks,
//                     int additionalRocks) {
//         int n = capacity.size();
//         int fullBags = 0;
//         vector<int> diff;

//         for (int i = 0; i < n; i++) {
//             diff.push_back(capacity[i] - rocks[i]);
//         }

//         sort(begin(diff), end(diff));

//         for (int i = 0; i < n; i++) {
//             if (additionalRocks >= diff[i]) {
//                 additionalRocks -= diff[i];
//                 fullBags++;
//             } else {
//                 break;
//             }
//         }

//         return fullBags;
//     };
// };
