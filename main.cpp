#include <iostream>

using namespace std;

void menu();

int main(int argc, char* argv[])
{
    menu();

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