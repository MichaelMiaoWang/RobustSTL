#include "testHeaders/vectorTest.h"
#include "testHeaders/listTest.h"
#include "testHeaders/stackTest.h"
#include "testHeaders/queueTest.h"
#include "testHeaders/dequeTest.h"
#include <iostream>


#define printMsg(message) std::cout<<(message);

int main() {
    printMsg("----------test start----------\n");
    vectorTest();
    listTest();
    stackTest();
    queueTest();
    dequeTest();
    printMsg("----------test finished----------\n");
    return 0;
}
