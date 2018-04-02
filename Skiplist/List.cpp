//
//  List.cpp
//  Skiplist
//
//  Created by Yan Mendes on 02/04/18.
//  Copyright © 2018 Yan Mendes. All rights reserved.
//

#include "List.hpp"
#include <iostream>

List::List(long long int level){
    this->level = level;
    
    if(this->level == 0)
        this->head = new LeafNode();
    else
        this->head = new SkipNode();
    
    this->head->setKey(LLONG_MIN);
}

Node * List::search(long long int key){
    return this->head->search(key);
}

Node * List::remove(long long int key){
    Node * left = this->search(key - 1);
    Node * node = left->getNext();
    
    if(node == NULL || node->getKey() != key)
        return NULL;
    
    Node * child;
    
    if(this->level != 0){
        child = ((SkipNode *) node)->getDown();
        ((SkipNode *) node)->setDown(NULL);
    } else
        child = NULL;
    
    left->setNext(node->getNext());
    node->setNext(NULL);
    
    delete node;
    
    return child;
}

Node * List::add(long long int key){
    Node * left = this->search(key - 1);
    Node * newNode;
    
    if(left->getNext() != NULL && left->getNext()->getKey() == key)
        return NULL;
    
    if(this->level == 0)
        newNode = new LeafNode();
    else
        newNode = new SkipNode();
    
    newNode->setKey(key);
    newNode->setNext(left->getNext());
    left->setNext(newNode);
    
    return newNode;
}

Node * List::add(long long int key, Info * info){
    LeafNode * newNode = (LeafNode *) this->add(key);
    newNode->setInfo(info);
    
    return newNode;
}

void List::print(){
    Node * node = this->head->getNext();
    
    while(node != NULL){
        std::cout << node->getKey() << '\t';
        node = node->getNext();
    }
    
    std::cout << std::endl;
}

void List::link(List * oldTop){
    ((SkipNode *) this->head)->setDown(oldTop->head);
}
