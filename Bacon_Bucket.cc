/*################################################
  # http://www.benryves.com/tutorials/winconsole/#
  # (windows API Tutorial)                       #
  ################################################*/
#include<windows.h>
#include<iostream>
#include<conio.h>
#include<cstdlib>

// wont print a function if I use a prototype...?
void GoToXY(int column, int line){
    // Create a COORD structure and fill in its members.
    // This specifies the new position of the cursor that we will set.
    COORD coord;
    coord.X = column;
    coord.Y = line;

    // Obtain a handle to the console screen buffer.
    // (You're just using the standard console, so you can use STD_OUTPUT_HANDLE
    // in conjunction with the GetStdHandle() to retrieve the handle.)
    // Note that because it is a standard handle, we don't need to close it.
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Finally, call the SetConsoleCursorPosition function.
    if (!SetConsoleCursorPosition(hConsole, coord))
    {
        // Uh-oh! The function call failed, so you need to handle the error.
        // You can call GetLastError() to get a more specific error code.
        // ...
    }
}
void assii_bucket(){std::cout     <<",.--'`````'--.,\n"
              <<"|'-.,_____,.-'|\n"
              <<"| -.,_____,.- |\n"
              <<"|             |\n"
              <<"|             |\n"
              <<"|             |\n"
              <<"`'-.,_____,.-''\n";
}


main(){
  HANDLE wHnd;    // Handle to write to the console.
  HANDLE rHnd;    // Handle to read from the console.
  // Set up the handles for reading/writing:
  wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
  rHnd = GetStdHandle(STD_INPUT_HANDLE);
  // Change the window title:
  SetConsoleTitle(TEXT("Bacon Bucket"));
  // Set up the required window size:
  _SMALL_RECT console_size;
  console_size.Top = 0;
  console_size.Left = 0;
  console_size.Bottom= 45;
  console_size.Right = 115;
  // Change the console window size:
  SetConsoleWindowInfo(wHnd, TRUE, &console_size);
  // Create a COORD to hold the buffer size:
  COORD bufferSize = {500, 500};
  // Change the internal buffer size:
  SetConsoleScreenBufferSize(wHnd, bufferSize);


    here:
    GoToXY(5,5);
    std::cout<<"test";
    for(int delay=1;delay<=300000000;delay++);

    GoToXY(0,5);
    assii_bucket();
    for(int delay=1;delay<=300000000;delay++);

goto here;
}

std::string thing [3]= {"  o\n"," oo\n","ooo\n"};

// windowed fullscreen
//ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
