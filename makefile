CPP = g++ -O2 -Wno-deprecated
CPPDEBUG = g++ -O2 -Wno-deprecated -g



sketch_bernoulli_sampling:  zipf.o xis.o sketches.o sampling.o sketch_bernoulli_sampling.o
	$(CPP) -lgsl -lgslcblas -o sketch_bernoulli_sampling.out zipf.o xis.o sketches.o sampling.o sketch_bernoulli_sampling.o

sketch_bernoulli_sampling.o : sketch_bernoulli_sampling.cpp
	$(CPP) -c sketch_bernoulli_sampling.cpp

zipf.o : zipf.h zipf.cpp data_generator.h
	$(CPP) -c zipf.cpp

xis.o : xis.h xis.cpp gen_scheme.h range_sum.h
	$(CPP) -c xis.cpp

sketches.o : sketches.h sketches.cpp
	$(CPP) -c sketches.cpp

sampling.o : sampling.h sampling.cpp
	$(CPP) -c sampling.cpp



clean:
	rm -f *.out
	rm -f *.o
	rm -f *~

