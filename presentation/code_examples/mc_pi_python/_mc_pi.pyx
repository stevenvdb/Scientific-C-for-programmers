""" Example of wrapping a C function"""

cdef extern from "mc_pi.h":
    double c_estimate_pi "estimate_pi"(unsigned long N)

def estimate_pi(unsigned long N):
    return c_estimate_pi(N)
