#include <iostream> 
using namespace std ;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

int Depth(TreeNode* root , int key , int dep = 0 ){
    if(!root) return -1 ;
    if(root -> val == key) return dep ;
    int leftDep = Depth(root -> left , key , dep + 1) ;
    if(leftDep != 1) return leftDep ;
    return Depth(root -> right , key , dep + 1) ;
}

int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    /*
        Tree structure:
             1
           /   \
          2     3
         / \   / \
        4   5 6   7
    */

    // Test depth function for different keys
    cout << "Depth of 4: " << Depth(root, 4) << endl;  // Expected: 2
}