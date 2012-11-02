
GTEST = ~/workspace/gtest-1.6.0/make/gtest_main.a
PARAMS = ~/workspace/gtest-1.6.0/make/gtest_main.a -I.. -I../config/ -I../utils/ -I../classifiers/ -lpthread -lpython2.6

CONFIG = ../config
UTILS = ../utils

test: test.cpp config.o feature.o utils.o dom.o transcoder.o
	g++ -o test test.cpp feature.o config.o utils.o dom.o transcoder.o $(PARAMS)

config.o: $(CONFIG)/config.h $(CONFIG)/config.cpp
	g++ -c $(CONFIG)/config.cpp $(PARAMS)

utils.o: $(UTILS)/utils.h $(UTILS)/utils.cpp $(UTILS)/dom_tree.h $(UTILS)/dom_tree.cpp
	g++ -c $(UTILS)/utils.cpp $(UTILS)/dom_tree.cpp $(PARAMS)

dom.o: $(UTILS)/dom_tree.h $(UTILS)/dom_tree.cpp
	g++ -o dom.o -c $(UTILS)/dom_tree.cpp $(PARAMS)

feature.o: features.h feature_repository.cpp feature_repository.h
	g++ -o feature.o -c feature_repository.cpp $(PARAMS)

transcoder.o: transcoder.h transcoder.cpp
	g++ -c transcoder.cpp $(PARAMS)

clean:
	rm *.o test
