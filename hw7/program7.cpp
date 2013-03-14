/*******************************************************
Program 7.  Uses the Newton method to solve a general
system of equations
                        F(x) = 0.

Inputs:  
  Feval    Function to evaluate F(x), n vector 
  DFeval   Function to evaluate dF/dx(x), nxn matrix
  x        Initial guess, n vector  
  maxIter  Maximum number of iterations
  tol      Tolerance parameter

Outputs: 
  x        Approx soln of F(x)=0, n vector
  iter     Number of Newton steps taken

Note 1: For any given problem the functions Feval and
DFeval must be changed.  These functions compute the
vector F and matrix DF for any given x.

Note 2: To compile this program use the command 
(all on one line)

c++ -o program7 matrix.cpp gauss_elim.cpp 
                                newton.cpp program7.cpp

*******************************************************/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include "matrix.h"
using namespace std ;


/*** Declare function with Newton algorithm ***/
int newton(vector&, int, int, double) ;


/*** Define F function for problem ***/
void Feval(vector& x, vector& F){
  double a=3.0, b=1.5, c=1.0, d=2.0, h=3.5, r=2.5 ; //define any constants
  double pi=4.0*atan(1.0) ; //the number pi

  F(0) = pow(x(2),2) / pow(a,2) + pow(x(3), 2) / pow(b,2) - 1.0 ; 
  F(1) = pow(x(4),2) / pow(c,2) + pow(x(5) + h,2) / pow(d,2) ;
  F(2) = pow(x(2) - x(0),2) + pow(x(3) - x(1),2) - pow(r,2) ;
  F(3) = pow(x(4) - x(0),2) + pow(x(5) - x(1),2) - pow(r,2) ;
  F(4) = x(2)*(x(3) - x(1))*pow(b,2) - x(3)*(x(2) - x(0))*pow(a,2) ;
  F(5) = x(4)*(x(5) - x(1))*pow(d,2) - (x(5) + h)*(x(4) - x(0))*pow(c,2) ;
}

/*** Define DF function (Jacobian) for problem ***/
void DFeval(vector& x, matrix& DF){
  double a=3.0, b=1.5, c=1.0, d=2.0, h=3.5, r=2.5 ; //define any constants
  double pi=4.0*atan(1.0) ; //the number pi

  DF(0,0) = 0 ;
  DF(0,1) = 0 ;
  DF(0,2) = 2*x(2)/pow(a,2) ;
  DF(0,3) = 2*x(3)/pow(b,2) ;
  DF(0,4) = 0 ;
  DF(0,5) = 0 ;

  DF(1,0) = 0 ;
  DF(1,1) = 0 ;
  DF(1,2) = 0 ;
  DF(1,3) = 0 ;
  DF(1,4) = 2*x(4)/pow(c,2) ;
  DF(1,5) = 2*(x(5) + h)/pow(d,2) ;

  DF(2,0) = 2*(x(2) - x(0)) ;
  DF(2,1) = 2*(x(3) - x(1)) ; 
  DF(2,2) = 2*(x(2) - x(0)) ; 
  DF(2,3) = 2*(x(3) - x(1)) ; 
  DF(2,4) = 0 ;
  DF(2,5) = 0 ;

  DF(3,0) = 2*(x(4) - x(0)) ;
  DF(3,1) = 2*(x(5) - x(1)) ;
  DF(3,2) = 0 ;
  DF(3,3) = 0 ;
  DF(3,4) = 2*(x(4) - x(0)) ;
  DF(3,5) = 2*(x(5) - x(1)) ;

  DF(4,0) = x(3)*pow(a,2) ;
  DF(4,1) = -x(2)*pow(b,2) ;
  DF(4,2) = (x(3) - x(1))*pow(b,2) - x(3)*pow(a,2) ;
  DF(4,3) = x(2)*pow(b,2) - (x(2) - x(0))*pow(a,2) ;
  DF(4,4) = 0 ;
  DF(4,5) = 0 ;

  DF(5,0) = (x(5) + h)*pow(c,2) ;
  DF(5,1) = -x(4)*pow(d,2) ;
  DF(5,2) = 0 ;
  DF(5,3) = 0 ;
  DF(5,4) = (x(5) - x(1))*pow(d,2) - (x(5) + h)*pow(c,2) ;
  DF(5,5) = x(4)*pow(d,2) - (x(4) - x(0))*pow(c,2) ;
}


int main() {
  /*** Define problem parameters ***/
  int n=6, maxIter=10, iter=0 ;  
  double tol=1e-6 ;
  vector x(n) ;
  x(0) = 2.5 ; // ~ One radii right of origin.
  x(1) = -2.5 ; // ~ One radii beneath origin.
  x(2) = 2.5 ; // ~ One r right of origin.
  x(3) = -0.5 ; // almost at axis.
  x(4) = 0.5 ; // " " "
  x(5) = -3.0 ; // One radii beneath origin.

  /*** Print problem info ***/
  cout << setprecision(10) ;
  cout << endl ;
  cout << "System size: n = " << n << endl ;
  cout << "Initial guess: x^(0) = " << endl ;
  cout << x << endl ;

  /*** Call Newton w/initial guess***/
  iter = newton(x,n,maxIter,tol) ;

  /*** Print results to screen ***/
  cout << endl ;
  cout << "Iteration index: k = " << iter << endl ;
  cout << "Approx solution: x = " << endl ;
  cout << x << endl ;
 
  return 0; //terminate main program
}
