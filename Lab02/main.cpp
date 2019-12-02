#include <iostream>
#include <fstream>
#include <vector>
#include "PathMatrix.h"
int main() {
    setlocale(LC_ALL,"rus");
    std::vector<int> RoadInt;
    std::ifstream fin(R"(C:\Users\old_g\IdeaProjects\Education\Task2\src\com\tsu\task02\Matrix.txt)");
    int amount_city;
    fin >> amount_city;
    RoadInt.reserve(amount_city*amount_city);
    int num = 0;

//ввод с файла в недрах ноута
    for(int i = 0;i<amount_city*amount_city;i++){
        fin>>num;
        RoadInt.push_back(num);
    }
    //объявляем место для результата
    int *arr = new int[amount_city];
    int *ResArray = new int[amount_city];
    for(int i = 1; i<=amount_city;i++){
        arr[i-1]=i;
        ResArray[i-1]=i;

    }

    int ResLength = PathMatrix::check(arr,amount_city,RoadInt);
    std::cout<<ResLength<<std::endl;
    //тут начинается Дейкстр
    int j=3, i=2;
    int itemp = 2, jtemp = 3;
    for(;;){
        int check = 0;
        //первая часть дейкстры. выбор ишки
        while(i<amount_city) {
            if (arr[i + 1-1] > arr[i-1]) {
                itemp = i;
                check++;
            }
            i++;
        }
        if(check==0) break;
        i=itemp;
        //вторая часть дейкстры. выбор жишки
        j=i+1;
        while(j<=amount_city){
            if(arr[i-1]<arr[j-1]){
                jtemp = j;
            }
            j++;
        }
        j=jtemp;
        //третья часть дейкстры. перестановка двух чисел
        int t = arr[i-1];
        arr[i-1] = arr[j-1];
        arr[j-1]=t;
        //четвертая часть дейкстры. упорядочивание перестановки после i-го элемента
        int  k = i+1, ktemp;
        for(;k<=amount_city;k++){
            ktemp = k;
            while(ktemp<=amount_city){
                if(arr[ktemp-1]<arr[k-1]){
                    int te = arr[k-1];
                    arr[k-1] = arr[ktemp-1];
                    arr[ktemp-1]=te;
                }
                ktemp++;
            }
        }
        //вроде как перестановка готова
        if(PathMatrix::check(arr,amount_city,RoadInt)<ResLength){
            ResLength = PathMatrix::check(arr,amount_city,RoadInt);
            for(int q = 0; q<amount_city;q++){
                ResArray[q]=arr[q];
            }
        }

        for(int q = 0; q<amount_city;q++){
            std::cout<<arr[q]-1;
        }
        std::cout<<" "<<PathMatrix::check(arr,amount_city,RoadInt)<<std::endl;
        j=3; i=2;
        itemp = 2; jtemp = 3;
    }

    for(int q = 0;q<amount_city;q++){
        std::cout<<ResArray[q];
    }

    std::cout<<std::endl<<" with length: "<<ResLength<<"\n";

    return 0;
}