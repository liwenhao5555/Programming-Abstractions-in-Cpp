# Makefile for 10-AlgorithmicAnalysis/programs/QuickSort
#****************************************************************

PROGRAMS = \
    QuickSort

ARCH = i386
CPPOPTIONS = -IStanfordCPPLib -arch $(ARCH) -fvisibility-inlines-hidden
LDOPTIONS = -LStanfordCPPLib -arch $(ARCH)
LIB = -lStanfordCPPLib

# ***************************************************************
# Entry to bring the package up to date
#    The "make all" entry should be the first real entry

all: $(PROGRAMS)

QuickSort: QuickSort.o
	g++ $(LDOPTIONS) -o QuickSort QuickSort.o $(LIB)

QuickSort.o: QuickSort.cpp
	g++ $(CPPOPTIONS) -c QuickSort.cpp


# ***************************************************************
# Standard entries to remove files from the directories
#    tidy  -- eliminate unwanted files
#    clean -- delete derived files in preparation for rebuild

tidy:
	rm -f ,* .,* *~ core a.out *.err

clean scratch: tidy
	rm -f *.o *.a $(PROGRAMS)
