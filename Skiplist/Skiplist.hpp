//
//  Skiplist.hpp
//  Skiplist
//
//  Created by Yan Mendes on 02/04/18.
//  Copyright © 2018 Yan Mendes. All rights reserved.
//

#ifndef Skiplist_hpp
#define Skiplist_hpp

#include "Helper.hpp"
#include "SkipNode.hpp"
#include "LeafNode.hpp"

class SkipList{
public:
    Info * search(long long int);
    void   add(long long int, Info*);
    void   remove(long long int);
    void   print(void);
    void   createLevel(void);
    SkipList();
private:
    long long int levels;
    Node * head;
};

#endif /* Skiplist_hpp */
