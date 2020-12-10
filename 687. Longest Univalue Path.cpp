public:
    int longestUnivaluePathUtil(TreeNode* temp, int& count){
        if (temp==NULL) return 0;
        
        int leftlen = longestUnivaluePathUtil(temp->left, count);
        int rightlen = longestUnivaluePathUtil(temp->right, count);
        
        int leftcount=0, rightcount=0;
        
        if(temp->left) if(temp->left->val==temp->val) leftcount += leftlen+1;
        if(temp->right) if(temp->right->val==temp->val) rightcount += rightlen+1;
        
        count = max(count, leftcount+rightcount);
        
        return max(leftcount, rightcount);
    }
    
    int longestUnivaluePath(TreeNode* root) {
        if (root==NULL){
            return 0;
        }
        int count = 0;
        longestUnivaluePathUtil (root, count);
        return count;
    }
};
