#include "header.h"

void rpy::display()
{
    cout << x << "\t" << y << "\t" << z << "\t";
} 

double rpy::getvalue(string s) {
    if (s == "x")
      return x;
    else if (s == "y")
      return y;
    else if (s == "z")
      return z;
}   

void Light::display()
 { 
    cout << intensity<<endl; 
    }   
