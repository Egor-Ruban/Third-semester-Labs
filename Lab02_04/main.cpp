#include <iostream>
#include "Path.h"
#include <vector>
#include <fstream>

int main() {
    std::vector<int> RoadInt;
    std::ifstream fin(R"(C:\Users\old_g\IdeaProjects\Education\Task2\src\com\tsu\task02\Matrix.txt)");
    int amount_city;
    fin >> amount_city;
    Path Cycle(amount_city), ResCycle(amount_city);
    RoadInt.reserve(amount_city*amount_city);
    int num = 0;

    for(int i = 0;i<amount_city*amount_city;i++){
        fin>>num;
        RoadInt.push_back(num);
    }



        ResCycle.Path_length(RoadInt);
    for( ;Cycle.Next_path(RoadInt);){
        if(Cycle.getlength()<ResCycle.getlength()){
            ResCycle = Cycle;
        }
    }
    std::cout<<ResCycle.getlength()<<std::endl;
    ResCycle.Print_to_console();


    return 0;
}