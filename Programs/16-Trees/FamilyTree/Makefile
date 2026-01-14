# Makefile for 16-Trees/programs/FamilyTree
#****************************************************************

PROGRAMS = \
    FamilyTreeTest

ARCH = i386
CPPOPTIONS = -IStanfordCPPLib -arch $(ARCH) -fvisibility-inlines-hidden
LDOPTIONS = -LStanfordCPPLib -arch $(ARCH)
LIB = -lStanfordCPPLib

# ***************************************************************
# Entry to bring the package up to date
#    The "make all" entry should be the first real entry

all: $(PROGRAMS)

FamilyTreeTest: FamilyTreeTest.o familytree.o
	g++ $(LDOPTIONS) -o FamilyTreeTest FamilyTreeTest.o familytree.o $(LIB)

FamilyTreeTest.o: FamilyTreeTest.cpp familytree.h
	g++ $(CPPOPTIONS) -c FamilyTreeTest.cpp

familytree.o: familytree.cpp familytree.h
	g++ $(CPPOPTIONS) -c familytree.cpp


# ***************************************************************
# Standard entries to remove files from the directories
#    tidy  -- eliminate unwanted files
#    clean -- delete derived files in preparation for rebuild

tidy:
	rm -f ,* .,* *~ core a.out *.err

clean scratch: tidy
	rm -f *.o *.a $(PROGRAMS)
