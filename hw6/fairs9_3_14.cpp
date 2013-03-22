/*******************************************************
*******************************************************/
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include "matrix.h"
using namespace std;


/*** Specify name of input data file ***/
const int maxChar = 20;
const char myfile[maxChar]="fairs9_3_14.dat" ;


/*** Declare user-defined functions to be used ***/
int genpower(matrix&, vector&, double&, int, int, double) ;


int main() {
  matrix A(3,3) ;
  /***A ***/
  A(0,0)=-2.66505636;   A(0,1)=0;   A(0,2)=1;
  A(1,0)=-18.12238325;  A(1,1)=3;   A(1,2)=3;
  A(2,0)=-15.10305958;  A(2,1)=3;   A(2,2)=2;
  
  /*** Print and A to screen ***/
  cout << "***Results for A***" << endl;
  cout << endl;
  cout << "Covariance matrix A = " << endl;
  cout << A << endl;

  /*** Parameters for power method ***/
  int maxIter=35, iter;  
  double tol=1e-4, lambda; 
  vector x(3);

  x=1; //initial vec
  if(matMaxNorm(A)==0) {A=1;} //reset A if zero

  /*** Print data to screen ***/
  cout << "***Results for power method***" << endl;
  cout << endl; 
  cout << "Given: A = " << endl;
  cout << A << endl;
  cout << "Given: x^(0) = " << endl;
  cout << x << endl;

  /*** Call general power function ***/
  iter=genpower(A,x,lambda, 3, maxIter,tol);
  
  /*** Print results to screen ***/
  cout << "Iteration index: k = " << iter << endl;
  cout << "Approximate eigval: lambda^(k) = " << lambda << endl;
  cout << "Approximate eigvec: x^(k) = " << endl;
  cout << x << endl ;

  return 0; //terminate main program
}

