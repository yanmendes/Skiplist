//
//  Node.cpp
//  Skiplist
//
//  Created by Yan Mendes on 02/04/18.
//  Copyright © 2018 Yan Mendes. All rights reserved.
//

#include <stdio.h>
#include "Node.hpp"

Node * Node::search(long long int key){
    Node * node = this;
    
    while(node->next != NULL && node->next->key <= key)
        node = node->next;
    
    return node;
}

Node * Node::removeNext(){
    Node * temp = this->next;
    
    this->next = next->next;
    
    delete temp;
    
    return this;
}
