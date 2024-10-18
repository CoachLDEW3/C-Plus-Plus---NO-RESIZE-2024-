/************************************************************************************************
Name:		CoachLDEW
Date:	 	10.18.2024
Purpose: 	This program removes the ability to resize the window.  This is a windows specific
            program.  It does this by removing the resizeable style of the console window
*************************************************************************************************/


#include <iostream>			//This library contains standard input and output processes
#include <Windows.h>		//This library contains the function to control the cursor position


using namespace std;

void NoResize()
{
    //Create a HANDLE to the console window
    HWND console = GetConsoleWindow();
    if (console != NULL) 
    {
        // Get the current window style
        LONG style = GetWindowLong(console, GWL_STYLE);

        // Remove the resizable style
        style &= ~WS_MAXIMIZEBOX;
        style &= ~WS_THICKFRAME;

        // Set the new style
        SetWindowLong(console, GWL_STYLE, style);
    }
}

int main() 
{
    NoResize();
    cout << "This program prevents the user from resizing the window" << endl;

    return 0;
}