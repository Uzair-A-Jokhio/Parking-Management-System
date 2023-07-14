#include<iostream>
#include<fstream>       // file input and ouptput
#include<conio.h>       // For _getch() function
#include<string.h>
#include<process.h>    // For system("CLS") and system("PAUSE")
#include "function.h"  // function header file user made 

using namespace std;



int main()
{
    login();
    int choice;
    while (1)
    {
        system("CLS");
        car_md();
        cout << "\n\n\t\t  ====== CAR PARKING RESERVATION SYSTEM ======";
        cout << "\n\n";
        cout << " \t\t  ==========================================";
        cout << "\n\n\t\t\t  1. Arrival of a Car";
        cout << "\n\n\t\t\t  2. Total number of cars arrived";
        cout << "\n\n\t\t\t  3. Total parking charges ";
        cout << "\n\n\t\t\t  4. Display all Car";
        cout << "\n\n\t\t\t  5. Search by Car Number";
        cout << "\n\n\t\t\t  6. Update Car Details";
        cout << "\n\n\t\t\t  7. Departure of a Car";
        cout << "\n\n\t\t\t  0. Exit Program";
        cout << "\n\n\t\t  ==========================================";
        cout << "\n\n";
        cout << "\t\t\t  Select Your Choice :: ";

        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            char f;
            cout << "\n\n\t\t== Do you want to continue? (y/n): ";
            cin >> f;
            if (f == 'y' || f == 'Y')
            {
                ofstream f1("parking3.dat", ios::binary | ios::out | ios::app);
                Car car;
                input_detail(car);
                f1.write((char*)&car, sizeof(car));
            }
            break;
        }
        case 2:
        {
            system("CLS");
            cout << "\n\n\t\t=== View the Records in the Parking Database ===";
            cout << "\n";
            ifstream infile("parking3.dat", ios::binary | ios::in);
            int d = 1;
            Car car;
            while (infile.read((char*)&car, sizeof(car)))
            {
                system("CLS");
                cout << "\n";
                cout << "\n\n\tThe Car position in the parking lot: " << d;
                d++;
                car_detail(car);
                cout << "\n";
                cout << "\n\n\n";
                system("PAUSE");
                cout << endl;
            }
            infile.close();
            break;
        }
        case 3:
        {
            ifstream infile("parking3.dat", ios::binary | ios::in);
            Car car;
            while (infile.read((char*)&car, sizeof(car)))
            {
                cout << "\n";
                calculate_price(car);
                car_detail(car);
                cout << "\n";
                cout << endl;
            }
            infile.close();
            break;
        }
        case 7:
        {   
            delete_record();
            break;
        }
        case 5:
        {   
            search_car();
            break;
        }
        case 6:
        {
            update_car();
            break;
        }
        case 4:
        {
            display_all();
            break;
        }
        case 0:
        {
            system("CLS");
            exit(0);
            break;
        }
        default:
        {
            cout << "\n\n\t\tInvalid input";
            cout << "\n\n\t\tPress Enter to continue";
        }
        }
        _getch();
    }

    return 0;
}
