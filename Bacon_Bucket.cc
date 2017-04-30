/*################################################
  # http://www.benryves.com/tutorials/winconsole/#
  # (windows API Tutorial)                       #
  ################################################*/
#include<windows.h>
#include<iostream>
#include<conio.h>
#include<cstdlib>

// wont print a function if I use a prototype...?...several prototype issues...
void prepare_cmd_size(){
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
  COORD bufferSize = {30, 50};
  // Change the internal buffer size:
  SetConsoleScreenBufferSize(wHnd, bufferSize);
}
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
/*################################################
  # method of moving things with minimal flicker #
  # an array with a loop that will print in a for#
  # loop, changeing the vertical...(windows API) #
  # array sligtly faster then a vector...        #
  ################################################*/
  void print_array_at_coordinate(int x, int y,std::string(array)[0]){
    for(int i=0;i<6;i++){
      GoToXY(x,i+y);
      std::cout<<array[i];
    }
  }
// All the ASSII ART arrays
std::string assii_bucket_array[6]={
  ",.--'`````'--.,",
  "|'-.,_____,.-'|",
  "| -.,_____,.- |",
  "|             |",
  "|             |",
  "`'-.,_____,.-''"
};
std::string assii_bacon_array[4]={
     "   .-'__`-._.'.--.'.__.,",
     " /--'  '-._.'    '-._./",
     "/__.--._.--._.'``-.__/",
     "'._.-'-._.-._.-''-..'"};


main(){
  prepare_cmd_size();
  start:
  print_array_at_coordinate(30,39,assii_bucket_array);
  print_array_at_coordinate(30,30,assii_bacon_array);
  goto start;
}
// windowed fullscreen
//ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
//goto here; for recursive things
//for(int delay=1;delay<=3000000;delay++);     to slow things down ...goog for seeing errors
