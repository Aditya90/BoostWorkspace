CCFLAGS=\
-fno-exceptions \
-fno-rtti \
-std=gnu++14

.PHONY=all
all:
	g++ -I boost_1_72_0 ${CCFLAGS} testStdStaticVector.cpp