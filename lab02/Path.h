//
// Created by old_g on 11.09.2019.
//
#include <vector>
class Path {
private:
    int firstCity;
    int secondCity;
    int length;

public:
    //static  std::vector<Path> Road;


    Path(int first, int second, int len){
        firstCity = first;
        secondCity = second;
        length = len;
    }

    Path(){

    }

    static void print_Path(Path p){
        std::cout<<p.firstCity<<" "<<p.secondCity<<" "<<p.length<<std::endl;
    }

    static int get_path_length(int first, int second, std::vector<Path> Road){
        for(int i = 0; i<Road.size();i++){
            if((Road[i].firstCity==first && Road[i].secondCity==second)){
                return Road[i].length;
            }
        }
        return -1;
    }

    static int check(int arr[],int first, std::vector<Path> Road) {
        int res = 0;
        //System.out.println(first+1000);
        for (int i = 0; i < first - 1; i++) {
            res += Path::get_path_length(arr[i], arr[i + 1], Road);
           // std::cout<<Path::get_path_length(arr[i], arr[i + 1], Road)<<" ";
        }
        res += Path::get_path_length(arr[first-1], arr[0], Road);
        //std::cout<<Path::get_path_length(arr[first-1], arr[0], Road)<<" ";
        return res;
    }
};


