//
//  SkipNode.hpp
//  Skiplist
//
//  Created by Yan Mendes on 02/04/18.
//  Copyright © 2018 Yan Mendes. All rights reserved.
//

#ifndef SkipNode_hpp
#define SkipNode_hpp

#include "Node.hpp"

class SkipNode: public Node {
public:
    SkipNode() : Node()  {this->down = NULL;};
    ~SkipNode() {delete this->down;};
    
    Node *  getDown(void) {return this->down;};
    void    setDown(Node * down) {this->down = down;};
private:
    Node * down;
};

#endif /* SkipNode_hpp */
