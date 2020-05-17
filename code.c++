#include <ctime>    /* time */
#include <stdlib.h> /* srand, rand */
#include <iostream> /* cin and cout */
using namespace std;

int randomNumber(int min, int max) {
  //acceps a minimum and maximum value
  //calculates a random number inbetween min and max
  //returns the number

  //returns a random number 1 to 100
  return rand() % (max-min) + min;
}

bool askQuestion(){
  //accepts nothing
  //asks the user the answer to a simple problem
  //returns true if the were correct, and false if not

  //create numbers to subract
  int number1=randomNumber(2,20); //Start from 2 so number 2 can be below.
  int number2=randomNumber(1,number1);

  //create vars for answers
  int answer=number1-number2;
  int userAnswer;

  //output problem & get user answer
  cout << number1 << "-" << number2 << "= ";
  cin >> userAnswer;

  //respond according if the user was right or wrong
  if(answer == userAnswer){
    cout << " Right (:" << endl;
    return true;
  }
  else{
    cout << " Wrong ):" << endl;
    return false;
  }
}

int main() {
  //Explanition
  cout << "When ready, press ENTER to begin your subtraction test.";
  cin.ignore();

  //settings
  int questions=50;
  int timeLimit=2*60; //2 minutes

  //# the user answered correctly
  int correct=0;

  //create and assign start time
  time_t start_time;
	time(&start_time);

  //game loop
  for(int q=0; q<questions; q++){
    //Ask the user a problem.
    if(askQuestion()){
      correct++;
    }

    //path: out of time
    if(difftime(time(NULL), start_time)>timeLimit){
      cout << "OUT OF TIME!" << endl;
      break;
    }
  }

  //Scoreing
  cout << "Results: " << correct << "/" << questions << endl;
}
