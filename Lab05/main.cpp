#include <iostream>
#include "BoolVector.h"
#include "BoolMatrix.h"
#include <stdlib.h>
#include <ctime>

int main() {
    srand(time(nullptr));

   int **pairs = new int*[5];
   for(int i = 0;i<5;i++){
      pairs[i] = new int[2];
      std::cin>>pairs[i][0]>>pairs[i][1];
       }


    BoolMatrix BM(5,5,true);
    BM.parsePairs(pairs, 5, 5).Log();

    BM.topologicalSort();




    return 0;
}