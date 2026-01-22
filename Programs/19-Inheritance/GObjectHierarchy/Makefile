# Makefile for 19-Inheritance/programs/GObjectHierarchy
#****************************************************************

PROGRAMS = \
    TestGObjects

ARCH = i386
CPPOPTIONS = -IStanfordCPPLib -arch $(ARCH) -fvisibility-inlines-hidden
LDOPTIONS = -LStanfordCPPLib -arch $(ARCH)
LIB = -lStanfordCPPLib

# ***************************************************************
# Entry to bring the package up to date
#    The "make all" entry should be the first real entry

all: $(PROGRAMS)

TestGObjects: TestGObjects.o gobjects.o
	g++ $(LDOPTIONS) -o TestGObjects TestGObjects.o gobjects.o $(LIB)

TestGObjects.o: TestGObjects.cpp gobjects.h
	g++ $(CPPOPTIONS) -c TestGObjects.cpp

gobjects.o: gobjects.cpp gobjects.h
	g++ $(CPPOPTIONS) -c gobjects.cpp


# ***************************************************************
# Standard entries to remove files from the directories
#    tidy  -- eliminate unwanted files
#    clean -- delete derived files in preparation for rebuild

tidy:
	rm -f ,* .,* *~ core a.out *.err

clean scratch: tidy
	rm -f *.o *.a $(PROGRAMS)
