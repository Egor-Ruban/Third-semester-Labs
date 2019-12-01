//
// Created by Egor_Ruban on 16.09.2019.
//
#include <iostream>
#include <vector>
class Path {
    int* path;
    int amount_city;
    int length;


public:
    Path(int n){
        amount_city = n;
        path = new int[n];
        for(int i = 1; i<=n;i++){
            path[i-1]=i;
        }
    }

    Path(Path &P){
        path = new int[P.amount_city];
        amount_city = P.amount_city;
        for(int i = 1; i<=P.amount_city;i++){
            path[i-1]=P.path[i-1];
        }
        length = P.length;
    }

    Path& operator= (Path &P){
        path = new int[P.amount_city];
        amount_city = P.amount_city;
        for(int i = 1; i<=P.amount_city;i++){
            path[i-1]=P.path[i-1];
        }
        length = P.length;
        return *this;
    }

    ~Path() { if(path != NULL) delete [] path; path = NULL; }

    int CostOf(std::vector<int> Roads, int firstCity, int secondCity){
        return(Roads[this->amount_city*(firstCity-1)+(secondCity-1)]);
    }

    int Path_length(std::vector<int> Roads){
        int res = 0;


        for (int i = 0; i < amount_city-1; i++) {
            res += CostOf(Roads, path[i], path[i + 1]);
        }
        res += CostOf(Roads, path[amount_city-1], path[0]);
        length = res;
        return res;
    }


    void Print_to_console(){
        for(int i = 0; i<amount_city;i++){
            std::cout<<path[i];
        }
        std::cout<<"\n";
    }
    int getlength(){
        return length;
    }

    bool Next_path(std::vector<int> Roads) {
        int j = 3, i = 2;
        int itemp = 2, jtemp = 3;
        for (;;) {
            int check = 0;
            //первая часть дейкстры. выбор ишки
            while (i < amount_city) {
                if (path[i + 1 - 1] > path[i - 1]) {
                    itemp = i;
                    check++;
                }
                i++;
            }
            if (check == 0) return false;
            i = itemp;
            //вторая часть дейкстры. выбор жишки
            j = i + 1;
            while (j <= amount_city) {
                if (path[i - 1] < path[j - 1]) {
                    jtemp = j;
                }
                j++;
            }
            j = jtemp;
            //третья часть дейкстры. перестановка двух чисел
            int t = path[i - 1];
            path[i - 1] = path[j - 1];
            path[j - 1] = t;
            //четвертая часть дейкстры. упорядочивание перестановки после i-го элемента
             for(int k = i+1, q = amount_city; k<q;k++, q--){
                 int t = path[k-1];
                 path[k-1] = path[q-1];
                 path[q-1] = t;
             }
            Path_length(Roads);
            for(int i = 1; i<=amount_city;i++){
                std::cout<<path[i-1];
            }
            std::cout<<" "<<Path_length(Roads)<<std::endl;
            return true;
        }
    }


};
