#include<iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

// useingnamespace std;  what we have been doing in class

main(){
  int user_input;

  // questions_size needs to match the amount of questions and answers +1
  int questions_size = 20;

  //parallel question and answer arrays
  std::string questions[questions_size],answers[questions_size];

  // questions Here
  questions[0] = "How do you make a new line ... what just happend";
  questions[1] = "How do you print to the screen aka like this";
  questions[2] = "How do you get user input";
  questions[3] = "How do you print to the screen";
  questions[4] = "What are some variable types";
  questions[5] = "How do you declare a function with a prototype";
  questions[6] = "How do you get a sudo random rumber?";
  questions[7] = "what are some Arithmetic Operators?";
  questions[8] = "what are some Relational Operators?";
  questions[9] = "what are some Logical  Operators?";
  questions[10] = "How do you write a for loop?";
  questions[11] = "How do you write a while loop or do while?";
  questions[12] = "what is an array?, an index? how do you declare an array?";
  questions[13] = "How do you write a for loop?";
  questions[14] = "what is a preprocesor directive?";
  questions[15] = "what does the % symboyl do?";
  questions[16] = "what is the diffrence between volitiole and non volitiole memory";
  questions[17] = "How do you write code comment";
  questions[18] = "for doubble how do you controll the decmal places?";
  questions[19] = "how many bits in a byte?";

  // answers Here
  answers[0] = "\n";
  answers[1] = "this is cout so and it was used everywhere so if you dont know what it is you are a cirtain kind of special";
  answers[2] = "How do you get user input";
  answers[3] = "How do you print to the screen";
  answers[4] = "What are some variable types";
  answers[5] = "How do you declare a function with a prototype";
  answers[6] = "How do you get a sudo random rumber?";
  answers[7] = "https://www.tutorialspoint.com/cplusplus/cpp_operators.htm";
  answers[8] = "https://www.tutorialspoint.com/cplusplus/cpp_operators.htm";
  answers[9] = "https://www.tutorialspoint.com/cplusplus/cpp_operators.htm";
  answers[10] = "line 60";
  answers[11] = "How do you write a while loop or do while?";
  answers[12] = "what is an array? mutivariable storage,\nan index? this is index 12 remember they start at 0,  \nhow do you declare an array? std::string questions[questions_size]";
  answers[13] = "for(int question_number = 0; question_number<questions_size; question_number++)";
  answers[14] = "Preprocessor directives are lines included in a program that being with the character #\n They are invoked by the compiler to process some programs before compilation. ";
  answers[15] = "finds the remander after divideing";
  answers[16] = "volitiole: A device which holds the data as long as it has power supply connected to it\n non vilitile memory: A device which can hold data in it even if it is not connected to any power source ";
  answers[17] = "// single line   or /* */";
  answers[18] = "controll the decmal places with std::setprecision(number)";
  answers[19] = "8 bits in a byte";

  do{
    if(user_input == 1){
      for(int question_number = 0; question_number<questions_size; question_number++){
        std::cout <<"\n" <<question_number <<") " <<questions[question_number];
      }
      std::cout <<"\n";
    }
    if(user_input == 2){
      srand (time(NULL));
      int random_question_number = rand() % questions_size;
      std::cout <<"\n" <<random_question_number <<") " <<questions[random_question_number]
                <<"\n enter any number but 0 to see answer";
      std::cin>> user_input;
      if(user_input!=0)std::cout <<"\n" <<random_question_number <<") " <<answers[random_question_number];
    }

    //the Main menu
    std::cout <<"\n"
              <<"-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_";
    std::cout<< "\n 0) to quit"
             << "\n 1) list Things you should know"
             << "\n 2) ask random question";
    std::cin>> user_input;
  }while(user_input != 0);
}

std::string ask_random_question(){
}




/*
a littile review programing for review with review
includeing review for the review

ask random questions for review

write a program that you can make a selection from that adds to a running total
then return the total with 2% tax
*/
