// 948. Bag of Tokens

// Problem statement:

/*
You start with an initial power of power, an initial score of 0, and a bag of tokens given as an integer array tokens, where each tokens[i] denotes the value of tokeni.

Your goal is to maximize the total score by strategically playing these tokens. In one move, you can play an unplayed token in one of the two ways (but not both for the same token):

Face-up: If your current power is at least tokens[i], you may play tokeni, losing tokens[i] power and gaining 1 score.
Face-down: If your current score is at least 1, you may play tokeni, gaining tokens[i] power and losing 1 score.
Return the maximum possible score you can achieve after playing any number of tokens.
*/

// Understand the problem first:

// Hme tokens array aur power di gayi hy. Hmara goal hy hy ke hme max score achieve krna hy. Hr token aik hi mrtaba play krna hy. Apke pas token ko play krne ke do strategies hy. one is ke ap ki power agr at least tokens[i] se badi hy tu ap token ko use kr skte hu aur apki power me se tokens[i] minus ho jaye ga aur score aik badh jaye ga. Dosra option ye hy ke agr score at least 1 hy tu pir ap power me tokens[i] plus kr ge aur score minue 1 ho jaye ga. hme maximum possible score return krna hy after any number of tokens.

// Approach and Solution:

// Iski agr approach ki trf aye tu sbse pehle ye dekhna ho ga ke score kb max aur min ho skta hy. Agr thoda problem smje tu nazar aye ga ke hme max ya min token ko use krna ho ga. Aur iske liye hum log two pointers approach use kre ge ta ke ye cheez implement kr ske. lekin sb se ahem cheez ye hy ke hme power ziada se ziada se maintain rakhni hy ta ke hum log ziada score kr ske.

// class Solution {
// public:
//     int bagOfTokensScore(vector<int>& tokens, int power) {
//         int score = 0;
//         int maxScore = 0;
//         int n = tokens.size();
//         int i = 0;
//         int j = n - 1;
//         sort(tokens.begin(), tokens.end());

//         while (i <= j) {
//             // km token value wale ko use kre ta ke score power ziada se ziada
//             // reh ske aur mazeed score badh ske
//             if (power >= tokens[i]) {
//                 power -= tokens[i];
//                 score += 1;
//                 i++;
//                 maxScore = max(score, maxScore);
//             } else if (score >= 1) {
//                 // ziada se ziada power lene ki koshih me ziada tokens wale ko le
//                 power += tokens[j];
//                 score -= 1;
//                 j--;
//             } else {
//                 // agr kahi bi oper wali dono match na hoi tu wahi return kr de
//                 // aik version ye bi hy ke i++, j-- kr de aur last pe i > j
//                 // ho jaye ga lekin ye little expensive operation hy
//                 return maxScore;
//             }
//             // } else {
//             //     i++;
//             //     j--;
//             // }
//         }

//         return maxScore;
//     }
// };
