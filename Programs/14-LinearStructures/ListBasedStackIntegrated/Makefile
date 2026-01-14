# Makefile for 14-LinearStructures/programs/ListBasedStackIntegrated
#****************************************************************

PROGRAMS = \
    TestStack

ARCH = i386
CPPOPTIONS = -IStanfordCPPLib -arch $(ARCH) -fvisibility-inlines-hidden
LDOPTIONS = -LStanfordCPPLib -arch $(ARCH)
LIB = -lStanfordCPPLib

# ***************************************************************
# Entry to bring the package up to date
#    The "make all" entry should be the first real entry

all: $(PROGRAMS)

TestStack: TestStack.o
	g++ $(LDOPTIONS) -o TestStack TestStack.o $(LIB)

TestStack.o: TestStack.cpp stack.h
	g++ $(CPPOPTIONS) -c TestStack.cpp


# ***************************************************************
# Standard entries to remove files from the directories
#    tidy  -- eliminate unwanted files
#    clean -- delete derived files in preparation for rebuild

tidy:
	rm -f ,* .,* *~ core a.out *.err

clean scratch: tidy
	rm -f *.o *.a $(PROGRAMS)
