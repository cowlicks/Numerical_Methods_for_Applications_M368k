#! /usr/bin/env bash
# Make it.
c++ -o program2 matrix.cpp conjgrad.cpp sor.cpp jacobi.cpp gauss_seidel.cpp program2.cpp
# Run it.
./program2
