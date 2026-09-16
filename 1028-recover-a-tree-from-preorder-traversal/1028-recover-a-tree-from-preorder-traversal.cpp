/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int idx = 0;
    TreeNode* build(string& s, int depth) {
        int d = 0;
        int i = idx;
        while (i < s.size() && s[i]== '-') {
            d++;
            i++;
        }
        if (d != depth) return nullptr;
        int val = 0;
        while (i<s.size() && s[i]-'0'>=0 && s[i]-'0'<=9) {
            val=val*10+(s[i] -'0');
            i++;
        }
        idx = i;
        TreeNode* node = new TreeNode(val);
        node->left = build(s, depth + 1);
        node->right = build(s, depth + 1);
        return node;
    }
    TreeNode* recoverFromPreorder(string s) {
        return build(s, 0);
    }
};