// 649. Dota2 Senate

// Problem statement:

/*
In the world of Dota2, there are two parties: the Radiant and the Dire.

The Dota2 senate consists of senators coming from two parties. Now the Senate wants to decide on a change in the Dota2 game. The voting for this change is a round-based procedure. In each round, each senator can exercise one of the two rights:

Ban one senator's right: A senator can make another senator lose all his rights in this and all the following rounds.
Announce the victory: If this senator found the senators who still have rights to vote are all from the same party, he can announce the victory and decide on the change in the game.
Given a string senate representing each senator's party belonging. The character 'R' and 'D' represent the Radiant party and the Dire party. Then if there are n senators, the size of the given string will be n.

The round-based procedure starts from the first senator to the last senator in the given order. This procedure will last until the end of voting. All the senators who have lost their rights will be skipped during the procedure.

Suppose every senator is smart enough and will play the best strategy for his own party. Predict which party will finally announce the victory and change the Dota2 game. The output should be "Radiant" or "Dire".
*/

// Understand the problem frist:

// Farz kre aik aesi dunya hy jis ka name Dota2 hy aur waha do parties hy Radiant aur Dire. Aur Dota2 ki senate in do parties ke senator se aye gi. Lekin is senate ko kon snbale ga iske liye voting like procedure ho ga. Lekin is trah nahi jis trah hmari dunya me hota hy ke jis ke zyada vote wo jeet jaye ga. In ke voting is trah ho gi ke hr round me aik senator ke pass do choices ho gi ya tu wo doosre bnde ko ban kr skta hy ya pir wo victory announce kr skta hy. Hme aik string senate dia gia hy jo ke R aur D sentors pe mustamil ho ga jo ke Radiant (R), aur Dire(D) party se ho ge. Round left se start ho ga. aur ye tb tk round chle ge jb tke kisi ki victory na ho jaye. Lekin in senators ko badi smjdari se khel khelna ho ga ke wo jeet ske. Jo jeete us party ka name return krna hy.

// Approach and Solution:

// Greedy approach ye hy ke wo apne mukhalif ko ban kre ga aur just apne sath wale first opponent ko ta ke us ko dobara mouqaa mil ske ban krne ka. Baqi ap left se start kre ge aur wrap around bi kr skte hy aur wapis a ke bi ban kr skte hy. Abhi neend a rahi. Kbhi pir discuss kre ge details me.

// class Solution {
// public:
//     bool removeSenate(string& senate, char sn, int crawler, int n) {
//         bool isSmallerIdx = false;

//         while (true) {
//             if (crawler == 0) {
//                 isSmallerIdx = true;
//             }

//             if (senate[crawler] == sn) {
//                 senate.erase(begin(senate) + crawler);
//                 break;
//             }

//             crawler = (crawler + 1) % n;
//         };

//         return isSmallerIdx;
//     }

//     string predictPartyVictory(string senate) {
//         int n = senate.length();

//         int rCount = count(begin(senate), end(senate), 'R');
//         int dCount = n - rCount;

//         int crawler = 0;

//         while (rCount > 0 && dCount > 0) {
//             if (senate[crawler] == 'R') {
//                 bool isSmallerIdx =
//                     removeSenate(senate, 'D', (crawler + 1) % n, n);
//                 dCount--;
//                 if (isSmallerIdx) {
//                     crawler--;
//                 };
//             } else if (senate[crawler] == 'D') {
//                 bool isSmallerIdx =
//                     removeSenate(senate, 'R', (crawler + 1) % n, n);
//                 rCount--;

//                 if (isSmallerIdx) {
//                     crawler--;
//                 };
//             }

//             crawler = (crawler + 1) % n;
//         }

//         return rCount == 0 ? "Dire" : "Radiant";
//     }
// };

// class Solution {
// public:
//     void removeSenate(string& senate, char sn, int crawler, int n) {
//         while (true) {
//             if (senate[crawler] == sn) {
//                 senate[crawler] = '$';
//                 break;
//             }

//             crawler = (crawler + 1) % n;
//         };

//     }

//     string predictPartyVictory(string senate) {
//         int n = senate.length();
//         int rCount = count(begin(senate), end(senate), 'R');
//         int dCount = n - rCount;

//         int crawler = 0;

//         while (rCount > 0 && dCount > 0) {
//             if (senate[crawler] == 'R') {
//                 removeSenate(senate, 'D', (crawler + 1) % n, n);
//                 dCount--;
//             } else if (senate[crawler] == 'D') {
//                 removeSenate(senate, 'R', (crawler + 1) % n, n);
//                 rCount--;
//             }

//             crawler = (crawler + 1) % n;
//         }

//         return rCount == 0 ? "Dire" : "Radiant";
//     }
// };
