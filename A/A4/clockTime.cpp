#include <iostream>
#include <algorithm>
#include <chrono>
#include <random>
using namespace std ;
using namespace std::chrono;


struct AVL{
    struct TreeNode{
        int val , height ;
        TreeNode *left , *right ;
        TreeNode(int val) : val(val) , left(nullptr) , right(nullptr) , height(1){}
    };

    AVL() : root(nullptr) {}
    TreeNode* root ;

    TreeNode* insert(TreeNode* root , int val){
        if(!root){
            root = new TreeNode(val) ; 
            return root ;
        }
        if(val < root -> val) root -> left = insert(root -> left , val) ;
        if(val > root -> val) root -> right = insert(root -> right , val) ;
        root->height = 1 + max(height(root->left), height(root->right));
        return rotate(root) ;
    }

    TreeNode* rotate(TreeNode* root){
        //left heavy
        if(height(root->left) - height(root->right) > 1){
            //LL
            if(height(root->left->left) - height(root->left->right) > 0) return rightRotate(root) ;
            //LR
            else if(height(root->left->left) - height(root->left->right) < 0){
                root->left = leftRotate(root->left) ;
                return rightRotate(root) ; 
            }
        }

        //right heavy
        if(height(root->right) - height(root->left) > 1){
            //RR
            if(height(root->right->right) - height(root->right->left) > 0) return leftRotate(root);
            //LR
            if(height(root->right->right) - height(root->right->left) < 0){
                root->right = rightRotate(root->right) ;
                return leftRotate(root) ;
            }
        }
        return root ;        
    }
    TreeNode* rightRotate(TreeNode* Node){
        TreeNode* x = Node->left;
        Node->left = x->right ;
        x->right = Node ;
        Node->height = 1 + max(height(Node->left), height(Node->right));
        x->height = 1 + max(height(x->left), height(x->right));
        return x;
    }
    
    TreeNode* leftRotate(TreeNode* Node){
        TreeNode* x = Node->right;
        Node->right = x->left ;
        x->left = Node;
        Node->height = 1 + max(height(Node->left), height(Node->right));
        x->height = 1 + max(height(x->left), height(x->right));
        
        return x;
    }
    int height(TreeNode* root) { return root ? root->height : 0 ; }

    void Inorder(TreeNode* root , int* sortedArray , int &idx){
        if(root){
            Inorder(root->left , sortedArray , idx) ;
            sortedArray[idx++] = root->val ;
            Inorder(root->right , sortedArray , idx) ;
        }
    }

    void insertionSort(int* arr , int n){
        for(int i = 1 ; i < n ; i++){
            int key = arr[i] ;
            int j = i-1 ;
            while(j >=0 && arr[j] > key){
                arr[j+1] = arr[j] ;
                j-- ;
            }
            arr[j+1] = key ;
        }
    }
};

int main() {
    int num = 10;// Start with n = 1
    int n_o = -1; // This will store the first n where AVL is faster than Insertion Sort

    random_device rd;                 // Seed for random number generation
    default_random_engine rng(rd()); // Random engine for shuffling

    while (true) {
        int* arr = new int[num];          // Create array of size n to hold random permutation
        int* insertionArr = new int[num]; // Create array for insertion sort copy
        int* sorted = new int[num];       // Array to store in-order traversal from AVL

        // Fill arr with values 1 to n
        for (int i = 0; i < num; i++) arr[i] = i + 1;

        // Shuffle array to create random permutation
        shuffle(arr, arr + num, rng);

        // Measure time taken to build AVL tree and perform in-order traversal
        AVL tree;
        auto start = high_resolution_clock::now();
        for (int i = 0; i < num; i++)  tree.root = tree.insert(tree.root, arr[i]); // Insert elements into AVL tree
        auto end = high_resolution_clock::now();
        int idx = 0;
        tree.Inorder(tree.root, sorted, idx); // Store sorted values using in-order traversal
        auto avlTime = duration_cast< microseconds>(end - start).count(); 

        copy(arr, arr + num, insertionArr); // Copy original array for fair comparison
        auto startIns =  high_resolution_clock::now();
        tree.insertionSort(insertionArr, num); // Perform insertion sort
        auto endIns =  high_resolution_clock::now();
        auto insertionTime =  duration_cast<microseconds>(endIns - startIns).count(); // Time in microseconds

        // Output time taken for both methods 
        cout << "n = " << num << ", AVL time = " << avlTime << " us, Insertion time = " << insertionTime << " us" << std::endl;

        // If AVL is faster, record n and break
        if (avlTime < insertionTime) {
            n_o = num;
            delete[] arr;
            delete[] insertionArr;
            delete[] sorted;
            break;
        }
        delete[] arr;
        delete[] insertionArr;
        delete[] sorted;

        num++; // Try next n
    }

    cout << "n_o = " << n_o << endl;
}
                                                          