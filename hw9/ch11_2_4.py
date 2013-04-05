a   = 1.
b   = 2.
ya  = .5
yb  = 1./3.
h   = .5
t0  = (yb - ya)/(2. - 1.)
t1  = 1.1*t0

def dv(v,x,y):
    return y**3 - y*v
def dy(v,x,y):
    return v

def v_step(v,x,y):
    return v + h*dv(v,x,y)
def y_step(v,x,y):
    return v

def euler(t):
    v1 = v_step(t, a, ya)
    y1 = y_step(t, a, ya)
    print "v1 = " + str(v1)
    print "y1 = " + str(y1)

    v2 = v_step(v1, a + h, y1)
    y2 = y_step(v1, a + h, y1)
    print "v2 = " + str(v2)
    print "y2 = " + str(y2)

    return y2
