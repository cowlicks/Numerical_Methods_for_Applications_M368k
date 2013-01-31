/*******************************************************************
Function to solve Ax=b using the Succesive over 
relaxation method.  A is assumed to be symmetric, pos-definite.

Inputs: matrix A(n,n), vector b(n), vector x(n),
        integer maxIter, double tol.

Outputs: vector x(n), integer iter (returned)
********************************************************************/
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "matrix.h"
using namespace std;


int sor(matrix& A, vector& b, vector& x, double w, int maxIter, 
                                                   double tol) {
  
  /*** Implement algo ***/
  int iter;
  int n = dim(A,0);
  double error, sumk, sumkold;
  vector xold(n), r(n);

  xold = 0;
  iter = 0;
  r = b - matVecMult(A,x);
  error = vecMaxNorm(r);

  while(iter<maxIter && error>=tol) {
      for(int i=0; i<n; i++) {
          sumk = 0;
          sumkold = 0;
          for(int j=0; j<i; j++) {
              sumk += A(i,j)*x(j);
          }
          for(int j=i+1; j<n; j++) {
              sumkold += A(i,j)*xold(j);
          }
          x(i) = (1-w)*xold(i) + (w/A(i,i))*(b(i) - sumkold - sumk);
      }
      r = b - matVecMult(A,x);
      error = vecMaxNorm(r);
      xold = x;
      iter++;
  }         

  /*** Print exit message to screen ***/
  if(error<tol) {
    cout << "SOR: solution converged, |r|_inf = " << error << endl;
  }
  else {
    cout << "SOR: max iterations exceeded" << endl;
  }

  return iter;
}
