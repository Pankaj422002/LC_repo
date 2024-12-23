// 2471_minNoOfSwapTomakeBTsorted.cpp

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
    int MinNoOfSwap(vector<int> &arr){
        int ans=0;

        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++)mp[arr[i]]=i;

        vector<int> sorted = arr;
        sort(sorted.begin(),sorted.end());

        for(int i=0;i<arr.size();i++){
            if(arr[i] != sorted[i]){
                int temp=arr[i], sorted_idx=mp[sorted[i]];
                swap(arr[sorted_idx],arr[i]);
                mp[arr[i]]=i;
                mp[temp]=sorted_idx;

                ans++;
            }
        }
        return ans;
    }
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);

        int ans=0;
        while(!q.empty()){
            int n=q.size();
            vector<int> arr;
            for(int i=0;i<n;i++){
                TreeNode* temp = q.front();q.pop();
                arr.push_back(temp->val);
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
            ans += MinNoOfSwap(arr);
        }
        return ans;
    }
};