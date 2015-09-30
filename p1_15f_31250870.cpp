/*
CS341 PROJECT 09/30/2015
ALI KALKANDELEN
31250870
*/
#include <iostream>
#include <string>
#include <ctype.h>
#include <cstdlib>
using namespace std;

string enter;
string input;
bool accept = false;


enum State {q0,q1,q2,q3,q4,q5,q6,q7,q8,q9,q10,q11,q12,trap};//state objects
State _state; //instance

//function headers
void changeState(State newstate);
void printState();
void dump();


int main(){

cout<<"Would you like to enter a string?" <<endl; //prompt
getline(cin, enter);
while(enter == "yes" || enter == "y")
{
cout<<"Okay Whats your string?"<<endl;//prompt
do{getline(cin, input);}while(input.length() < 1);//accepts string as long as its at least 1 character.
cout<<"Okay\n"<<"Here is your String: "<<input<<"\n\nAnd Here Is Your Report: "<<endl;
changeState(State::q0); //initialize states
printState();
for(unsigned int i=0; i < input.length(); i++)//loops through each character
{
    if(isupper(input[i]) || (!isalpha(input[i])&&input[i] != '.'))//automatically dumps if char not in L
        changeState(State::trap);

/*Since there is not that many states, i've used a simple switch statement for my dfa.
this checks each character and the current state and compares them to move along the dfa. */
    cout<<"Character: "<<input[i]<<" ";
    switch(_state)
    {
    case State::q0:
        if (input[i] == 'w')
            changeState(State::q1);
        else if(isalpha(input[i]))
            changeState(State::q5);
        else dump();
            break;

    case State::q1:
        if (input[i] == 'w')
            changeState(State::q2);
        else if(isalpha(input[i]))
            changeState(State::q5);
        else if(input[i] == '.')// for w.com
            changeState(State::q6);
        else dump();
            break;

    case State::q2:
        if (input[i] == 'w')
            changeState(State::q3);
        else if(isalpha(input[i]))
            changeState(State::q5);
        else if(input[i] == '.')// for ww.com
            changeState(State::q6);
        else dump();
            break;

    case State::q3:
        if (input[i] == '.')
            changeState(State::q4);
        else if(isalpha(input[i]))
            changeState(State::q5);
        else dump();
            break;

    case State::q4:
        isalpha(input[i]) ? changeState(State::q5) : dump();
            break;

    case State::q5:
        if (input[i] == '.')
            changeState(State::q6);
        else if(isalpha(input[i]))break;
        else dump();
            break;

    case State::q6:
        input[i] == 'c' ? changeState(State::q7) : dump();
            break;

    case State::q7:
        input[i] == 'o' ? changeState(State::q8) : dump();
            break;

    case State::q8:
        if (input[i] == 'm')
            changeState(State::q9);
        else if(input[i] == '.')
            changeState(State::q10);
        else dump();
            break;

    case State::q10:
        input[i] == 'u' ? changeState(State::q11) : dump();
            break;

    case State::q11:
       input[i] == 'k' ? changeState(State::q12) : dump();
       break;


    case State::q9:
    case State::q12:
    case State::trap:
    default:
        dump();
        break;
    }
    printState();

}
if(_state == State::q9 || _state == State::q12) accept = true;//assigns the accepting states
cout<<"\nString accepted? : "<<std::boolalpha<<accept<<endl;

cout<<"Would you like to enter another string?"<<endl;
getline(cin, enter);
}


return 0;
}

void changeState(State newstate){_state = newstate;}//changes state
void printState(){cout<<"Current State: "; _state == State::trap ? cout<<"Trap" : cout<<"q"<<_state;cout<<endl;}//prints state
void dump() {changeState(State::trap); accept = false;}//Assigns trap state;
