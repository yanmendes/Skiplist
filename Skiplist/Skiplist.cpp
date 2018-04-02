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
    lists.push_back((new List(0)));
}

Info * SkipList::search(long long int key){
    Node * node = lists.back()->search(key);
    long long int levels = lists.size();
    if(_DEBUG){
        std::cout << "(" << levels << "," << node->getKey() << ")" << "->";
    
        while(--levels){
            node = ((SkipNode *) node)->getDown()->search(key);
            if(levels == 1)
                std::cout << "(" << levels << "," << node->getKey() << ")" << std::endl;
            else
                std::cout << "(" << levels << "," << node->getKey() << ")" << "->";
        }
    } else
        while(--levels)
            node = ((SkipNode *) node)->getDown()->search(key);
    
    return node->getKey() == key ? ((LeafNode *) node)->getInfo() : NULL;
}

void SkipList::add(long long int key, Info * info){
    long long int level = 0;
    Node * newNode = lists.at(level++)->add(key, info);
    Node * oldNode = newNode;
    while (Helper::floatRandom() <= 0.5) {
        if(level == lists.size())
            this->createNewList(level);
        newNode = lists.at(level++)->add(key, info);
        ((SkipNode *) newNode)->setDown(oldNode);
        oldNode = newNode;
    }
}

void SkipList::remove(long long int key){
    Node * node = lists.back()->search(key);
    long long int level = lists.size() - 1;
    
    while(node->getKey() != key && level > 0) {
        node = ((SkipNode *) node)->getDown()->search(key);
        --level;
    }
    
    for(; level >= 0; --level)
        lists.at(level)->remove(key);
}

void SkipList::print(){
    for (std::vector<List*>::reverse_iterator i = lists.rbegin(); i != lists.rend(); ++i){
        (*i)->print();
    }
}

void SkipList::createNewList(long long int level) {
    List * oldTop = lists.back();
    this->lists.push_back((new List(level)));
    List * newTop = lists.back();
    
    newTop->link(oldTop);
}
