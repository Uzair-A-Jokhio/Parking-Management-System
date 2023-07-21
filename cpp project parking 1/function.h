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
    char pay;             // Payment 
    char time_slot[50];      // Time slot of parking
};



//-----------------------void function for the collecting data--------------------
void input_detail(Car& car)
{
    system("CLS"); // Clear the console screen

    doubledash();  // user defined function from design.h
    cout << "\n\t\t\t\tCar Parking Reservation";
    doubledash();

    int d = 0; // // Initialize a variable to keep track of parking position

    // Prompt the user to enter the driver's name, car number, hours of stay, and time slot
    cout << "\n\n\t\tEnter the name of driver: ";
    cin >> car.driver_name; 
    cout << "\n\n\t\tEnter the car number: ";
    cin >> car.car_numbers; 
    cout << "\n\n\t\tEnter the number of hours of stay: ";
    cin >> car.time_hours;
    cout << "\n\n\t\tEnter the time slot: ";
    cin >> car.time_slot;
    


    // Check if parking is available (assuming parking slots are limited to 20 and stay duration is less than 8 hours)
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
    cout << "\n\n";
    system("PAUSE");
}



//-------------------------calculating the price of the stay-----------------------
void calculate_price(const Car& car)
{
    char x;
    cout << "\n";
    car_md(); // User-defined car model design from design.h file

    cout << "\n\t\n\tAre you a V.I.P: y/n ";
    cin >> x;
    system("CLS");

    doubledash();  // user defined function from design.h
    cout << "\n\t\t\t Expense Calculation";
    doubledash();

    if (x == 'y' || x == 'Y') {
        // Display the total parking expense for VIP in green color
        setColor(32); // Green color (32 is the ANSI escape code for green)
        cout << "\n\n\t\tThe total expense during parking: " << car.time_hours * 35 << " rupees\n";
        resetColor(); // Reset the color to default
    }
    else {
        // Display the total parking expense for non-VIP in yellow color
        setColor(33); // Yellow color (33 is the ANSI escape code for yellow)
        cout << "\n\n\t\tThe total expense during parking: " << car.time_hours * 15 << " rupees\n";
        resetColor(); // Reset the color to default
    }

    doubledash();
}




//------------------ Displaying the information--------------------------
void car_detail(const Car& car)
{
    // Set color to Dark Gray 
    setColor(90);
    doubledash();  // user-defined function from design.h
    cout << "\n\n\t\t\t\tCar Details";
    doubledash();
    resetColor();

    // Set color to Light Green
    setColor(92);
    cout << "\n\n\t\tDriver Name     : " << car.driver_name;
    cout << "\n\t\tCar No          : " << car.car_numbers;
    cout << "\n\t\tHours Of Stay   : " << car.time_hours;
    cout << "\n\t\tTime Slot       : " << car.time_slot;
    resetColor();

    // Set color to Dark Gray 
    setColor(90);
    doubledash();
    resetColor();
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
    Car car{};
    bool carFound = false;

    // Loop through each record in the input file
    while (inFile.read((char*)&car, sizeof(car)))
    {
        // If the car number matches the one to be deleted, display the details and price
        if (car.car_numbers == n)
        {
            car_detail(car); // Display the car details
            calculate_price(car); // Display the parking price for the car
            carFound = true;
            cout << "\n\n\t\tPress any key to confirm the deletion of this record...";
            int e = _getch(); // Wait for user confirmation to delete the record
        }
        else
        {
            outFile.write((char*)&car, sizeof(car)); // Write the record to the temporary file
        }
    }

    inFile.close();
    outFile.close();

    if (carFound)
    {
        cout << "\n\n\t\t Parking Record Deleted";
    }
    else
    {
        cout << "\n\n\t\tCar not found!";
    }

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
    doubledash();          
}





//---------------------search the car details by car number--------------------
void search_car()
{
    int n;
    system("CLS");

    // Set color to Dark Gray 
    setColor(90);
    doubledash();   // user-defined function from design.h
    cout << "\n\n\t\tSearch Car Details";
    doubledash();
    resetColor();

    // Set color to Dark Green 
    setColor(32);
    cout << "\n\n\t\tEnter Car NO#, you want to search : ";
    resetColor();

    cin >> n;

    ifstream inFile("parking3.dat", ios::binary);
    Car car{};
    bool carFound = false;

    while (inFile.read((char*)&car, sizeof(car)))
    {
        if (car.car_numbers == n)
        {
            // Set color to Light Blue 
            setColor(94);
            cout << "\n\n\t\tCar Found! Details:";
            resetColor();
            car_detail(car);
            carFound = true;
            break;
        }
    }
    inFile.close();

    if (!carFound)
    {
        // Set color to Red 
        setColor(31);
        cout << "\n\n\t\tCar not found!";
        // Set color to default
        resetColor();
    }
}



