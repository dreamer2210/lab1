#include <iostream>
#include <fstream>
#include <vector>

#define NAME_FILE "data.txt"

using namespace std;

void menu();

double* get_array(const char* nameFile, size_t& size);

double* add_value(double*& array, size_t& size, double value, size_t pos);

void print(double* array, size_t size);

int main(int argc, char* argv[])
{


    system("pause");
    return 0;
}

void menu()
{
    short int number = 1;

    while(number != 0)
    {
        cout << "Enter number task (0 for exit): ";
        cin >> number;

        switch(number)
        {
            case 1:
                // task_1();
                break;
            case 2:
                // task_2();
                break;
            case 3:
                // task_3();
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

double* add_value(double*& array, size_t& size, double value,size_t pos)
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

void print(double* array, size_t size)
{
    for(size_t i = 0; i < size; ++i)
        cout << array[i] << '\t';
    
    cout << endl;
}
