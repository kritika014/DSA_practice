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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==nullptr){
            return ans;
        }
        bool l_r=true;
        queue<TreeNode*>q;
        //vector<vector<int>>ans;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int>lvl(size);
            for(int i=0;i<size;i++){
                TreeNode* top=q.front();
                q.pop();
                int idx=(l_r) ? i : (size - i - 1);
                lvl[idx]=top->val;

                if(top->left){
                    q.push(top->left);
                }
                if(top->right){
                    q.push(top->right);
                }
            }
            ans.push_back(lvl);
            l_r = !l_r;
        }
        return ans;
    }
};