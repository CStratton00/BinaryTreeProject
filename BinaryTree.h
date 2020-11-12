//
// Created by Collin Stratton on 11/4/20.
//

#ifndef BINARYSEARCHTREE_BINARYTREE_H
#define BINARYSEARCHTREE_BINARYTREE_H

#include "Node.h"

using namespace std;

template<class T>
class BinaryTree {
private:
    Node<T>* head;
    int count = 0;
public:
    BinaryTree() : head(nullptr) {}

    /*
     * functions to set and return the head
     * head is used to keep track of the root of the tree
     */
    struct Node<T>* header() { return head; }
    void setheader(struct Node<T>* node) { head = node; }

    /*
     * insert function to add new values to the tree
     * if the tree has no root then a root is created
     * data is added to the leaves of the tree, or where its null
     */
    struct Node<T>* insert(struct Node<T>* node, T data) {
        if (node == nullptr) {
            struct Node<T>* node = new Node<T>;
            node->data = data;
            node->left = nullptr;
            node->right = nullptr;
            return node;
        } else {
            if (data < node->data)
                node->left = insert(node->left, data);
            else
                node->right = insert(node->right, data);
            return node;
        }
    }

    /*
     * delete function to remove a node from the tree
     * function searches recursively through the tree to find the value
     * dereferences the node to delete then deletes it
     */
    struct Node<T>* deleteNode(struct Node<T>* root, T key) {
        if(root == nullptr){ return root; }
        if(key < root->data)
            root->left = deleteNode(root->left, key);
        else if(key > root -> data)
            root->right = deleteNode(root->right, key);
        else {
            if(root->left == nullptr) {
                struct Node<T>* temp = root->right;
                delete(root);
                return temp;
            } else if(root->right == nullptr) {
                struct Node<T>* temp = root->left;
                delete(root);
                return temp;
            }

            struct Node<T>* temp = minVal(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, key);
        }
        return root;
    }

    /*
     * finds the smallest value on the tree branch
     */
    Node<T>* minVal(struct Node<T>* node) {
        struct Node<T>* current = node;
        while(current && current->left != nullptr){
            current = current->left;
        }
        return current;
    }

    /*
     * search function to find a target in the tree
     * Returns true if the target is found
     */
    bool search(Node<T>* node, T target) {
        if(node == nullptr) {
            cout << "Inspected " << count << " elements" << endl;
            cout << target << " is not in the tree" << endl;
            count = 0;
            return false;
        }
        else {
            if(target == node->data) {
                cout << "Inspected " << count << " elements" << endl;
                cout << target << " was located in the tree" << endl;
                count = 0;
                return true;
            }
            else {
                if (target < node->data) {
                    count++;
                    return(search(node->left, target));
                } else {
                    count++;
                    return(search(node-> right, target));
                }
            }
        }
    }


    /*
     * returns the height of the tree
     */
    int getHeight(struct Node<T>* node) {
        if(node == nullptr) { return -1; }
        else { return max(getHeight(node->left), getHeight(node->right)) + 1; }
    }

    void display(Node<T>* temp) {
        if (temp == nullptr) { return; }
        else {
            display(temp->left);
            cout <<  temp->data << " ";
            display(temp->right);
        }
    }
};


#endif //BINARYSEARCHTREE_BINARYTREE_H
