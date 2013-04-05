# Programming mini project

The shortest path over the terrain must satisfy:

    y'' = (py' - q)(u + 2vy' + wy'y') / (1 + p**2 + q**2) 

* `p = z_x`
* `q = z_y`
* `u = z_xx`
* `v = z_xy`
* `w = z_yy`


## part (a)

## part (b)

 consider the terrain described by:
    
    z = Ax + By + C

which gives:
* `p = A`
* `q = B`
* `u = 0`
* `v = 0`
* `w = 0`

Plugging this into the Euler-Lagrange equation we get:

    y'' = (Ay' - B)*( 0 ) / (1 + A**2 + B**2) = 0

This implies `y' = c1` & `y = c1*x + c2`

## part (c)

consider the terrain:

    z = exp(-(x+1)**2 - (y+1)**2) + 0.5*exp(-(x-1)**2 - (y-1)**2)


which gives:
* `p = -2*(x+1)*exp(-(x+1)**2 - (y+1)**2) - (x-1)*exp(-(x-1)**2 - (y-1)**2)`
* `q = -2*(y+1)*exp(-(x+1)**2 - (y+1)**2) - (y-1)*exp(-(x-1)**2 - (y-1)**2)`
* `u = -2*exp(-(x+1)**2 - (y+1)**2) + 4*(x+1)**2 * exp(-(x+1)**2 - (y-1)**2) - exp(-(x-1)**2 - (y-1)**2) + 2*(x-1)**2 * exp(-(x-1)**2 - (y-1)**2)`
* `v = 4*(x+1)*(y+1)*exp(-(x+1)**2 - (y+1)**2) + 2*(x-1)*(y-1)*exp(-(x-1)**2 - (y-1)**2)`
* `w = -2*exp(-(x+1)**2 - (y+1)**2) + 4*(y+1)**2 * exp(-(x+1)**2 - (y-1)**2) - exp(-(x-1)**2 - (y-1)**2) + 2*(y-1)**2 * exp(-(x-1)**2 - (y-1)**2)`

## Path 0
Output:

    Newton-RK4: initial t = 0.7499
    Newton-RK4: |F| = 0.039169904
    Newton-RK4: |F| = 0.00041358139
    Newton-RK4: |F| = 1.1555126e-06
    Newton-RK4: |F| = 3.4177909e-09
    Newton-RK4: soln converged

    Pathlength: 7.23

    Number of Newton iterations: 3
    Approx solution: t = 0.7499
    Approx solution: x_j, y_j =  
    x =    -3   y =        -2   
    x =  -2.7   y =    -1.775   
    x =  -2.4   y =     -1.55   
    x =  -2.1   y =    -1.325   
    x =  -1.8   y =      -1.1   
    x =  -1.5   y =   -0.8767   
    x =  -1.2   y =   -0.6556   
    x =  -0.9   y =   -0.4411   
    x =  -0.6   y =   -0.2404   
    x =  -0.3   y =  -0.06118   
    x =-3.331e-16   y =   0.09731   
    x =   0.3   y =    0.2436   
    x =   0.6   y =    0.3844   
    x =   0.9   y =    0.5303   
    x =   1.2   y =    0.6975   
    x =   1.5   y =     0.897   
    x =   1.8   y =     1.118   
    x =   2.1   y =     1.342   
    x =   2.4   y =     1.563   
    x =   2.7   y =     1.782   
    x =     3   y =         2   

## Path 1
Output:

    Newton-RK4: initial t = 0.9622
    Newton-RK4: |F| = 15.855098
    Newton-RK4: |F| = 0.060912889
    Newton-RK4: |F| = 0.012256896
    Newton-RK4: |F| = 0.0023936383
    Newton-RK4: |F| = 0.00047023003
    Newton-RK4: |F| = 9.226944e-05
    Newton-RK4: |F| = 1.8109425e-05
    Newton-RK4: |F| = 3.5541277e-06
    Newton-RK4: |F| = 6.9752418e-07
    Newton-RK4: soln converged

    Pathlength: 10.05

    Number of Newton iterations: 8
    Approx solution: t = 0.9622
    Approx solution: x_j, y_j =  
    x =    -3   y =        -2   
    x =  -2.7   y =     -1.71   
    x =  -2.4   y =    -1.396   
    x =  -2.1   y =   -0.7811   
    x =  -1.8   y =     2.849   
    x =  -1.5   y =     2.798   
    x =  -1.2   y =     2.747   
    x =  -0.9   y =     2.696   
    x =  -0.6   y =     2.645   
    x =  -0.3   y =     2.595   
    x =-3.331e-16   y =     2.544   
    x =   0.3   y =     2.493   
    x =   0.6   y =     2.443   
    x =   0.9   y =     2.392   
    x =   1.2   y =     2.339   
    x =   1.5   y =     2.284   
    x =   1.8   y =     2.227   
    x =   2.1   y =     2.169   
    x =   2.4   y =     2.112   
    x =   2.7   y =     2.056   
    x =     3   y =         2   
