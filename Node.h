//
// Created by Collin Stratton on 9/26/20.
//

#ifndef SINGLYLINKEDLIST_NODE_H
#define SINGLYLINKEDLIST_NODE_H

template<class T>
struct Node {
    T data;
    struct Node* left;
    struct Node* right;
};


#endif //SINGLYLINKEDLIST_NODE_H
