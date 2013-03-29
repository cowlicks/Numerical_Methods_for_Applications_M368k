import math as m
ya  = -0.3
yb  = -0.1
h   = m.pi/4
t0  = (-0.1 + 0.3)/(m.pi/2.)
t1  = 1.1*t0

def dv(v,x,y):
    return v + 2*y + m.cos(x)
def dy(v,x,y):
    return v

def v_step(v,x,y):
    return v + h*dv(v,x,y)
def y_step(v,x,y):
    return y + h*dy(v,x,y)

def euler(t):
    v1 = v_step( t, 0., ya)
    y1 = y_step( t, 0., ya)
    print "v1 = " + str(v1)
    print "y1 = " + str(y1)
    print ""

    v2 = v_step(v1, m.pi/4, y1)
    y2 = y_step(v1, m.pi/4, y1)
    print "v2 = " + str(v2)
    print "y2 = " + str(y2)

    return y2

