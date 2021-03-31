#include "testHeaders/dequeTest.h"
#include <iostream>


#define printMsg(message) std::cout<<(message);


void dequeTest()
{
    printMsg("----------deque test start-----------\n");
    
    RobustSTL::deque<int> de;
    
    de.push_back(123);//123
    printMsg("de.front() == ");
    std::cout<<de.front()<<std::endl;
    
    de.push_front(233);//233 123
    de.push_front(466);//466 233 123
    printMsg("de.front() == ");
    std::cout<<de.front()<<std::endl;
    printMsg("de.back() ==");
    std::cout<<de.back()<<std::endl;
    
    printMsg("de.isEmpty() == ")
    std::cout<<de.isEmpty()<<std::endl;
    
    printMsg("de.size() == ")//3
    std::cout<<de.size()<<std::endl;
    
    de.clear();
    printMsg("after de.clear(), de.isEmpty() == ");
    std::cout<<de.isEmpty()<<std::endl;
    
    printMsg("----------deque test end----------\n");
}
