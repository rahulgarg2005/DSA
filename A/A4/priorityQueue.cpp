#include <iostream>
using namespace std ;

struct TreeNode{
    int val ;
    TreeNode* left ;
    TreeNode* right ;
    TreeNode(int val) : val(val) , left(nullptr) , right(nullptr) {}
};

struct PriorityQueue{
    PriorityQueue() : root(nullptr) {}
    TreeNode* root ;

    TreeNode* insert(TreeNode* root , int val){
        if(!root){
            root = new TreeNode(val) ;
            return root ;
        }
        if(val < root -> val) root -> left = insert(root -> left , val) ;
        else if (val > root -> val) root -> right = insert(root -> right , val) ;
        return root ;
    }
 
    TreeNode* deleteMin(TreeNode* root, int& minVal) {
        if (!root) return nullptr;
    
        if (!root->left) {
            minVal = root->val;
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
    
        root->left = deleteMin(root->left, minVal);
        return root;
    }
    
    bool search(TreeNode* root , int key){
        if(!root) return false ;
        if(root -> val == key) return true ;
        else if(root -> val > key) return search(root -> left , key) ;
        else if(root -> val < key) return search(root -> right , key) ;
        return false ;
    } 
 
    void inOrder(TreeNode* root){
        if(!root) return ;
        inOrder(root -> left) ;
        cout << root -> val << ">" ;
        inOrder(root -> right) ;
    }
};

int main() {
    PriorityQueue solution;
    int values[] = {5, 3, 7, 1, 9, 6, 4, 8, 2};

    // Insert values
    cout << "Inserting values: " ;
    for (int val : values) {
        cout << val << " ";
        solution.root = solution.insert(solution.root, val);
    }
    cout << endl ;
    cout << "Inorder traversal: " ;
    solution.inOrder(solution.root);
    cout << endl ;
    // Search for values
    int searchKey = 6;
    solution.search(solution.root, searchKey) ? cout << "True" : cout << "false";
    cout << endl ;
    // Delete minimum value
    int min ;
    cout << "Deleting minimum value: " ;
    TreeNode* minVal = solution.deleteMin(solution.root, min);
    cout << min << endl;

    cout << "Inorder traversal after deletion: " ;
    solution.inOrder(solution.root);
}