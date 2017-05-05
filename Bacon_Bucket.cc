/*################################################
  # # USE windows time to move bacon at interval #
  # (windows API testing)                        #
  ################################################*/
#define _WIN32_WINNT 0x0500
#include<windows.h>
#include<SDKDDKVer.h> //https://msdn.microsoft.com/en-us/library/aa383745(VS.85).aspx
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
  //http://stackoverflow.com/questions/20017457/getconsolewindow-was-not-declared-in-this-scope
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
void print_array_at_coordinate(int x, int y,std::string(array)[0],int color){
  SetConsoleTextAttribute(writing, color);
  for(int i=0;array[i] != "end";i++){
    GoToXY(x,i+y);
    std::cout<<array[i];
  }
}
//void recive_pressed_key(){

// All the ASSII ART arrays.. need "end" (notifys print_array_at_coordinate when to stop)
std::string assii_bucket_array[7]={
  ",.--'`````'--.,",
  "|'-.,_____,.-'|",
  "| -.,_____,.- |",
  "|             |",
  "|             |",
  "`'-.,_____,.-''",
  "end"};
std::string assii_bacon_array[5]={
     "   .-'__`-._.'.--.'.__.,",
     " /--'  '-._.'    '-._./",
     "/__.--._.--._.'``-.__/",
     "'._.-'-._.-._.-''-..'",
     "end"};

main(){
  prepare_cmd_size();
  int Bacon_x = 30;
  int Bacon_y = 20;

  start:
  print_array_at_coordinate(30,39,assii_bucket_array,15); //color 15 is grey
  print_array_at_coordinate(Bacon_x,Bacon_y,assii_bacon_array,12); //color 12 is red

  // Fetch tab key state.
SHORT KeyState_down  = GetAsyncKeyState( VK_DOWN );
SHORT KeyState_right = GetAsyncKeyState( VK_RIGHT );
SHORT KeyState_left  = GetAsyncKeyState( VK_LEFT );

// Test high bit - if set, key was down when GetAsyncKeyState was called.
if( ( 1 << 15 ) & KeyState_right && Bacon_x < 170){
    print_array_at_coordinate(Bacon_x,Bacon_y,assii_bacon_array,0);   //color 0 is blank
    Bacon_x += 1;
    print_array_at_coordinate(Bacon_x,Bacon_y,assii_bacon_array,12); //color 12 is red
}
if( ( 1 << 15 ) & KeyState_left && Bacon_x > 1){
      print_array_at_coordinate(Bacon_x,Bacon_y,assii_bacon_array,0);   //color 0 is blank
      Bacon_x -= 1;
      print_array_at_coordinate(Bacon_x,Bacon_y,assii_bacon_array,12); //color 12 is red
}
  goto start;
}
//ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);   windowed fullscreen
//start:  goto start;                            for recursive things
//for(int delay=1;delay<=3000000;delay++);       to slow things down


/*   #<http://www.benryves.com/tutorials/winconsole/>
for(int i=0;i<180;i++){
  print_array_at_coordinate(i,30,assii_bacon_array,12);  //color 12 is red
  for(int delay=1;delay<=3000000;delay++);     //to slow things down
  print_array_at_coordinate(i,30,assii_bacon_array,0);   //color 0 is blank
}
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
