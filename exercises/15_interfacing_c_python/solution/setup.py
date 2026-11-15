from setuptools import setup, Extension
from Cython.Build import cythonize
import numpy


extensions = [
    Extension(
        "cmandelbrot",
        sources=["_cmandelbrot.pyx", "cmandelbrot.c"],
        include_dirs=[numpy.get_include()],
    )
]

setup(ext_modules=cythonize(extensions))
