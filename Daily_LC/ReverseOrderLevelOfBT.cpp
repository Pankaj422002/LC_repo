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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;

        int level=0;

        q.push(root);
        while(!q.empty()){
            int n=q.size();

            if(level%2 != 0){
                //odd: 
                vector<TreeNode*> temp;
                vector<int> data;
                for(int i=0;i<n;i++){
                    temp.push_back(q.front());
                    data.push_back(q.front()->val);q.pop();
                }
                int j=temp.size()-1;
                for(int i=0;i<temp.size();i++,j--){
                    temp[i]->val=data[j];
                    if(temp[i]->left)q.push(temp[i]->left);
                    if(temp[i]->right)q.push(temp[i]->right);
                }
            }else{
                //even: 
                for(int i=0;i<n;i++){
                    TreeNode* temp = q.front();q.pop();
                    if(temp->left)q.push(temp->left);
                    if(temp->right)q.push(temp->right);
                }
            }
            level++;
        }
        return root;
    }
};
