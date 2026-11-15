from setuptools import setup, Extension
from Cython.Build import cythonize


extensions = [
    Extension(
        "_mc_pi",
        sources=["_mc_pi.pyx", "mc_pi.c"],
    )
]

setup(ext_modules=cythonize(extensions))
