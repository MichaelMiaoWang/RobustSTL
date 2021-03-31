#include "testHeaders/vectorTest.h"
#include <iostream>

#define printMsg(message)   std::cout<<(message);

#define printVector(vec) do {                                       \
                            std::cout<<"[ ";                        \
                            for( int i = 0; i < (vec).size(); ++i )   \
                            {                                       \
                                if( i != (vec).size()-1 )             \
                                    std::cout<<(vec)[i]<<", ";      \
                                else                                \
                                    std::cout<<(vec)[i]<<' ';       \
                            }                                       \
                            std::cout<<"]"<<std::endl;              \
                        } while(0)


void vectorTest() {
    
    printMsg( "----------vector test start----------\n" );
    
    RobustSTL::vector<int> vecTest;
    printVector(vecTest);
    vecTest.push_back(1);
    vecTest.push_back(122);
    vecTest.pop_back();
    printVector(vecTest);
    vecTest.push_back(1233);
    vecTest.push_back(466);
    RobustSTL::vector<int> vec2 = vecTest;
    printVector(vec2);
    printVector(vecTest);
    
    
    printMsg("测试带初始化参数的构造函数:");
    RobustSTL::vector<int> dp(12,466);
    printVector(dp);
    
    printMsg("----------vector test end----------\n");
}
