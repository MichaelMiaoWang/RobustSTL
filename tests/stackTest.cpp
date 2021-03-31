#include "testHeaders/stackTest.h"
#include <iostream>


#define printMsg(message) std::cout<<(message);


void stackTest()
{
    printMsg("----------stack test start-----------\n");
    RobustSTL::stack<int> stk;
    stk.push(123);
    printMsg("stk.top() == ");
    std::cout<<stk.top()<<std::endl;
    stk.push(233);
    printMsg("stk.top() == ");
    std::cout<<stk.top()<<std::endl;
    printMsg("stk.isEmpty() == ")
    std::cout<<stk.isEmpty()<<std::endl;
    stk.clear();
    printMsg("after stk.clear(), stk.isEmpty() == ");
    std::cout<<stk.isEmpty()<<std::endl;
}
