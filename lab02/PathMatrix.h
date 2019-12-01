//
// Created by old_g on 12.09.2019.
//


class PathMatrix {
public:
    static int get_path_length(int first, int second, std::vector<int> Road){
       return(Road[sqrt(Road.size())*(first-1)+(second-1)]);
    }

    static int check(int arr[],int first, std::vector<int> Road) {
        int res = 0;
        for (int i = 0; i < first - 1; i++) {
            res += get_path_length(arr[i], arr[i + 1], Road);
        }
        res += get_path_length(arr[first-1], arr[0], Road);
        return res;
    }

};

