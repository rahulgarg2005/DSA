#include <iostream>
using namespace std ;

class AVL{
    struct TreeNode{
        int val ;
        TreeNode* left, *right;
        TreeNode(int val) : val(val) , left(nullptr) , right(nullptr) {}
    };
    public:
    AVL() : root(nullptr) {} 
    TreeNode* root ;
    
    TreeNode* insert(TreeNode* root , int val){
        if(!root) {
            root = new TreeNode(val) ;
            return root ;
        }
        if(val < root -> val) root -> left = insert(root -> left , val) ;
        if(val > root -> val) root -> right = insert(root -> right , val) ;
        return rotate(root) ;
    }

    TreeNode* rotate(TreeNode* Node){
        //left heavy
        if(height(Node->left)-height(Node->right) > 1){
            // left-left
            if(height(Node->left->left)-height(Node->left->right) > 0){
                return rightRotate(Node) ;
            }
            //left-right
            if(height(Node->left->left)-height(Node->left->right) < 0){
                Node->left = leftRotate(Node->left) ;
                return rightRotate(Node) ;
            }       
        }
        //right heavy
        if(height(Node->right)-height(Node->left) > 1){
            // right-right
            if(height(Node->right->right)-height(Node->right->left) > 0){
                return leftRotate(Node) ;
            }
            //right-left
            if(height(Node->right->right)-height(Node->right->left) < 0){
                Node->right = rightRotate(Node->right) ;
                return leftRotate(Node) ;
            }       
        }
        return Node ;
    }

    TreeNode* rightRotate(TreeNode* Node){
        TreeNode* x = Node->left ;
        Node->left = x->right ;
        x->right = Node ;
        return x ;
    }
 
    TreeNode* leftRotate(TreeNode* Node){
        TreeNode* x = Node->right ;
        Node->right = x->left ;
        x->left = Node ;
        return x ;
    }

    int height(TreeNode* root){
        if(!root) return 0 ;
        return max(height(root->left) , height(root->right)) + 1 ;
    }

    bool Search(TreeNode* root , int val){
        if(!root) return false ;
        if(val == root->val) return true ;
        else if(val < root->val) return Search(root->left , val) ;
        else if(val > root->val) return Search(root->right , val) ;
        return false ;
    }

    TreeNode* delNode(TreeNode* root , int val){
        if(!root) return root ;
        if(val < root->val) root->left = delNode(root->left,val) ;
        else if(val > root->val) root->right = delNode(root->right,val) ;
        else{
            if(!root->left || !root->right){
                TreeNode* temp = root->right ? root->right : root->left ;
                delete root ;
                return temp ;
            }
            else{
                TreeNode* temp = root->right ;
                while(temp->left) temp = temp->left ;
                root->val = temp->val ;
                root->right = delNode(root->right , temp->val) ;
            }
        }
        return rotate(root) ;
    }
};

int main() {
    AVL avl; 

    avl.root = avl.insert(avl.root, 10);
    avl.root = avl.insert(avl.root, 20);
    avl.root = avl.insert(avl.root, 5);
    avl.root = avl.insert(avl.root, 4);
    avl.root = avl.insert(avl.root, 15);

    int searchVal = 10;
    avl.Search(avl.root, searchVal) ? std::cout << "True" : std::cout << "False" << "\n";
    cout << endl ;
    int delVal = 10;
    avl.root = avl.delNode(avl.root, delVal);

    int searchVal2 = 10;
    avl.Search(avl.root, searchVal2) ? std::cout << "True" : std::cout << "False" << endl;

} 