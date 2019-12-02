//
// Created by old_g on 26.09.2019.
//

using namespace std;

class MyString {
    char *str;
    int len;

public:
    //получение длины строки
    int getLen() {
        return len;
    }

    //деструктор
    ~MyString() {
        if(str!=NULL) {
            delete[]str;
            str=NULL;
        }
    }

    //вывод строки в консоль
    void print() {
        printf("%s\n", this->str);
    }

    //перегрузка >> (ввод строки через >>)
    friend istream& operator>>(istream &r, MyString &s);

    //перегрузка << (вывод строки через <<)
    friend ostream& operator<<(ostream &out, const MyString &myString);


    //конструктор. выделяет память требуемого размера
    explicit MyString(int l = 0) {
        str = new char[l+1];
        len = 0;
        str[0] = '\0';
    }

    //конструктор. создает строку по заданному массиву символов
     explicit MyString(const char *s) {
        str = new char[strlen(s) + 1];
        for (len = 0; s[len] != '\0'; str[len] = s[len], len++);
        str[len] = '\0';
    }

    //конструктор. копирует другой объект MyString
    MyString(MyString &s) {
        str = new char[s.len + 1];
        for (len = 0; s[len] != '\0'; str[len] = s.str[len], len++);
        str[len] = '\0';
    }

    //обращение к i-ому символу строки
    char &operator[](int i) {
        if (i < 0 || i >= len) {
            cout << "\n Индекс за пределами строки";
            return str[0];
        }
        return str[i];
    }

    //перегрузка оператора = (присваивание одному объекту значение другого)
    MyString &operator=(const MyString &s2) {
        if (this != &s2) {
            delete[] str;
            str = new char[(len = s2.len) + 1];
            strcpy(str, s2.str);
        }
        return *this;
    }

    //перегрузка оператор + (конкатенация)
    MyString operator+(MyString &s2) {
        MyString z(len + s2.len + 1);
        strcpy(z.str, str);
        strcat(z.str, s2.str);
        z.len = strlen(z.str);
        return z;
    }

    //перегрузка оператора += (опять конкатенация)
    MyString &operator+=(MyString &s2) {
        char *t = new char[len + 1];
        strcpy(t, str);
        delete[]str;
        len += s2.len;
        str = new char[len + 1];
        strcpy(str, t);
        strcat(str, s2.str);
        delete[]t;
        return *this;
    }


    void BM(MyString &s2) {

        int *temp = new int[256];
        int i;
        for (i = 0; i < 256; i++)
            temp[i] = s2.len;

        for (i = 0; i < s2.len - 1; i++)
            temp[s2.str[i]] = s2.len - i - 1;


        int result;
        for (i = s2.len; i <= len; i += temp[str[i - 1]]) {
            int j, k;
            for (j = s2.len - 1, k = i - 1; j >= 0 && str[k] == s2.str[j]; k--, j--);
            if (j < 0) {
                result = i - s2.len;
                cout << result << endl;
                break;
            }
        }

        if (i > len) {
            result = -1;
            cout << result << endl;
        } else if (i == len){
            result = 0;
            cout<<result<<endl;
        }


        delete temp;
    }

    int KMP2(MyString &s2){
        int *t = new int[s2.len];
        int k = t[0] = -1;
        int j = 0;
        while(j<s2.len-1){
            while(k>=0 && s2.str[j]!=s2.str[k]){
                k = t[k];
            }
            k++;
            j++;
            if(s2.str[j]==s2.str[k]){
                t[j]=t[k];
            } else {
                t[j] = k;
            }
        }

        while(j<s2.len-1){

        }
        for(int k = 0; k<s2.len;k++){
           // cout<<t[k];
        }
        //cout<<endl;
        int i;
        for (i = 0, j = 0; i < len && j < s2.len; i++, j++)
            while (j >= 0 && str[i] != s2.str[j]) {
                j = t[j];
                cout << j <<",";
            }

        delete t;

        if (j == s2.len) {
            //cout << i - s2.len << endl;
            return i-s2.len;
        } else {
            //cout << -1 << endl;
            return -1;
        }

    }

     void delStr (MyString &s, int i){

        if (this != &s) {
            int l = len-s.len;
            //cout<<l;

            MyString t(l);
            t.len = l;
            //cout<<"tlen"<<t.len;
            int k;
            for(k = 0; k<i; k++){
                t.str[k]=str[k];
                //cout<<t.str[k];
            }
            int j = k+s.len;
            for(; j<len; j++,k++){
                t.str[k]=str[j];
                //cout<<t.str[k];
            }
            delete[] str;
            len = l;
            str = new char[len+1];
            str[len] = '\0';
            for(int l = 0; l<len;l++){
                str[l]=t.str[l];
            }

        }
    }
};

 ostream& operator<<(ostream &out, const MyString &s){
    out << s.str;
    return out;
}

istream& operator>>(istream &r, MyString &s) {
    char buf[80];
    cin >> buf;
    MyString q(buf);
    s = q;
    return r;
}

