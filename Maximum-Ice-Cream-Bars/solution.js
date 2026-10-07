// 1833. Maximum Ice Cream Bars

/* It is a sweltering summer day, and a boy wants to buy some ice cream bars.

At the store, there are n ice cream bars. You are given an array costs of length n, where costs[i] is the price of the ith ice cream bar in coins. The boy initially has coins coins to spend, and he wants to buy as many ice cream bars as possible. 

Note: The boy can buy the ice cream bars in any order.

Return the maximum number of ice cream bars the boy can buy with coins coins.

You must solve the problem by counting sort.
*/

// Understand the problem first:

// Hme aik costs array dia hua hy jaha costs[i] ith ice cream ko denote kr raha hy. Kuch coins hy aur hme maximum se maximum ice creams buy krni hy. 

// Approach and Solution:

// Sb se pehle approach tu yahi mind me ati hy ke sb se km price wali buy ki jaye ta ke maximum se maximum buy ki ja ske. Dosri approach counting sort ke zariye kr skte hy. Please see counting sort on the yt.

// class Solution {
// public:
//     int maxIceCream(vector<int>& costs, int coins) {
//         // Find maximum cost
//         int maxCost = 0;
//         for (int cost : costs) {
//             maxCost = max(maxCost, cost);
//         }

//         // Frequency of each cost
//         vector<int> costsFreq(maxCost + 1, 0);
//         for (int cost : costs) {
//             costsFreq[cost]++;
//         }

//         int ans = 0;
//         // Start from cheapest ice cream
//         for (int price = 1; price <= maxCost; price++) {
//             if (costsFreq[price] == 0)
//                 continue;

//             if (price > coins)
//                 break;

//             // How many can we afford?
//             int quantity = min(costsFreq[price], coins / price);

//             ans += quantity;
//             coins -= quantity * price;

//             // No money left
//             if (coins == 0)
//                 break;
//         }

//         return ans;
//     }
// };

// class Solution {
// public:
//     int maxIceCream(vector<int>& costs, int coins) {
//         sort(begin(costs), end(costs));

//         int n = costs.size();
//         int ans = 0;

//         for (int i = 0; i < n; i++) {
//             if (costs[i] > coins) {
//                 break;
//             }

//             coins -= costs[i];
//             ans += 1;
//         }

//         return ans;
//     }
// };
