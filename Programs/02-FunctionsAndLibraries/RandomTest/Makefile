# Makefile for 02-FunctionsAndLibraries/programs/RandomTest
#****************************************************************

PROGRAMS = \
    RandomTest

ARCH = i386
CPPOPTIONS = -IStanfordCPPLib -arch $(ARCH) -fvisibility-inlines-hidden
LDOPTIONS = -LStanfordCPPLib -arch $(ARCH)
LIB = -lStanfordCPPLib

# ***************************************************************
# Entry to bring the package up to date
#    The "make all" entry should be the first real entry

all: $(PROGRAMS)

RandomTest: RandomTest.o random.o
	g++ $(LDOPTIONS) -o RandomTest RandomTest.o random.o $(LIB)

RandomTest.o: RandomTest.cpp random.h
	g++ $(CPPOPTIONS) -c RandomTest.cpp

random.o: random.cpp random.h
	g++ $(CPPOPTIONS) -c random.cpp


# ***************************************************************
# Standard entries to remove files from the directories
#    tidy  -- eliminate unwanted files
#    clean -- delete derived files in preparation for rebuild

tidy:
	rm -f ,* .,* *~ core a.out *.err

clean scratch: tidy
	rm -f *.o *.a $(PROGRAMS)
