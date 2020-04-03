#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

using namespace std;

#define EPSILON 0.01

//example function: x^3(x+sin(x^2-1)-1)-1 
double fun1(double x) {
  return x * x * x * (x + sin(x * x - 1) - 1) - 1;
}
//example function: x^3 +2x
double fun2(double x) {
    return x*x*x + 2*x;
}
//implementation of the bisection method for finding roots
void bisection(double a, double b, double (*f)(double)) {
    double x0,fa,fb,f0;
    fa = f(a);
    fb = f(b);
    if(fa * fb > 0)    
    cout << "incorrect values for a, b" << endl;
    else
    {
      while(fabs(a - b) > EPSILON)
      {
          x0 = (a+b)/2;
          f0 = f(x0);
          if(fabs(f0) < EPSILON) break;
          if(fa * f0 < 0)
              b = x0;
          else {
              a = x0;
              fa = f0;
          }
      }
      cout << "x_0 = " << x0 << endl;
    }
}

int main()
{
  double a,b;
  cout << "a: ";    
      cin >> a;
  cout << "b: ";
      cin >> b;

  bisection(a,b,fun2);

  return 0;
} 