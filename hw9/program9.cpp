/*******************************************************
Program 9. Uses the Newton-RK4 shooting method to find 
an approximate solution of a two-point BVP of the form

              y'' = f(x,y,y'),  a<=x<=b  
              y(a) = alpha,  y(b) = beta

Inputs:  
  feval         Function to evaluate f(x,y,y')
  a,b           Interval params
  alpha,beta    Boundary value params
  t             Initial guess for y'(a)
  N             Number of grid points for RK4
  maxIter,tol   Control params for Newton

Outputs: 
  iter    Number of Newton steps taken
  t       Approx value of y'(a) 
  x       Grid point vector: x(j)=a+jh, j=0...N
  y       Approx soln vector: y(j)=soln at x(j), j=0...N

Note 1: For any given problem, the function feval must 
be changed.  This function computes f for any given x, y 
and y'.  (Below we use the symbol yp in place of y').

Note 2: For any given problem the parameters a, b, alpha,
beta, t, N, maxIter and tol must also be specified.

Note 3: To compile this program use the command (all on 
one line)

  c++ -o program9  matrix.cpp shootRK4.cpp program9.cpp

*******************************************************/
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <math.h>
#include "matrix.h"
using namespace std;

/*** Declare external function ***/
int shootRK4(int&, double&, double&, double&, double&, 
                double&, int&, double&, vector&, vector&) ;


/*** Define f(x,y,yp) function ***/
void feval(const double& x, const double& y, 
                              const double& yp, double& f){
  double M=0.2, L=1.3, R=-0.6 ; //define any constants
  double pi=4.0*atan(1.0) ; //the number pi
  double p, q, u, v, w ;

  p = -2*(x-1)*exp(-pow(x+1,2) - pow(y+1,2)) - (x-1)*exp(-pow(x-1,2) - pow(y-1,2)) ;
  q = -2*(y-1)*exp(-pow(x+1,2) - pow(y+1,2)) - (y-1)*exp(-pow(x-1,2) - pow(y-1,2)) ;
  u = -2*exp(-pow(x+1,2) - pow(y+1,2)) + 4*pow(x-1,2)*exp(-pow(x+1,2) - pow(y+1,2)) - exp(-pow(x-1, 2) - pow(y-1, 2)) + 2*pow(x-1,2) * exp(-pow(x-1,2) - pow(y-1,2)) ;
  v = 4*(x+1)*(y+1)*exp(-pow(x+1,2) - pow(y+1,2)) + (x-1)*(y-1)*exp(-pow(x-1,2) - pow(y-1,2)) ;
  w = -2*exp(-pow(x+1,2) - pow(y+1,2)) + 4*pow(y-1,2)*exp(-pow(x+1,2) - pow(y+1,2)) - exp(-pow(x-1, 2) - pow(y-1, 2)) + 2*pow(y-1,2) * exp(-pow(x-1,2) - pow(y-1,2)) ;

  f = (p*yp - q)*(u + 2*v*yp + w*yp*yp) / (1 + pow(p, 2) + pow(q, 2)) ;
}

double zeval(double x, double y) {
    double z ;
    z = exp(-pow(x+1,2)-pow(y+1,2)) + .5*exp(-pow(x-1,2)-pow(y-1,2)) ;
    return z ;
}

double pathLength(vector x, vector y) {
    int N = 20; // Vector length
    double sum = 0 ;
    for(int i=1; i<N+1; i++){
        sum += sqrt((x(i)-x(i-1))*(x(i)-x(i-1)) + (y(i)-y(i-1))*(y(i)-y(i-1)) + pow((zeval(x(i), y(i))-zeval(x(i-1), y(i-1))),2)) ;
    }
    return sum ;
}


int main() {
  /*** Define problem parameters ***/
  double tol=1e-6 ;
  int N=20, maxIter=200, iter ;  
  double a=-3.0, b=3.0, alpha=-2.0, beta=2.0, t , dist ;
  vector x(N+1), y(N+1) ; 
  t=0.7499 ; // initial guess of slope 

  /*** Call Newton-RK4 method ***/
  cout << setprecision(8) ;
  iter=shootRK4(N,a,b,alpha,beta,t,maxIter,tol,x,y) ;

  dist=pathLength(x, y) ;  
  
  /*** Print results to screen ***/
  cout << setprecision(4) ;
  cout << "Pathlength: " << dist << endl ;
  cout << endl ;
  cout << "Number of Newton iterations: " << iter << endl ;
  cout << "Approx solution: t = " << t << endl ;
  cout << "Approx solution: x_j, y_j =  " << endl ;
  for(int j=0; j<N+1; j++){
    cout << "x =" << setw(6) << x(j) ;
    cout << "   " ;
    cout << "y =" << setw(10) << y(j) ;
    cout << "   " ; 
    cout << endl;
  }

  return 0 ; //terminate main program
}

