# Makefile for 19-Inheritance/programs/DisplayListUsingVector
#****************************************************************

PROGRAMS = \
    TestDisplayList

ARCH = i386
CPPOPTIONS = -IStanfordCPPLib -arch $(ARCH) -fvisibility-inlines-hidden
LDOPTIONS = -LStanfordCPPLib -arch $(ARCH)
LIB = -lStanfordCPPLib

# ***************************************************************
# Entry to bring the package up to date
#    The "make all" entry should be the first real entry

all: $(PROGRAMS)

TestDisplayList: TestDisplayList.o gobjects.o
	g++ $(LDOPTIONS) -o TestDisplayList TestDisplayList.o gobjects.o $(LIB)

TestDisplayList.o: TestDisplayList.cpp gobjects.h
	g++ $(CPPOPTIONS) -c TestDisplayList.cpp

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
