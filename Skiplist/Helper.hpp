//
//  Helper.hpp
//  Skiplist
//
//  Created by Yan Mendes on 02/04/18.
//  Copyright © 2018 Yan Mendes. All rights reserved.
//

#ifndef Helper_hpp
#define Helper_hpp

#include <stdio.h>
#include <time.h>
#include <random>
#include <iostream>
#include <vector>

extern std::mt19937 gen;
extern std::uniform_real_distribution<> float_dis;
extern std::uniform_int_distribution<> int_dis;

class Helper{
public:
    static double floatRandom() {return float_dis(gen);}
    static double intRandom() {return int_dis(gen);}
private:
    Helper() {};
};

#endif /* Helper_hpp */
