#include <iostream>
#include "testHeaders/queueTest.h"

#define printMsg(message) std::cout<<(message);

void queueTest()
{
    printMsg("----------queue test start-----------\n");
    
    RobustSTL::queue<int> que;
    
    que.push(123);
    printMsg("after que.push(123), que.front() == ");
    std::cout<<que.front()<<std::endl;
    
    que.pop();
    que.push(233);
    printMsg("after que.pop() and que.push(233),que.front() == ");
    std::cout<<que.front()<<std::endl;
    
    printMsg("que.isEmpty() == ");
    std::cout<<que.isEmpty()<<std::endl;
    
    que.clear();
    printMsg("after que.clear(), que.isEmpty() == ");
    std::cout<<que.isEmpty()<<std::endl;
    
    
    printMsg("----------queue test end-----------\n");
}
