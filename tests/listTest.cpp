#include <iostream>
#include "testHeaders/listTest.h"

#define printMsg(message) std::cout<<(message);

#define printList(lis)  do {                                   \
                                std::cout<< "[ " ;                             \
                                auto lastItr = (lis).end();     --lastItr;     \
                                for( auto itr = (lis).begin(); itr != (lis).end(); ++itr ) \
                                {                                    \
                                    if(itr != lastItr)             \
                                        std::cout<<*(itr)<<", ";      \
                                    else                                \
                                        std::cout<<*(itr)<<' ';       \
                                }                                    \
                                std::cout << "]" << std::endl;              \
                            } while(0)




void listTest()
{
    printMsg("\n----------list test start----------\n");
    RobustSTL::list<int> liss;
    liss.push_back(233);
    liss.push_back(123);
    liss.push_back(233);
    liss.push_back(4663);
    liss.push_back(1123);
    printList(liss);
    printMsg("----------list test end----------\n");
}
