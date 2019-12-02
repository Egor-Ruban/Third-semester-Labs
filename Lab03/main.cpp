#include <iostream>
#include "MyString.h"
#include <clocale>

using namespace std;
int main() {
    setlocale(LC_ALL,"Russian");
    MyString str3, str("К8Б27СК3К8БКГ4");
    MyString str2("ПНЛ9ВАК8БЕНК8Б27СК3К8БКГ4ПАН1");
    str2.KMP2(str);

    //cin>>str;
    //str.print();
    //cout<<str;
    return 0;
}