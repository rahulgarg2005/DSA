#include <iostream>
using namespace std;

class BinaryTreeByArray {
    int tree[15];
    int size;

public:
    BinaryTreeByArray() : size(0) {
        for (int i = 0; i < 15; i++) tree[i] = -1;
    }

    void insert(int val) {
        if (size >= 15) {
            cout << "Tree is Full" << endl;
            return;
        }

        int idx = 0;
        while (idx < 15) {
            if (tree[idx] == -1) {
                tree[idx] = val;
                size++;
                return;
            } else if (val < tree[idx])
                idx = 2 * idx + 1;
            else
                idx = 2 * idx + 2;
        }

        cout << "Tree is Full" << endl;
    }

    bool search(int keyToSearch) {
        int idx = 0;
        while (idx < 15 && tree[idx] != -1) {
            if (tree[idx] == keyToSearch)
                return true;
            else if (keyToSearch < tree[idx])
                idx = 2 * idx + 1;
            else
                idx = 2 * idx + 2;
        }
        return false;
    }

    void deleteNode(int val) {
        deleteNodeHelper(0, val);
    }

private:
    void deleteNodeHelper(int idx, int val) {
        if (idx >= 15 || tree[idx] == -1) {
            cout << "Value not found in the tree" << endl;
            return;
        }

        if (val < tree[idx]) {
            deleteNodeHelper(2 * idx + 1, val);
        } else if (val > tree[idx]) {
            deleteNodeHelper(2 * idx + 2, val);
        } else {
            // Found node to delete
            int leftChild = 2 * idx + 1;
            int rightChild = 2 * idx + 2;

            // Case 1: No child
            if ((leftChild >= 15 || tree[leftChild] == -1) &&
                (rightChild >= 15 || tree[rightChild] == -1)) {
                tree[idx] = -1;
                size--;
            }
            // Case 2: One child
            else if (leftChild < 15 && tree[leftChild] != -1 &&
                     (rightChild >= 15 || tree[rightChild] == -1)) {
                tree[idx] = tree[leftChild];
                deleteNodeHelper(leftChild, tree[leftChild]);
            }
            else if (rightChild < 15 && tree[rightChild] != -1 &&
                     (leftChild >= 15 || tree[leftChild] == -1)) {
                tree[idx] = tree[rightChild];
                deleteNodeHelper(rightChild, tree[rightChild]);
            }
            // Case 3: Two children
            else {
                // Find inorder successor
                int successorIdx = getMinIndex(rightChild);
                if (successorIdx == -1) return; // Error case

                tree[idx] = tree[successorIdx];
                deleteNodeHelper(successorIdx, tree[successorIdx]);
            }
        }
    }

    int getMinIndex(int idx) {
        while (idx < 15 && 2 * idx + 1 < 15 && tree[2 * idx + 1] != -1)
            idx = 2 * idx + 1;
        if (idx < 15 && tree[idx] != -1)
            return idx;
        return -1;
    }

public:
    void print() {
        for (int i = 0; i < 15; i++) cout << tree[i] << ",";
        cout << -1 << endl;
    }
};
