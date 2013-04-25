# Programming mini project.

##(b)

    for dx = dy = 1/10, dt = 1/20
    u(0.6, 0.6, 5) = 0.95370

    for dx = dy = 1/15, dt = 1/25
    u(0.6, 0.6, 5) = 0.95438

    for dx = dy = 1/20, dt = 1/30
    u(0.6, 0.6, 5) = -1761348060742576552087612555264.0000

The last grid does not converge because of spurious growth, because 
the `dt` is not small enough. If we decreased `dt` further, we would see:

    for dx = dy = 1/20, dt = 1/100
    u(0.6, 0.6, 5) = 0.95447

##(c)

for `dx = dy = 1/15, dt = 1/25` we compute Uavg at:

    T = .5, Uavg = 0.991799386056
    T = 3,  Uavg = 0.964031685744
    T = 10, Uavg = 0.935708834547
    T = 20, Uavg = 0.92489508845
    T = 40, Uavg = 0.922111040583

The concentration at T = 0.5
![T = 0.5](plot-5.png)

The concentration at T = 3
![T = 3](plot3.png)

The concentration at T = 40
![T = 40](plot40.png)

