//
//  Skiplist.cpp
//  Skiplist
//
//  Created by Yan Mendes on 02/04/18.
//  Copyright © 2018 Yan Mendes. All rights reserved.
//

#include "Skiplist.hpp"

extern bool _DEBUG;

SkipList::SkipList(){
    this->head = new LeafNode();
    this->head->setKey(LLONG_MIN);
    this->levels = 0;
}

Info * SkipList::search(long long int key){
    Node * node = this->head->search(key);
    long long int levels = this->levels;
    
    if(_DEBUG){
        std::cout << "(" << levels << "," << node->getKey() << ")" << "->";
    
        while(--levels){
            node = ((SkipNode *) node)->getDown()->search(key);
            std::cout << "(" << levels << "," << node->getKey() << ")" << "->";
        }
    } else
        while(--levels)
            node = ((SkipNode *) node)->getDown()->search(key);
    
    node = node->search(key);
    std::cout << "(" << levels << "," << node->getKey() << ")" << std::endl;
    return node->getKey() == key ? ((LeafNode *) node)->getInfo() : NULL;
}

void SkipList::add(long long int key, Info * info){
    long long int level = 0;
    
    while (Helper::floatRandom() <= 0.5)
        ++level;
    
    long long int insertions = level;
    
    while(level > this->levels)
        this->createLevel();
    
    Node * insertionNode = this->head;
    
    while(level < this->levels){
        insertionNode = ((SkipNode *) insertionNode)->getDown();
        ++level;
    }
    
    SkipNode * oldNode = NULL;
    
    while(insertions){
        insertionNode = insertionNode->search(key - 1);
        Node * newNode = ((SkipNode *) insertionNode)->add(key);
        if(oldNode != NULL)
            oldNode->setDown(newNode);
        oldNode = (SkipNode *) newNode;
        insertionNode = ((SkipNode *) insertionNode)->getDown();
        --insertions;
    }
    
    insertionNode = insertionNode->search(key - 1);
    ((LeafNode *) insertionNode)->add(key, info);
    if(oldNode != NULL)
        oldNode->setDown(insertionNode);
}

void SkipList::remove(long long int key){
    long long int levels = this->levels;
    Node * node = this->head;
    
    while(levels){
        node = node->search(key - 1);
        
        if(node->getNext() != NULL && node->getNext()->getKey() == key)
            node->removeNext();
        
        node = ((SkipNode *) node)->getDown();
        
        --levels;
    }
    
    node = node->search(key - 1);
    
    if(node->getNext() != NULL && node->getNext()->getKey() == key)
        node->removeNext();
}

void SkipList::print(){
    Node * provisoryHead = this->head;
    Node * iterator;
    
    for(long long int i = levels; i > 0; --i){
        iterator = provisoryHead->getNext();
        
        while(iterator != NULL){
            std::cout << iterator->getKey() << '\t';
            iterator = iterator->getNext();
        }
        
        std::cout << std::endl;
        provisoryHead = ((SkipNode *) provisoryHead)->getDown();
    }
    
    iterator = provisoryHead->getNext();
    
    while(iterator != NULL){
        std::cout << iterator->getKey() << '\t';
        iterator = iterator->getNext();
    }
    
    std::cout << std::endl;
}

void SkipList::createLevel() {
    SkipNode * newTop = new SkipNode();
    newTop->setKey(LLONG_MIN);
    newTop->setDown(this->head);
    this->head = newTop;
    ++this->levels;
}
