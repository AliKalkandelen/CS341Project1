#include <iostream>
#include <string>
using namespace std;

string enter;
string input;

int main(){


cout<<"Would you like to enter a string?" <<endl;
getline(cin, enter);

while(enter == "yes" || enter == "y")
{
cout<<"whats your string?"<<endl;
getline(cin, input);
cout<<"heres your string: " << input <<endl;

cout<<"Would you like to enter another string?"<<endl;
getline(cin, enter);
}


return 0;
}
