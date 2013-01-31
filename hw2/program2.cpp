/*******************************************************
Program 2
Solves Ax=b using Successive Over Relaxation method.

Inputs: A, b, x^(0), w, maxIter, tol
Outputs: x^(k), iteration count k

Here's how to get started:

1) Copy this file, sor.cpp, matrix.cpp and matrix.h into your working
directory.

2) Compile (and link) the files by typing
"c++ -o program2sor matrix.cpp sor.cpp program2sor.cpp"
at the Linux prompt.

3) Type "program2sor" to run the program.

4) For any given problem, you'll need to set the 
values of the variables {n,A,b,x,w,maxIter,tol} 
below, and then compile and run as described above.

*******************************************************/
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "matrix.h"
using namespace std;


/*** Declare user-defined functions to be used ***/
int conjgrad(matrix&, matrix&, vector&, vector&, int, double);
int sor(matrix&, vector&, vector&, double, int, double);
int jacobi(matrix&, vector&, vector&, int, double);
int gauss_seidel(matrix&, vector&, vector&, int, double);

/*** Main program ***/
int main() {

  /*** Define and input problem data ***/
  int n=100, maxIter=500, iter;
  double tol=1e-5, w; 
  matrix Cinv_D(n,n), Cinv_I(n,n), A(n,n);
  vector x(n), b(n);

  /*** Constuct the data ***/
  for(float i=0; i<n; i++) {
      for(float j=0; j<n; j++) {
          if(j==i-1) {
              A(i,j)=-1;
          }
          else if(j==i) {
              A(i,j)=2+(i/10);
          }
          else if(j==i+1) {
              A(i,j)=-1;
          }
          else {
              A(i,j)=0;
          }
      }
  }
  for(float i=0; i<n; i++) {
      b(i)=1+(i/20);
  }

  x=0; //initialize  x

  /*** Construct pre-conditioning matrix D^.5 ***/
  Cinv_D=0;
  for(int i=0; i<n; i++) {
    if(A(i,i) <= 0) {
      cerr << "CG: bad data -- exiting" << endl;
      exit(EXIT_FAILURE);
    } 
    else { 
      Cinv_D(i,i) = 1/sqrt(A(i,i)); 
      // Cinv(i,i) = 1; //Use this for no pre-cond
    }
  }

  /*** Contstruct pre-conditioning matrix D = I ***/
  Cinv_I=0;
  for(int i=0; i<n; i++) {
      Cinv_I(i,i)=1;
  }

  /*** Call conjugate gradient function with Cinv = D^.5 ***/
  iter=conjgrad(Cinv_D,A,b,x,maxIter,tol);
  
  /*** Print results to screen for conjugate gradient ***/
  cout << endl; 
  cout << "Conjugate gradient with Cinv = D^.5" << endl;
  cout << "Iteration index: k = " << iter << endl;
  cout << "Approximate solution components of x^(k); x_1, ... , x_4 = " << endl;
  for(int i=0; i<4; i++) {
      cout << x(i) << endl;
  }
  cout << endl; 

  x=0; // reset x

  /*** Call jacobi function ***/
  iter=jacobi(A, b, x, maxIter, tol);

  /*** Print jacobi results ***/
  cout << endl; 
  cout << "Jacobi" << endl;
  cout << "Iteration index: k = " << iter << endl;
  cout << "Approximate solution components of x^(k); x_1, ... , x_4 = " << endl;
  for(int i=0; i<4; i++) {
      cout << x(i) << endl;
  }
  cout << endl; 

  x=0; // reset x

  /*** Call gauss_seidel function ***/
  iter=gauss_seidel(A, b, x, maxIter, tol);

  /*** Print gauss_seidel results ***/
  cout << endl; 
  cout << "Gauss Seidel" << endl;
  cout << "Iteration index: k = " << iter << endl;
  cout << "Approximate solution components of x^(k); x_1, ... , x_4 = " << endl;
  for(int i=0; i<4; i++) {
      cout << x(i) << endl;
  }
  cout << endl; 

  x=0; // reset x

  /*** Call sor function with w=1.2 ***/
  w = 1.2;
  iter=sor(A, b, x, w, maxIter, tol);

  /*** Print sor results ***/
  cout << endl; 
  cout << "SOR w = 1.2" << endl;
  cout << "Iteration index: k = " << iter << endl;
  cout << "Approximate solution components of x^(k); x_1, ... , x_4 = " << endl;
  for(int i=0; i<4; i++) {
      cout << x(i) << endl;
  }
  cout << endl; 

  x=0; // reset x

  /*** Call sor function with w=1.6 ***/
  w = 1.6;
  iter=sor(A, b, x, w, maxIter, tol);

  /*** Print sor results ***/
  cout << endl; 
  cout << "SOR w = 1.6" << endl;
  cout << "Iteration index: k = " << iter << endl;
  cout << "Approximate solution components of x^(k); x_1, ... , x_4 = " << endl;
  for(int i=0; i<4; i++) {
      cout << x(i) << endl;
  }
  cout << endl; 

  x=0; // reset x

  /*** Call sor function with w=2.3 ***/
  w = 2.3;
  iter=sor(A, b, x, w, maxIter, tol);

  /*** Print sor results ***/
  cout << endl; 
  cout << "SOR w = 2.3" << endl;
  cout << "Iteration index: k = " << iter << endl;
  cout << "Approximate solution components of x^(k); x_1, ... , x_4 = " << endl;
  for(int i=0; i<4; i++) {
      cout << x(i) << endl;
  }
  cout << endl; 

  x=0; // reset x

  /*** Call CG function with Cinv = I ***/
  iter=conjgrad(Cinv_I, A, b, x, maxIter, tol);

  /*** Print sor results ***/
  cout << endl; 
  cout << "CG with Cinv = I " << endl;
  cout << "Iteration index: k = " << iter << endl;
  cout << "Approximate solution components of x^(k); x_1, ... , x_4 = " << endl;
  for(int i=0; i<4; i++) {
      cout << x(i) << endl;
  }
  cout << endl; 

  return 0;
}
