#include <iostream>
#include <queue> 
using namespace std ;

struct BinarySearchTree{
    BinarySearchTree() : root(nullptr) {}
    struct TreeNode{
        int data ;
        TreeNode* left ;
        TreeNode* right ;
        TreeNode(int data) : data(data) , left(nullptr) , right(nullptr) {}
    };

    TreeNode* root ;

    TreeNode* insert(TreeNode* root , int val , int& comparisons){
        if(!root){
            root = new TreeNode(val) ;
            return root ;
        }
        comparisons++ ;
        if(val > root -> data) root -> right = insert(root -> right , val , comparisons) ;
        else root -> left = insert(root -> left , val , comparisons) ;
        return root ;
    }

    TreeNode* findMin(TreeNode* Node){
        while(Node -> left) Node = Node -> left ;
        return Node ;
    }
 
    TreeNode* deletion(TreeNode* root , int val , int& comparisons) {
        if(!root) return root ;
        comparisons++ ;
        if(val > root -> data) root -> right = deletion(root -> right , val , comparisons) ;
        else if(val < root -> data) root -> left = deletion(root -> left , val , comparisons) ;
        else{
            comparisons++ ;
            if(!root -> left){
                TreeNode* temp = root -> right ;
                delete root ;
                return temp ;
            }else if(!root -> right){
                TreeNode* temp = root -> left ;
                delete root ;
                return temp ;
            }
            TreeNode* temp = findMin(root -> right) ;
            root -> data = temp -> data ;
            root -> right = deletion(root -> right , temp -> data , comparisons) ;
        }
        return root ;
    }
    bool Search(TreeNode* root , int key , int& comparisons){
		if (!root) return false ;
        comparisons++ ;
		if(root -> data == key) return true ;
        comparisons++ ;
		if(root -> data < key) return Search(root -> right , key , comparisons);
		else if(root -> data > key) return Search(root -> left , key , comparisons);
		return false ;
    }

    void levelOrder(TreeNode* root) {
        if(!root) return ;
        queue<TreeNode*> q ;
        q.push(root) ;
        while(!q.empty()){
            int size = q.size() ;
            for(int i = 0 ; i < size ; i++){
                TreeNode* curr = q.front() ;
                q.pop() ;
                cout << curr -> data << " "  ;
                if(curr -> left) q.push(curr -> left) ;
                if(curr -> right) q.push(curr -> right) ;
            }
            cout << endl ;
        }
    }
};
int main(){ 
    BinarySearchTree tree ;
    int val[] = {8, 5, 3, 1, 4, 6, 10, 11, 14};
    int insertCompr = 0 ;
    int DelCompr = 0 ;
    int SearchCompr = 0 ;


    for (int num : val) tree.root = tree.insert(tree.root, num , insertCompr);
	cout << "Comparisons for insert:" << insertCompr << endl ;
    tree.levelOrder(tree.root);
    cout << endl ;

    tree.Search(tree.root , 5 , SearchCompr) ? cout << "TRUE" << endl: cout << "FALSE" << endl ;
	cout << "Comparisons for Search:" << SearchCompr << endl ;
    tree.deletion(tree.root , 5 , DelCompr) ;
	cout << "Comparisons for delete:" << DelCompr << endl ;
       
    tree.levelOrder(tree.root);
    cout << endl ;
}