# Makefile for 18-Graphs/programs/GraphClass
#****************************************************************

PROGRAMS = \
    GraphTest

ARCH = i386
CPPOPTIONS = -IStanfordCPPLib -arch $(ARCH) -fvisibility-inlines-hidden
LDOPTIONS = -LStanfordCPPLib -arch $(ARCH)
LIB = -lStanfordCPPLib

# ***************************************************************
# Entry to bring the package up to date
#    The "make all" entry should be the first real entry

all: $(PROGRAMS)

GraphTest: GraphTest.o cmdscan.o path.o
	g++ $(LDOPTIONS) -o GraphTest GraphTest.o cmdscan.o path.o $(LIB)

GraphTest.o: GraphTest.cpp cmdscan.h graph.h graphtypes.h path.h
	g++ $(CPPOPTIONS) -c GraphTest.cpp

cmdscan.o: cmdscan.cpp cmdscan.h
	g++ $(CPPOPTIONS) -c cmdscan.cpp

dfsbfs.o: dfsbfs.cpp
	g++ $(CPPOPTIONS) -c dfsbfs.cpp

path.o: path.cpp graphtypes.h path.h
	g++ $(CPPOPTIONS) -c path.cpp


# ***************************************************************
# Standard entries to remove files from the directories
#    tidy  -- eliminate unwanted files
#    clean -- delete derived files in preparation for rebuild

tidy:
	rm -f ,* .,* *~ core a.out *.err

clean scratch: tidy
	rm -f *.o *.a $(PROGRAMS)
