#include<iostream>
#include <stdlib.h>
#include <string>

std::string who_won(int human_choice,int Computer_Choice);
std::string num_to_hand(int number);
std::string atomic_option();

main(){
  int human_choice = 0;
  while(human_choice != 4){
    std::cout<<"\n    --- Rock Paper Scissors (Human VS random) ---"
           <<"\n 1) Rock"
           <<"\n 2) Paper"
           <<"\n 3) Scissors"
           <<"\n 4) Quit"

    <<"\n\n Your Choice: ";
    std::cin>> human_choice;
    int Computer_Choice = rand() % 3 + 1;     //range 1 to 3


    if(human_choice == 1 || human_choice == 2 || human_choice == 3){
      std::cout<<"\n Human "<<num_to_hand(human_choice)<<" VS Computer "<<num_to_hand(Computer_Choice);
      if(who_won(human_choice,Computer_Choice) == "Human")std::cout<<"\n\n YOU WIN!";
      if(who_won(human_choice,Computer_Choice) == "Computer")std::cout<<"\n\n YOU LOSE!";
      if(who_won(human_choice,Computer_Choice) == "Tie")std::cout<<"\n\n Tie!";
    }
    else if(human_choice == 4) std::cout<<"\n\n QUITING PROGRAM!";
    else if(human_choice == 5) atomic_option();
    else std::cout<<"\n\n only 1 2 3 4 are valid entrys!";

    std::cout<<"\n\n-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_";
  }
}

std::string who_won(int human_choice,int Computer_Choice){
  if(human_choice == Computer_Choice)return"Tie";
  if(human_choice == 1){ //Rock
    if(Computer_Choice == 2)return"Computer";
    if(Computer_Choice == 3)return"Human";
  }
  if(human_choice == 2){ //Paper
    if(Computer_Choice == 3)return"Computer";
    if(Computer_Choice == 1)return"Human";
  }
  if(human_choice == 3){ //Scissors
    if(Computer_Choice == 1)return"Computer";
    if(Computer_Choice == 2)return"Human";
  }
}

std::string num_to_hand(int number){
  if(number == 1)return"Rock";
  if(number == 2)return"Paper";
  else return"Scissors";
}

std::string atomic_option(){
  std::cout << "\nMuch confuse \n"
  << "\n─────────▄──────────────▄────"
  << "\n────────▌▒█───────────▄▀▒▌───"
  << "\n────────▌▒▒▀▄───────▄▀▒▒▒▐───"
  << "\n───────▐▄▀▒▒▀▀▀▀▄▄▄▀▒▒▒▒▒▐───"
  << "\n─────▄▄▀▒▒▒▒▒▒▒▒▒▒▒█▒▒▄█▒▐───"
  << "\n───▄▀▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▀██▀▒▌───"
  << "\n──▐▒▒▒▄▄▄▒▒▒▒▒▒▒▒▒▒▒▒▒▀▄▒▒▌──"
  << "\n──▌▒▒▐▄█▀▒▒▒▒▄▀█▄▒▒▒▒▒▒▒█▒▐──"
  << "\n─▐▒▒▒▒▒▒▒▒▒▒▒▌██▀▒▒▒▒▒▒▒▒▀▄▌─"
  << "\n─▌▒▀▄██▄▒▒▒▒▒▒▒▒▒▒▒░░░░▒▒▒▒▌─"
  << "\n─▌▀▐▄█▄█▌▄▒▀▒▒▒▒▒▒░░░░░░▒▒▒▐─"
  << "\n▐▒▀▐▀▐▀▒▒▄▄▒▄▒▒▒▒▒░░░░░░▒▒▒▒▌"
  << "\n▐▒▒▒▀▀▄▄▒▒▒▄▒▒▒▒▒▒░░░░░░▒▒▒▐─"
  << "\n▐▒▒▒▀▀▄▄▒▒▒▄▒▒▒▒▒▒░░░░░░▒▒▒▐─"
  << "\n─▌▒▒▒▒▒▒▀▀▀▒▒▒▒▒▒▒▒░░░░▒▒▒▒▌─"
  << "\n─▌▒▒▒▒▒▒▀▀▀▒▒▒▒▒▒▒▒░░░░▒▒▒▒▌─"
  << "\n─▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▐──"
  << "\n──▀▄▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▄▒▒▒▒▌──"
  << "\n────▀▄▒▒▒▒▒▒▒▒▒▒▄▄▄▀▒▒▒▒▄▀───"
  << "\n───▐▀▒▀▄▄▄▄▄▄▀▀▀▒▒▒▒▒▄▄▀─────"
  << "\n──▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▀▀────────";
}
