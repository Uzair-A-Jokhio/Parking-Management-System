#include<iostream>
#include<fstream>       // file input and ouptput
#include<conio.h>       // For _getch() function
#include<string.h>
#include<process.h>    // For system("CLS") and system("PAUSE")

    // function header file user made 
#include "function.h"  

using namespace std;


int main()
{
    login();
    int choice;
    while (true)            
    {
        system("CLS");
        car_md();
        setColor(33);
        setColor(1);
        cout << "\n\t\t=====================================================";
        cout << "\n\t\t|            CAR PARKING RESERVATION SYSTEM         |";
        cout << "\n\t\t=====================================================";
        resetColor();
        cout << "\n";
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
        cout << "\n\n\t\t\t  8. Display slots";
        cout << "\n\n\t\t\t  9. Exit Program";
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
            int n = 0;
            int c = 1;
            cout << "\n\n\t\t== NO of Customers:  ";
            cin >> n;
            while (c <= n )
            {   // Open the "parking3.dat" file in binary mode for writing and appending data
                ofstream file("parking3.dat", ios::binary | ios::out | ios::app);
                Car car;
                input_detail(car); // call the function to collect data from users
                file.write((char*)&car, sizeof(car)); // Write the car details to the file
                c++;
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
            Car car{};
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
            Car car{};
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
        case 4:
        {
            display_all();
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
        case 7:
        {
            delete_record(); 
            break;
        }
        case 8: {
            parking_slots();
            break;
        }
        case 9:{
            system("CLS");
            setColor(32); // 32 is the ANSI escape code for green
            setColor(1);
            cout << "\n\n\n\n\n\t\t\tGoodbye! Thank you for using our system.\n\n";
            resetColor(); // Reset text color

            setColor(33);
            setColor(1);
            cout << "\t\t===== Developed by Uzair Jokhio && Safdar Sheikh ===== \n\n\n ";
            cout << "\t\t Dawood University, Dept Computer System Engineering (2nd Semester) 2022-Fall\n\n\n\n\n\n\n\n\n ";
            resetColor();
            return 0;
        }
        case 898: {
            DoomsDay();
            break;
        }
        default:
        {
            setColor(31); // Set color to red
            cout << "\n\n\t\tInvalid input. Please select a valid option.\n";
            resetColor(); // Reset text color
            cout << "\n";
            system("PAUSE");
            break;
        }
        }
        int g = _getch(); // Wait for a key press before clearing the console screen
        g;
    }

    return 0;  // Return 0 to indicate successful execution of the main function
}
