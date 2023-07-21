
#include <iostream>
#include <ostream>

using namespace std;

/* These function are very helpfull for making the GUI look good :) */

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



void car_md() {
    /*A car model design */
    // Set car color to orange (33 is the ANSI escape)
    setColor(33);
    setColor(1);
    /*A car model design */
    cout << "   _____  " << endl;
    cout << "  /|||_\\`._ " << endl;
    cout << " (   _    _ _\\ " << endl;
    cout << " =`-(_)--(_)-' " << endl;
    resetColor();

    // Set name color to blue (94 is the ANSI escape )
    setColor(94);
    setColor(1);
    cout << "  Car Wala Bhai" << endl; // You can change the name..
    resetColor();
}