#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to build tree from preorder input (-1 for NULL)
TreeNode* buildTree() {
    int val;
    if (!(cin >> val)) return nullptr; // safety check
    if (val == -1) return nullptr;
    TreeNode* root = new TreeNode(val);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

// Helper function to compute max path sum
int maxPathDown(TreeNode* node, int &maxSum) {
    if (!node) return 0;
    
    int left = max(0, maxPathDown(node->left, maxSum));   // ignore negative paths
    int right = max(0, maxPathDown(node->right, maxSum));
    
    maxSum = max(maxSum, node->val + left + right);       // update max path sum
    return node->val + max(left, right);                  // return best downward path
}

int maxPathSum(TreeNode* root) {
    int maxSum = INT_MIN;
    maxPathDown(root, maxSum);
    return maxSum;
}

int main() {
    TreeNode* root = buildTree();
    cout << "Maximum Path Sum " << maxPathSum(root);
    return 0;
}
