#include <iostream>
#include "BoolVector.h"
#include "BoolMatrix.h"
#include <stdlib.h>
#include <ctime>

int main() {
    srand(time(nullptr));
    std::string str = "0100";
    BoolVector vec1 = str;
    vec1.Log();
    std::cout<<vec1<<std::endl;
    BoolMatrix b(10,5);
    b.Log();
    std::cout<<b<<std::endl;
    BoolMatrix c(10,10);
    c.topologicalSort();

    return 0;
}