#include <iostream>
using namespace std ;

struct TreeNode{
    int val ;
    TreeNode* left ;
    TreeNode* right ;
    TreeNode(int val) : val(val) , left(nullptr) , right(nullptr) {}
};

struct Traversal{
    Traversal() : root(nullptr) {}
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
 
    void preOrder(TreeNode* root){ 
        if(!root){
            cout << "NULL>" ;
            return ;
        }
        cout << root -> val << ">" ;
        preOrder(root -> left) ;
        preOrder(root -> right) ;
    }

    void inOrder(TreeNode* root){
        if(!root){
            cout << "NULL>" ;
            return ;
        }
        inOrder(root -> left) ;
        cout << root -> val << ">" ;
        inOrder(root -> right) ;
    }

    void postOrder(TreeNode* root){
        if(!root){
            cout << "NULL>" ;
            return ;
        }
        postOrder(root -> left) ;
        postOrder(root -> right) ;
        cout << root -> val << ">" ;
    }
};

int main(){
    Traversal tree ;
    int val[] = {8, 5, 3, 1, 4, 6, 10, 11, 14};
    for (int num : val) tree.root = tree.insert(tree.root, num);
    cout << "PRE-ORDER:" << endl; 
    tree.preOrder(tree.root) ;
    cout << endl;
    cout << "IN-ORDER:" << endl; 
    tree.inOrder(tree.root) ;
    cout << endl;
    cout << "POST-ORDER:" << endl; 
    tree.postOrder(tree.root) ;
}