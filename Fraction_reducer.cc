// Fraction reducer
#include "iostream"
using namespace std;
main(){
  int numerator,denominator,twoTten=0,stop=0;
  cout << "Numerator: ";
  cin  >> numerator;
  cout << "Denominator: ";
  cin  >> denominator;

  //why wont denominator/numerator == numerator work? in the while loop?
  while(stop!=true){
    cout <<"\nboth the numerator and denominator divisable by any number 2-9? \n";
    for(twoTten = 2; twoTten <= 9; twoTten++){
      if(numerator%twoTten == 0 && denominator%twoTten == 0){
        cout <<"Yes!: " <<twoTten <<" will work\n";
        numerator/=twoTten;
        denominator/=twoTten;
        cout <<numerator <<"/" <<denominator <<"\n";
      }
    }
    //dealing 1/x or x/1
    if(numerator/denominator == numerator || denominator/numerator == denominator)stop=true;
    // dealing with x/x
    if(numerator/denominator == 1)stop=true;
    // dealing with all other cases... I think <-----------------------------------------------------------
    if(numerator%denominator > 0 && denominator%numerator > 0)stop=true;
  }

  cout <<"\n\n";
  if      (numerator==denominator)cout <<"the answer is: 1";
  else if (denominator==1)cout <<"the answer is: " <<numerator;
  //just restateing the answer neatly...
  else{
    cout <<"the answer is: " <<numerator <<"/" <<denominator;
  }
}
