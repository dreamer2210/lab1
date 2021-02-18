#include <iostream>
#include <fstream>
#include <ctime>

#define NAME_FILE "data.txt"

using namespace std;

void menu();

double* get_array(const char* nameFile, size_t& size);
double* add_value(double*& array, size_t& size, double value, size_t pos);
double* del_value(double*& array, size_t& size, size_t pos);
double* del_value(double*& array, size_t& size, double value);
void print(double* array, size_t size);

// Добавить элемент в конец массива
double* task_1(double*& array, size_t& size, double value);
// Добавить элемент в начало массива
double* task_2(double*& array, size_t& size, double value);
// Добавить элемент на k-ую позицию
double* task_3(double*& array, size_t& size, double value, size_t k);
// Удалить последний элемент массива
double* task_4(double*& array, size_t& size);
// Удалить первый элемент массива
double* task_5(double*& array, size_t& size);
// Удалить k-ый элемент массива
double* task_6(double*& array, size_t& size, size_t pos);
// Добавить элемент массива после первого встреченного элемента с заданным значением, 
// если такого значения нет, то выдать предупреждающее сообщение.
double* task_7(double*& array, size_t& size, double valueFind, double valueSet);

int main(int argc, char* argv[])
{
    menu();

    //system("pause");
    return 0;
}

void menu()
{
    srand(time(0));

    short int number = 1;
    size_t size;
    double* array = get_array(NAME_FILE, size);
    double value, value2;
    short int k;

    if(!array)
    {
        cerr << "Array is 0" << endl;
        system("pause");
        return;
    }

    while(number != 0)
    {
        cout << "Enter number task (0 for exit): ";
        cin >> number;

        switch(number)
        {
            case 1:
                cout << "=======================task 1=======================" << endl;
                print(array, size);

                cin >> value;
                print(task_1(array, size, value), size + 1);

                value = double(rand() % 100) / 10;
                print(task_1(array, size, value), size + 1);
                cout << "====================================================" << endl;
                break;
            case 2:
                cout << "=======================task 2=======================" << endl;
                print(array, size);
                
                cin >> value;
                print(task_2(array, size, value), size + 1);

                value = double(rand() % 100) / 10;
                print(task_2(array, size, value), size + 1);
                cout << "====================================================" << endl;
                break;
            case 3:
                cout << "=======================task 3=======================" << endl;
                print(array, size);

                cin >> value;
                cin >> k;
                print(task_3(array, size, value, k), size + 1);

                value = double(rand() % 100) / 10;
                print(task_3(array, size, value, k), size + 1);
                cout << "====================================================" << endl;
                break;
            case 4:
                cout << "=======================task 4=======================" << endl;
                print(array, size);

                print(task_4(array, size), size - 1);
                cout << "====================================================" << endl;
                break;
            case 5:
                cout << "=======================task 5=======================" << endl;
                print(array, size);

                print(task_5(array, size), size - 1);
                cout << "====================================================" << endl;
                break;
            case 6:
                cout << "=======================task 6=======================" << endl;
                print(array, size);

                cin >> k;
                print(task_6(array, size, k), size - 1);
                cout << "====================================================" << endl;
                break;
            case 7:
                cout << "=======================task 7=======================" << endl;
                print(array, size);

                cin >> value >> value2;
                print(task_7(array, size, value, value2), size + 1);
                cout << "====================================================" << endl;
                break;
            case 8:
                // task_8();
                break;
            default:
                cout << "Try again" << endl;
                break;
        }
    }
}

double* get_array(const char* nameFile, size_t& size)
{
    fstream file(nameFile);
    double value;
    size = 0;

    if(!file)
    {
        cerr << "Error. File not found." << endl;
        return 0;
    }

    while(file >> value)
        ++size;
    
    if(size == 0)
    {
        cerr << "Error. File is empty." << endl;
        return 0;
    }

    file.close();
    file.open(nameFile);

    double* result = new double[size];

    for(size_t i = 0; i < size; ++i)
        file >> result[i];

    file.close();

    return result;
}

double* add_value(double*& array, size_t& size, double value, size_t pos)
{
    double* result = new double[++size];

    for(size_t i = 0, j = 0; i < size; ++i)
    {
        if(i == pos)
        {
            result[pos] = value;
        }
        else
        {
            result[i] = array[j];
            ++j;
        }
    }

    delete[] array;
    array = result;

    return array;
}

double* del_value(double*& array, size_t& size, size_t pos)
{
    if(size <= 1)
        return 0;

    double* result = new double[--size];

    for(size_t i = 0, j = 0; i < size; ++j)
    {
        if(j == pos)
            continue;
        else
        {
            result[i] = array[j];
            ++i;
        }
    }

    delete[] array;
    array = result;

    return array;
}

double* del_value(double*& array, size_t& size, double value)
{
    if(size <= 1)
        return 0;

    double* result = new double[--size];

    for(size_t i = 0, j = 0; i < size; ++j)
    {
        if(array[j] == value)
            continue;
        else
        {
            result[i] = array[j];
            ++i;
        }
    }

    delete[] array;
    array = result;

    return array;
}

void print(double* array, size_t size)
{
    for(size_t i = 0; i < size; ++i)
        cout << array[i] << '\t';
    
    cout << endl;
}

double* task_1(double*& array, size_t& size, double value)
{
    return add_value(array, size, value, size);
}

double* task_2(double*& array, size_t& size, double value)
{
    return add_value(array, size, value, 0);
}

double* task_3(double*& array, size_t& size, double value, size_t k)
{
    return add_value(array, size, value, k);
}

double* task_4(double*& array, size_t& size)
{
    return del_value(array, size, (size_t)size - 1);
}

double* task_5(double*& array, size_t& size)
{
    return del_value(array, size, (size_t)0);
}

double* task_6(double*& array, size_t& size, size_t pos)
{
    return del_value(array, size, pos);
}

double* task_7(double*& array, size_t& size, double valueFind, double valueSet)
{
    size_t i;

    for(i = 0; i < size; ++i)
    {
        if(array[i] == valueFind)
            break;
    }

    return add_value(array, size, valueSet, i + 1);
}