//----------------------update the car details -------------------------
void update_car()
{
    int n;
    system("CLS");

    // Set color to Dark Gray 
    setColor(90);
    doubledash();   // user-defined function from design.h
    cout << "\n\t\t\t\tUpdate Car Details";
    doubledash();
    // Set color to default
    resetColor();

    cout << "\n\n\t\tEnter the car number you want to update: ";
    cin >> n;

    fstream file("parking3.dat", ios::binary | ios::in | ios::out);
    Car car{};
    bool carFound = false;

    while (file.read((char*)&car, sizeof(car)))
    {
        if (car.car_numbers == n)
        {
            // Set color to Light Blue 
            setColor(94);
            cout << "\n\n\t\tCar Found! Update the details:";
            resetColor();

            // Set color to Dark Green 
            setColor(32);
            cout << "\n\n\t\tEnter the name of driver: ";
            resetColor();
            cin >> car.driver_name;

            // Set color to Dark Green 
            setColor(32);
            cout << "\n\n\t\tEnter the number of hours of stay: ";
            resetColor();
            cin >> car.time_hours;
            
            // Set color to Dark Green 
            setColor(32);
            cout << "\n\n\t\tEnter the time slot: ";
            resetColor();
            cin >> car.time_slot;

            // Move the file pointer to the position where the current record was read.
            // The position is calculated by subtracting the size of the 'car' structure from the current file pointer position.
            file.seekp(static_cast<streampos>(file.tellg()) - static_cast<streampos>(sizeof(car)));

            // Write the updated 'car' structure to the file at the position pointed by the file pointer.
            // This updates the existing record in the file with the new data provided by the user.
            file.write((char*)&car, sizeof(car));

            carFound = true;
            // Set color to Light Blue 
            setColor(94);
            cout << "\n\n\t\tCar details updated successfully!";
            resetColor();
            break;
        }
    }
    file.close();

    if (!carFound)
    {
        // Set color to Red 
        setColor(31);
        cout << "\n\n\t\tCar not found!";
        resetColor();
    }
    doubledash();
}




//---------display all-----------------------------------------------------------------
void display_all()
{
    system("CLS");
    ifstream inFile("parking3.dat", ios::binary);
    Car car{};

    setColor(90);
    cout << "\n\n\t\t==============================================";
    cout << "\n\t\t        Car Parking Reservation System        ";
    cout << "\n\t\t==============================================";
    cout << "\n\t\t  Car No |   Driver Name   |  Hours of Stay   ";
    cout << "\n\t\t==============================================";

    // Set color to default
    resetColor();

    while (inFile.read((char*)&car, sizeof(car)))
    {
        // Display car details in the table format with setw() for proper spacing
        // Set color to Light Blue 
        setColor(94);
        cout << "\n\t\t| " << setw(7) << car.car_numbers;
        // Set color to Dark Green 
        setColor(32);
        cout << " | " << setw(15) << car.driver_name;
        // Set color to Orange 
        setColor(33);
        cout << " | " << setw(14) << car.time_hours;
        cout << " | ";
        resetColor();
    }
    setColor(90);
    doubledash();
    // Set color to default
    resetColor();

    inFile.close();
}


#include <cstdio> // Include this header for the remove function

// Function to delete all records from the "parking3.dat" file
void delete_all_records()
{
    system("CLS");
    cout << "\n\n\t\t=== Delete All Records ===";

    // Ask for confirmation before deleting all records
    char confirm;
    cout << "\n\n\t\tAre you sure you want to delete all records? (y/n): ";
    cin >> confirm;

    if (confirm == 'y' || confirm == 'Y')
    {
        // Open the "parking3.dat" file in binary mode for writing and truncate the file
        ofstream outFile("parking3.dat", ios::binary | ios::trunc);
        outFile.close();
        cout << "\n\n\t\tAll records deleted successfully!";
    }
    else
    {
        cout << "\n\n\t\tDelete operation canceled.";
    }
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
    while (password != 13) { // character 13 is the ASCII code for the 'Enter' key
        pass.push_back(password); // Store each character of the password entered by the user
        cout << '*'; // Display '*' instead of the actual characters for security
        password = _getch();  // Read the next character
    }
    if (pass == "pass") {

        setColor(32);
        star_start();
        cout << "\t\t\t\t\t\t  Access Granted! Welcome To Our System" << endl;
        star_end();
        resetColor();

        system("PAUSE");// Pause the program to let the user read the success message
    }
    else{
        // Display access denied message with decorative lines
        setColor(31);
        cout << "\n\n\n\t\t\t\tX X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X" << endl;
        cout << "\t\t\t\t\t\t Access Aborted...Please Try Again!!\n";
        cout << "\t\t\t\tX X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X" << endl;
        resetColor();

        system("PAUSE");
        system("CLS");
        login();
    }
    return 0;
}


// Function to display parking slot visualization
void display_parking_slots()
{
    system("CLS");
    ifstream inFile("parking3.dat", ios::binary);
    Car car{};
    int parkingSlots[20] = { 0 }; // Initialize an array to represent parking slots (0 indicates an empty slot)

    // Read the parking records and mark occupied slots in the array
    while (inFile.read((char*)&car, sizeof(car)))
    {
        if (car.car_numbers >= 1 && car.car_numbers <= 20)
        {
            parkingSlots[car.car_numbers - 1] = 1; // Mark the slot as occupied
        }
    }

    setColor(90);
    doubledash();
    cout << "\n\n\t\t\tParking Slot Visualization";
    doubledash();
    resetColor();

    cout << "\n\n\t\t   Parking Layout";
    cout << "\n\t\t---------------------\n";

    for (int i = 0; i < 20; i++)
    {
        if (parkingSlots[i] == 0)
        {
            // Set color to Light Green
            setColor(92);
            cout << "\t\t[" << setw(2) << i + 1 << "]"; // Display empty slot number
        }
        else
        {
            // Set color to Light Red
            setColor(91);
            cout << "\t\t[" << setw(2) << "X" << "]"; // Display occupied slot with 'X'
        }

        if ((i + 1) % 5 == 0)
        {
            cout << "\n"; // Move to the next row after displaying 5 slots
        }
    }
    resetColor();
    inFile.close();

    doubledash();
}
