# Makefile for 01-OverviewOfC++/programs/DirectionTest
#****************************************************************

PROGRAMS = \
    DirectionTest

ARCH ?= $(shell uname -m)
CPPOPTIONS = -IStanfordCPPLib -arch $(ARCH) -fvisibility-inlines-hidden
LDOPTIONS = -LStanfordCPPLib -arch $(ARCH)
LIB = -lStanfordCPPLib

# ***************************************************************
# Entry to bring the package up to date
#    The "make all" entry should be the first real entry

all: $(PROGRAMS)

DirectionTest: DirectionTest.o
	g++ $(LDOPTIONS) -o DirectionTest DirectionTest.o $(LIB)

DirectionTest.o: DirectionTest.cpp
	g++ $(CPPOPTIONS) -c DirectionTest.cpp


# ***************************************************************
# Standard entries to remove files from the directories
#    tidy  -- eliminate unwanted files
#    clean -- delete derived files in preparation for rebuild

tidy:
	rm -f ,* .,* *~ core a.out *.err

clean scratch: tidy
	rm -f *.o *.a $(PROGRAMS)
