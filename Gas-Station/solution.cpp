// 134. Gas Station

// Problem statement:

// There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i]. You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations. Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique.

// Understand the problem first:

// Kuch n gas stations hy jo ke aik circle me arrange hy aur waha pe kuch amount of gas padi hoi hy aur ith gas station me gas[i] gas available hy. Hme aik se doosre gas station jana hy aur pure circle goom ke ana hy aur ye dekhna hy ke konsa aesa station ho ga jaha se hum log pura tour kr ske gas station ka. Aur hme kuch cost[i] cost pade gi during visis from ith to (i + 1)th station. Hme aik sirf clockwise aik mrtaba hy goomna hy aur agr koi bi aesa station nahi milta tu -1 return krna hy otherwise index of that station. 

// Approach & Solution:

// Honestly, me ne is question ko teen ghanto me solve kia hy. Tu iski explanation itni simple nahi hy. Lekin me apko recommend kro ga ke MIK ki ye video dekh le. (https://www.youtube.com/watch?v=tcOcmNHFTTM). I hope code me likhe gaye comments apko help kre ge mazeed.

// TLE: 35/41

// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         int n = gas.size();

//         // Try each station as a potential starting point.
//         for (int start = 0; start < n; start++) {
//             // Skip stations that cannot reach the next station initially.
//             if (gas[start] < cost[start])
//                 continue;

//             // Start traveling from the station immediately after the start.
//             int current = (start + 1) % n;

//             // Collect gas at the start and pay the cost to reach the next station.
//             int remainingGas = gas[start] - cost[start] + gas[current];

//             // Continue traveling until we return to the starting station.
//             while (current != start) {
//                 // Stop if we cannot afford the cost of reaching the next station.
//                 if (remainingGas < cost[current])
//                     break;

//                 // Save the cost of traveling from the current station.
//                 int travelCost = cost[current];

//                 // Move to the next station, wrapping around at the end.
//                 current = (current + 1) % n;

//                 // Collect gas available at the next station.
//                 int gasAtNextStation = gas[current];

//                 // Update the tank after paying the travel cost and collecting gas.
//                 remainingGas = remainingGas - travelCost + gasAtNextStation;
//             }

//             // If we returned to the start, the entire circuit is possible.
//             if (current == start)
//                 return start;
//         }

//         return -1;
//     }
// };

// PASSED: 41/41

// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         int n = gas.size();

//         // Calculate the total gas available across all stations.
//         int totalGas = accumulate(begin(gas), end(gas), 0);

//         // Calculate the total gas required to travel between all stations.
//         int totalCost = accumulate(begin(cost), end(cost), 0);

//         // If total gas is less than total cost, completing the circuit is impossible.
//         if (totalGas < totalCost) {
//             return -1;
//         }

//         // Track the current gas balance while testing the candidate starting station.
//         int currentTank = 0;

//         // Store the index of the current candidate starting station.
//         int startIndex = 0;

//         // Traverse every station to find a valid starting point in linear time.
//         for (int i = 0; i < n; i++) {

//             // Update the tank with the net gas gained or lost at the current station.
//             currentTank += gas[i] - cost[i];

//             // If the tank becomes negative, the current candidate cannot reach this station.
//             if (currentTank < 0) {
//                 // Reset the tank because the next station becomes the new candidate.
//                 currentTank = 0;

//                 // Choose the station after the failure point as the next starting candidate.
//                 startIndex = i + 1;
//             }
//         }

//         return startIndex;
//     }
// };
