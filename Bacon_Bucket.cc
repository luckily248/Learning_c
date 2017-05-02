/*################################################
  # #issuse with prototypeing functions         #
  # (windows API testing)                       #
  ################################################*/
#include<windows.h>
#include<iostream>
#include<conio.h>
#include<cstdlib>

    // Set up the handles for reading/writing:
    HANDLE writing = GetStdHandle(STD_OUTPUT_HANDLE);
    HANDLE reading = GetStdHandle(STD_INPUT_HANDLE);

void prepare_cmd_size(){
  // Change the window title:
  SetConsoleTitle(TEXT("Bacon Bucket"));

  // Set up the required window size:
  HWND hwnd = GetConsoleWindow();
  RECT size = {0, 0, 900, 1500};
  MoveWindow(
    hwnd, size.top,
    size.left,
    size.bottom-size.top,
    size.right-size.left,
    TRUE
  );
}
void GoToXY(int column, int line){
    // Create a COORD structure and fill in its members.
    // This specifies the new position of the cursor that we will set.
    COORD coord;
    coord.X = column;
    coord.Y = line;

    // call the SetConsoleCursorPosition function.
    if (!SetConsoleCursorPosition(writing, coord)){
        // The function call failed, so you need to handle the error.
        // You can call GetLastError() to get a more specific error code.
    }
}
/*################################################
  # method of moving things with minimal flicker #
  # an array with a loop that will print in a for#
  # loop, changeing the vertical...(windows API) #
  # array sligtly faster then a vector...        #
  ################################################*/
  void print_array_at_coordinate(int x, int y,std::string(array)[0],int array_size,int color){
    SetConsoleTextAttribute(writing, color);
    for(int i=0;i<array_size;i++){
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
  print_array_at_coordinate(30,39,assii_bucket_array,6,15); //color 15 is grey

  //animation test... will make a function with a key for 1 iteration later....
  // if it goes past the end of the cmd it prints below "randomly"... why?
  //delay will cause an error too ... cant move many things at once or heavy flicker
  for(int i=0;i<180;i++){
    print_array_at_coordinate(i,30,assii_bacon_array,4,12);  //color 12 is red
    for(int delay=1;delay<=3000000;delay++);     //to slow things down
    print_array_at_coordinate(i,30,assii_bacon_array,4,0);   //color 0 is blank

    print_array_at_coordinate(i,20,assii_bacon_array,4,12);  //color 12 is red
    for(int delay=1;delay<=3000000;delay++);     //to slow things down
    print_array_at_coordinate(i,20,assii_bacon_array,4,0);   //color 0 is blank

//theres a print error ... but I like it for a one pass then start...
    print_array_at_coordinate(i,39,assii_bucket_array,6,15); //color 15 is grey
    for(int delay=1;delay<=300000;delay++);     //to slow things down
    print_array_at_coordinate(i,39,assii_bucket_array,6,15); //color 15 is grey
  }
  goto start;
}
// windowed fullscreen
//ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
//goto here; for recursive things
//for(int delay=1;delay<=3000000;delay++);     to slow things down ...goog for seeing errors


/*   #<http://www.benryves.com/tutorials/winconsole/>
  ###############################################################################################################
  // Set up the required window size FAIL.. but important information                                     FAIL 1
  _SMALL_RECT console_size;
  console_size.Top = 0;
  console_size.Left = 0;
  console_size.Bottom= 45;
  console_size.Right = 50;
  // SetConsoleWindowInfo() does not reposition the console window on the screen.
  // The name of this function is misleading. It rather scrolls the current visible portion inside the console window
  SetConsoleWindowInfo(wHnd, TRUE, &console_size);
  // Create a COORD to hold the buffer size:
  COORD bufferSize = {30, 50};
  // Change the internal buffer size:
  SetConsoleScreenBufferSize(wHnd, bufferSize);
  ####################################################################################################################
  // learned about memset... but realized I can just print blank characters                                    FAIL 2
  void clear_array_at_cordinate(int x, int y,std::string(array)[0],int array_size){
    std::string blank_array[array_size]={};
    int array_width = array[0].length();

    char blank_string[] = "8";
    memset (blank_string,'0',array_width);
    for (int i=0;i<array_size;i++){
      blank_array[i]= blank_string;
    }
    print_array_at_coordinate(x,y,blank_array,array_size,3);
  }
  #################################################################################################################



  */
