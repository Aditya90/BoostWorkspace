CCFLAGS=\
-fno-exceptions \
-fno-rtti \
-std=gnu++14

BOOST_DIR=boost_1_72_0

.PHONY=all
all:
	g++ -I ${BOOST_DIR} ${CCFLAGS} testStdStaticVector.cpp