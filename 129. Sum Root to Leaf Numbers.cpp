class Solution {
public:
    void sumNumbersUtil (TreeNode* temp, int product, int& sum){
        if(temp->left==NULL && temp->right==NULL){
            product *= 10;
            product += temp->val;
            sum += product;
            return ;
        }
        product *= 10;
        product += temp->val;
        if (temp->left) sumNumbersUtil (temp->left, product, sum);
        if (temp->right) sumNumbersUtil (temp->right, product, sum);
        
    }
    
    int sumNumbers(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int product = 0;
        int sum = 0;
        sumNumbersUtil(root, product, sum);
        return sum;
    }
};
