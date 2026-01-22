# Makefile for 02-FunctionsAndLibraries/programs/CircleArea
#****************************************************************

PROGRAMS = \
    CircleArea

ARCH = i386
CPPOPTIONS = -IStanfordCPPLib -arch $(ARCH) -fvisibility-inlines-hidden
LDOPTIONS = -LStanfordCPPLib -arch $(ARCH)
LIB = -lStanfordCPPLib

# ***************************************************************
# Entry to bring the package up to date
#    The "make all" entry should be the first real entry

all: $(PROGRAMS)

CircleArea: CircleArea.o
	g++ $(LDOPTIONS) -o CircleArea CircleArea.o $(LIB)

CircleArea.o: CircleArea.cpp
	g++ $(CPPOPTIONS) -c CircleArea.cpp


# ***************************************************************
# Standard entries to remove files from the directories
#    tidy  -- eliminate unwanted files
#    clean -- delete derived files in preparation for rebuild

tidy:
	rm -f ,* .,* *~ core a.out *.err

clean scratch: tidy
	rm -f *.o *.a $(PROGRAMS)
