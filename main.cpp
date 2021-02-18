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
    double value;
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
                print(task_1(array, size, value), size);

                value = double(rand() % 100) / 10;
                print(task_1(array, size, value), size);
                cout << "====================================================" << endl;
                break;
            case 2:
                cout << "=======================task 2=======================" << endl;
                print(array, size);
                
                cin >> value;
                print(task_2(array, size, value), size);

                value = double(rand() % 100) / 10;
                print(task_2(array, size, value), size);
                cout << "====================================================" << endl;
                break;
            case 3:
                cout << "=======================task 3=======================" << endl;
                print(array, size);

                cin >> value;
                cin >> k;
                print(task_3(array, size, value, k), size);

                value = double(rand() % 100) / 10;
                print(task_3(array, size, value, k), size);
                cout << "====================================================" << endl;
                break;
            case 4:
                // task_4();
                break;
            case 5:
                // task_5();
                break;
            case 6:
                // task_6();
                break;
            case 7:
                // task_7();
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

    for(size_t i = 0, j = 0; j < size + 1; ++j)
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

    for(size_t i = 0, j = 0; j < size + 1; ++j)
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
