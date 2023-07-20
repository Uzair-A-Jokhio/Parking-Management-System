
#include <iostream>
#include <ostream>

using namespace std;

/* These function are very helpfull for making the GUI look good :) */



void car_md() {
    /*A car model design */
    cout << "   _____  " << endl;
    cout << "  /|||_\\`._ " << endl;
    cout << " (   _    _ _\\ " << endl;
    cout << " =`-(_)--(_)-' " << endl;
    cout << "  Car Wala Bhai"; // You can change the name..
}



void star_start() {
    cout << "\n\n\n\t\t\t\t***************************************************************" << endl;
}

void star_end() {
    cout << "\t\t\t\t***************************************************************" << endl;
}

void doubledash() {
	cout << "\n\t\t===============================================";
}

// Function to set the text color
void setColor(int color)
{
    cout << "\033[" << color << "m";
}

// Function to reset text color and formatting
void resetColor()
{
    cout << "\033[0m";
}