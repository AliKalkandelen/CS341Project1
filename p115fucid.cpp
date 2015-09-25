#include <iostream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <ctype.h>

using namespace std;

string enter;
string input;

enum State {q0,q1,q2,q3,q4,q5,q6,q7,q8,q9,q10,F,err};

State _state;

void changeState(State newstate){_state = newstate;}
void printState(){cout<<"Current State: q"<< _state <<endl;}
void dump() {changeState(State::err);}


int main(){


cout<<"Would you like to enter a string?" <<endl;
getline(cin, enter);if(enter=="no"||enter=="n")cout<<"Then why you here? lol";
while(enter == "yes" || enter == "y")
{
cout<<"Okay Whats your string?"<<endl;
getline(cin, input);
cout<<endl<<"Okay Here Is Your Report: "<<endl;
_state = State::q0;
printState();
for(int i=0; i < input.length(); i++)
{

    cout<<"Character: "<<input[i]<<" ";
    switch(_state)
    {
    case State::q0:
        if (input[i] == 'w')
            changeState(State::q1);
        else dump();
            break;

    case State::q1:
        if (input[i] == 'w')
            changeState(State::q2);
        else dump();
            break;

    case State::q2:
        if (input[i] == 'w')
            changeState(State::q3);
        else dump();
            break;

    case State::q3:
        if (input[i] == '.')
            changeState(State::q4);
        else dump();
            break;

    case State::q4:
        if(input[i] == '.')
            changeState(State::q5);
        else if(!isalpha(input[i]) || isupper(input[i]))
            dump();
     break;
    case State::q5:
        if (input[i] == 'c')
            changeState(State::q6);
        else dump();
            break;
    case State::q6:
        if (input[i] == 'o')
            changeState(State::q7);
        else dump();
            break;
    case State::q7:
        if (input[i] == 'm')
            changeState(State::q8);
        else dump();
            break;

    }
    printState();
}

cout<<endl<<"Would you like to enter another string?"<<endl;
getline(cin, enter);
}


return 0;
}

