/*******************************************************
Program 8.  Uses the steepest descent method to find a 
local minimum of a function g(x).

Inputs:  
  geval    Function to evaluate g(x), scalar
  dgeval   Function to evaluate dg/dx(x), n vector
  x        Initial guess for x, n vector  
  maxIter  Maximum number of descent iterations
  tol      Tolerance parameter for ||dg/dx||

  a0       Initial guess for alpha (step size)
  maxSrch  Maximum number of alpha search steps


Outputs: 
  x        Approx local minimum point of g(x)
  g        Approx value of g(x) at local min
  k        Number of descent steps taken


Note 1: For any given problem the functions geval and
dgeval must be changed.  These functions compute the
scalar g and vector dg for any given x.

Note 2: The function file descent.cpp is incomplete; 
you'll need to code the quadratic interpolation step
as indicated in that file.

Note 3: To compile this program use the command (all 
on one line)

  c++ -o program8 matrix.cpp descent.cpp program8.cpp

*******************************************************/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include "matrix.h"
using namespace std ;


/*** Declare function with steepest descent algorithm ***/
int descent(vector&, int, int, double, int, double) ;


/*** Define g function for problem ***/
void geval(vector& x, double& g){
  double r, t, y, z ;
  double a=1, b=1.5, L=0.7 ; //define any constants
  r = x(0) ;
  t = x(1) ;

  y = pow(L*cos(t),2) + pow(r - L*sin(t),2) ;
  z = pow(L*cos(t),2) + pow(r + L*sin(t),2) ;

  g = pow(a/y,2) - 2*a/y + pow(b/z,2) - 2*b/z ;
}


/*** Define dg function (gradient) for problem ***/
void dgeval(vector& x, vector& dg){
  double r, t, y, z, dydr, dzdr, dydt, dzdt;
  double a=1, b=1.5, L=0.7 ; //define any constants
  r = x(0) ;
  t = x(1) ;

  y = pow(L*cos(t),2) + pow(r - L*sin(t),2) ;
  z = pow(L*cos(t),2) + pow(r + L*sin(t),2) ;
  
  dydr = 2*(r - L*sin(t)) ;
  dzdr = 2*(r + L*sin(t)) ;
  dydt = -2*L*L*cos(t)*sin(t) + 2*(r - L*sin(t))*(-L*cos(t)) ;
  dzdt = -2*L*L*cos(t)*sin(t) + 2*(r + L*sin(t))*(L*cos(t)) ;

  dg(0) =  -2*a*a*dydr/pow(y, 3) + 2*a*dydr/pow(y, 2) - 
            2*b*b*dzdr/pow(z, 3) + 2*b*dzdr/pow(z, 2) ;
  dg(1) =  -2*a*a*dydt/pow(y, 3) + 2*a*dydt/pow(y, 2) - 
            2*b*b*dzdr/pow(z, 3) + 2*b*dzdr/pow(z, 2) ;
}


int main() {
  /*** Define problem parameters ***/
  int n=2, maxIter=100, iter=0, maxSrch=20 ;
  double tol=1e-6, a0=0.2, g ;
  vector x(n) ;
  x(0) = 3.0 ; x(1) = 1.0 ; //initial guess

  /*** Print problem info ***/
  cout << setprecision(10) ;
  cout << endl ;
  cout << "System size: n = " << n << endl ;
  cout << "Initial guess: x^(0) = " << endl ;
  cout << x << endl ;

  /*** Call steepest descent w/initial guess***/
  iter = descent(x,n,maxIter,tol,maxSrch,a0) ;

  /*** Print results to screen ***/
  geval(x,g) ;
  cout << endl ;
  cout << "Iteration index: k = " << iter << endl ;
  cout << endl ;
  cout << "Approx solution: x = " << endl ;
  cout << x << endl ;
  cout << "Approx g-value: g = " << g << endl ;

  return 0; //terminate main program
}

