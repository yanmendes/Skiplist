//
//  List.hpp
//  Skiplist
//
//  Created by Yan Mendes on 02/04/18.
//  Copyright © 2018 Yan Mendes. All rights reserved.
//

#ifndef List_hpp
#define List_hpp

#include <stdio.h>
#include "LeafNode.hpp"
#include "SkipNode.hpp"

class List {
public:
    List(long long int);
    Node * add(long long int);
    Node * add(long long int, Info*);
    Node * search(long long int);
    Node * remove(long long int);
    void   print();
    void   link(List*);
private:
    Node * head = NULL;
    long long int level;
};

#endif /* List_hpp */
