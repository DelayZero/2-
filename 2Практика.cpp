#pragma once
#include <iostream>
#include <sstream>
#include <cstring>
using namespace std;
class exmpl
{
public:
    exmpl(int* arr, size_t len) :
        mas(new int[len]), length(len){
        for (size_t i = 0; i < len; i++){
            mas[i] = arr[i];
        }
    }

    ~exmpl(){
        delete[] mas;
    }

    void setLength(int newLength){
        length = newLength;
        resize();
    }

    unsigned int getLength(){
        return length;
    }

    const char* result(){
        int sum = calcSummOfValue();
        int middle = calcMiddleValue();
        stringstream ss;
        ss << "Сумма: " << sum << endl << "Среднее значение: " << middle;
        resultString = ss.str();
        return resultString.c_str();
    }

protected:
    int calcMiddleValue(){
        int sum = 0;
        for (size_t i = 0; i < length; i++)
        {
            sum += mas[i];
        }
        return sum / length;
    }

    int calcSummOfValue(){
        int sum = 0;
        for (size_t i = 0; i < length; i++)
        {
            sum += mas[i];
        }
        return sum;
    }

private:
    int* mas;
    size_t length;
    string resultString;

    void resize(){
        int* newMas = new int[length];
        memcpy(newMas, mas, sizeof(int) * length);
        delete[] mas;
        mas = newMas;
    }
};

int main(){
    setlocale(LC_ALL, "RUS");
    int arr[] = { 3, 6, 2, 8, 0, 12, 5, 7 };
    exmpl obj(arr, sizeof(arr) / sizeof(arr[0]));
    cout << "Текущая длина: " << obj.getLength() << endl;
    cout << "Результат: " << endl << obj.result() << endl;
    cout << "====================" << endl;
    obj.setLength(3);
    cout << "Новая длина: " << obj.getLength() << endl;
    cout << "Результат: " << endl << obj.result() << endl;

    return 0;
}