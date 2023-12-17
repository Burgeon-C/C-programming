#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){
 char letter;
 int sum = 0;
 
 cout<<"enter digit :"<<endl;
 while ( cin>>(letter) && sum < 7 ) {
 
 if (letter != ' ' && letter >= 'a' && letter <= 'z' && letter >= 'A' && letter <= 'z') sum++;
 
 if (letter > 'Z' && letter > 'z') {letter = (int)letter-32;}
 
 if(sum == 4) {cout << "-";}

 switch (letter) {
 
 case 'a':
 case 'b':
 case 'c':
 cout << "2";
 break;
 case 'd':
 case 'e':
 case 'f':
 cout << "3";
 break;
 case 'g':
 case 'h':
 case 'i':
 cout << "4";
 break;
 case 'j':
 case 'k':
 case 'l':
 cout << "5";
 break;
 case 'm':
 case 'n':
 case 'o':
 cout << "6";
 break;
 case 'p':
 case 'q':
 case 'r':
 case 's':
 cout << "7";
 break;
 case 't':
 case 'u':
 case 'v':
 cout << "8";
 break;
 case 'w':
 case 'x':
 case 'y':
 case 'z':
 cout << "9";
 cout<<"\n";
break;
}
}