/*******************************************************
Program 4.  Finds the least-squares trig poly S_n of 
specified degree n for a given set of data (x_j,y_j), 
j=0...2m-1.  It is assumed 2 <= n < m and that x_j are 
the std nodes in [-pi,pi], i.e. x_j = -pi + j*pi/m.

Inputs:  data (x_j,y_j),  j=0...2m-1
         degree n (entered at runtime)

Outputs: coeffs a_0...a_n, b_1...b_{n-1} of S_n
         error E_n associated with S_n

Note 1: This program is incomplete; you'll need to 
code the a,b-coefficients and fitting error E as 
indicated below.

Note 2: For any given problem, you'll need to set the 
value of m and specify the input file with the xy-data,
and then compile and run.
*******************************************************/
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include "matrix.h"
using namespace std;


// S_n function
double S_n(double x, vector& a, vector& b, int n) {
    double sum = 0;
    for(int k=1; k<=n-1; k++) {
        sum += a(k)*cos(k*x) + b(k-1)*sin(k*x);

    }
    sum += 0.5*a(0) + a(n)*cos(n*x);
    return sum;
}

/*** Specify name of input data file ***/
const int maxChar = 20;
const char myfile[maxChar]="program4.dat" ;


double error(int n) {

  /*** Input/read (x_j,y_j) data ***/
  int m=50;
  double pi=4.0*atan(1.0); // the number pi
  vector x(2*m), y(2*m);

  ifstream fileRead(myfile);
  for(int j=0; j<2*m; j++) {
    fileRead >> x(j) >> y(j); // read xy-pair 
  }

  /*** Compute a,b-coefficients ***/

  vector a(n+1), b(n-1);
  a = 0 ; b = 0 ; // initialize for sum

  // compute a(0) and a(n+1) first.
  for(int k=0; k<=n ; k++) {
      for(int j=0; j<=2*m-1; j++) {
          a(k) += y(j)*cos(k*x(j)) /m;
          if(k != 0 && k != n) {
              b(k-1) += y(j)*sin(k*x(j)) /m;
          }
      }
  }

  /*** Compute least-squares fitting error ***/
  double E = 0;

  for(int i=0; i<dim(x); i++) {
      E += pow((y(i) - S_n(x(i), a, b, n)),2);
  }
  
  return E;
}

int main() {
    double E;
    double Eold;
    double Echange;
    for(int n=2; n<40; n++) {
        E = error(n);
        if(n > 2) {
            cout << "E = " << E << endl;
            cout << "Eold = " << Eold << endl;
            Echange = fabs(E - Eold)/Eold;
            cout << "Echange = " << Echange << endl;
            if( Echange <  0.05) {
                cout << n << endl;
                break;
            }
        }
        Eold = E;
    }
}

