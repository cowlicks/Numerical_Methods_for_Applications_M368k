#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "matrix.h"
using namespace std;


int sympower(matrix& A, vector& x, double& lambda, 
                          int n, int maxIter, double tol) {
  
  int iter=0, pindex ;
  double error=1, ynorm ;
  vector y(n), r(n) ;

  x = scaleVec(1/vecL2Norm(x), x);
  while(iter<maxIter && error>=tol) {
      
      y = matVecMult(A,x);
      lambda = vecDot(x,y);
      if(vecL2Norm(y) == 0) {
          cout << "Eigenvector x = " << x << endl;
          cout << "A has a zero eigenvalue, select a new vector x" << endl;
      }
      error = vecL2Norm(x - scaleVec( 1/vecL2Norm(y), y));
      x = scaleVec(1/vecL2Norm(y), y);
      iter++;
  }

  if(error < tol) {
    cout << "Sym power: soln converged, |r|_inf = " << error << endl;
  }
  else {
    cout << "Sym power: max iterations exceeded" << endl;
  }
  return iter;
}
