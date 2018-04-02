//
//  Node.hpp
//  Skiplist
//
//  Created by Yan Mendes on 02/04/18.
//  Copyright © 2018 Yan Mendes. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>

class Node {
public:
    
    long long int   getKey(void) {return this->key;};
    void            setKey(long long int key) {this->key = key;};
    
    Node *          getNext(void) {return this->next;};
    void            setNext(Node * next) {this->next = next;};
    
    virtual         ~Node() {delete this->next;};
                     Node() {this->next = NULL;};
    
    Node * search(long long int);
protected:
    int type;
    long long int key;
    Node * next;
};

#endif /* Node_hpp */
