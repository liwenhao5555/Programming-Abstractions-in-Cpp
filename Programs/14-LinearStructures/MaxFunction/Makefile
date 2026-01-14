# Makefile for 14-LinearStructures/programs/MaxFunction
#****************************************************************

PROGRAMS = \
    TestMax

ARCH = i386
CPPOPTIONS = -IStanfordCPPLib -arch $(ARCH) -fvisibility-inlines-hidden
LDOPTIONS = -LStanfordCPPLib -arch $(ARCH)
LIB = -lStanfordCPPLib

# ***************************************************************
# Entry to bring the package up to date
#    The "make all" entry should be the first real entry

all: $(PROGRAMS)

TestMax: TestMax.o rational.o
	g++ $(LDOPTIONS) -o TestMax TestMax.o rational.o $(LIB)

TestMax.o: TestMax.cpp rational.h
	g++ $(CPPOPTIONS) -c TestMax.cpp

rational.o: rational.cpp rational.h
	g++ $(CPPOPTIONS) -c rational.cpp


# ***************************************************************
# Standard entries to remove files from the directories
#    tidy  -- eliminate unwanted files
#    clean -- delete derived files in preparation for rebuild

tidy:
	rm -f ,* .,* *~ core a.out *.err

clean scratch: tidy
	rm -f *.o *.a $(PROGRAMS)
