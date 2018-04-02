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
    
    Info * getInfo(void) {return this->info;};
    void   setInfo(Info * info) {this->info = info;};
private:
    Info * info;
};

#endif /* LeafNode_hpp */
