# Makefile for 05-Collections/programs/RPNCalculator
#****************************************************************

PROGRAMS = \
    RPNCalculator

ARCH = i386
CPPOPTIONS = -IStanfordCPPLib -arch $(ARCH) -fvisibility-inlines-hidden
LDOPTIONS = -LStanfordCPPLib -arch $(ARCH)
LIB = -lStanfordCPPLib

# ***************************************************************
# Entry to bring the package up to date
#    The "make all" entry should be the first real entry

all: $(PROGRAMS)

RPNCalculator: RPNCalculator.o
	g++ $(LDOPTIONS) -o RPNCalculator RPNCalculator.o $(LIB)

RPNCalculator.o: RPNCalculator.cpp
	g++ $(CPPOPTIONS) -c RPNCalculator.cpp


# ***************************************************************
# Standard entries to remove files from the directories
#    tidy  -- eliminate unwanted files
#    clean -- delete derived files in preparation for rebuild

tidy:
	rm -f ,* .,* *~ core a.out *.err

clean scratch: tidy
	rm -f *.o *.a $(PROGRAMS)
