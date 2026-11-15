import time

import matplotlib
import matplotlib.pyplot as plt
import numpy as np
from numba import jit

import _mc_pi


@jit(nopython=True, parallel=False)
def estimate_pi_numba(N):
    hits = 0
    for i in range(N):
        x = np.random.rand(2)
        if x[0] * x[0] + x[1] * x[1] < 1.0:
            hits += 1
    return 4.0 * hits / N


def estimate_pi_naive(N):
    hits = 0
    for i in range(N):
        x = np.random.rand(2)
        if x[0] * x[0] + x[1] * x[1] < 1.0:
            hits += 1
    return 4.0 * hits / N


def best_time(func, N, repeats=3):
    """Best wall-clock time of `repeats` runs, in seconds."""
    times = []
    for _ in range(repeats):
        t0 = time.perf_counter()
        func(N)
        times.append(time.perf_counter() - t0)
    return min(times)


# (label, function, largest N to run); pure Python is capped because it is slow
approaches = [
    ("C (Cython wrapper)", _mc_pi.estimate_pi, 10**8),
    ("Numba", estimate_pi_numba, 10**8),
    ("Naive Python", estimate_pi_naive, 10**6),
]

Ns = [10**k for k in range(2, 9)]

# Trigger JIT compilation once so it isn't included in the timings
estimate_pi_numba(10)

results = {}
for label, func, n_max in approaches:
    ns = [N for N in Ns if N <= n_max]
    ts = []
    for N in ns:
        t = best_time(func, N)
        ts.append(t)
        print(f"{label:20s} N={N:>10d}  {t:.4e} s")
    results[label] = (ns, ts)

fig, ax = plt.subplots(figsize=(7, 5))
for label, (ns, ts) in results.items():
    ax.loglog(ns, ts, "o-", label=label)
ax.set_xlabel("N (number of samples)")
ax.set_ylabel("Time (s)")
ax.set_title("Monte Carlo pi estimation")
ax.grid(True, which="both", alpha=0.3)
ax.legend()
fig.tight_layout()
fig.savefig("benchmark_mc_pi.png", dpi=150)
print("Saved benchmark_mc_pi.png")
