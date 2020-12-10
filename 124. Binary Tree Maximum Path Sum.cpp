class Solution {
public:
    int maxPathSumUtil (TreeNode* temp, int& maxsum){
        if(temp==NULL) return INT_MIN;
        
        int leftsum = maxPathSumUtil (temp->left, maxsum);
        int rightsum = maxPathSumUtil (temp->right, maxsum);
        
        if (leftsum<0) leftsum = 0;
        if (rightsum<0) rightsum = 0;
        
        int sum = leftsum + rightsum + temp->val;
        
        maxsum = max (maxsum, sum);
        
        return max(leftsum, rightsum)+temp->val;
    }
    
    int maxPathSum (TreeNode* root) {
        if(root==NULL) return 0;
        int maxsum = INT_MIN;
        maxPathSumUtil (root, maxsum);
        return maxsum;
    }
};
