//
//  LeafNode.hpp
//  Skiplist
//
//  Created by Yan Mendes on 02/04/18.
//  Copyright © 2018 Yan Mendes. All rights reserved.
//

#ifndef LeafNode_hpp
#define LeafNode_hpp

#include "Node.hpp"
#include "Info.hpp"

class LeafNode: public Node {
public:
    LeafNode() : Node() {info = NULL;};
    
    Info *     getInfo(void) {return this->info;};
    LeafNode * setInfo(Info * info) {this->info = info; return this;};
    Node *     add(long long int key){
        Node * newNode = new LeafNode();
        newNode->setKey(key);
        newNode->setNext(this->getNext());
        this->setNext(newNode);
        
        return newNode;
    }
    Node * add(long long int key, Info * info) {return ((LeafNode *)this->add(key))->setInfo(info);};
private:
    Info * info;
};



#endif /* LeafNode_hpp */
