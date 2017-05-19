/*################################################
  # # USE windows time to move bacon at interval #
  # (windows API testing)                        #
  ################################################*/
#define _WIN32_WINNT 0x0500                           //https://msdn.microsoft.com/en-us/library/aa383745(VS.85).aspx
#define ARRAY_SIZE(x) (sizeof((x)) / sizeof((x)[0]))  //becaue ponters/functions --no ponter iterator
#include<windows.h>
#include<iostream>
#include<conio.h>
#include<cstdlib>

// Set up the handles for reading/writing:
HANDLE writing = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE reading = GetStdHandle(STD_INPUT_HANDLE);

//initilize cordinates of arrays
int Bacon_x = 30, Bacon_y = 5;
int Bucket_x = 60, Bucket_y = 20;

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
void moveBacon(){
  // Fetch key state.
  SHORT KeyState_up    = GetAsyncKeyState(VK_UP);
  SHORT KeyState_down  = GetAsyncKeyState(VK_DOWN);
  SHORT KeyState_right = GetAsyncKeyState(VK_RIGHT);
  SHORT KeyState_left  = GetAsyncKeyState(VK_LEFT);
  // Test high bits - if set, key was down when GetAsyncKeyState was called.
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
  if( ( 1 << 15 ) & KeyState_down && Bacon_y < 50){
        print_array_at_coordinate(Bacon_x,Bacon_y,assii_bacon_array,0);   //color 0 is blank
        Bacon_y += 1;
        print_array_at_coordinate(Bacon_x,Bacon_y,assii_bacon_array,12); //color 12 is red
  }
  if( ( 1 << 15 ) & KeyState_up && Bacon_y > 1){
        print_array_at_coordinate(Bacon_x,Bacon_y,assii_bacon_array,0);   //color 0 is blank
        Bacon_y -= 1;
        print_array_at_coordinate(Bacon_x,Bacon_y,assii_bacon_array,12); //color 12 is red
  }
  //need to use a windows time delay to prevent flicker... outside of this... like do after time but keep going on to next
  for(int delay=1;delay<=5000000;delay++);       //to slow things down... can have speed upgrades???
}

main(){
  prepare_cmd_size();
  start:
  //need make a random start pont and move velocity for buckets....
  //the point will be to doge things.... make powerups?
  // can make walls with collision  // speed of bacon // slow time //

  print_array_at_coordinate(Bucket_x,Bucket_y,assii_bucket_array,15); //color 15 is grey
  print_array_at_coordinate(Bacon_x,Bacon_y,assii_bacon_array,12); //color 12 is red
  moveBacon();

  //basic array collision ... only really need to check perimiter... not area... WHATEVER Mr.duck
  //check one coordinate x & y   agenst every coordinate of the other array....
  // slow but works for sillyness continuity  ( vector would be used to make this a function)
  for(int x = 0; x < sizeof(assii_bacon_array)/sizeof(assii_bacon_array[0]); x++){
    for(int x2 = 0; x2 < assii_bacon_array[0].size(); x2++){
      for(int x3 = 0; x3 < sizeof(assii_bucket_array)/sizeof(assii_bucket_array[0]); x3++){
        for(int x4 = 0; x4 < assii_bucket_array[0].size(); x4++){
          if(Bacon_x+x2 == Bucket_x+x4 && Bacon_y-(x+2) == Bucket_y-x3)goto print;    // .. bacon fix y-coordinate
        }
      }
    }
  }

  // use time to move function down one line.. x value every half SetConsoleWindowInfo
  if(time- last checked > last checked  + .05 SECONDS) aprox .05 sec an incriment fall

  goto start;
  print:
  std::cout <<"   THE BACON HIT THE BUCKET!!!!!!!!\a";
}
/*##########################################################################
ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);   windowed fullscreen
start:  goto start;                            for recursive things
for(int delay=1;delay<=3000000;delay++);       to slow things down
\a   OR   \7                                   plays a sound

##########################################################################*/

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
  // The array is passed as a reference to the function, keeping the size information (only for C++)           Fail 3
   template<typename T, size_t N>
  void colision_check(std::string T (&a)[N],std::string* array2){
    //basic array collision ... only really need to check perimiter... not area... WHATEVER Mr.duck
    //check one coordinate x & y   agenst every coordinate of the other array....
    // slow but works for sillyness continuity   vector.incude?
    std::cout<<N;
    for(int x = 0; x < sizeof(array1)/sizeof(array1[0]); x++){
      for(int x2 = 0; x2 < array1[0].size(); x2++){
        for(int x3 = 0; x3 < sizeof(array2)/sizeof(array2[0]); x3++){
          for(int x4 = 0; x4 < array2[0].size(); x4++){
            if(Bacon_x+x2 == Bucket_x+x4 && Bacon_y-(x+2) == Bucket_y-x3)std::cout<<"HIT THE ARRAY";    // .. bacon fix y-coordinate
          }
        }
      }
    }
  }
  */
