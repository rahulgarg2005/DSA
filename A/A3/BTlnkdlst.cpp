#include <iostream>
using namespace std ;

class BinaryTree{
public:
	BinaryTree() : root(nullptr) {}
	class Node{
	public:
		int val ;
		Node* left ;	
		Node* right ;	
		Node(int val) : val(val) , left(nullptr) , right(nullptr) {}
	};

	Node* root ;
	Node* insert(Node* root , int val){
		if(!root) {
			root = new Node(val) ; 
			return root ;
		}
		if(val > root -> val) root -> right = insert(root -> right , val) ;
		else root -> left = insert(root -> left , val) ;
		return root ;
	}

	bool Search(Node* root , int key){
		if (!root) return false ;
		if(root -> val == key) return true ;
		else if(root -> val < key) return Search(root -> right , key);
		else if(root -> val > key) return Search(root -> left , key);
		return false ;
	}
	
	Node* deleteNode(Node* root , int key) {
		if(!root) return root ;
		if(key > root -> val) return deleteNode(root -> right , key) ;
		if(key < root -> val) return deleteNode(root -> left , key) ;
		else{			
			// No child
			if(root -> left == nullptr && root -> right == nullptr){	
				delete root ;
				return nullptr ;
			}
			//1 child
			if(!root -> left){
				Node* temp = root -> right ;
				delete root ;
				return temp ;
			}
			if(!root -> right){
				Node* temp = root -> left ;
				delete root ;
				return temp ;
			}
			//2 child
			Node* right = inorderSuccessor(root) ;
			root -> val = right -> val ;
			root->right = deleteNode(root->right , right->val) ;			
		}
		return root ;			 
	}

	Node* inorderSuccessor(Node* root) {
		Node* current = root ;
		while(current -> right) current = current -> right ;
		return current ;
	}

	void print(Node* root){
		if(!root) {
			cout << "NULL" << " > ";
			return ;
		}
		cout << root -> val << " > ";
		print(root -> left) ;
		print(root -> right) ;
	}														
};
int main(){
    BinaryTree tree ;
    int val[] = {8, 5, 3, 1, 4, 6, 10, 11, 14};

    for (int num : val) {
        tree.root = tree.insert(tree.root, num);
    }
	
     tree.print(tree.root);
     cout << endl ;

     tree.Search(tree.root , 5) ? cout << "TRUE" : cout << "FALSE" << endl ;

    tree.deleteNode(tree.root , 5) ;
    
       
    tree.print(tree.root);
cout << endl ;

     tree.Search(tree.root , 5) ? cout << "TRUE" : cout << "FALSE" << endl ;

    cout << endl;
    tree.Search(tree.root , 5) ;
  
}