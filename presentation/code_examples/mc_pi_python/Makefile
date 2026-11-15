.PHONY: all run clean

all:
	python3 setup.py build_ext -i

run: all
	python3 benchmark_mc_pi.py

clean:
	rm -rf build __pycache__ *.so _mc_pi.c
