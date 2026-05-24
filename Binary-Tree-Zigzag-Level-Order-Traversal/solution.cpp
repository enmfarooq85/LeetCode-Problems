// 103. Binary Tree Zigzag Level Order Traversal

// Problem statement:

// Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

// Understand the problem first:

// hme aik binary tree ko root dia gia hy hme us pe zigzag level order traversal krna.

// Approach and Solution:

// hum simple level order traversal kre ge aur sath me flag variable ka use kre ge. Us ke through hum log apne zigzag ko handle kre ge. Hr level ke bad zigzag ka direction bi bdle ge.

#include "bits/stdc++.h"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
right(right) {}
};


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // {{}}
        // {{3}}
        // {{3}, {20, 9}}
        // {{3}, {20, 9}, {15, 7}}

        vector<vector<int>> result;
        // false
        if (root == NULL) {
            return result;
        }

        // creating queue
        // {3}
        // {20, 9}
        queue<TreeNode*> q;
        // pushing the root
        q.push(root);

        // first is going with true because we knew that first will be always
        // left side of zigzag pattern false
        bool leftToRight = true;

        // true
        // true
        while (!q.empty()) {
            // 1
            // 2
            // 3
            int size = q.size();
            vector<int> level(size);

            for (int i = 0; i < size; i++) {
                // take 3 from the front of queue
                // take 20 from the front of queue
                // teke 9 from the front of queue
                // take 15 from the fronte of queue
                // take 7 from the front of queue
                TreeNode* node = q.front();
                // delete 3
                // delete 20
                // delete 9
                // delete 15
                // delete 7
                q.pop();

                // creating index variable so that we choose from the left or
                // right of the level to meet zigzag pattern
                int index;

                // true
                // false
                // false
                // true
                // true
                if (leftToRight) {
                    // 0
                    // 0
                    // 1
                    index = i;
                } else {
                        // index = 2 - 1 - i <==> 1
                        // index = 2 - 1 - i <==> 0
                        index = size - 1 - i;
                }
                // 0 = 3
                // 1 = 20
                // 0 = 9
                // 0 = 15
                // 1 = 7
                level[index] = node->val;

                // true
                // true
                // false
                // false
                // false
                if (node->left) {
                    // 9
                    // 15
                    q.push(node->left);
                }

                // true
                // true
                // false
                // false
                // false
                if (node->right) {
                    // 20
                    // 7
                    q.push(node->right);
                }
            }

            // now we have to negate the previous direction
            // true = false
            // false = true
            // true = false
            leftToRight = !leftToRight;

            // push the current level {3}
            // push the current level {20, 9}
            // push the current level {15, 7}
            result.push_back(level);
        }

        return result;
    }
};