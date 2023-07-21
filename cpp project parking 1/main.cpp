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
        setColor(33);
        cout << "\n\t\t=====================================================";
        cout << "\n\t\t|            CAR PARKING RESERVATION SYSTEM         |";
        cout << "\n\t\t=====================================================";
        resetColor();
        cout << "\n\n";
        setColor(36); // set color to cyan
        cout << " \t\t  ==========================================";
        resetColor();
        cout << "\n\n\t\t\t  1. Arrival of a Car";
        cout << "\n\n\t\t\t  2. Total number of cars arrived";
        cout << "\n\n\t\t\t  3. Total parking charges ";
        cout << "\n\n\t\t\t  4. Display all Car";
        cout << "\n\n\t\t\t  5. Search by Car Number";
        cout << "\n\n\t\t\t  6. Update Car Details";
        cout << "\n\n\t\t\t  7. Departure of a Car";
        cout << "\n\n\t\t\t  0. Exit Program";
        setColor(36); // set color to cyan
        cout << "\n\n\t\t  ==========================================";
        resetColor();
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
            {   // Open the "parking3.dat" file in binary mode for writing and appending data
                ofstream file1("parking3.dat", ios::binary | ios::out | ios::app);
                Car car;
                input_detail(car); // call the function to collect data from users
                file1.write((char*)&car, sizeof(car)); // Write the car details to the file
            }
            break;
        }
        case 2:
        {
            system("CLS");
            cout << "\n\n\t\t=== View the Records in the Parking Database ===";
            cout << "\n";
            // Open the "parking3.dat" file in binary mode for reading
            ifstream infile("parking3.dat", ios::binary | ios::in);
            int d = 1;
            Car car;
            // Loop through the file to read and display all car records
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
            delete_record(); // call the function from function.h
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
            setColor(32); // Set color to green
            cout << "\n\n\t\tGoodbye! Thank you for using our system.\n";
            resetColor(); // Reset text color
            return 0;
        }
        default:
        {
            setColor(31); // Set color to red
            cout << "\n\n\t\tInvalid input. Please select a valid option.\n";
            resetColor(); // Reset text color
            break;
        }
        }
        _getch(); // Wait for a key press before clearing the console screen
    }
    return 0;  // Return 0 to indicate successful execution of the main function
}
