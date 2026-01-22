# Makefile for 08-RecursiveStrategies/programs/SubsetSum
#****************************************************************

PROGRAMS = \
    SubsetSum

ARCH = i386
CPPOPTIONS = -IStanfordCPPLib -arch $(ARCH) -fvisibility-inlines-hidden
LDOPTIONS = -LStanfordCPPLib -arch $(ARCH)
LIB = -lStanfordCPPLib

# ***************************************************************
# Entry to bring the package up to date
#    The "make all" entry should be the first real entry

all: $(PROGRAMS)

SubsetSum: SubsetSum.o
	g++ $(LDOPTIONS) -o SubsetSum SubsetSum.o $(LIB)

SubsetSum.o: SubsetSum.cpp
	g++ $(CPPOPTIONS) -c SubsetSum.cpp


# ***************************************************************
# Standard entries to remove files from the directories
#    tidy  -- eliminate unwanted files
#    clean -- delete derived files in preparation for rebuild

tidy:
	rm -f ,* .,* *~ core a.out *.err

clean scratch: tidy
	rm -f *.o *.a $(PROGRAMS)
