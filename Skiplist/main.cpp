//
//  main.cpp
//  Skiplist
//
//  Created by Yan Mendes on 02/04/18.
//  Copyright © 2018 Yan Mendes. All rights reserved.
//

#include "Skiplist.hpp"

bool _DEBUG = true;
std::random_device rd;  //Will be used to obtain a seed for the random number engine
std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
std::uniform_real_distribution<> float_dis(0.0, 1.0);
std::uniform_int_distribution<> int_dis(INT_MIN, INT_MAX);

int main(int argc, const char * argv[]) {
    SkipList * s = new SkipList();
    
    for(long long int i = 0; i < 5; ++i)
        s->add(Helper::intRandom(), NULL);
    
    return 0;
}
