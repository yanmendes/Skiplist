//
//  Skiplist.hpp
//  Skiplist
//
//  Created by Yan Mendes on 02/04/18.
//  Copyright © 2018 Yan Mendes. All rights reserved.
//

#ifndef Skiplist_hpp
#define Skiplist_hpp

#include "List.hpp"
#include "Helper.hpp"

class SkipList{
public:
    Info * search(long long int);
    void   add(long long int, Info*);
    void   remove(long long int);
    void   print();
    void   createNewList(long long int);
    SkipList();
private:
    std::vector<List*> lists;
};

#endif /* Skiplist_hpp */
