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
