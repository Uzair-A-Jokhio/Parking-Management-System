#include<iostream>
#include<fstream>         // file input and ouptput 
#include<conio.h>         // For _getch() function
#include<string.h>
#include<process.h>       // For system("CLS") and system("PAUSE")
#include<iomanip> 
#include"design.h"        // design header file user made 


using namespace std;


//---------------structure for information of car driver car no and other--------
struct Car {
    int car_numbers;         // Car number
    float time_hours;        // Number of hours of stay
    char driver_name[15];    // Driver name
    char vip_st;             // V.I.P status
    char time_slot[50];      // Time slot of parking
};



//-----------------------void function for the collecting data--------------------
void input_detail(Car& car)
{
    system("CLS"); // Clear the console screen

    doubledash();  // user defined function from design.h
    cout << "\n\t\t\t\tCar Parking Reservation";
    doubledash();

    int d = 0;
    cout << "\n\n\t\tEnter the name of driver: ";
    cin >> car.driver_name;
    cout << "\n\n\t\tEnter the car number: ";
    cin >> car.car_numbers;
    cout << "\n\n\t\tEnter the number of hours of stay: ";
    cin >> car.time_hours;
    cout << "\n\n\t\tEnter the time slot: ";
    cin >> car.time_slot;

    if (d < 20 && car.time_hours < 8)
    {
        cout << "\n\n\t\tParking Available! You can park your car.";
        cout << "\n\n\t\tCar successfully parked!";

    }
    else
    {
        cout << "\n\n\t\tParking not possible!!";
    }
    doubledash();
}



//-------------------------calculating the price of the stay-----------------------
void calculate_price(const Car& car)
{
    char x;
    cout << "\n\t\n\tAre you a V.I.P: y/n ";
    cin >> x;
    system("CLS");

    doubledash();                                                 // user defined function from design.h
    cout << "\n\t\t\t Expense Calculation";
    doubledash();

    if (x == 'y') {
        cout << "\n\n\t\tThe total expense during parking: ";
        cout << car.time_hours * 35 << " rupees";
    }
    else {
        cout << "\n\n\t\tThe total expense during parking: ";
        cout << car.time_hours * 15 << " rupees";
    }

    doubledash();
}



//------------------ Displaying the information--------------------------
void car_detail(const Car& car)
{
    doubledash();  // user defined function from design.h
    cout << "\n\n\t\t\t\tCar Details";
    doubledash(); 
    cout << "\n\n\t\tDriver Name    : " << car.driver_name;
    cout << "\n\t\tCar No          : " << car.car_numbers;
    cout << "\n\t\tHours Of Stay   : " << car.time_hours;
    cout << "\n\t\tTime Slot       : " << car.time_slot;
    doubledash();

}



//------------------delete the records of the driver--------------------------------
void delete_record()
{   
    int n;
    system("CLS");
    cout << "\n\n\t\tEnter the car no you want to get depart : ";
    cin >> n;

    ifstream inFile("parking3.dat", ios::binary);       // open the input file for reading
    ofstream outFile("temp.dat", ios::out | ios::binary);   // open a temporary file for writing 
    Car car;

    while (inFile.read((char*)&car, sizeof(car)))
    {
        // If the car number does not match the one to be deleted, write the record to the temporary file
        if (car.car_numbers != n)
        {
            outFile.write((char*)&car, sizeof(car));
        }
    }
    cout << "\n\n\t\t Parking Record Deleted";

    inFile.close();
    outFile.close();

    if (remove("parking3.dat") != 0)
    {
        cout << "\n\n\t\t Error deleting file";
        // Handle the error as needed
    }
    if (rename("temp.dat", "parking3.dat") != 0)
    {
        cout << "\n\n\t\t Error renaming file";
        // Handle the error as needed
    }
}




void search_car()
{   
    int n;
    system("CLS");
    
    cout << "\n\n\t\tEnter the car no you want to search : ";
    cin >> n;

    ifstream inFile("parking3.dat", ios::binary);
    Car car;
    bool carFound = false;

    while (inFile.read((char*)&car, sizeof(car)))
    {
        if (car.car_numbers == n)
        {
            cout << "\n\n\t\tCar Found! Details:";
            car_detail(car);
            carFound = true;
            break;
        }
    }
    inFile.close();

    if (!carFound)
    {
        cout << "\n\n\t\tCar not found!";
    }
}



void update_car()
{
    int n;
    system("CLS");

    doubledash();                                                 // user defined function from design.h
    cout << "\n\t\t\t\tUpdate Car Details";
    doubledash();  

    cout << "\n\n\t\tEnter the car number you want to update: ";
    cin >> n;

    fstream file("parking3.dat", ios::binary | ios::in | ios::out);
    Car car;
    bool carFound = false;

    while (file.read((char*)&car, sizeof(car)))
    {
        if (car.car_numbers == n)
        {
            cout << "\n\n\t\tCar Found! Update the details:";
            cout << "\n\n\t\tEnter the name of driver: ";
            cin >> car.driver_name;
            cout << "\n\n\t\tEnter the number of hours of stay: ";
            cin >> car.time_hours;
            cout << "\n\n\t\tEnter the time slot: ";
            cin >> car.time_slot;

            file.seekp(static_cast<streampos>(file.tellg()) - static_cast<streampos>(sizeof(car)));
            file.write((char*)&car, sizeof(car));

            carFound = true;
            cout << "\n\n\t\tCar details updated successfully!";
            break;
        }
    }

    file.close();

    if (!carFound)
    {
        cout << "\n\n\t\tCar not found!";
    }
    doubledash();          
}



//---------display all-----------------------------------------------------------------
void display_all()
{
    system("CLS");
    ifstream inFile("parking3.dat", ios::binary);
    Car car;
    cout << "\n\n\t\t=============================================";
    cout << "\n\t\t| Car No |   Driver Name   | Hours of Stay |";
    cout << "\n\t\t==============================================";
    while (inFile.read((char*)&car, sizeof(car)))
    {
        cout << "\n\t\t| " << setw(7) << car.car_numbers << " | " << setw(15) << car.driver_name << " | " << setw(14) << car.time_hours << " | ";
    }
    doubledash();     
    inFile.close();
}



//------------------the main login page grants or denies accesss to the system-----
int login() {
    string pass = "";
    char password;

    car_md();   // user defined function from design.h file
    star_start();
    cout << "\t\t\t\t\t\tCar Parking Reservation System Login\n";
    star_end();
    cout << "\n\n\n\t\t\t\t\t\tEnter Password: ";

    password = _getch();
    while (password != 13) { // character 13 is enter
        pass.push_back(password);
        cout << '*';
        password = _getch();
    }
    if (pass == "pass") {
        star_start();
        cout << "\t\t\t\t\t\t  Access Granted! Welcome To Our System \n";
        star_end();
        system("PAUSE");
    }
    else {
        cout << "\n\n\n\t\t\t\tX X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X" << endl;
        cout << "\t\t\t\t\t\t Access Aborted...Please Try Again!!\n";
        cout << "\t\t\t\tX X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X" << endl;
        system("PAUSE");
        system("CLS");
        login();
    }
    return 0;
}
